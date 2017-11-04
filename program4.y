/* 
 * Shaya Wolf
 * cosc5785 - Compilers
 * Program4
 * program4.y
 * 11/1/2017
 */

%{

#include <iostream>
#include <FlexLexer.h>
#include "node.hpp"
#include "attributes.h"

using namespace std;
//using std::cerr;
//using std::cout;
//using std::endl;

// externs defined in program3.cpp 
extern vector<Node*> forest;
extern yyFlexLexer myScanner;

// Make C++ scanner play nice with C parser
#define yylex() myScanner.yylex()

// Parser function prototype
void yyerror(const char *);

%}

%union {
  Node *ttype;
  struct attributes* atts;
}
// Bison Declarations

%type<ttype> elem 
%type<ttype> param paramstar paramlist
%type<ttype> resulttype methoddec constdec
%type<ttype> statement optexp
%type<ttype> simpleType type varDec 
%type<ttype> condstatement
%type<ttype> locvardec block stateplus locvardecplus
%type<ttype> exp name newexp expstar brackstar
%type<ttype> explist arglist
%type<ttype> relop sumop proop unyop

%token<atts> DOT THIS
%token<atts> LBRACK RBRACK DOUBBRACK 
%token<atts> LBRACE RBRACE
%token<atts> INT IDEN 
%token<atts> NUM NLL READ NEW LPAREN RPAREN
%token<atts> IF ELSE

%token<atts> DEQ NEQ LEQ GEQ GT LT 
%token<atts> PLUS MINUS OR
%token<atts> MULT DIVD MOD AND
%token<atts> BANG
%token<atts> SEMI EQ COMMA RETURN WHILE PRINT
%token<atts> VOID

%left DEQ NEQ LEQ GEQ GT LT RO
%left PLUS MINUS OR SO
%left MULT DIVD MOD AND PO

%precedence UO
%precedence DE
%precedence ELSE
//%precedence PRMTR
//%precedence SEMI
%precedence RT
%precedence IDEN
%precedence NM
%precedence LPAREN


%% 

// Bison Grammar

start : %empty {}
      | start elem {if($2->getValid()) forest.push_back($2);
                    else delete $2;}
      ;

elem : statement {}
     | varDec {}
     | methoddec {}
     | constdec {}
     ;
     
constdec : IDEN LPAREN paramlist RPAREN block
             {$$ = new constdecNode($1->value);
              $$->addChild($3);
              $$->addChild($5);
              delete $1;
              delete $2;
              delete $4;}
         ;
     
methoddec : resulttype IDEN LPAREN paramlist RPAREN block
              {$$ = new methoddecNode($2->value);
               $$->addChild($1);
               $$->addChild($4);
               $$->addChild($6);
               delete $2;
               delete $3;
               delete $5;}
          ;
     
resulttype : type %prec RT
               {$$ = new resulttypeNode("type");
                $$->addChild($1);}
           | VOID
               {$$ = new resulttypeNode("void");
                delete $1;}
           ;
     
paramlist : %empty
              {$$ = new paramlistNode("empty");}
          | paramstar
              {$$ = new paramlistNode("rec");
               $$->addChild($1);}
          ;
     
paramstar : param 
              {$$ = new paramstarNode();
               $$->addChild($1);}
          | paramstar COMMA param
              {$$ = new paramstarNode();
               $1->addChild($3);
               $$ = $1;
               delete $2;}
          ;
     
param : type IDEN //%prec PRMTR
          {$$ = new paramNode($2->value);
           $$->addChild($1);
           delete $2;}
      ;
     
statement : SEMI
              {$$ = new statementNode("semi");
               delete $1;}
          |name EQ exp SEMI 
              {$$ = new statementNode("nameeq");
               if(!$1->getValid() || !$3->getValid()) {
                 $$->setValid(false);
               }
               $$->addChild($1);
               $$->addChild($3);
               delete $2;
               delete $4;}
          | name EQ exp error
              {cerr << "Missing ';' after statement: line " << $2->lNum << endl << endl;
               $$ = new errorNode("<Statement>");
               $$->setValid(false);
               $$->addChild($1);
               $$->addChild($3);
               delete $2;
               yyerrok;}
          | name LPAREN arglist RPAREN SEMI
              {$$ = new statementNode("namearglist");
               $$->addChild($1);
               $$->addChild($3);
               delete $2;
               delete $4;
               delete $5;}
          | PRINT LPAREN arglist RPAREN SEMI
              {$$ = new statementNode("printarglist");
               $$->addChild($3);
               delete $1;
               delete $2;
               delete $4;
               delete $5;}
          | condstatement
              {$$ = new statementNode("cond");
               $$->addChild($1);}
          | WHILE LPAREN exp RPAREN statement
              {$$ = new statementNode("while");
               $$->addChild($3);
               $$->addChild($5);
               delete $1;
               delete $2;
               delete $4;}
          | RETURN optexp SEMI
              {$$ = new statementNode("optexp");
               $$->addChild($2);
               delete $1;
               delete $3;}
          | block
              {$$ = new statementNode("block");
               $$->addChild($1);}
          ; 
           
