//
//  Analyzer.hpp
//  center
//
//  Created by 李然 on 2016/12/15.
//  Copyright © 2016年 李然. All rights reserved.
//

#ifndef Analyzer_hpp
#define Analyzer_hpp

#include <map>
#include <string>
#include <queue>
#include <pthread.h>



using namespace std;

namespace center {
    struct MonitorDetail{
      //  string m_ip;
        double m_usage_ratio;
    };
    
    struct MigrationDetail{
        string from;
        string to;
    };
    
    class Analyzer{
    
    public:
        bool m_analyzing;
        //key is monitor‘s ip?
        map<string, MonitorDetail> m_monitor_info;
        queue<MigrationDetail> m_migration_queue;
        
        pthread_mutex_t m_monitor_info_lock = PTHREAD_MUTEX_INITIALIZER;
        pthread_mutex_t m_migration_lock = PTHREAD_MUTEX_INITIALIZER;
        
        Analyzer();
        void start();
        void stop();
        void apply_migration(const MigrationDetailail &migrationDetail);
    };
}
#endif /* Analyzer_hpp */
