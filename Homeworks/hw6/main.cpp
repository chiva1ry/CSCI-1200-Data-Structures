//
//  main.cpp
//  hw6
//
//  Created by Sriyuth Sagi on 3/10/18.
//  Copyright © 2018 Sriyuth Sagi. All rights reserved.
//


#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>

#include "board.hpp"

using namespace std;

// function to find the total solution after defining all possible unknown values. Most of the variables entered into the function add_ship function, however, it is missing the Board and the vector solutions which are only defined during the function, though it also contains the variables for the values of the rows and columns
void find_solutions(int& index, vector<int>& ships, int& x, int& y, int prev_x, int prev_y,
                    vector<vector<vector<int> > >& past_solutions, int& find_one,
                    vector<string> constraints, bool& solved,
                    vector<char>& rows, vector<char>& cols);


// function that works if unknown ships were entered into the program and works by assigning values to the unknown ships and executing the add_ship program on different possible values for the unknowns. The variables entered are the same as find_solutions
void unknown_ship(int& index, vector<int>& ships, int& x, int& y, int prev_x, int prev_y,
                  vector<vector<vector<int> > >& past_solutions, int& find_one,
                  vector<string> constraints, bool& solved,
                  vector<char>& rows, vector<char>& cols);


// function which uses recursion to add ships to the board and find solutions before returning them through cout statements. It requires a large number of variables to help store information from previous parts of the recursion.
void add_ship(Board& b, int& index, vector<int>& ships, int& x, int& y, int prev_x, int prev_y,
              vector<vector<int> >& solution, vector<vector<vector<int> > >& past_solutions, int& find_one,
              vector<string> constraints, bool& solved);







// function to find the total solution after defining all possible unknown values. Most of the variables entered into the function add_ship function, however, it is missing the Board and the vector solutions which are only defined during the function, though it also contains the variables for the values of the rows and columns
void find_solutions(int& index, vector<int>& ships, int& x, int& y, int prev_x, int prev_y,
                    vector<vector<vector<int> > >& past_solutions, int& find_one,
                    vector<string> constraints, bool& solved,
                    vector<char>& rows, vector<char>& cols) {
    
    // defines the new Board and the vector for solutions
    Board b(x, y, rows, cols);
    vector<vector<int> > solution(ships.size(), vector<int>(4, 0));
    
    // sets the constraints
    b.setConstraints(constraints);
    
    // sorts the ships so biggest is first for highest efficiency and executes the function
    sort(ships.rbegin(), ships.rend());
    add_ship(b, index, ships, x, y, 0, 0, solution, past_solutions, find_one, constraints, solved);
}




// function that works if unknown ships were entered into the program and works by assigning values to the unknown ships and executing the add_ship program on different possible values for the unknowns. The variables entered are the same as find_solutions
// work in progress
void unknown_ship(int& index, vector<int>& ships, int& x, int& y, int prev_x, int prev_y,
                  vector<vector<vector<int> > >& past_solutions, int& find_one,
                  vector<string> constraints, bool& solved,
                  vector<char>& rows, vector<char>& cols) {
    
    // sorts ships to put unknown ships first
    sort(ships.begin(), ships.end());
    
    // finds the number of unknown ships;
    int num_unknowns = 0;
    for(int i = 0; i < ships.size(); i++) {
        if(ships[i] == 0)
            num_unknowns++;
    }
    
    // variables to keep track of unknown values
    vector<int> past_trials;
    string trial = string(ships.size(), '1');
    
    int in_trial_sum = 0;
    for(int i = 0; i < trial.length(); i++) {
        in_trial_sum = in_trial_sum + (int)trial[i] - 48;
    }
    
    // assigns values to the unknowns
    if (in_trial_sum == ships.size()) {
        for(int i = 0; i < ships.size(); i++) {
            
            if((int)trial[6] - 48 > 0) {
                ships[i] = 7;
                trial[6]--;
            }
            else if((int)trial[5] - 48 > 0) {
                ships[i] = 6;
                trial[5]--;
            }
            else if((int)trial[4] - 48 > 0) {
                ships[i] = 5;
                trial[4]--;
            }
            else if((int)trial[3] - 48 > 0) {
                ships[i] = 4;
                trial[3]--;
            }
            else if((int)trial[2] - 48 > 0) {
                ships[i] = 3;
                trial[2]--;
            }
            else if((int)trial[1] - 48 > 0) {
                ships[i] = 2;
                trial[1]--;
            }
            else if((int)trial[0] - 48 > 0) {
                ships[i] = 1;
                trial[0]--;
            }
            
        }
        
        // executes function
        find_solutions(index, ships, x, y, 0, 0, past_solutions, find_one, constraints, solved, rows, cols);
    }
}