condstatement : IF LPAREN exp RPAREN statement %prec DE
                  {$$ = new condstatementNode("if");
                   $$->addChild($3);
                   $$->addChild($5);
                   delete $1;
                   delete $2;
                   delete $4;}
              | IF LPAREN exp RPAREN statement ELSE statement 
                  {$$ = new condstatementNode("if-else");
                   $$->addChild($3);
                   $$->addChild($5);
                   $$->addChild($7);
                   delete $1;
                   delete $2;
                   delete $4;
                   delete $6;}
              ;
           
block : LBRACE RBRACE
          {$$ = new blockNode("empty");
           delete $1;
           delete $2;}
      | LBRACE locvardecplus RBRACE
          {$$ = new blockNode("locvardecs");
           $$->addChild($2);
           delete $1;
           delete $3;}
      | LBRACE stateplus RBRACE
          {$$ = new blockNode("statements");
           $$->addChild($2);
           delete $1;
           delete $3;}
      | LBRACE locvardecplus stateplus RBRACE
          {$$ = new blockNode("both");
           $$->addChild($2);
           $$->addChild($3);
           delete $1;
           delete $4;}
      ;
           
stateplus : statement
              {$$ = new stateplusNode();
               $$->addChild($1);}
          | stateplus statement
              {$$ = new stateplusNode();
               $1->addChild($2);
               $$ = $1;}
          ;
           
locvardecplus : locvardec
                  {$$ = new locvardecplusNode();
                   $$->addChild($1);}
              | locvardecplus locvardec
                  {$$ = new locvardecplusNode();
                   $1->addChild($2);
                   $$ = $1;}
              ;
           
locvardec : type IDEN SEMI 
              {$$ = new locvardecNode($2->value);
               $$->addChild($1);
               delete $2;
               delete $3;}
          ;
           
optexp : %empty
           {$$ = new optexpNode("empty");}
       | exp
           {$$ = new optexpNode("exp");
            $$->addChild($1);}
       ;
           
exp : name 
        {$$ = new expNode("name");
         $$->addChild($1);}
    | NUM
        {$$ = new expNode("num", $1->value);
         delete $1;}
    | NLL
        {$$ = new expNode("null");
         delete $1;}
    | name LPAREN RPAREN
        {$$ = new expNode("name paren");
         $$->addChild($1);
         delete $2;
         delete $3;}
    | name LPAREN error
        {cerr << "Missing ')' after name declaration: line " << $2->lNum << endl << endl;
         $$ = new errorNode("<Expression>");
         $$->setValid(false);
         $$->addChild($1);
         delete $2;
         yyerrok;}
    | READ LPAREN RPAREN
        {$$ = new expNode("read");
         delete $1;
         delete $2;
         delete $3;}
    | READ LPAREN error
        {cerr << "Missing ')' after read: line " << $1->lNum << endl << endl;
         $$ = new errorNode("<Expression>");
         $$->setValid(false);
         delete $1;
         delete $2;
         yyerrok;}
    | READ error RPAREN
        {cerr << "Missing '(' after read: line " << $1->lNum << endl << endl;
         $$ = new errorNode("<Expression>");
         $$->setValid(false);
         delete $1;
         delete $3;
         yyerrok;}
    | newexp
        {$$ = new expNode("newexp");
         if(!$1->getValid()) {
           $$->setValid(false);
         }
         $$->addChild($1);}
    | exp relop exp %prec RO
        {$$ = new expNode("relop");
         $$->addChild($1);
         $$->addChild($2);
         $$->addChild($3);}
    | exp sumop exp %prec SO
        {$$ = new expNode("sumop");
         $$->addChild($1);
         $$->addChild($2);
         $$->addChild($3);}
    | exp proop exp %prec PO
        {$$ = new expNode("proop");
         $$->addChild($1);
         $$->addChild($2);
         $$->addChild($3);}
    | unyop exp %prec UO
        {$$ = new expNode("unyop");
         $$->addChild($1);
         $$->addChild($2);}
    | LPAREN exp RPAREN 
        {$$ = new expNode("paren");
         $$->addChild($2);
         delete $1;
         delete $3;}
    | LPAREN exp error 
        {cerr << "Missing ')' after expression: line " << $1->lNum << endl << endl;
         $$ = new errorNode("<Expression>");
         $$->addChild($2);
         $$->setValid(false);
         delete $1;
         yyerrok;}
    ;  
    
