//
//  Center.hpp
//  center
//
//  Created by 李然 on 2016/12/14.
//  Copyright © 2016年 李然. All rights reserved.
//

#ifndef Center_hpp
#define Center_hpp

#include "Analyzer.hpp"
#include "thrift/CenterServer.hpp"

#define MIGRATION_THRESHOLD 2.0

namespace center {
    class Center
    {
    public:
        Center();
        ~Center();
        
        Analyzer *m_analyzer;
        CenterServer *m_server;
    };
}

#endif /* Center_hpp */
