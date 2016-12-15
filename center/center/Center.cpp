//
//  Center.cpp
//  center
//
//  Created by 李然 on 2016/12/14.
//  Copyright © 2016年 李然. All rights reserved.
//

#include "Center.hpp"
#include <unistd.h>

#include <iostream>


using namespace center;
using namespace std;


Center::Center(){
    m_analyzer = new Analyzer();
    m_analyzer->start();
    m_server = new CenterServer(m_analyzer);
    m_server->start();
}

Center::~Center(){
    m_server->stop();
    delete(m_server);
    delete (m_analyzer);
}

int main(int argc, char** argv){
    Center* center = new Center();

    cout << "center server go to sleep" << endl;
    while (1) {
        sleep(10);
    }
}
