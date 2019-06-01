//
//  hash_table.hpp
//  hw9
//
//  Created by Sriyuth Sagi on 4/11/18.
//  Copyright © 2018 Sriyuth Sagi. All rights reserved.
//

#ifndef hash_table_hpp
#define hash_table_hpp

#include <vector>
#include <iostream>
#include <string>
using namespace std;

class hash_table {
    
public:
    
    // class initializer
    hash_table(const unsigned int in_table_size, const float in_occupancy, const unsigned int in_kmer, const string &in_genome);
    
    // a function that queries the data to find any matching values
    void query(const unsigned int mismatches, const string &sequence) const;
    
private:
    
    // private variables
    int table_size;
    float occupancy;
    unsigned int kmer;
    string genome;
    // variable for hash table
    vector<pair<int, string> > data;
    
    //hash function from https://stackoverflow.com/questions/98153/whats-the-best-hashing-algorithm-to-use-on-a-stl-string-when-using-hash-map
    unsigned int hash(string s) const;
    
    
};

#endif /* hash_table_hpp */
