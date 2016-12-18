//
//  Analyzer.cpp
//  center
//
//  Created by 李然 on 2016/12/15.
//  Copyright © 2016年 李然. All rights reserved.
//

#include "Analyzer.hpp"

#include "Center.hpp"

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include <pthread.h>
#include <iostream>
#include <map>
#include <string>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using boost::shared_ptr;


using namespace center;
using namespace std;


void *analyzing(void *argv){
    Analyzer *analyzer = (Analyzer*)argv;
    
    int max_magrition_size = 3;
    
    while(analyzer->m_analyzing){
        cout << "Center begins analyze" << endl;
        cout << "Current migration queue size is " << analyzer->m_migration_queue.size() << endl;
        for (map<string, MonitorDetail>::iterator mon = analyzer->m_monitor_info.begin();mon != analyzer->m_monitor_info.end();  mon++) {
            
            if(mon->second.m_usage_ratio >= MIGRATION_THRESHOLD){
                
                if (analyzer->m_migration_queue.size() >= max_magrition_size) break;
                
                
                //find monitor has the smallest usage ratio
                double smallest_ratio = 10000.00;
                pair<string,MonitorDetail> smallest_monitor;
                for (map<string, MonitorDetail>::iterator it = analyzer->m_monitor_info.begin();it != analyzer->m_monitor_info.end();  it++) {
                    if (it->second.m_usage_ratio < smallest_ratio) {
                        smallest_ratio = it->second.m_usage_ratio;
                        smallest_monitor = *it;
                    }
                }
                
                if(smallest_monitor.first == mon->first){
                    cout << "Every subcluster's usage ratio has exceeded the MIGRATION_THREHOLD!" << endl;
                    break;
                }
                pthread_mutex_lock(&analyzer->m_migration_lock);

                MigrationDetail migration{mon->first, smallest_monitor.first};
                analyzer->m_migration_queue.push(migration);
                
                pthread_mutex_unlock(&analyzer->m_migration_lock);
            
                //TODO: like Monitor module in MOBBS, after iteration reweight usage ration by *0.1
                
                cout << "Migration queue has length " << analyzer->m_migration_queue.size() << endl;
            }
        }
    
    }
    return NULL;
}

void *dispathing(void *argv){
    Analyzer *analyzer = (Analyzer*) argv;
    while (analyzer->m_analyzing) {
        while (!analyzer->m_migration_queue.empty()) {
            pthread_mutex_lock(&analyzer->m_migration_lock);
            MigrationDetail mig = analyzer->m_migration_queue.front();
            analyzer->m_migration_queue.pop();
            analyzer->apply_migration(mig);
            pthread_mutex_unlock(&analyzer->m_migration_lock);
        }
    }
    
   return NULL;
}

Analyzer::Analyzer(){
    m_analyzing = false;
}
    
void Analyzer::start(){
    m_analyzing = true;
    pthread_t pid1, pid2;
    pthread_create(&pid1, NULL, analyzing, this);
    pthread_create(&pid2, NULL, dispathing, this);
}
void Analyzer::stop(){
    m_analyzing = false;
}

void Analyzer::apply_migration(const MigrationDetail &migrationDetail){
   
    string from_ip = migrationDetail.from;
    boost::shared_ptr<TTransport> from_socket(new TSocket(from_ip, 9090));
    boost::shared_ptr<TTransport> from_transport(new TBufferedTransport(from_socket));
    boost::shared_ptr<TProtocol> from_protocol(new TBinaryProtocol(from_transport));
    try{
        from_transport->open();
        //TODO: add monitor RPC
        from_transport->close();
    }catch(TException &e){
        cout << "Fail to connect monitor:" << from_ip << endl;
    }
    
    string to_ip = migrationDetail.to;
    boost::shared_ptr<TTransport> to_socket(new TSocket(to_ip, 9090));
    boost::shared_ptr<TTransport> to_transport(new TBufferedTransport(to_socket));
    boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(to_transport));
    try{
        to_transport->open();
        //TODO: add monitor RPC
        to_transport->close();
    }catch(TException &e){
        cout << "Fail to connect monitor:" << to_ip << endl;
    }
    
    
}
