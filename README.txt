README

Assignment 1: Chain
CSCI335-01
Shu Xin Lei

Overview:
The purpose of this assignment is to create a dynamically allocated array within a Chain class from scratch. This assignment contains two parts. The first part deals with Weiss's big five, which includes constructor, copy-constructor, copy-assignment, move-constructor, and move-assignment. The second part of the code includes reading a chain input from user, and overloading the [], +, and << operator to locate the element at index, concatenating a chain with another chain/string, and printing the chain respectively. 

The zip file contains the necessary components to run the program: test_chain.cpp 
chain.h 
Makefile 
It also includes the following sample input/output file:
test_input_file.txt
expected_output.txt

To compile on terminal type
  make all

To delete executables and object file type
  make clean

To run
  ./test_chain

To run with sample file attached
  ./test_chain < test_input_file.txt

Issues:
While working on this program, I've came across some problems with allocating memory for the Chain objects in the ReadChain() function and in overloading the + operator. These issues were resolved when I reviewed the material from previous CS classes, and with a friendly reminder that it should be an array of Objects and not an array of Chain. I also encounter issues with taking elements from user input, but this was resolved with the assistance of stringstream and the removal of brackets prior to taking in each element. The output of my program differs with the expected output by an extra empty line after printing the concatenated chain of strings. I've added endl to my overloaded << operator after it prints the chain. However, within the test_chain.cpp in lines 42, 43, and 47, there is also endl provided with the given code. So endl is used twice for those lines, therefore giving an extra empty line after the chain is printed. 

Final Thoughts:
This was a great exercise overall to review how to create a dynamically allocated array, but also to review the basics of initializing a class with dynamically allocated memory. It was also my first time including move-assignment, move operator, and copy-assignment to a class, which optimizes the Chain object's usage in general. It is important to have these constructors in order to deal with the necessary clean up. 

