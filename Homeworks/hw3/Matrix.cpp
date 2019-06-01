//
//  Matrix.cpp
//  hw3
//
//  Created by Sriyuth Sagi on 2/10/18.
//  Copyright © 2018 Sriyuth Sagi. All rights reserved.
//

#include <iostream>
#include "Matrix.h"
using namespace std;

// initializing a new empty matrix
Matrix::Matrix() {
    row = 0;
    col = 0;
}



// initializing the Matrix so that it takes two unsigned ints: a rows count and a columns count, and a double fill value. The constructor creates a data representation of a rows×columns matrix with every value initialized to fill. If either dimension is 0, the resulting matrix will be of size 0×0.
Matrix::Matrix(unsigned int rows, unsigned int cols, double fills) {
    // initializing rows and columns
    row = rows;
    col = cols;
    
    // creating a new location for the multidimensional array fill and assigning default values based on the number of rows and columns
    fill = new double*[row];
    for (int i=0; i<row;i++) {
        fill[i] = new double[col];
        
        for (int j=0; j<col;j++) {
            fill[i][j] = fills;
        }
    }
    
    // checking if either the rows or columns is equal to 0, in which case the whole Matrix will become an empty matrix
    if (row == 0 || col == 0) {
        clear();
    }
}



// copying the values of a different matrix into a new matrix with the number of rows, columns and values in the fill being the same
Matrix::Matrix(const Matrix& other) {
    // initializing rows and columns
    row = other.row;
    col = other.col;
    
    // creating a new location for the multidimensional array fill and assigning default values based on the number of rows and columns
    fill = new double*[row];
    for (int i=0; i<row;i++) {
        fill[i] = new double[col];
        
        for (int j=0; j<col;j++) {
            fill[i][j] = other.fill[i][j];
        }
    }
}


Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        clear();
        
        // initializing rows and columns
        row = other.row;
        col = other.col;
        
        // creating a new location for the multidimensional array fill and assigning default values based on the number of rows and columns
        fill = new double*[row];
        for (int i=0; i<row;i++) {
            fill[i] = new double[col];
            
            for (int j=0; j<col;j++) {
                fill[i][j] = other.fill[i][j];
            }
        }
    }
    return *this;
}



// a method to  reset the number of rows and columns to 0, and deallocate any memory currently held by the Matrix
void Matrix::clear() {
    // checks if it is not a zero matrix
    if (row > 0 && col > 0) {
        
        // deletes values inside the matrix subarrays
        for (int i=0; i<row;i++) {
            delete[] fill[i];
        }
        
        // deletes the main array
        delete[] fill;
    }
    
    // sets row and col to 0
    row = 0;
    col = 0;
}



//  a method which takes in a row, a column, and a double. If the row and column are within the bounds of the matrix, then the value at the position should be stored in the double, and the function should return true. Otherwise the function should return false
bool Matrix::get(unsigned int getRow, unsigned int getCol, double& store) {
    // checking if the position exists in the matrix
    if (getRow <= row && getCol <= col) {
        
        // replacing the stored value to be taken from the matrix and returning true
        store = fill[getRow][getCol];
        return true;
    }
    else {return false;}
}



// a method that takes in a row, column, and a double value. Then returns false if the position is out of bounds, and true if the position is valid. If the position is valid, the function should also set arow,col to the value of the double that was passed in.
bool Matrix::set(unsigned int setRow, unsigned int setCol, const double& store) {
    // checking if the position exists in the matrix
    if (setRow <= row && setCol <= col) {
        
        // setting the value at that position in the matrix to the stored value and returning true
        fill[setRow][setCol] = store;
        return true;
    }
    else {return false;}
}



// a method which takes another matrix to check if two Matrices are equal and returns true if they are equal and false if they are not
bool Matrix::operator == (const Matrix& other) {
    // checks if both matrices are the same size and returns false if they are not
    if (row != other.num_rows() || col != other.num_cols()) {
        return false;
    }
    
    // goes through the whole matrix and returns false if any of the values do not match or true if all of them do
    for (int i=0; i<row;i++) {
        for (int j=0; j<col;j++) {
            
            if (fill[i][j] != other.get_fill()[i][j]) {
                return false;
            }
        }
    }
    return true;
}



