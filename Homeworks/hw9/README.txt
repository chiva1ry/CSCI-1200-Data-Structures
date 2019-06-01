HOMEWORK 7: MINIBLAST


NAME:  < Sriyuth Sagi >


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

<
stackoverflow.com
cplusplus.com
>

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 6 >


HASH FUNCTION DESCRIPTION

I found a functioning hash function through searching through stack overflow (link below) that functions by multiplying each character in the string by a predetermined value FNVMultiple, which is a determined prime number value while the other predefined value, InitialFNV is a composite number that also acts as a minimum number for all the hash values. The function works by multiplying the value at each character position in the string by a prime number constant and generating a hash table value based on the characters being input. The difference I added to the function was to modulus the final returned hash value by the total size of the table to allow indexing to function without providing access errors.

link: https://stackoverflow.com/questions/98153/whats-the-best-hashing-algorithm-to-use-on-a-stl-string-when-using-hash-map



HASH TABLE IMPLEMENTATION

The hash table is first made by finding the final required length and populating a vector with that number of empty values. The total size of the vector is found by checking if the number of values to be added to the table divided by the current table size is greater than the maximum allowed occupancy and raising the table size to the power of two until this statement becomes false. Following this, the function will hash each set of characters of length kmer starting from each index position in the genome string and return a unique index. Using this index, the string at that position and the index position in the genome string are both stored at their hashed index value. In the case of a conflict, the value will be moved to the next available position meaning all similar strings can be found through linear probing
Query is done by finding the position of the entered string in the hash table and using linear probing to find all similar values to query. Each of these matching values will then be queried for mismatches and provide their outputs if appropriate.





ANALYSIS OF PERFORMANCE OF YOUR ALGORITHM:
(order notation & concise paragraph, < 200 words)

L = length of the genome sequence
q - query length
p - number of different locations where key is found
k - key size (k-mer size)

How much memory will the map data structure require (order notation for memory use)?

O(Lk)


What is the order notation for performance (running time) of each of
the commands?

genome: O(1)

table_size: O(1)

occupancy: O(1)

kmer: O(1)

hash table implementation: O(Lk)

query: O(k + pq)

quit: O(1)


EXTRA CREDIT
Add a new command to implement the database using one of the other
 data structures that we have covered so far in the course: 
vectors, lists, arrays etc. 

Compare the performance your alternative method to the homework method
by making a table of run times for each of the genomes and query 
sets provided with the homework  and compare the times to build
the index and the times to process the queries. 
Document any new commands you have added in your README file.



MISC. COMMENTS TO GRADER:  
(optional, please be concise!)


