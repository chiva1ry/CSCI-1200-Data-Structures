//
//  justify.cpp
//  Homework_1
//
//  Created by Sriyuth Sagi on 1/19/18.
//  Copyright © 2018 Sriyuth Sagi. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;



// function to split up long words
void long_word(vector<string>& lines, string& text, const int length, int& line_length, string& line) {
    
    //makes a new line if there are already any words in the line
    if (line_length>0){
        lines.push_back(line+' ');
    }
    line.erase();
    
    int count=0;
    // iterates over each letter in the word
    for (int j=0;j<text.length();j++) {
        
        // adds letters to the line if the line length is not exceeded
        if (count <= length-2) {
            line = line + text[j];
            count++;
        }
        
        // creates a new line in the word and hyphonates
        else {
            lines.push_back(line+'-');
            line=text[j];
            count = 1;
        }
        
        // ensures the final line length is carried over
        line_length = line.length();
    }
}



//function to return the words that go in each line in the form of a vector
void make_lines(vector<string>& lines, vector<string>& text, const int length) {
    
    // variables for a single line and the length of the line
    string line;
    int line_length=0;
    
    // iterates over each word
    for (int i=0;i<text.size();i++) {
        
        // appends word to a line if the character length is not exceeded
        if (line_length + text[i].length()+1 <= length) {
            line = line + ' ' + text[i];
            line_length = line_length + text[i].length()+1;
            
            // removes accidental space before the first word
            if (i==0) {
                line.erase(0,1);
                line_length--;
            }
        }
        
        // splits up a very long word over multiple lines
        else if (text[i].length()>length) {
            long_word(lines, text[i], length, line_length, line);
        }
        
        // creates a new line and resets counting parameters
        else {
            lines.push_back(line);
            line=text[i];
            line_length=text[i].length();
        }
    }
    
    // adds the last line even if incomplete
    lines.push_back(line);
}



// function to make lines left justified
void flush_left(vector<string>& lines, const int length) {
    
    long int spaces;
    
    // iterates over the lines vector
    for (int i=0;i<lines.size();i++) {
        
        // finds the number of characters less than the maximum and add them as spaces to the left of the line
        spaces = length - lines[i].length();
        lines[i] = lines[i] + string(spaces,' ');
    }
}



// function to make lines right justified
void flush_right(vector<string>& lines, const int length) {
    
    long int spaces;
    
    // iterates over the lines vector
    for (int i=0;i<lines.size();i++) {
        
        // finds the number of characters less than the maximum and add them as spaces to the right of the line
        spaces = length - lines[i].length();
        lines[i] = string(spaces,' ') + lines[i];
    }
}



// function to make lines full justified by iterating over each line and adding extra spaces
void full_justify(vector<string>& lines, const int length) {
    long int spaces;
    int j=0;
    // iterates over the lines vector
    for (int i=0;i<lines.size()-1;i++) {
        // finds the number of characters less than the maximum and sets up a counter
        spaces = length - lines[i].length();
        j=0;
        // loops while there are still empty spaces
        while (spaces > 0) {
            // inserts a space into the line at each space and removes from the number of spaces needed and adds one to the counter so the same position in the line is not picked repeatedly
            if (isspace(lines[i][j])) {
                lines[i].insert(j, " ");
                spaces--;
                j++;
            }
            // continues counter and resets counter if the end of the line is reached but there are still extra spaces
            j++;
            if (j>lines[i].length()) {
                j=0;
            }
        }
    }
    // writing second to last line will be left justified so find the spaces missing and add to the left of the line
    spaces = length - lines[lines.size()-1].length();
    lines[lines.size()-1] = lines[lines.size()-1] + string(spaces,' ');
}



// print lines in a rectangle in a new file
void rectangle(vector<string>& lines, const int length, ofstream& out_str) {
    
    // top line
    out_str << string(length+4,'-') << endl;
    
    // middle lines
    for (int i=0;i<lines.size();i++) {
        out_str << "| " << lines[i] << " |" << endl;
    }
    
    // bottom line
    out_str << string(length+4,'-') << endl;
}



