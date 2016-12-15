//
//  CenterService.hpp
//  center
//
//  Created by 李然 on 2016/12/14.
//  Copyright © 2016年 李然. All rights reserved.
//

#ifndef CenterServer_hpp
#define CenterServer_hpp

#include "../Analyzer.hpp"

#define THRIFT_PORT 9090

namespace center{
    class CenterServer
    {
    public:
        CenterServer(Analyzer *analyzer);
        void start();
        void stop();
        
        Analyzer *m_analyzer;
        void* m_server;
    };
}



#endif /* CenterServer_hpp */
