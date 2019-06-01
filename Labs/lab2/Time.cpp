//
//  Time.cpp
//  lab2
//
//  Created by Sriyuth Sagi on 1/23/18.
//  Copyright © 2018 Sriyuth Sagi. All rights reserved.
//

#include "Time.hpp"
#include <iomanip>
#include <iostream>

Time::Time() {
    hour = 0;
    minute = 0;
    second = 0;
}
Time::Time(int aHour, int aMinute, int aSecond) {
    hour = aHour;
    minute = aMinute;
    second = aSecond;
}

int Time::getHour() const {
    return hour;
}
int Time::getMin() const {
    return minute;
}
int Time::getSec() const {
    return second;
}

void Time::PrintTime() {
    std::cout << std::setfill ('0') << std::setw (2) << hour << ':' << std::setfill ('0') << std::setw (2) << minute << ':' << std::setfill ('0') << std::setw (2) << second << std::endl;
}


void Time::setHour(int h) {
    hour = h;
}
void Time::setMin(int m) {
    minute = m;
}
void Time::setSec(int s) {
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











