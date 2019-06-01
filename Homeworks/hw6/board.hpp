//
//  board.hpp
//  hw6
//
//  Created by Sriyuth Sagi on 3/11/18.
//  Copyright © 2018 Sriyuth Sagi. All rights reserved.
//

#ifndef board_hpp
#define board_hpp

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// class for the board to be played on
class Board {
public:
    
    // initializing the board after getting the number of rows and columns and the values for the rows and columns
    Board(int x, int y, vector<char>& rowsvec, vector<char>& colsvec);
    
    
    // accessors to access the private member functions
    vector<vector<char> > getBoard() {return board;}
    vector<char> getRows() {return rows;}
    vector<char> getCols() {return cols;}
    vector<char> getCurrows() {return current_rows;}
    vector<char> getCurcols() {return current_cols;}
    vector<string> getConstraints() {return constraints;}
    
    
    // horizontal functions
    // checks if a ship can be added horizontally after taking in the position and the length of the ship
    bool checkHorz(int x, int y, int length) const;
    // adds the ship to the board horizontally after taking in the position and the length of the ship
    void addHorz(int x, int y, int length);
    // removes the ship from the board in a horizontal direction after taking in the position and the length of the ship
    void removeHorz(int x, int y, int length);
    
    
    // vertical functions
    // checks if a ship can be added vertically after taking in the position and the length of the ship
    bool checkVert(int x, int y, int length) const;
    // adds the ship to the board vertically after taking in the position and the length of the ship
    void addVert(int x, int y, int length);
    // removes the ship from the board in a vertical direction after taking in the position and the length of the ship
    void removeVert(int x, int y, int length);
    
    
    // sets the constraints entered onto the board
    void setConstraints(vector<string> cons);
    // checks to make sure those constraints added to the board have not been changed
    bool checkConstraints();
    
    
    // prints the values on the board
    void print();
    
private:
    
    // values on the board
    vector<vector<char> > board;
    // entered values of the rows
    vector<char> rows;
    // entered values of the columns
    vector<char> cols;
    // current values of the rows
    vector<char> current_rows;
    // current values of the columns
    vector<char> current_cols;
    // values of the constraints
    vector<string> constraints;
    
    
};

#endif /* board_hpp */
