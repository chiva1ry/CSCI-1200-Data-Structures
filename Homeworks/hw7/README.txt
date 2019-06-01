HOMEWORK 7: SPATIALLY-EMBEDDED ADJACENCY MAPS


NAME:  < Sriyuth Sagi >


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

<
cplusplus.com
>

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 5 >



ORDER NOTATION ANALYSIS:
Consider the following variables and give the complexity along with a short
justification for each of the functions below:

n: The total number of users
l: The total number of users with a location
d: The total number of users with degree >= 1
m: The total number of connections
p: The number of users that a function will print out
b: The number of bits required to represent the largest ID
i: The number of decimal digits required to represent the largest ID
f: The number of friends a user has

loadConnections():
O( m*log(n) )
It iterates through each line in the connections file as m at uses count in each iteration, giving log(n) each time.

loadLocations():
O( l )
It iterates through each line in locations and runs a constant length each time.

printAllUsersWithinDistance():
O( l + p*log(p) )
Iterates through the different locations to give l and adds the value to the order notation of a sort function that sorts the final answers giving p*log(p).

printDegreesHistogram():
O( n*log(n) + p )
Iterates through the total number of users, n, and uses count to check if the there if a unique degree giving log(n) and adds the total number of answers p.

printDegreesOfAll():
O( n )
Iterates through the total number of users n to find all the degrees.

printFriendsWithDegree():
O( f( 2*log(f) + 2*log(n) ) + p )
Iterates through the total number of friends f and uses an it inside a count function giving 2*log(f) and also uses an it inside an it function giving 2*log(n) and finally adds the number of results p after the iteration.

printFriendsWithinDistance():
O( f( log(l + f) + 4*log(n) ) + p*log(p) )
Iterates through the total number of friends f and uses an it for friends inside a count function for locations giving log(l + f) and also uses four different it functions inside the distance equation giving 4*log(n) and finally adds the value to the order notation of a sort function that sorts the final answers giving p*log(p).

printUsersWithinIDRange():
O( n + p )
// iterates through the number of users and executes constant operations before iteratiterating through the results p and printing out.


MISC. COMMENTS TO GRADER:  
(optional, please be concise!)






