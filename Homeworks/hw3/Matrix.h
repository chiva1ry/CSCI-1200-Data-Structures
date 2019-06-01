//
//  Matrix.h
//  hw3
//
//  Created by Sriyuth Sagi on 2/10/18.
//  Copyright © 2018 Sriyuth Sagi. All rights reserved.
//

#ifndef Matrix_h
#define Matrix_h

using namespace std;



class Matrix {
public:
    // Initializing Matrix class
    Matrix();
    Matrix(unsigned int rows, unsigned int cols, double fills);
    Matrix(const Matrix& other);
    Matrix& operator = (const Matrix& other);
    ~Matrix() {clear();}
    
    // returning values for row, colums or the values in the matrix
    unsigned int num_rows() const {return row;}
    unsigned int num_cols() const {return col;}
    double** get_fill() const {return fill;}
    
    // a method to  reset the number of rows and columns to 0, and deallocate any memory currently held by the Matrix
    void clear();
    //  a method which takes in a row, a column, and a double. If the row and column are within the bounds of the matrix, then the value at the position should be stored in the double, and the function should return true. Otherwise the function should return false
    bool get(unsigned int getRow, unsigned int getCol, double& store);
    // a method that takes in a row, column, and a double value. Then returns false if the position is out of bounds, and true if the position is valid. If the position is valid, the function should also set arow,col to the value of the double that was passed in.
    bool set(unsigned int setRow, unsigned int setCol, const double& store);
    
    
    // a method which takes another matrix to check if two Matrices are equal and returns true if they are equal and false if they are not
    bool operator == (const Matrix& other);
    // a method which takes another matrix to check if two Matrices are not equal and returns true if they are not equal and false if they are
    bool operator != (const Matrix& other);
    // a method to display the matrix in a specific layout
    friend ostream& operator << (ostream& out, Matrix& m);
    
    
    // a method which takes another Matrix and adds the values in the second Matrix to the original, returning true if they are both the same size and it is possible to add while returning false if they are different sizes and can't be added
    bool add(const Matrix& other);
    // a method which takes another Matrix and subtracts the values in the second Matrix from the original, returning true if they are both the same size and it is possible to subtract while returning false if they are different sizes and can't be subtracted
    bool subtract(const Matrix& other);
    // a method which takes a double called a value. The method should multiply every element in the matrix by the value
    void multiply_by_coefficient(const double& value);
    
    // a method that takes one unsigned int for a row number and return a double* with all the values in that row
    double* get_row(unsigned int getRow);
    // a method that takes one unsigned int for a column number and return a double* with all the values in that column
    double* get_col(unsigned int getCol);
    
    // a method that takes no arguments and returns a Matrix* containing four new Matrix elements in order: an Upper Left (UL) quadrant, an Upper Right (UR) quadrant, a Lower Left (LL) quadrant, and finally a Lower Right (LR) quadrant. All four quadrants will be the same size
    Matrix* quarter();
    
    // a method which takes two arguments of type unsigned int: a source row number and a target row number. If both rows are inside the bounds of the matrix, then the function should switch the values in the two rows and return true. Otherwise the function should return false.
    bool swap_row(unsigned int row1, unsigned int row2);
    // a method which has a return type of void and changes the values from an m×n matrix into n×m
    void transpose();

    
    
    
    
private:
    // number of rows
    unsigned int row;
    // number of columns
    unsigned int col;
    // the values that make up the matrix
    double **fill;
};

#endif /* Matrix_h */
