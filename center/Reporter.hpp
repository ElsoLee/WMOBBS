
#ifndef Reporter_hpp
#define Reporter_hpp

#include <stdio.h>

namespace monitor {
    class Reporter{
    public:
        Reporter();
        bool m_reporting;
        double m_usage_ratio;
        
        void start();
        void stop();
        void repoter_to_center();
    };
}


#endif /* Reporter_hpp */
