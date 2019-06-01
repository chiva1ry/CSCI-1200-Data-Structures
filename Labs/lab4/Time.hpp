//
//  Time.hpp
//  lab4
//
//  Created by Sriyuth Sagi on 2/7/18.
//  Copyright © 2018 Sriyuth Sagi. All rights reserved.
//

#ifndef Time_hpp
#define Time_hpp


#include <iomanip>
#include <iostream>


class Time {
public:
    Time();
    Time(uintptr_t aHour, uintptr_t aMinute, uintptr_t aSecond);
    
    uintptr_t getHour() const;
    uintptr_t getMin() const;
    uintptr_t getSec() const;
    void PrintTime();
    
    void setHour(uintptr_t aHour);
    void setMin(uintptr_t aMinute);
    void setSec(uintptr_t aSecond);
    void PrintAmPm();
    
    
private:
    uintptr_t hour;
    uintptr_t minute;
    uintptr_t second;
};

#endif /* Time_hpp */

bool IsEarlierThan(const Time& t1, const Time& t2);
void change_times(Time& t1, Time t2);

