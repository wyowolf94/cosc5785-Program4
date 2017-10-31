Shaya Wolf
Program 4 Files
cosc5785 - Compilers
10/17/2017

Some Notes:


attributes.cpp 
--> File containing method to update token attributes

attributes.h 
--> Header file for attributes.cpp containing the attributes
    data structure and macros for lex to use

grammar.txt
--> Grammar implemented in this iteration 

grammarTest.txt
--> Test file that *should* completely test the grammar

grammarTestExpected.txt
--> Expected output when grammarTest.txt is run

Makefile
--> Make and clean functions

node.hpp
--> Node class that uses a base class to implement different
    type of nodes with specific print functions. Might expand
    later to one node per terminal.

program4.cpp
--> Main program that calls yyparse and prints the parse tree

program4.lpp
--> Lex file to read in input from standard in and return 
    tokens for Bison file. This does not pass white space/comments
    to Bison but does print lexical word/char errors to std::out.
    
program4.y
--> Bison file for parsing and recovering from syntactic errors 