// a method which takes another matrix to check if two Matrices are not equal and returns true if they are not equal and false if they are
bool Matrix::operator != (const Matrix& other) {
    // checks if both matrices are the same size and returns true if they are not
    if (row != other.num_rows() || col != other.num_cols()) {
        return true;
    }
    
    // goes through the whole matrix and returns true if any of the values do not match or false if all of them do
    for (int i=0; i<row;i++) {
        for (int j=0; j<col;j++) {
            
            if (fill[i][j] != other.get_fill()[i][j]) {
                return true;
            }
        }
    }
    return false;
}



// a method to display the matrix in a specific layout
ostream& operator << (ostream& out, Matrix& m) {
    // prints the title
    out << endl;
    out << m.num_rows() << " x " << m.num_cols() << " matrix:" << endl;
    out << "[ " << flush;
    
    // ends the method if it is an empty matrix
    if (m.num_rows() == 0 && m.num_cols() == 0) {
        out << "]" << endl;
        return out;
    }
    
    // prints the first line
    for (int j=0;j<m.num_cols();j++) {
        out << m.get_fill()[0][j] << ' ' << flush;
    }
    out << endl;
    
    // prints all middle lines
    for (int i=1;i<m.num_rows()-1;i++) {
        out << "  " << flush;
        for (int j=0;j<m.num_cols();j++) {
            out << m.get_fill()[i][j] << ' ' << flush;
        }
        out << endl;
    }
    
    // prints the last line of the matrix
    out << "  " << flush;
    for (int j=0;j<m.num_cols();j++) {
        out << m.get_fill()[m.num_rows()-1][j] << ' ' << flush;
    }
    out << "]" << endl;
    
    return out;
}



// a method which takes another Matrix and adds the values in the second Matrix to the original, returning true if they are both the same size and it is possible to add while returning false if they are different sizes and can't be added
bool Matrix::add(const Matrix& other) {
    // checks if both matrices are the same size and returns true if they are
    if (row == other.num_rows() && col == other.num_cols()) {
        
        // iterates through the matrix and adds the value from the other matrix to the coresponding position
        for (int i=0; i<row;i++) {
            
            for (int j=0; j<col;j++) {
                fill[i][j] = fill[i][j] + other.get_fill()[i][j];
            }
        }
        return true;
    }
    else {return false;}
}



// a method which takes another Matrix and subtracts the values in the second Matrix from the original, returning true if they are both the same size and it is possible to subtract while returning false if they are different sizes and can't be subtracted
bool Matrix::subtract(const Matrix& other) {
    // checks if both matrices are the same size and returns true if they are
    if (row == other.num_rows() && col == other.num_cols()) {
        
        // iterates through the matrix and subtracts the value from the other matrix from the coresponding position
        for (int i=0; i<row;i++) {
            
            for (int j=0; j<col;j++) {
                fill[i][j] = fill[i][j] - other.get_fill()[i][j];
            }
        }
        return true;
    }
    else {return false;}
}



// a method which takes a double called a value. The method should multiply every element in the matrix by the value
void Matrix::multiply_by_coefficient(const double& value) {
    // iterates through the matrix and multiplies the value of the coefficient to each position
    for (int i=0; i<row;i++) {
        
        for (int j=0; j<col;j++) {
            fill[i][j] = fill[i][j] * value;
        }
    }
}



// a method that takes one unsigned int for a row number and return a double* with all the values in that row
double* Matrix::get_row(unsigned int getRow) {
    // checks if the row is in the matrix otherwise returns a NULL
    if (getRow < row) {
        double *rows = new double[row];
        
        // iterates through the matrix and takes all values in the row into a new array
        for (int i=0; i<row;i++) {
            
            for (int j=0; j<col;j++) {
                if (i==getRow) {
                    rows[j] = fill[i][j];
                }
            }
        }
        return rows;
    }
    else {return NULL;}
}