// function which uses recursion to add ships to the board and find solutions before returning them through cout statements. It requires a large number of variables to help store information from previous parts of the recursion.
void add_ship(Board& b, int& index, vector<int>& ships, int& x, int& y, int prev_x, int prev_y,
               vector<vector<int> >& solution, vector<vector<vector<int> > >& past_solutions, int& find_one,
               vector<string> constraints, bool& solved) {
    
    // checks if a solution is found by looking if all the ships are on the board and if they match the entered row and column values
    if(index == ships.size() && b.getRows() == b.getCurrows() && b.getCols() == b.getCurcols()) {

        // bool variable that checks if the solution is a repeated value and a temporary solution variable so the solution variable is not affected
        bool copy = false;
        vector<vector<int> > temp_sol(solution);
        sort(temp_sol.begin(), temp_sol.end());
        
        for(int i = 0; i < past_solutions.size(); i++) {
            if(past_solutions[i] == temp_sol)
                copy = true;
        }
        
        // checks if the constraints are properly in place and if it is a copy or not
        if(b.checkConstraints() && !copy) {
            
            // changes the value of find_one which, when changed, will stop and further operations in the recursion part of the add_ships function
            if(find_one == 1)
                find_one++;
            
            solved = true;
            // adds solution to the vector of all solutions
            past_solutions.push_back(temp_sol);
            
            // output
            cout << "Solution:" << endl;
            
            // checks each ship and finds the ship name from the length
            for(int i = 0; i < temp_sol.size(); i++) {
                string this_ship;
                if(temp_sol[i][2] == 1) {
                    this_ship = "submarine";
                }
                if(temp_sol[i][2] == 2) {
                    this_ship = "destroyer";
                }
                if(temp_sol[i][2] == 3) {
                    this_ship = "cruiser";
                }
                if(temp_sol[i][2] == 4) {
                    this_ship = "battleship";
                }
                if(temp_sol[i][2] == 5) {
                    this_ship = "carrier";
                }
                if(temp_sol[i][2] == 6) {
                    this_ship = "cargo";
                }
                if(temp_sol[i][2] == 7) {
                    this_ship = "tanker";
                }
                
                // outputs of the solution other than the board
                cout << left << setw(11) << this_ship << temp_sol[i][0] << ' ' << temp_sol[i][1] << flush;
                if(temp_sol[i][3] == 0 && temp_sol[i][2] != 1)
                    cout << " vertical" << flush;
                else if(temp_sol[i][3] == 1 && temp_sol[i][2] != 1)
                    cout << " horizontal" << flush;
                cout << endl;
            }
            
            // prints the board and exits the recursion
            b.print();
            return;
        }
    }
    
    // checks to make sure there will be no access errors from the index and checks if it still needs to find more solutions
    if(index < ships.size() && find_one < 2) {
        int xx = 0;
        int last_ship = 0;
        if(index > 0) {
            last_ship = ships[index-1];
        }
        
        // checks if the length of this ship if the same as the last one
        if(ships[index] == last_ship) {
            xx = prev_x + 1;
            
            // checks if there is any horizontal distance remaining and iterates from there horizontally
            if(prev_x < x + 1 - ships[index]) {
                for(int j = prev_y+2; j < y; j++) {
                    
                    // checks if a ship can be added horizontally
                    if(b.checkHorz(prev_x, j, ships[index])) {
                        
                        // creates a solution
                        solution[index][0] = j;
                        solution[index][1] = prev_x;
                        solution[index][2] = ships[index];
                        solution[index][3] = 1;
                        
                        // adds the ship to the board
                        b.addHorz(prev_x, j, ships[index]);
                        int index_next = index + 1;
                        if(index_next > ships.size())
                            return;
                        
                        // recursion
                        add_ship(b, index_next, ships, x, y, prev_x, j, solution, past_solutions, find_one, constraints, solved);
                        
                        // removes the ship so it is no longer occupying the board
                        b.removeHorz(prev_x, j, ships[index]);
                    }
                }
            }
            
            
            // checks if the ship is longer than one so it can decide whether it should attempt adding vertically and iterates vertically.
            if(ships[index] > 1) {
                for(int j = prev_y+2; j < y + 1 - ships[index]; j++) {
                    
                    // checks if a ship can be added vertically
                    if(b.checkVert(prev_x, j, ships[index])) {
                        
                        // creates a solution
                        solution[index][0] = j;
                        solution[index][1] = prev_x;
                        solution[index][2] = ships[index];
                        solution[index][3] = 0;
                        
                        // adds the ship to the board
                        b.addVert(prev_x, j, ships[index]);
                        int index_next = index + 1;
                        if(index_next > ships.size())
                            return;
                        
                        // recursion
                        add_ship(b, index_next, ships, x, y, prev_x, j, solution, past_solutions, find_one, constraints, solved);
                        
                        // removes the ship so it is no longer occupying the board
                        b.removeVert(prev_x, j, ships[index]);
                    }
                }
            }
        }
        
        
        // iterates through each value in the board and checks if the ship can be added horizontally anywhere
        for(int i = xx; i < x + 1 - ships[index]; i++) {
            for(int j = 0; j < y; j++) {
                
                // checks if a ship can be added horizontally
                if(b.checkHorz(i, j, ships[index])) {
                    
                    // creates a solution
                    solution[index][0] = j;
                    solution[index][1] = i;
                    solution[index][2] = ships[index];
                    solution[index][3] = 1;
                    
                    // adds the ship to the board
                    b.addHorz(i, j, ships[index]);
                    int index_next = index + 1;
                    if(index_next >  ships.size())
                        return;
                    
                    // recursion
                    add_ship(b, index_next, ships, x, y, i, j, solution, past_solutions, find_one, constraints, solved);
                    
                    // removes the ship so it is no longer occupying the board
                    b.removeHorz(i, j, ships[index]);
                }
            }
        }
        
        
        // iterates through each value in the board and checks if the ship can be added horizontally anywhere
        if(ships[index] > 1) {
            for(int i = xx; i < x; i++) {
                for(int j = 0; j < y + 1 - ships[index]; j++) {
                    
                    // checks if a ship can be added vertically
                    if(b.checkVert(i, j, ships[index])) {
                        
                        // creates a solution
                        solution[index][0] = j;
                        solution[index][1] = i;
                        solution[index][2] = ships[index];
                        solution[index][3] = 0;
                        
                        // adds the ship to the board
                        b.addVert(i, j, ships[index]);
                        int index_next = index + 1;
                        if(index_next > ships.size())
                            return;
                        
                        // recursion
                        add_ship(b, index_next, ships, x, y, i, j, solution, past_solutions, find_one, constraints, solved);
                        
                        // removes the ship so it is no longer occupying the board
                        b.removeVert(i, j, ships[index]);
                    }
                }
            }
        }
    }
}




