//
//  Time.cpp
//  lab4
//
//  Created by Sriyuth Sagi on 2/7/18.
//  Copyright © 2018 Sriyuth Sagi. All rights reserved.
//

#include "Time.hpp"
#include <cstdio>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <stdint.h>
#include <vector>
#include <iomanip>
#include <string>

Time::Time() {
    hour = 0;
    minute = 0;
    second = 0;
}
Time::Time(uintptr_t aHour, uintptr_t aMinute, uintptr_t aSecond) {
    hour = aHour;
    minute = aMinute;
    second = aSecond;
}

uintptr_t Time::getHour() const {
    return hour;
}
uintptr_t Time::getMin() const {
    return minute;
}
uintptr_t Time::getSec() const {
    return second;
}

void Time::PrintTime() {
    std::cout << std::setfill ('0') << std::setw (2) << hour << ':' << std::setfill ('0') << std::setw (2) << minute << ':' << std::setfill ('0') << std::setw (2) << second << std::endl;
}


void Time::setHour(uintptr_t h) {
    hour = h;
}
void Time::setMin(uintptr_t m) {
    minute = m;
}
void Time::setSec(uintptr_t s) {
    second = s;
}

void Time::PrintAmPm() {
    if (hour >= 12) {
        if (hour == 12) {
            std::cout << std::setfill ('0') << std::setw (2) << hour << ':' << std::setfill ('0') << std::setw (2) << minute << ':' << std::setfill ('0') << std::setw (2) << second << " pm" << std::endl;
        } else {
            std::cout << std::setfill ('0') << std::setw (2) << hour - 12 << ':' << std::setfill ('0') << std::setw (2) << minute << ':' << std::setfill ('0') << std::setw (2) << second << " pm" << std::endl;
        }
        
    } else if (hour == 0) {
        std::cout << std::setfill ('0') << std::setw (2) << 12 << ':' << std::setfill ('0') << std::setw (2) << minute << ':' << std::setfill ('0') << std::setw (2) << second << " am" << std::endl;
    }
    else {
        std::cout << std::setfill ('0') << std::setw (2) << hour << ':' << std::setfill ('0') << std::setw (2) << minute << ':' << std::setfill ('0') << std::setw (2) << second << " am" << std::endl;
    }
}






bool IsEarlierThan(const Time& t1, const Time& t2) {
    if (((t1.getHour()*3600) + (t1.getMin()*60) + t1.getSec()) < ((t2.getHour()*3600) + (t2.getMin()*60) + t2.getSec())) {
        return true;
    } else {
        return false;
    }
}






void change_times(Time& t1, Time t2) {
    t1.setHour(t1.getHour()+1);
    if (t1.getHour() == 13) {
        t1.setHour(1);
    }
    t1.setMin(t1.getMin()+30);
    if (t1.getMin() > 59) {
        t1.setMin(t1.getMin()-60);
        t1.setHour(t1.getHour()+1);
    }
    
    t2.setHour(t2.getHour()+1);
    if (t2.getHour() == 13) {
        t2.setHour(1);
    }
    t2.setMin(t2.getMin()+30);
    if (t2.getMin() > 59) {
        t2.setMin(t2.getMin()-60);
        t2.setHour(t2.getHour()+1);
    }
    
    

    
}