// print lines in a right triangle facing right in a new file
void right_triangle_right(vector<string>& lines, const int length, ofstream& out_str) {
    
    // a vector with the drawing of the shape
    vector<string> shape;
    
    // draws the corner of the shape
    shape.push_back("|");
    
    // draws the part above the text
    for (int i=2;i<length;i=i+3) {
        shape.push_back("|"+string(i, ' ')+"\\");
    }
    
    // draws the part of the triangle overlapping the text
    for (int i=0;i<lines.size();i++) {
        shape.push_back("|"+string((3*i)+length+1, ' ')+"\\");
    }
    
    // draws the last line
    shape.push_back(string((lines.size()*3)+length+1,'-'));
    
    // adds the lines of text to the shape
    for (int i=0;i<lines.size();i++) {
        shape[shape.size()-i-2].replace(1, length, lines[lines.size()-i-1]);
    }
    
    // outputs the full shape to the new file
    for (int i=0;i<shape.size();i++) {
        out_str << shape[i] << endl;
    }
}



// print lines in a right triangle facing left in a new file
void right_triangle_left(vector<string>& lines, const int length, ofstream& out_str) {
    
    // a vector with the drawing of the shape
    vector<string> shape;
    
    // draws the corner of the shape
    shape.push_back(string((lines.size()*3)+length,' ')+"|");
    
    // draws the part above the text
    for (int i=2;i<length;i=i+3) {
        shape.push_back(string((lines.size()*3)+length-i-1,' ')+"/"+string(i, ' ')+"|");
    }
    
    // draws the part of the triangle overlapping the text
    for (int i=0;i<lines.size();i++) {
        shape.push_back(string((lines.size()*3)-(i*3)-2,' ')+"/"+string(length+(i*3)+1, ' ')+"|");
    }
    
    // draws the last line
    shape.push_back(string((lines.size()*3)+length+1,'-'));
    
    // adds the lines of text to the shape
    for (int i=0;i<lines.size();i++) {
        shape[shape.size()-i-2].replace(shape[shape.size()-i-2].length()-length-1, length, lines[lines.size()-i-1]);
    }
    
    // outputs the full shape to the new file
    for (int i=0;i<shape.size();i++) {
        out_str << shape[i] << endl;
    }
}



int main(int argc, const char * argv[]) {
    //argv[0] is file name -->justify.cpp
    //argv[1] is input file name
    //argv[2] is output file name
    //argv[3] is the provided length
    //argv[4] is function to be executed
    //argv[5] is the shape for extra credit
    
    // tests if there is the correct number of arguments
    if (argc < 5) {
        cerr << "Not enough arguments.";
        exit(1);
    }
    
    // initializing and defining input file and checking if file exists
    ifstream in_str(argv[1]);
    if (!in_str.good()) {
        cerr << "Can't open " << argv[1] << " to read." << endl;
        exit(1);
    }
    
    // initializing and defining output file and checking if file exists
    ofstream out_str(argv[2]);
    if (!out_str.good()) {
        cerr << "Can't open " << argv[2] << " to write." << endl;
        exit(1);
    }
    
    // reading the length of the text to be justified per line from arc and using streams to convert this value to an int length
    const int length = atoi(argv[3]);
    
    // iterating over the input stream and creating a new vector with all the individual words along the file
    string word;
    vector<string> text;
    while (in_str >> word) {
        text.push_back(word);
    }
    
    // creating a vector to decide how lines are to be split up for justification
    vector<string> lines;
    make_lines(lines, text, length);
    
    // reading the justification function to be executed by the program and returning an output if it does not exist
    if (argv[4] == string("flush_left")) {
        flush_left(lines, length);
    }
    else if (argv[4] == string("flush_right")) {
        flush_right(lines, length);
    }
    else if (argv[4] == string("full_justify")) {
        full_justify(lines, length);
    } else {
        cout << "This is not a proper function" << endl;
    }
    
    // Extra credit printing and printing the box
    // Only looks for a shape if there is a sixth argument, will print a rectangle by default
    if (argc > 5) {
        if (argv[5] == string("right_triangle_right")) {
            right_triangle_right(lines, length, out_str);
        }
        else if (argv[5] == string("right_triangle_left")) {
            right_triangle_left(lines, length, out_str);
        } else {
            rectangle(lines, length, out_str);
        }
    } else {
        rectangle(lines, length, out_str);
    }
    
    // closing the output file
    out_str.close();
    return 0;
}
