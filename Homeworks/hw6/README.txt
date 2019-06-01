HOMEWORK 6: BATTLESHIP RECURSION


NAME:  < Sriyuth Sagi >



COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

<
cplusplus.com
stackoverflow.com
geeksforgeeks.org
cppreference.com
>

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 30 >



ANALYSIS OF PERFORMANCE OF YOUR ALGORITHM:
(order notation & concise paragraph, < 200 words)
The dimensions of the board (w and h) 
The number of ships (s)? 
The total number of occupied cells (o) or open water (w)? 
The number of constraints (c)? 
The number of unknown sums (u) or unspecified ship types (t)? 
Etc. 

In the program, the time increases when the solution number is higher and constraints reduce the number of possible solutions so they have a strong effect on decreasing the total time taken drastically. Conversely, my implementation for unknowns was left as rather inefficient and has resulted in a huge increase in the time taken though this is largerly due to it not being fully completed. However, board size and the number of ships still showed to have a major effect on the time taken, with an increase in size resulting in an increase in time.



SUMMARY OF PERFORMANCE OF YOUR PROGRAM ON THE PROVIDED PUZZLES:
# of solutions & approximate wall clock running time for different
puzzles for a single solution or all solutions.


puzzle1.txt                1          0.000307
puzzle2.txt                1          0.000595
puzzle3.txt                1          0.000531
puzzle4.txt                1          0.000553
puzzle4_unknowns.txt       1          0.000547
puzzle5.txt                2          0.00111
puzzle6.txt                24         0.011763
puzzle6_unknowns.txt       24         9.10695
puzzle7.txt                14         0.003609
puzzle8.txt                2          0.004349
puzzle9.txt                152        0.163656
puzzle9_constraints.txt    1          0.00286
puzzle10.txt               3754       3.10289
puzzle10_constraints.txt   1          0.013254


MISC. COMMENTS TO GRADER:  
(optional, please be concise!)


