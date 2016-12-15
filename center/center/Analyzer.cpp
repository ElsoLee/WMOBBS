//
//  Analyzer.cpp
//  center
//
//  Created by 李然 on 2016/12/15.
//  Copyright © 2016年 李然. All rights reserved.
//

#include "Analyzer.hpp"

namespace center {
    Analyzer::Analyzer(){
        m_analyzing = false;
    }
    
    
    void Analyzer::start(){
        m_analyzing = true;
    }
    void Analyzer::stop(){
        m_analyzing = false;
    }
    
    
}
