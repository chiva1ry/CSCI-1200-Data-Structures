//
//  board.cpp
//  hw6
//
//  Created by Sriyuth Sagi on 3/11/18.
//  Copyright © 2018 Sriyuth Sagi. All rights reserved.
//


#include "board.hpp"

using namespace std;

// initializing the board after getting the number of rows and columns and the values for the rows and columns
Board::Board(int x, int y, vector<char>& rowsvec, vector<char>& colsvec) {
    
    // sets the board based on the intended width and height
    board = vector<vector<char> >(x, vector<char>(y, '0'));
    
    // sets the final rows and columns
    rows = rowsvec;
    cols = colsvec;
    
    // sets all values in the current rows to 0
    for(int i=0; i < y; i++) {
        current_rows.push_back('0');
    }
    
    // sets all values in the current columns to 0
    for(int i=0; i < x; i++) {
        current_cols.push_back('0');
    }
}




// checks if a ship can be added horizontally after taking in the position and the length of the ship
bool Board::checkHorz(int x, int y, int length) const {

    bool check = true;
    int cons = 0;
    
    // checks if there are any values that are not constraints on the positions to be occupied
    // checks beginning
    if(board[x][y] != '0' && (board[x][y] != '<' || length == 1))
        check = false;

    // checks end
    if(board[x + length - 1][y] != '0' && (board[x + length - 1][y] != '>' || length == 1))
        check = false;
    
    // checks middle
    for(int i = x + 1; i <= x + length - 2; i++) {
        if(board[i][y] != '0' && board[i][y] != 'X') {
            check = false;
        }
    }
    
    // checks if the length will exceed any of the max values on the final columns
    for(int i = x; i < x + length; i++) {
        if(current_cols[i] + 1 > cols[i]) {
            // checks it the value has a constraint
            if(board[i][y] < 'a' && board[i][y] > '9')
                cons++;
            else
                check = false;
        }
    }
    
    // checks if the length will exceed any of the max values on the final rows
    if(current_rows[y] + length - cons > rows[y])
        check = false;
    
    
    return check;
}




// adds the ship to the board horizontally after taking in the position and the length of the ship
void Board::addHorz(int x, int y, int length) {
    
    int temp_length = 0;
    
    // finds the initial and final positions for the x and y values
    int x_i = x - 1;
    if(x_i < 0) {
        x_i = 0;
    }
    int y_i = y - 1;
    if(y_i < 0) {
        y_i = 0;
    }
    
    int x_f = x + length;
    if(x_f >= board.size()) {
        x_f--;
    }
    int y_f = y + 1;
    if(y_f >= board.size()) {
        y_f--;
    }
    
    // iterates through each position that will be occupied
    for(int i = x_i; i <= x_f; i++) {
        for(int j = y_i; j <= y_f; j++) {
            // adds a value to all the places adjacent to the intended position of the ship
            if(i == x - 1 || i == x + length || j == y - 1 || j == y + 1) {
                board[i][j]++;
            // assigns the respective values for each position on the board
            } else if(board[i][j] == '0') {
                if(length == 1)
                    board[i][j] = 'o';
                else if(i == x)
                    board[i][j] = 'l';
                else if(i == x + length - 1)
                    board[i][j] = 'r';
                else
                    board[i][j] = 'c';
                
                // adds value to the current column
                current_cols[i]++;
                temp_length++;
            }
        }
    }
    
    // adds value to the current rows
    current_rows[y] = current_rows[y] + temp_length;
}




// removes the ship from the board in a horizontal direction after taking in the position and the length of the ship
void Board::removeHorz(int x, int y, int length) {
    
    int temp_length = 0;
    
    // finds the initial and final positions for the x and y values
    int x_i = x - 1;
    if(x_i < 0) {
        x_i = 0;
    }
    int y_i = y - 1;
    if(y_i < 0) {
        y_i = 0;
    }
    
    int x_f = x + length;
    if(x_f >= board.size()) {
        x_f--;
    }
    int y_f = y + 1;
    if(y_f >= board.size()) {
        y_f--;
    }
    
    // iterates through each position that will be occupied
    for(int i = x_i; i <= x_f; i++) {
        for(int j = y_i; j <= y_f; j++) {
            // adds a value to all the places adjacent to the intended position of the ship
            if(i == x - 1 || i == x + length || j == y - 1 || j == y + 1) {
                board[i][j]--;
            } else if(board[i][j] > 'a') {
                board[i][j] = '0';
                
                // removes value from the current column
                current_cols[i]--;
                temp_length++;
            }
        }
    }
    
    // removes value from the current row
    current_rows[y] = current_rows[y] - temp_length;
}




// checks if a ship can be added vertically after taking in the position and the length of the ship
bool Board::checkVert(int x, int y, int length) const {
    
    bool check = true;
    int cons = 0;
    
    // checks if there are any values that are not constraints on the positions to be occupied
    // checks beginning
    if(board[x][y] != '0' && (board[x][y] != '^' || length == 1))
        check = false;
    
    // checks end
    if(board[x][y + length - 1] != '0' && (board[x][y + length - 1] != 'V' || length == 1))
        check = false;
    
    // checks middle
    for(int i = y + 1; i <= y + length - 2; i++) {
        if(board[x][i] != '0' && board[x][i] != 'X')
            check = false;
    }
    
    // checks if the length will exceed any of the max values on the final rows
    for(int i = y; i < y + length; i++) {
        // checks it the value has a constraint
        if(board[x][i] < 'a' && board[x][i] > '9')
            cons++;
        else {
            if(current_rows[i] + 1 > rows[i])
                check = false;
        }
    }
    
    // checks if the length will exceed any of the max values on the final columns
    if(current_cols[x] + length - cons > cols[x])
        check = false;
    
    
    return check;
}




