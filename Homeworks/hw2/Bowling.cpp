//
//  Bowling.cpp
//  hw2
//
//  Created by Sriyuth Sagi on 1/26/18.
//  Copyright © 2018 Sriyuth Sagi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "Bowling.hpp"
using namespace std;


// initializing the class using the input of a string with the name of a player and the scores the got
Bowl::Bowl(string& line) {
    
    vector<string> split;
    istringstream iss(line);
    string value;
    // adding values in the string to a vector with the first two values in the new vector becoming the name and the rest of the values becoming scores
    while (iss >> value) {
        split.push_back(value);
    }
    name = split[0] + ' ' + split[1];
    for (int i=2;i<split.size();i++) {
        scores.push_back(stoi(split[i]));
    }
    
    
    // a vector which checks each box and returns a zero if no strikes or spares, a 1 for a strike and a 2 for a spare in each box
    vector<int> strikeSpareTrack;
    gutters = 0;
    strikes = 0;
    spares = 0;
    // finding values to display in each box of the table by checking for the presence of tens (in which case it will instantly move o the new box and display an X), zeros (which will instead display a -) and spares (which will display a /)
    // evaluates for the first nine boxes
    int i = 0;
    int box = 1;
    string first;
    string second;
    while (i<scores.size() && box<10) {
        // replaces the value with a X, pushes to a new box and adds a strike to the counter
        if (scores[i] == 10) {
            inBox.push_back("X");
            strikes++;
            strikeSpareTrack.push_back(1);
        } else {
            first = to_string(scores[i]);
            second = to_string(scores[i+1]);
            // checks if the total score in the box is ten, where it then replaces the second value with a / and sends the two values to a new box while adding a spare
            if (scores[i]+scores[i+1] == 10) {
                second = "/";
                spares++;
                strikeSpareTrack.push_back(2);
            } else {
                strikeSpareTrack.push_back(0);
            }
            // replaces zeros with -
            if (scores[i] == 0) {
                first = "-";
                gutters++;
            }
            if (scores[i+1] == 0) {
                second = "-";
                gutters++;
            }
            // adds the new value to the vector for each box if no strikes or spares
            inBox.push_back(first + ' ' + second);
            i++;
        }
        
        box++;
        i++;
    }
    // last box
    string lastBox;
    bool lastBoxSpare = false;
    // checks if the last box has a spare
    if (scores[i] != 10 && scores[i]+scores[i+1] == 10) {
        lastBoxSpare = true;
    }
    
    while (i<scores.size()) {
        // replaces tens with X
        if (scores[i] == 10) {
            lastBox = lastBox + " X";
            strikes++;
        }
        else if (scores[i] == 0) {
            // replaces zeros with -
            lastBox = lastBox + " -";
            gutters++;
        } else {
            lastBox = lastBox + ' ' + to_string(scores[i]);
        }
        i++;
    }
    // adds a / if the last box has a spare
    if (lastBoxSpare == true) {
        lastBox[3] = '/';
        spares++;
    }
    // adds the string as the last box after removing the extra space at the beginning of the string
    lastBox.erase(0,1);
    inBox.push_back(lastBox);
    
    
    // finding the running score and final score throughout the game
    // first 9 boxes
    i = 0;
    int j = 0;
    int runningScore = 0;
    int boxScore = 0;
    // finding the running score for the first nine boxes
    while (j<9) {
        // adds all the scores from the box
        for (int k=0;k<((inBox[j].length()+1)/2);k++) {
            runningScore = runningScore + scores[i];
            boxScore = boxScore + scores[i];
            i++;
        }
        // checks if there is a strike on that box in which case it adds the scores from the next two values
        if (strikeSpareTrack[j] == 1) {
            runningScore = runningScore + scores[i] + scores[i+1];
        }
        // checks if there is a spare on that box in which case it adds the scores from the next value
        else if (strikeSpareTrack[j] == 2) {
            runningScore = runningScore + scores[i];
        }
        // adds the score from that box to the vector of running scores and resets the score from the specific box
        total.push_back(runningScore);
        j++;
        boxScore = 0;
    }
    // last box where it only has to find the total score in the box
    for (int k=0;k<((inBox[j].length()+1)/2);k++) {
        runningScore = runningScore + scores[i];
        boxScore = boxScore + scores[i];
        i++;
    }
    total.push_back(runningScore);
    
    
    // assigning the final score
    finalScore = runningScore;
    
}



