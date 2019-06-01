HOMEWORK 3: MATRIX CLASS


NAME:  < Sriyuth Sagi >


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

<

https://stackoverflow.com/questions/476272/how-to-properly-overload-the-operator-for-an-ostream
https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
Keenan Adams (classmate)
Alexei Hazel (classmate)

>

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.


ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 9 >



ORDER NOTATION:
For each of the functions below, write the order notation O().
Write each answer in terms of m = the number of rows and n = the
number of columns.  You should assume that calling new [] or delete []
on an array will take time proportional to the number of elements in
the array.

get
O(1)
set
O(1)
num_rows
O(1)
get_column
O(mxn)
operator<<
O(mxn)
quarter
O(mxn)
operator==
O(mxn)
operator!=
O(mxn)
swap_rows
O(mxn)
rref (provided in matrix_main.cpp)
O(m^2xn)


TESTING & DEBUGGING STRATEGY: 
Discuss your strategy for testing & debugging your program.  
What tools did you use (gdb/lldb/Visual Studio debugger,
Valgrind/Dr. Memory, std::cout & print, etc.)?  How did you test the
"corner cases" of your Matrix class design & implementation?
I found it most convenient to use Dr. Memory as a higher level tool to find where problems are ocurring and then found the details of what and where things might be going wrong with prints and cout. When cout was not enough I would have to go into lldb but the majority of problems I encountered were solved through couts and different test cases.

EXTRA CREDIT: 
Indicate here if you implemented resize() for extra credit.  
Also document the order notation for your resize() function.



MISC. COMMENTS TO GRADER:  
(optional, please be concise!)

