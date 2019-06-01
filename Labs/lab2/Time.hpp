//
//  Time.hpp
//  lab2
//
//  Created by Sriyuth Sagi on 1/23/18.
//  Copyright © 2018 Sriyuth Sagi. All rights reserved.
//

#ifndef Time_hpp
#define Time_hpp


class Time {
public:
    Time();
    Time(int aHour, int aMinute, int aSecond);
    
    int getHour() const;
    int getMin() const;
    int getSec() const;
    void PrintTime();
    
    void setHour(int aHour);
    void setMin(int aMinute);
    void setSec(int aSecond);
    void PrintAmPm();

 
private:
    int hour;
    int minute;
    int second;
};

#endif /* Time_hpp */

bool IsEarlierThan(const Time& t1, const Time& t2);