int main(int argc, char *argv[]) {
    
    // checks whether to find all solutions or a single one
    int find_one = 1;
    if(argc > 2) {
        if(argv[2] == string("find_all_solutions"))
            find_one = 0;
    }
    
    // defining different variables
    // stream for input
    ifstream input(argv[1]);
    // number of rows
    int x = 0;
    // number of columns
    int y = 0;
    // index to keep track of which ship during recursion
    int index = 0;
    // vector of the lengths of each ship
    vector<int> ships;
    // vector of the desired values in each row
    vector<char> rows;
    // vector of the desired values in each column
    vector<char> cols;
    // checks if there are any unknown rows or columns
    bool unknown_values = false;
    // checks if there are any unknown ships
    bool unknown_ship_present = false;
    // vector of the constraints
    vector<string> constraints;
    // stores all the solutions that have been found
    vector<vector<vector<int> > > past_solutions;
    // checks if there are any solutions
    bool solved = false;
    // placeholder value when taking in input text
    string value;
    
    
    // inputs x and y
    input >> value;
    input >> value;
    y = stoi(value);
    
    input >> value;
    x = stoi(value);
    
    // enters rows based on the y value
    input >> value;
    for(int i = 0; i < y; i++) {
        input >> value;
        
        // checks for unknowns
        if(value == string("?")) {
            rows.push_back('?');
            unknown_values = true;
        } else {
            rows.push_back(value[0]);
        }
        
    }
    
    // enters columns based on the x value
    input >> value;
    for(int i = 0; i < x; i++) {
        input >> value;
        
        // checks for unknowns
        if(value == string("?")) {
            cols.push_back('?');
            unknown_values = true;
        } else {
            cols.push_back(value[0]);
        }
    }
    
    // checks the words entered and pushes back the associated length into the vector
    while(input >> value) {
        
        if(value == "constraint") {
            // adds the values of the constraint
            string cons;
            
            input >> value;
            cons = value;
            input >> value;
            cons = value + cons;
            input >> value;
            
            cons = cons + value;
            
            constraints.push_back(cons);
        } else {
            
            if(value == "submarine") {
                ships.push_back(1);
            }
            if(value == "destroyer") {
                ships.push_back(2);
            }
            if(value == "cruiser") {
                ships.push_back(3);
            }
            if(value == "battleship") {
                ships.push_back(4);
            }
            if(value == "carrier") {
                ships.push_back(5);
            }
            if(value == "cargo") {
                ships.push_back(6);
            }
            if(value == "tanker") {
                ships.push_back(7);
            }
            // checks for unknowns
            if(value == "unknown") {
                unknown_ship_present = true;
                ships.push_back(0);
            }
            
        }
    }
    
    
    // checks for unknown columns or rows
    if(unknown_values) {
        
        // finds the position of the unknown rows
        vector<int> unk_row_pos;
        for(int i = 0; i < rows.size(); i++) {
            if(rows[i] == '?')
                unk_row_pos.push_back(i);
        }
        
        // finds the position of the unknown columns
        vector<int> unk_col_pos;
        for(int i = 0; i < cols.size(); i++) {
            if(cols[i] == '?')
                unk_col_pos.push_back(i);
        }

        // iterates through possible values at each of the unknown rows and columns
        for(int i = 0; i < cols.size(); i++) {
            for(int j = 0; j < unk_row_pos.size(); j++) {
                rows[unk_row_pos[j]] = i + '0';
                
                for(int k = 0; k < rows.size(); k++) {
                    for(int l = 0; l < unk_col_pos.size(); l++) {
                        cols[unk_col_pos[l]] = k + '0';
                        
                        // recursion for the presence of unknown columns and rows and has unknown ships
                        if(unknown_ship_present) {
                            unknown_ship(index, ships, x, y, 0, 0, past_solutions, find_one, constraints, solved, rows, cols);
                        }
                        
                        // recursion for the presence of unknown columns and rows but no unknown ships
                        if(!unknown_ship_present) {
                            find_solutions(index, ships, x, y, 0, 0, past_solutions, find_one, constraints, solved, rows, cols);
                        }
                    }
                }
            }
        }
        
    // if there are no unknown rows or columns
    } else {
    
        // recursion for the absence of unknown columns and rows but has unknown ships
        if(unknown_ship_present) {
            unknown_ship(index, ships, x, y, 0, 0, past_solutions, find_one, constraints, solved, rows, cols);
        }
        
        // recursion for the absence of unknown columns and rows and no unknown ships
        if(!unknown_ship_present) {
            find_solutions(index, ships, x, y, 0, 0, past_solutions, find_one, constraints, solved, rows, cols);
        }
    }
        

    // checks if any solutions were found
    if (!solved)
        cout << "No solutions" << endl;

    
    
    
    return 0;
}




