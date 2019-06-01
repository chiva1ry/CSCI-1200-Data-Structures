//
//  main.cpp
//  lab6
//
//  Created by Sriyuth Sagi on 2/21/18.
//  Copyright © 2018 Sriyuth Sagi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
using namespace std;

/*
vector<int> reverse_vector(vector<int>& vec) {
    for (int i=0; i<vec.size()/2; i++) {
        int temp = vec[i];
        vec[i] = vec[vec.size()-1-i];
        vec[vec.size()-1-i] = temp;
    }
    return vec;
}


void printv(vector<int>& vec) {
    for (int i=0; i<vec.size(); i++) {
        cout << vec[i] << ' ' << flush;
    }
    cout << endl;
}




list<int> reverse_list(list<int>& lst) {
    list<int>::iterator ni=lst.begin();
    list<int>::reverse_iterator ri=lst.rbegin();
    for (int i=0; i<lst.size()/2; i++) {
        int temp = *ni;
        *ni = *ri;
        *ri = temp;
        ri++;
        ni++;
    }
    return lst;
}


void printl(list<int>& lst) {
    for (list<int>::iterator i=lst.begin(); i!=lst.end(); i++) {
        cout << *i << ' ' << flush;
    }
    cout << endl;
}






int main(int argc, const char * argv[]) {
    vector<int> vec;
    for (int i=0; i<5; i++) {
        vec.push_back(i*i);
    }
    printv(vec);
    reverse_vector(vec);
    printv(vec);
    
    cout << endl;
    
    list<int> lst;
    for (int i=0; i<10; i++) {
        lst.push_back(i*i);
    }
    printl(lst);
    reverse_list(lst);
    printl(lst);
    
    
    
    return 0;
}
*/
