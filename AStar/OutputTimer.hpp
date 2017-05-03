//
//  OutputTimer.hpp
//  AStar
//
//  Created by Sam Clark on 5/3/17.
//
//

#ifndef OutputTimer_hpp
#define OutputTimer_hpp

#include <time.h>

class OutputTimer {
public:
    OutputTimer();
    
    void start();
    void stop();
    double getTime();
    
private:
    clock_t startTime;
    clock_t endTime;
};

#endif /* OutputTimer_hpp */
