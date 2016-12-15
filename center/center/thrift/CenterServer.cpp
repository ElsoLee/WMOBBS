//
//  CenterService.cpp
//  center
//
//  Created by 李然 on 2016/12/14.
//  Copyright © 2016年 李然. All rights reserved.
//

#include "CenterServer.hpp"
#include "center_service/CenterService.h"

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

#include <iostream>
#include <pthread.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace std;
using namespace center;

void* server_listening(void* argv);


class CenterServiceHandler : virtual public CenterServiceIf{
public:
    Analyzer *m_analyzer;
    
    CenterServiceHandler(Analyzer *analyzer):m_analyzer(analyzer){}
    
    void report_monitor_info(const MonitorInfo& mi){
        pthread_mutex_lock(&m_analyzer->m_monitor_info_lock);
        
        MonitorDetail detail;
        //detail.m_ip = mi.m_ip;
        detail.m_usage_ratio = mi.m_usage_ratio;
            
        m_analyzer->m_monitor_info[mi.m_ip] = detail;
        
        pthread_mutex_unlock(&m_analyzer->m_monitor_info_lock);
    }
};


CenterServer::CenterServer(Analyzer *analyzer){
    m_analyzer = analyzer;
}

void CenterServer::start(){
    int port = THRIFT_PORT;
    boost::shared_ptr<CenterServiceHandler> handler(new CenterServiceHandler(m_analyzer));
    boost::shared_ptr<TProcessor> processor(new CenterServiceProcessor(handler));
    boost::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
    boost::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    boost::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
    
    m_server = new TSimpleServer(processor, serverTransport, transportFactory, protocolFactory);
    
    pthread_t pid;
    int ret = pthread_create(&pid, NULL, server_listening, m_server);
    if(ret != 0)
    {
        cout << "failed to start server!" << endl;
    }
}

void* server_listenning(void* argv)
{
    cout << "start center server" << endl;
    TSimpleServer* server = (TSimpleServer*)argv;
    server->serve();
    return NULL;
}

void CenterServer::stop()
{
    ((TSimpleServer*)m_server)->stop();
    delete((TSimpleServer*)m_server);
}



