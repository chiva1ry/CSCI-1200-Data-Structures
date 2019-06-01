//
//  main.cpp
//  lab2
//
//  Created by Sriyuth Sagi on 1/23/18.
//  Copyright © 2018 Sriyuth Sagi. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "Time.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    
    Time t1(14,4,5);
    Time t2(12,0,0);
    Time t3;
    
    cout << "Checkpoint 1" << endl;
    cout << "t1 --> " << flush;
    t1.PrintTime();
    cout << "t2 --> " << flush;
    t2.PrintTime();
    cout << "t3 --> " << flush;
    t3.PrintTime();
    
    
    cout << "Checkpoint 2" << endl;
    cout << "t1 in 12 hour --> " << flush;
    t1.PrintAmPm();
    cout << "t2 in 12 hour --> " << flush;
    t2.PrintAmPm();
    cout << "t3 in 12 hour --> " << flush;
    t3.PrintAmPm();
    
    
    cout << "Checkpoint 3" << endl;
    vector<Time> times;
    Time vect1(14,54,6);
    times.push_back(vect1);
    Time vect2(3,5,56);
    times.push_back(vect2);
    Time vect3(11,34,23);
    times.push_back(vect3);
    Time vect4(12,0,0);
    times.push_back(vect4);
    Time vect5;
    times.push_back(vect5);
    
    sort(times.begin(), times.end(), IsEarlierThan);
    for (int i=0;i<times.size();i++) {
        times[i].PrintAmPm();
    }
    
    
    
    return 0;
}
