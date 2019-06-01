//
//  main.cpp
//  hw2
//
//  Created by Sriyuth Sagi on 1/26/18.
//  Copyright © 2018 Sriyuth Sagi. All rights reserved.
//

// including all libraries
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Bowling.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    //argv[0] is executable
    //argv[1] is input file name
    //argv[2] is output file name
    //argv[3] is the type of output required
    
    
    // inputting the file and returning an error if file does not exist
    ifstream infile(argv[1]);
    if (!infile.good()) {
        cerr << "Can't open " << argv[1] << " to read." << endl;
        exit(1);
    }
    
    
    // outputting the file and returning an error if file does not exist
    ofstream outfile(argv[2]);
    if (!outfile.good()) {
        cerr << "Can't open " << argv[2] << " to write." << endl;
        exit(1);
    }
    
    
    // making lines with names and scores
    vector<string> scores;
    string word;
    string line;
    // first pulling all the words and separating by the presence of either a word or a number (problem with the first and last name being stored as different values)
    while (infile >> word) {
        // for the presence of a word
        if ( ('0' <= word[0] && word[0] <= '9' ) == false) {
            scores.push_back(line);
            line = word;
        // for the presence of a number
        } else {
            line = line + ' ' + word;
        }
    }
    scores.push_back(line);
    scores.erase(scores.begin());
    // combines the first and last names that were separated by changing the values in the elements with the last names
    for (int i=0;i<scores.size();i=i+2) {
        scores[i] = scores[i] + ' ' + scores[i+1];
    }
    // removes the elements in the vector that now only have the first name
    for (int i=1;i<scores.size();i++) {
        scores.erase(scores.begin() + i);
    }
    
    
    
    // making vector of classes and a vector of the length of each of the names from each player
    vector<Bowl> names;
    vector<int> nameLengths;
    for ( int i=0;i<scores.size();i++) {
        Bowl stat(scores[i]);
        names.push_back(stat);
        nameLengths.push_back(stat.getName().length());
    }

    // finding the length of the longest name from among the players
    const int highestNameLength = *max_element(nameLengths.begin(),nameLengths.end());
    
    
    // output for the standard part of the program
    if (argv[3] == string("standard")) {
        // displaying all scores and running scores
        // sorting by the last names in alphabetical order
        sort(names.begin(),names.end(),sortingName);
        // displays all the details of the game in a scoreboard like format
        for (int i=0;i<names.size();i++) {
            names[i].scoreDisplay(highestNameLength, outfile);
        }
        outfile << string(highestNameLength,'-') << string(66,'-') << endl;
        
        outfile << endl;
        
        
        // displaying name and total scores
        // sorting from highest to lowest score
        sort(names.begin(),names.end(),sortingScore);
        for (int i=0;i<names.size();i++) {
            names[i].statsDisplay(highestNameLength, outfile);
        }
    }
    
    
    // outputting the custom output in the form of a table with the values of the names, scores from the beginning part of the game, the middle part of the game and the end part of the game along with the total scores, number of strikes spares and gutters sorted by the alphabetical order of the names and followed by the averages of all of these statistics
    else if (argv[3] == string("custom")) {
        // the column titles of all the values in the table
        outfile << string(117,'-') << endl;
        outfile << "| " << flush;
        outfile << setw(highestNameLength) << left << "Names" << internal << flush;
        outfile << " | " << flush;
        outfile << setw(10) << "Early game" << flush;
        outfile << " | " << flush;
        outfile << setw(10) << "Mid game" << flush;
        outfile << " | " << flush;
        outfile << setw(10) << "Late game" << flush;
        outfile << " | " << flush;
        outfile << setw(10) << "End score" << flush;
        outfile << " | " << flush;
        outfile << setw(10) << "Strikes" << flush;
        outfile << " | " << flush;
        outfile << setw(10) << "Spares" << flush;
        outfile << " | " << flush;
        outfile << setw(10) << "Gutters" << flush;
        outfile << " |" << endl;
        outfile << string(117,'-') << endl;
        
        
        // prints all the statistics that are to go in the table and calculates the average of all these statistics
        sort(names.begin(),names.end(),sortingName);
        float averageEarly = 0;
        float averageMid = 0;
        float averageLate = 0;
        float averageTotal = 0;
        float averageStrikes = 0;
        float averageSpares = 0;
        float averageGutters = 0;
        for (int i=0;i<names.size();i++) {
            names[i].scoreBreakdown(highestNameLength, outfile);
            averageEarly = averageEarly + names[i].earlyGameScore();
            averageMid = averageMid + names[i].midGameScore();
            averageLate = averageLate + names[i].lateGameScore();
            averageTotal = averageTotal + names[i].getScore();
            averageStrikes = averageStrikes + names[i].getStrike();
            averageSpares = averageSpares + names[i].getSpare();
            averageGutters = averageGutters + names[i].getGutter();
        }
        averageEarly = averageEarly / scores.size();
        averageMid = averageMid / scores.size();
        averageLate = averageLate / scores.size();
        averageTotal = averageTotal / scores.size();
        averageStrikes = averageStrikes / scores.size();
        averageSpares = averageSpares / scores.size();
        averageGutters = averageGutters / scores.size();
        
        
        // the averages of all the statistics are displayed
        outfile << "| " << flush;
        outfile << setw(highestNameLength) << left << "Averages" << internal << flush;
        outfile << " | " << flush;
        outfile << setw(10) << setprecision(4) << averageEarly << flush;
        outfile << " | " << flush;
        outfile << setw(10) << setprecision(4) << averageMid << flush;
        outfile << " | " << flush;
        outfile << setw(10) << setprecision(4) << averageLate << flush;
        outfile << " | " << flush;
        outfile << setw(10) << setprecision(4) << averageTotal << flush;
        outfile << " | " << flush;
        outfile << setw(10) << setprecision(2) << averageStrikes << flush;
        outfile << " | " << flush;
        outfile << setw(10) << setprecision(2) << averageSpares << flush;
        outfile << " | " << flush;
        outfile << setw(10) << setprecision(2) << averageGutters << flush;
        outfile << " |" << endl;
    
    }
    
    
    return 0;
}