// function to return name
string Bowl::getName() const {
    return name;
}

// function to return final score
int Bowl::getScore() const {
    return finalScore;
}

// function to return number of gutter balls
int Bowl::getGutter() const {
    return gutters;
}

// function to return number of strikes
int Bowl::getStrike() const {
    return strikes;
}

// function to return number of spares
int Bowl::getSpare() const {
    return spares;
}

// function to return the score accumulated in the early part of the game
int Bowl::earlyGameScore() {
    int early = total[2];
    
    return early;
}

// function to return the score accumulated in the middle part of the game
int Bowl::midGameScore() {
    int mid = total[6] - total[2];
    
    return mid;
}

// function to return the score accumulated in the final part of the game
int Bowl::lateGameScore() {
    int late = total[9] - total[6];
    
    return late;
}




// displays score in the form of a table with boxes to represent the score in each round and the running score up till that point of the game and output this data to an outfile after taking the length of the name and the file to output to
void Bowl::scoreDisplay(const int nameLength, ofstream& outfile) {
    
    // outputing the first line
    outfile << string(nameLength,'-') << string(66,'-') << endl;
    // outputing the name
    outfile << "| " << flush;
    outfile << setw(nameLength) << left << name << internal << flush;
    // outputing the scores achieved in each round until the 9th
    for (int i=0;i<9;i++) {
        outfile << " | " << flush;
        outfile << setw(3) << inBox[i] << flush;
    }
    // outputting the scores made in the tenth round
    outfile << " | " << flush;
    outfile << setw(5) << left << inBox[9] << internal << flush;
    outfile << " |" << endl;
    
    // outputting a blank space under the name
    outfile << "| " << flush;
    outfile << string(nameLength,' ') << flush;
    // outputing the running total score over each round
    for (int i=0;i<9;i++) {
        outfile << " | " << flush;
        outfile << setw(3) << total[i] << flush;
    }
    // outputting the final score in the tenth box
    outfile << " | " << flush;
    outfile << setw(5) << total[9] << flush;
    outfile << " |" << endl;
  
}



// displays the name and final score of the game with the text being justified by a set length according to the inputted length of the name and this text being sent to the file in the ofstream
void Bowl::statsDisplay(const int nameLength, ofstream& outfile) {
    outfile << setw(nameLength+2) << left << name << setw(3) << right << finalScore << internal << endl;
}


// outputting the custom output in the form of a table with the values of the names, scores from the beginning part of the game, the middle part of the game and the end part of the game along with the total scores, number of strikes spares and gutters sorted by the alphabetical order of the names and followed by the averages of all of these statistics
void Bowl::scoreBreakdown(const int nameLength, ofstream& outfile) {
    
    outfile << "| " << flush;
    outfile << setw(nameLength) << left << name << internal << flush;
    outfile << " | " << flush;
    outfile << setw(10) << earlyGameScore() << flush;
    outfile << " | " << flush;
    outfile << setw(10) << midGameScore() << flush;
    outfile << " | " << flush;
    outfile << setw(10) << lateGameScore() << flush;
    outfile << " | " << flush;
    outfile << setw(10) << finalScore << flush;
    outfile << " | " << flush;
    outfile << setw(10) << strikes << flush;
    outfile << " | " << flush;
    outfile << setw(10) << spares << flush;
    outfile << " | " << flush;
    outfile << setw(10) << gutters << flush;
    outfile << " |" << endl;
    
}




// function for sorting the names in alphabetical order by finding the the earlier and later last names using data from two classes
bool sortingName(Bowl i, Bowl j) {
    
    // getting the full names of both players from both of the classes and splitting them up into first and last names
    istringstream iss1(i.getName());
    istringstream iss2(j.getName());
    
    // switching the order from first name then last name to last name then first name
    string first;
    string last;
    iss1 >> first;
    iss1 >> last;
    string result1 = last+first;
    iss2 >> first;
    iss2 >> last;
    string result2 = last+first;
    
    // comparing the new names in alphabetical order
    return (result1 < result2);
}


// function for sorting classes depending on the final score with the data from two different classes
bool sortingScore(Bowl i, Bowl j) {
    // returns the scores after looking up the final scores from both the classes
    return (i.getScore() > j.getScore());
}

