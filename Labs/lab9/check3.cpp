//
//  check3.cpp
//  lab9
//
//  Created by Sriyuth Sagi on 3/21/18.
//  Copyright © 2018 Sriyuth Sagi. All rights reserved.
//

// A simple "caller ID" program
// memory used -> O(1)




#include <iostream>
#include <string>
#include <map>
using namespace std;

// add a number, name pair to the phonebook
void add(map<int,string> &phonebook, int number, const string& name) {
    phonebook[number] = name;
}

// given a phone number, determine who is calling
void identify(const map<int,string>& phonebook, int number) {
    if (phonebook.find(number) == phonebook.end())
        cout << "unknown caller!" << endl;
    else
        cout << phonebook.find(number)->second << " (" << number << ") is calling!" << endl;
}


int main() {
    // create the phonebook; initially all numbers are unassigned
    map<int,string> phonebook;
    
    // add several names to the phonebook
    phonebook[1111] = "fred";
    phonebook[2222] = "sally";
    phonebook[3333] = "george";

    
    // test the phonebook
    identify(phonebook, 2222);
    identify(phonebook, 4444);
}