// a method that takes one unsigned int for a column number and return a double* with all the values in that column
double* Matrix::get_col(unsigned int getCol) {
    // checks if the column is in the matrix otherwise returns a NULL
    if (getCol < col) {
        double *cols = new double[col];
        
        // iterates through the matrix and takes all values in the column into a new array
        for (int i=0; i<row;i++) {
            
            for (int j=0; j<col;j++) {
                if (i==getCol) {
                    cols[j] = fill[i][j];
                }
            }
        }
        return cols;
    }
    else {return NULL;}
}



// a method that takes no arguments and returns a Matrix* containing four new Matrix elements in order: an Upper Left (UL) quadrant, an Upper Right (UR) quadrant, a Lower Left (LL) quadrant, and finally a Lower Right (LR) quadrant. All four quadrants will be the same size
Matrix* Matrix::quarter() {
    // declaring and initializing the value to be returned by the function
    Matrix* pieces = new Matrix[4];
    
    // initializing variables to decide the size of each of the four corners
    unsigned int row_piece_num = (row+1)/2;
    unsigned int col_piece_num = (col+1)/2;
    
    // initializing the four corners
    Matrix UL(row_piece_num,col_piece_num,0);
    Matrix UR(row_piece_num,col_piece_num,0);
    Matrix LL(row_piece_num,col_piece_num,0);
    Matrix LR(row_piece_num,col_piece_num,0);
    
    // variables to help keep track of position
    int x;
    int y;
    
    // iterating through the upper left corner and adding values to the matrix
    for (int i=0; i<row_piece_num;i++) {
        for (int j=0; j<col_piece_num;j++) {
            UL.set(i, j, fill[i][j]);
        }
    }
    
    // iterating through the upper right corner and adding values to the matrix
    for (int i=0; i<row_piece_num;i++) {
        for (int j=0; j<col_piece_num;j++) {
            // using x to start from partway through the matrix
            x = row_piece_num + j;
            UR.set(i, j, fill[i][x]);
        }
    }
    
    // iterating through the lower left corner and adding values to the matrix
    for (int i=0; i<row_piece_num;i++) {
        for (int j=0; j<col_piece_num;j++) {
            // using y to start from partway through the matrix
            y = col_piece_num + i - 1;
            LL.set(i, j, fill[y][j]);
        }
    }
    
    // iterating through the lower right corner and adding values to the matrix
    for (int i=0; i<row_piece_num;i++) {
        for (int j=0; j<col_piece_num;j++) {
            // using x and y to start from partway through the matrix
            x = row_piece_num + j;
            y = col_piece_num + i - 1;
            LR.set(i, j, fill[y][x]);
        }
    }
    
    // adding the matrices to the array and returning the array
    pieces[0] = UL;
    pieces[1] = UR;
    pieces[2] = LL;
    pieces[3] = LR;
    
    return pieces;
}



// a method which takes two arguments of type unsigned int: a source row number and a target row number. If both rows are inside the bounds of the matrix, then the function should switch the values in the two rows and return true. Otherwise the function should return false.
bool Matrix::swap_row(unsigned int row1, unsigned int row2) {
    // checking if both rows are present in the matrix and returning true if they both are
    if (row1 <= row && row2 <= row) {
        
        // creating a placeholder variable and storing one of the rows
        double* tempRow = fill[row1];
        
        // moving one of the rows over and overwriting the other row that has already been stored in the placeholder
        fill[row1] = fill[row2];
        
        // moving the value from the placeholder into the second row
        fill[row2] = tempRow;
        return true;
    }
    else {return false;}
    
}



// a method which has a return type of void and changes the values from an m×n matrix into n×m
void Matrix::transpose() {
    // swapping the values of the rows and columns
    unsigned int n = row;
    row = col;
    col = n;
    
    // making a new array which flips the positions of the values in the x and y directions
    float newer[row][col];
    for (int i=0; i<col;i++) {
        for (int j=0; j<row;j++) {
            newer[j][i] = fill[i][j];
        }
    }
    
    // deleting the old array fill
    for (int i=0; i<col;i++) {
        delete[] fill[i];
    }
    delete[] fill;
    
    // making the array fill again but this time taking the new row and column numbers and the data from the flipped array
    fill = new double*[row];
    for (int i=0; i<row;i++) {
        fill[i] = new double[col];
        
        for (int j=0; j<col;j++) {
            fill[i][j] = newer[i][j];
        }
    }
}

