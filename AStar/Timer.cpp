//
//  Timer.cpp
//  AStar
//
//  Created by Sam Clark on 4/29/17.
//
//

#include "Timer.hpp"

Timer::Timer(double ms, function<void()> callback) {
    // http://stackoverflow.com/questions/19555121/how-to-get-current-timestamp-in-milliseconds-since-1970-just-the-way-java-gets
    this->endMs = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() + ms;
    this->callback = callback;
}

bool Timer::hasCompleted() {
    double now = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    return now >= endMs;
}
