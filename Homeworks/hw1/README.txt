HOMEWORK 1: TEXT JUSTIFICATION


NAME:  < Sriyuth Sagi >


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

<
http://www.cs.rpi.edu/academics/courses/spring18/csci1200/other_information.php
https://stackoverflow.com/questions/2797813/how-to-convert-a-command-line-argument-to-int
https://stackoverflow.com/questions/22929554/using-command-line-input-to-call-a-function
http://www.cplusplus.com/doc/tutorial/files/
http://www.cplusplus.com/reference/string/string/erase/
other www.cplusplus.com references and informations
>

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 4-5 >



EXTRA CREDIT SHAPES:
Describe your new shapes, include example files of the output with
your submission, and provide the command line used to create the these
examples.
I have two extra shapes, both being right triangles with one facing towards the right and the the other facing towards the left and they will look at both the length inputted from terminal and the total number of lines that are written so the text will always fall inside the shape. It works by taking in left, right and full justified text so the type of justification has no effect on the shape. If there is no sixth argument, the file will print a rectangle.
Basic shapes on example.txt with length 16
./justify.exe example.txt example_16_traingle_right.txt 16 flush_left right_triangle_right
./justify.exe example.txt example_16_traingle_left.txt 16 flush_left right_triangle_left

Basic shapes on gettysburg_address.txt with length 70
./justify.exe gettysburg_address.txt gettysburg_address_70_triangle_right.txt 70 flush_left right_triangle_right
./justify.exe gettysburg_address.txt gettysburg_address_70_triangle_left.txt 70 flush_left right_triangle_left

Change in shape to include more line and less length on gettysburg_address.txt with length 35
./justify.exe gettysburg_address.txt gettysburg_address_35_triangle_right.txt 35 flush_left right_triangle_right
./justify.exe gettysburg_address.txt gettysburg_address_35_triangle_left.txt 35 flush_left right_triangle_left



MISC. COMMENTS TO GRADER:  
Optional, please be concise!


