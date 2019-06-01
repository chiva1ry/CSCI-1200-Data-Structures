//
//  hash_table.cpp
//  hw9
//
//  Created by Sriyuth Sagi on 4/11/18.
//  Copyright © 2018 Sriyuth Sagi. All rights reserved.
//

#include "hash_table.hpp"


//hash function from https://stackoverflow.com/questions/98153/whats-the-best-hashing-algorithm-to-use-on-a-stl-string-when-using-hash-map
/* magic numbers from http://www.isthe.com/chongo/tech/comp/fnv/ */
static const size_t InitialFNV = 2166136261U;
static const size_t FNVMultiple = 16777619;

/* Fowler / Noll / Vo (FNV) Hash */
unsigned int hash_table::hash(string s) const
{
    size_t hash = InitialFNV;
    for(size_t i = 0; i < s.length(); i++)
    {
        hash = hash ^ (s[i]);       /* xor  the low 8 bits */
        hash = hash * FNVMultiple;  /* multiply by the magic number */
    }
    return hash % table_size; //added % table_size to avoid errors
}


// class initializer
hash_table::hash_table(const unsigned int in_table_size, const float in_occupancy, const unsigned int in_kmer, const string &in_genome) {
    
    // assigns private variables in the class
    table_size = in_table_size;
    occupancy = in_occupancy;
    kmer = in_kmer;
    genome = in_genome;
    
    // checks how big the table has to be by looping to the power of 2 until the size is greater than the set value
    while (((float)(genome.length() - kmer + 1) / table_size) > occupancy) {
        table_size *= 2;
    }
    
    // populates the hash table with empty values
    for (int i = 0; i < table_size; i++) {
        data.push_back(make_pair(-1, ""));
    }
    
    // inserts all the strings of length kmer starting at each index on the genome string into the hash table
    for (unsigned int i = 0; i < genome.length() - kmer + 1; i++) {
        
        // finds the sequence of length kmer at the position and finds the hash value for the string
        string sequence(genome, i, kmer);
        int ind = hash(sequence);
        
        // enters the value into the vector if the position is empty otherwise loops until an empty position
        if(data[ind].second == "") {
            data[ind] = make_pair(i, sequence);
        } else {
            
            while(data[ind].second != "") {
                ind = (ind + 1) % table_size;
            }
            
            data[ind] = make_pair(i, sequence);
        }
    }
}


// a function that queries the data to find any matching values
void hash_table::query(const unsigned int mismatches, const string &sequence) const {
    
    // finds the sequence of length kmer at the position and finds the hash value for the string and sets found solutions to false
    string seq_kmer(sequence, 0, kmer);
    unsigned int ind = hash(seq_kmer);
    bool solution = false;
    
    // loops until the next empty index in the vector as the same string will be in the next position in the vector
    while (data[ind].second != "") {
        
        // checks if the value at the index matches the string
        if (data[ind].second == seq_kmer) {
            
            // finds a variable with the string at that position in the genome
            string found(genome, data[ind].first, sequence.length());
            unsigned int m = 0;
            
            // finds the number of mismatches by finding the number of times the letters in the string at each position do not match
            for(unsigned int i = 0; i < sequence.length(); i++) {
                if (found[i] != sequence[i]) {
                    m++;
                }
            }
            
            // outputs if there is an acceptable number of mismatches and sets solutions to true
            if (m <= mismatches) {
                cout << data[ind].first << " " << m << " " << found << endl;
                solution = true;
            }
        }
        
        // iterates to the next value in the vector
        ind = (ind + 1) % table_size;
    }
    
    // outputs if there are no solutions
    if (!solution){
        cout << "No Match" << endl;
    }
}
