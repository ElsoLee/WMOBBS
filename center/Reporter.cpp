
#include "Reporter.hpp"
#include "thrift/center_service/center_types.h"
#include "thrift/center_service/CenterService.h"
#include <pthread.h>
#include <unistd.h>

#include <iostream>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

using namespace std;
using namespace monitor;

using boost::shared_ptr;
using namespace apache::thrift::transport;
using namespace apache::thrift::protocol;
using namespace apache::thrift;

void* report(void* argv){
    Reporter* reporter = (Reporter*) argv;
    while(reporter->m_reporting){
        while(true){
            reporter->repoter_to_center();
            sleep(5);   //default report period is 5s
        }
    }
    return NULL;
}

Reporter::Reporter(){
    m_reporting = false;
}


void Reporter::start(){
    m_reporting = true;
    pthread_t pid;
    pthread_create(&pid, NULL, report, this);
}

void Reporter::stop(){
    m_reporting = false;
}


void Reporter::repoter_to_center(){
    center::MonitorInfo info;
    info.m_ip = "10.0.0.10";    //TODO: set monitor ip; 1. use an unique funtcion to get monitor ip dynamicly; 2. set static ip
    info.m_usage_ratio = m_usage_ratio;
    info.m_monitor_id = -1;   //TODO: delete this field
    boost::shared_ptr<TTransport> socket(new TSocket(""/*center ip*/, 9090));
    boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
    boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
    
    center::CenterServiceClient center_client(protocol);
    try{
        transport->open();
        center_client.report_monitor_info(info);
        transport->close();
    }
    catch(TException &tx){
        cout << "Repoter failed to connect to center" << endl;
    }
}
