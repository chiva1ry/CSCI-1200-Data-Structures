////
////  phonebook.cpp
////  lab9
////
////  Created by Sriyuth Sagi on 3/21/18.
////  Copyright © 2018 Sriyuth Sagi. All rights reserved.
////
//
//
//
//
//
//
//// A simple "caller ID" program
//// O(N)
//// memory usage -> O(N * l), l is average length of each caller names
//// 7 digit number -> 100 times more
//// 10 digit number -> 100,000 times more
//// both functions O(1)
//
//
//
//
//
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//// add a number, name pair to the phonebook
//void add(vector<string> &phonebook, int number, string const& name) {
//    phonebook[number] = name;
//}
//
//// given a phone number, determine who is calling
//void identify(const vector<string> & phonebook, int number) {
//    if (phonebook[number] == "UNASSIGNED")
//        cout << "unknown caller!" << endl;
//    else
//        cout << phonebook[number] << " is calling!" << endl;
//}
//
//
//int main() {
//    // create the phonebook; initially all numbers are unassigned
//    vector<string> phonebook(10000, "UNASSIGNED");
//    
//    // add several names to the phonebook
//    add(phonebook, 1111, "fred");
//    add(phonebook, 2222, "sally");
//    add(phonebook, 3333, "george");
//    
//    // test the phonebook
//    identify(phonebook, 2222);
//    identify(phonebook, 4444);
//}
//
//
