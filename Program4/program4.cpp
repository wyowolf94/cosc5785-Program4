// Shaya Wolf
// COSC5785 - Compilers   
// Program 4
// program4.cpp
// 11/1/2017

#include<FlexLexer.h>

#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>

#include "attributes.h"
#include "node.hpp"
#include "program4.tab.h"

using namespace std;

attributes *atts;
yyFlexLexer myScanner;
vector<Node*> forest;

int main() { 
  // Initialize Attributes Struct
  atts = new attributes{0,0,0,""};
  
  cout << endl;
    
  // Make call for Bison
  yyparse();
  
  // Print the Parse Tree
  if(forest.size() > 0) {
    cout << endl << "<Program> -> ";
    for(unsigned int i = 0; i < forest.size(); i++) {
      cout << "<ClassDec> ";
    }
    cout << endl;
    for(unsigned int i = 0; i < forest.size(); i++) {
      cout << endl << "**" << i << "**" << endl;
      forest[i]->printNode();
      delete forest[i];
    }
    cout << endl;
  }
  
  delete atts;
  
  return 0 ;
}
