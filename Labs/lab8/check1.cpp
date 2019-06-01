////
////  check1.cpp
////  lab8
////
////  Created by Sriyuth Sagi on 3/7/18.
////  Copyright © 2018 Sriyuth Sagi. All rights reserved.
////
//
//#include <iostream>
//using namespace std;
//
//
//int numberPaths(int x, int y) {
//    if (x == 0 && y == 0) {
//        return 1;
//    }
//
//    int hor = 0;
//    int ver = 0;
//
//    if (x > 0) {
//        hor = numberPaths(x-1, y);
//    }
//    if (y > 0) {
//        ver = numberPaths(x, y-1);
//    }
//
//    return hor + ver;
//}
//
//
//int main(int argc, char **argv)
//{
//
//    int x = atoi(argv[1]);
//    int y = atoi(argv[2]);
//
//    cout << numberPaths(x, y) << endl;
//    return 0;
//}
//
//
//
