//
//  OutputTimer.cpp
//  AStar
//
//  Created by Sam Clark on 5/3/17.
//
//

#include "OutputTimer.hpp"

OutputTimer::OutputTimer() {
    startTime = 0;
    endTime = 0;
}

void OutputTimer::start() {
    startTime = clock();
}

void OutputTimer::stop() {
    endTime = clock();
}

double OutputTimer::getTime() {
    // https://ubuntuforums.org/showthread.php?t=209511
    return (double) (endTime - startTime) / (CLOCKS_PER_SEC / 1000);
}