newexp : NEW IDEN LPAREN arglist RPAREN 
           {$$ = new newexpNode("parens", $2->value);
            $$->addChild($4);
            delete $1;
            delete $2;
            delete $3;
            delete $5;}
       | NEW IDEN LPAREN arglist error 
           {cerr << "Missing ')' after type: line " << $1->lNum << endl << endl;
            $$ = new errorNode("<NewExpression>");
            $$->addChild($4);
            $$->setValid(false);
            delete $1;
            delete $2;
            delete $3;
            yyerrok;}
       | NEW simpleType expstar brackstar
           {$$ = new newexpNode("bracks");
            if(!$3->getValid()) {
              $$->setValid(false);
            }
            $$->addChild($2); 
            $$->addChild($3);
            $$->addChild($4);
            delete $1;}
       ;
           
brackstar : %empty
              {$$ = new brackstarNode();}
          | brackstar DOUBBRACK
              {$$ = new brackstarNode();
               $1->addChild(new brackstarNode());
               $$ = $1;
               delete $2;}
          ;
          
expstar : %empty
            {$$ = new expstarNode();}
        | expstar LBRACK exp RBRACK 
            {$$ = new expstarNode();
             $1->addChild($3);
             $$ = $1;
             delete $2;
             delete $4;}
        | expstar LBRACK exp error
            {cerr << "Missing ']' after expression: line " << $2->lNum << endl << endl;
             $$ = new errorNode("<expstar>");
             $1->addChild($3);
             $$->setValid(false);
             $1->setValid(false);
             $3->setValid(false);
             $$ = $1;
             delete $2;
             yyerrok;}
        ;
    
arglist : %empty
            {$$ = new arglistNode("empty");}
        | explist
            {$$ = new arglistNode("rec");
             $$->addChild($1);}
        ;
  
explist : exp 
            {$$ = new explistNode();
             $$->addChild($1);} 
        | explist COMMA exp 
            {$$ = new explistNode();
             $1->addChild($3);
             $$ = $1;
             delete $2;}
        ;
  
name : THIS  
         {$$ = new nameNode("this", "");
          delete $1;}
     | IDEN %prec NM
         {$$ = new nameNode("id", $1->value);
          delete $1;}
     | name DOT IDEN 
         {$$ = new nameNode("dotid", $3->value);
          $$->addChild($1);;
          delete $2;
          delete $3;} 
     | name LBRACK exp RBRACK 
         {$$ = new nameNode("exp", "");
          $1->addChild($3);
          $$ = $1;
          delete $2;
          delete $4;}
     | name LBRACK exp error
         {cerr << "Missing ']' after name: line " << $2->lNum << endl << endl;
          $$ = new errorNode("<Name>");
          $$->setValid(false);
          $$->addChild($1);
          $$->addChild($3);
          delete $2;
          yyerrok;}        
     ;
     
varDec : type IDEN SEMI  {$$ = new varDecNode($2->value);
                          $$->addChild($1);
                          delete $2;
                          delete $3;}
       | type IDEN error {cerr << "Missing ';' after identifier: line " 
                               << $2->lNum << endl << endl;
                          $$ = new errorNode("<VarDeclaration>");
                          $$->addChild($1);
                          $$->setValid(false);
                          delete $2;
                          yyerrok;}
       ;
     
type : simpleType 
         {$$ = new typeNode("simpleType");
          $$->addChild($1);}
     | type DOUBBRACK 
         {$$ = new typeNode("type");
          $$->addChild($1);
          delete $2;}
     ;
     
simpleType : INT  {$$ = new simpleTypeNode($1->token, "");
                   delete $1;} 
           | IDEN {$$ = new simpleTypeNode("id", $1->value);
                   delete $1;}
           ;

relop : DEQ   {$$ = new relopNode("==");
               delete $1;}
      | NEQ   {$$ = new relopNode("!=");
               delete $1;}
      | LEQ   {$$ = new relopNode("<=");
               delete $1;}
      | GEQ   {$$ = new relopNode(">=");
               delete $1;}
      | GT    {$$ = new relopNode(">");
               delete $1;}
      | LT    {$$ = new relopNode("<");
               delete $1;}
      ;
      
sumop : PLUS  {$$ = new sumopNode("+");
               delete $1;}
      | MINUS {$$ = new sumopNode("-");
               delete $1;}
      | OR    {$$ = new sumopNode("||");
               delete $1;}
      ;
      
proop : MULT  {$$ = new proopNode("*");
               delete $1;}
      | DIVD  {$$ = new proopNode("/");
               delete $1;}
      | MOD   {$$ = new proopNode("%");
               delete $1;}
      | AND   {$$ = new proopNode("&&");
               delete $1;}
      ;
        
unyop : PLUS  {$$ = new unyopNode("+");
               delete $1;}
      | MINUS {$$ = new unyopNode("-");
               delete $1;}
      | BANG  {$$ = new unyopNode("!");
               delete $1;}
      ;
      
%%
