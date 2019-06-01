//
//  main.cpp
//  hw9
//
//  Created by Sriyuth Sagi on 4/11/18.
//  Copyright © 2018 Sriyuth Sagi. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "hash_table.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    
    // assigning variables
    unsigned int table_size = 100;
    float occupancy = 0.5;
    unsigned int kmer = 0;
    string genome = "";
    string temp;

    // reading in the genome file to the genome variable as a string
    cin >> temp >> temp;
    ifstream genome_file(temp);
    
    while(genome_file >> temp) {
        genome += temp;
    }

    // reads in parameters through a loop for other variables until kmer is changed
    while(kmer == 0) {
        cin >> temp;
        if(temp == "table_size") {
            cin >> temp;
            table_size = stoi(temp);
        }
        if(temp == "occupancy") {
            cin >> temp;
            occupancy = stof(temp);
        }
        if(temp == "kmer") {
            cin >> temp;
            kmer = stoi(temp);
        }
    }

    // initializes and creates a hash table
    hash_table table(table_size, occupancy, kmer, genome);

    // loops until quit is entered
    while(true) {
        cin >> temp;

        // checks for quit
        if(temp == "quit") {
            break;
        } else {
            unsigned int m;
            string query_string;
            cin >> m >> query_string;
            
            // output and query
            cout << "Query: " << query_string << endl;
            table.query(m, query_string);
        }

    }
    
    return 0;
}
