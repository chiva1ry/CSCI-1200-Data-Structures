//
//  Bowling.hpp
//  hw2
//
//  Created by Sriyuth Sagi on 1/26/18.
//  Copyright © 2018 Sriyuth Sagi. All rights reserved.
//

#ifndef Bowling_hpp
#define Bowling_hpp

class Bowl {
public:
    // initializing class
    Bowl(std::string& line);
    
    // returning values
    // function to return name
    std::string getName() const;
    // function to return final score
    int getScore() const;
    // function to return number of gutter balls
    int getGutter() const;
    // function to return number of strikes
    int getStrike() const;
    // function to return number of spares
    int getSpare() const;
    // function to return the score accumulated in the early part of the game
    int earlyGameScore();
    // function to return the score accumulated in the middle part of the game
    int midGameScore();
    // function to return the score accumulated in the final part of the game
    int lateGameScore();
    
    // displaying score in table and list formats
    // displays score in the form of a table with boxes to represent the score in each round and the running score up till that point of the game and output this data to an outfile after taking the length of the name and the file to output to
    void scoreDisplay(const int nameLength, std::ofstream& outfile);
    // displays the name and final score of the game with the text being justified by a set length according to the inputted length of the name and this text being sent to the file in the ofstream
    void statsDisplay(const int nameLength, std::ofstream& outfile);
    // outputting the custom output in the form of a table with the values of the names, scores from the beginning part of the game, the middle part of the game and the end part of the game along with the total scores, number of strikes spares and gutters sorted by the alphabetical order of the names and followed by the averages of all of these statistics
    void scoreBreakdown(const int nameLength, std::ofstream& outfile);
    
    
private:
    // name
    std::string name;
    // all the scores entered into the class
    std::vector<int> scores;
    // running total of scores
    std::vector<int> total;
    // the values to put in each box of the table
    std::vector<std::string> inBox;
    // final score
    int finalScore;
    // number of gutters
    int gutters;
    // number of strikes
    int strikes;
    // number of spares
    int spares;
};

// function for sorting the names in alphabetical order by finding the the earlier and later last names using data from two classes
bool sortingName(Bowl i, Bowl j);
// function for sorting classes depending on the final score with the data from two different classes
bool sortingScore(Bowl i, Bowl j);


#endif /* Bowling_hpp */
