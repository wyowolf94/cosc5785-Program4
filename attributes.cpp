// Shaya Wolf
// COSC5785 - Compilers   
// Program 4
// attributes.cpp
// 11/1/2017

#include<string>
#include "attributes.h"
#include "node.hpp"
#include "program4.tab.h"

using namespace std;

void updateAtts(int lNum, int cNum, int leng, string token, string value) {
  yylval.atts->lNum = lNum;
  yylval.atts->cNum = cNum;
  yylval.atts->leng = leng;
  yylval.atts->token = token;
  yylval.atts->value = value; 
  return;
}

