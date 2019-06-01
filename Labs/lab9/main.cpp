////
////  main.cpp
////  lab9
////
////  Created by Sriyuth Sagi on 3/21/18.
////  Copyright © 2018 Sriyuth Sagi. All rights reserved.
////
//
//#include <iostream>
//#include <vector>
//#include <fstream>
//#include <map>
//using namespace std;
//
//int main(int argc, char *argv[])
//{
//    
//    ifstream file(argv[1]);
//    
//    map<int,int> modes;
//    int n;
//    while (file >> n)
//        modes[n]++;
//    
//    
//    
//    
//    vector<int> high_mode;
//    int max_modes = -1;
//
//    
//    for (map<int,int>::iterator i = modes.begin(); i != modes.end(); i++) {
//        if (i->second > max_modes) {
//            max_modes = i->second;
//            high_mode.clear();
//            high_mode.push_back(i->first);
//        }
//        else if (i->second == max_modes) {
//            high_mode.push_back(i->first);
//        }
//    }
//    
//    cout << "Modes: " << endl;
//    for (int i = 0; i < high_mode.size(); i++) {
//        cout << high_mode[i] << endl;
//    }
//    
//
//    return 0;
//}
//
//
//