// adds the ship to the board vertically after taking in the position and the length of the ship
void Board::addVert(int x, int y, int length) {
    
    int temp_length = 0;
    
    // finds the initial and final positions for the x and y values
    int x_i = x - 1;
    if(x_i < 0) {
        x_i = 0;
    }
    int y_i = y - 1;
    if(y_i < 0) {
        y_i = 0;
    }
    
    int x_f = x + 1;
    if(x_f >= board.size()) {
        x_f--;
    }
    int y_f = y + length;
    if(y_f >= board.size()) {
        y_f--;
    }
    
    // iterates through each position that will be occupied
    for(int i = x_i; i <= x_f; i++) {
        for(int j = y_i; j <= y_f; j++) {
            // adds a value to all the places adjacent to the intended position of the ship
            if(i == x - 1 || i == x + 1 || j == y - 1 || j == y + length) {
                board[i][j]++;
            // assigns the respective values for each position on the board
            } else if(board[i][j] == '0') {
                if(length == 1)
                    board[i][j] = 'o';
                else if(j == y)
                    board[i][j] = 't';
                else if(j == y + length - 1)
                    board[i][j] = 'b';
                else
                    board[i][j] = 'c';
                
                // adds value to the current row
                current_rows[j]++;
                temp_length++;
            }
        }
    }
    
    // adds value to the current column
    current_cols[x] = current_cols[x] + temp_length;
}




// removes the ship from the board in a vertical direction after taking in the position and the length of the ship
void Board::removeVert(int x, int y, int length) {

    int temp_length = 0;
    
    // finds the initial and final positions for the x and y values
    int x_i = x - 1;
    if(x_i < 0) {
        x_i = 0;
    }
    int y_i = y - 1;
    if(y_i < 0) {
        y_i = 0;
    }
    
    int x_f = x + 1;
    if(x_f >= board.size()) {
        x_f--;
    }
    int y_f = y + length;
    if(y_f >= board.size()) {
        y_f--;
    }
    
    // iterates through each position that will be occupied
    for(int i = x_i; i <= x_f; i++) {
        for(int j = y_i; j <= y_f; j++) {
            // adds a value to all the places adjacent to the intended position of the ship
            if(i == x - 1 || i == x + 1 || j == y - 1 || j == y + length) {
                board[i][j]--;
            } else if(board[i][j] > 'a') {
                board[i][j] = '0';
                
                // removes value from the current row
                current_rows[j]--;
                temp_length++;
            }
        }
    }
    
    // removes value from the current column
    current_cols[x] = current_cols[x] - temp_length;
}




// sets the constraints entered onto the board
void Board::setConstraints(vector<string> cons) {

    // sets constraints
    constraints = cons;
    
    // iterates through the vector and assigns values of each constraint to their respective positions on the board and adds values to the current values of the rows and columns
    for(int i = 0; i < cons.size(); i++) {
        board[cons[i][0] - '0'][cons[i][1] - '0'] = cons[i][2];
        current_rows[cons[i][1] - '0']++;
        current_cols[cons[i][0] - '0']++;
    }
}




// checks to make sure those constraints added to the board have not been changed
bool Board::checkConstraints() {
    
    // iterates through the vector and checks if any of the values of the constraints have been changed
    for(int i = 0; i < constraints.size(); i++) {
        if(!(board[constraints[i][0] - '0'][constraints[i][1] - '0'] == constraints[i][2])) {
            return false;
        }
    }
    return true;
}




// prints the values on the board
void Board::print() {

    // number of rows and columns
    int num_rows = (int)board[0].size();
    int num_cols = (int)board.size();
    
    // starts output
    cout << '+' << string(num_cols, '-') << '+' << endl;
    
    // iterates through the rows
    for(int i = 0; i < num_rows; i++) {
        cout << '|' << flush;
        
        // iterates through the columns
        for(int j = 0; j < num_cols; j++) {
            // adds spaces if there is no value
            if(board[j][i] < '9') {
                    cout << ' ' << flush;
            } else {
                // adds the respective symbol if there is a value
                if(board[j][i] == 'l' || board[j][i] == '<')
                    cout << '<' << flush;
                if(board[j][i] == 'r' || board[j][i] == '>')
                    cout << '>' << flush;
                if(board[j][i] == 't' || board[j][i] == '^')
                    cout << '^' << flush;
                if(board[j][i] == 'b' || board[j][i] == 'v')
                    cout << 'v' << flush;
                if(board[j][i] == 'c' || board[j][i] == 'X')
                    cout << 'X' << flush;
                if(board[j][i] == 'o')
                    cout << 'o' << flush;
            }
        }
        
        // adds values of the current row
        cout << '|' << current_rows[i] - '0' << endl;
    }
    
    // adds bottom
    cout << '+' << string(num_cols, '-') << '+' << endl << ' ';
    
    // adds values of the current column
    for(int i = 1; i < num_cols + 1; i++)
        cout << current_cols[i - 1] - '0' << flush;
    
    cout << endl;
    cout << endl;
    
}
