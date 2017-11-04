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

using std::cerr;
using std::cout;
using std::endl;

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

%type<ttype> program 
%type<ttype> classdec
%type<ttype> classbody vardecplus constdecplus methdecplus 
%type<ttype> param paramplus paramlist
%type<ttype> methoddec constdec
%type<ttype> statement optexp
%type<ttype> simpleType type vardec 
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
%token<atts> VOID CLASS

%left DEQ NEQ LEQ GEQ GT LT RO
%left PLUS MINUS OR SO
%left MULT DIVD MOD AND PO

%precedence UO
%precedence DE
%precedence ELSE


%% 
  
program : classdec
            {if(!$1->getValid()) {
               $$->setValid(false);
             }
             forest.push_back($1);}
        | program classdec
            {if(!$2->getValid()) {
               $$->setValid(false);
             }
             forest.push_back($2);}
        ;
   
classdec : CLASS IDEN classbody
             {$$ = new classdecNode($2->value);
              if(!$3->getValid()) {
                $$->setValid(false);
              }
              $$->addChild($3);
              delete $1;
              delete $2;}
         ;
   
classbody : LBRACE RBRACE 
              {$$ = new classbodyNode("empty");
               delete $1;
               delete $2;}
          | LBRACE vardecplus RBRACE 
              {$$ = new classbodyNode("vdecs");
               if(!$2->getValid()) {
                 $$->setValid(false);
               }
               $$->addChild($2);
               delete $1;
               delete $3;}
          | LBRACE constdecplus RBRACE 
              {$$ = new classbodyNode("cdecs");
               if(!$2->getValid()) {
                 $$->setValid(false);
               }
               $$->addChild($2);
               delete $1;
               delete $3;}
          | LBRACE methdecplus RBRACE 
              {$$ = new classbodyNode("mdecs");
               if(!$2->getValid()) {
                 $$->setValid(false);
               }
               $$->addChild($2);
               delete $1;
               delete $3;}
          | LBRACE vardecplus constdecplus RBRACE 
              {$$ = new classbodyNode("vcdecs");
               if(!$2->getValid() || !$3->getValid()) {
                 $$->setValid(false);
               }
               $$->addChild($2);
               $$->addChild($3);
               delete $1;
               delete $4;}
          | LBRACE vardecplus methdecplus RBRACE 
              {$$ = new classbodyNode("vmdecs");
               if(!$2->getValid() || !$3->getValid()) {
                 $$->setValid(false);
               }
               $$->addChild($2);
               $$->addChild($3);
               delete $1;
               delete $4;}
          | LBRACE constdecplus methdecplus RBRACE 
              {$$ = new classbodyNode("cmdecs");
               if(!$2->getValid() || !$3->getValid()) {
                 $$->setValid(false);
               }
               $$->addChild($2);
               $$->addChild($3);
               delete $1;
               delete $4;}
          | LBRACE vardecplus constdecplus methdecplus RBRACE 
              {$$ = new classbodyNode("vcmdecs");
               if(!$2->getValid() || !$3->getValid() || $4->getValid()) {
                 $$->setValid(false);
               }
               if(!$2->getValid()) {
                 $$->setValid(false);
               }
               $$->addChild($2);
               $$->addChild($3);
               $$->addChild($4);
               delete $1;
               delete $5;}
          ;
          
methdecplus : methoddec 
                {if(!$1->getValid()) {
                   $$->setValid(false);
                 }
                 $$ = new plusstarNode();
                 $$->addChild($1);}
            | methdecplus methoddec 
                {if(!$2->getValid()) {
                   $$->setValid(false);
                 }
                 $1->addChild($2);
                 $$ = $1;}
            ;
            
constdecplus : constdec 
                 {if(!$1->getValid()) {
                    $$->setValid(false);
                  }
                  $$ = new plusstarNode();
                  $$->addChild($1);}
             | constdecplus constdec 
                 {if(!$2->getValid()) {
                    $$->setValid(false);
                  }
                  $1->addChild($2);
                  $$ = $1;}
             ;
             
vardecplus : vardec 
               {if(!$1->getValid()) {
                  $$->setValid(false);
                }
                $$ = new plusstarNode();
                $$->addChild($1);}
           | vardecplus vardec 
               {if(!$2->getValid()) {
                   $$->setValid(false);
                }
                $1->addChild($2);
                $$ = $1;}
           ;
           
     
methoddec : type IDEN LPAREN paramlist RPAREN block
              {$$ = new methoddecNode("type", $2->value);
               if(!$6->getValid()) {
                 $$->setValid(false);
               }
               $$->addChild($1);
               $$->addChild($4);
               $$->addChild($6);
               delete $2;
               delete $3;
               delete $5;}
          | VOID IDEN LPAREN paramlist RPAREN block
              {$$ = new methoddecNode("void", $2->value);
               if(!$6->getValid()) {
                 $$->setValid(false);
               }
               $$->addChild($4);
               $$->addChild($6);
               delete $1;
               delete $2;
               delete $3;
               delete $5;}
          | type IDEN LPAREN paramlist error block 
              {cerr << endl << "Expected ')' after parameter list: line " 
                    << $2->lNum << endl << endl;
               $$ = new errorNode("<MethDec>");
               $$->addChild($1);
               $$->addChild($4);
               $$->addChild($6);
               $$->setValid(false);
               delete $2;
               delete $3;
               yyerrok;}
          | VOID IDEN LPAREN paramlist error block 
              {cerr << endl << "Expected ')' after parameter list: line " 
                    << $2->lNum << endl << endl;
               $$ = new errorNode("<MethDec>");
               $$->addChild($4);
               $$->addChild($6);
               $$->setValid(false);
               delete $1;
               delete $2;
               delete $3;
               yyerrok;}
          ;
     
constdec : IDEN LPAREN paramlist RPAREN block
             {$$ = new constdecNode($1->value);
              if(!$5->getValid()) {
                $$->setValid(false);
              }
              $$->addChild($3);
              $$->addChild($5);
              delete $1;
              delete $2;
              delete $4;}
         | IDEN error paramlist RPAREN block
             {cerr << endl << "Expected '(' after identifier: line " 
                   << $1->lNum << endl << endl;
              $$ = new errorNode("<ConstDec>");
              $$->addChild($3);
              $$->addChild($5);
              $$->setValid(false);
              delete $1;
              delete $4;
              yyerrok;}
         | IDEN LPAREN paramlist error block
             {cerr << endl << "Expected ')' after parameter list: line " 
                   << $1->lNum << endl << endl;
              $$ = new errorNode("<ConstDec>");
              $$->addChild($3);
              $$->addChild($5);
              $$->setValid(false);
              delete $1;
              delete $2;
              yyerrok;}
         ;
          
vardec : type IDEN SEMI  
           {$$ = new varDecNode($2->value);
            $$->addChild($1);
            delete $2;
            delete $3;}
       | type IDEN error 
           {cerr << endl << "Missing ';' after identifier: line " 
                 << $2->lNum << endl << endl;
            $$ = new errorNode("<VarDec>");
            $$->addChild($1);
            $$->setValid(false);
            delete $2;
            yyerrok;}
      ;
     
paramlist : %empty
              {$$ = new paramlistNode("empty");}
          | paramplus
              {$$ = new paramlistNode("rec");
               $$->addChild($1);}
          ;
     
paramplus : param 
              {$$ = new plusstarNode();
               $$->addChild($1);}
          | paramplus COMMA param
              {$1->addChild($3);
               $$ = $1;
               delete $2;}
          ;
     
param : type IDEN 
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
              {cerr << endl << "Missing ';' after statement: line " 
                    << $2->lNum << endl << endl;
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
          | name LPAREN arglist RPAREN error 
              {cerr << endl << "Missing ';' after statement: line " 
                    << $2->lNum << endl << endl;
               $$ = new errorNode("<Statement>");
               $$->setValid(false);
               $$->addChild($1);
               $$->addChild($3);
               delete $2;
               delete $4;
               yyerrok;}
          | name LPAREN arglist error SEMI 
              {cerr << endl << "Missing ')' after arglist in statement: line " 
                    << $2->lNum << endl << endl;
               $$ = new errorNode("<Statement>");
               $$->setValid(false);
               $$->addChild($1);
               $$->addChild($3);
               delete $2;
               delete $5;
               yyerrok;}
          | PRINT LPAREN arglist RPAREN SEMI
              {$$ = new statementNode("printarglist");
               $$->addChild($3);
               delete $1;
               delete $2;
               delete $4;
               delete $5;}
          | PRINT LPAREN arglist RPAREN error 
              {cerr << endl << "Missing ';' after statement: line " 
                    << $2->lNum << endl << endl;
               $$ = new errorNode("<Statement>");
               $$->setValid(false);
               $$->addChild($3);
               delete $1;
               delete $2;
               delete $4;
               yyerrok;}
          | PRINT LPAREN arglist error SEMI 
              {cerr << endl << "Missing ')' after arglist in statement: line " 
                    << $2->lNum << endl << endl;
               $$ = new errorNode("<Statement>");
               $$->setValid(false);
               $$->addChild($3);
               delete $1;
               delete $2;
               delete $5;
               yyerrok;}
          | condstatement
              {$$ = new statementNode("cond");
               if(!$1->getValid()) {
                 $$->setValid(false);
               }
               $$->addChild($1);}
          | WHILE LPAREN exp RPAREN statement
              {$$ = new statementNode("while");
               if(!$3->getValid()) {
                 $$->setValid(false);
               }
               $$->addChild($3);
               $$->addChild($5);
               delete $1;
               delete $2;
               delete $4;}
          | WHILE LPAREN exp error statement
              {cerr << endl << "Missing ')' after while expression in statement: line " 
                    << $2->lNum << endl << endl;
               $$ = new errorNode("<Statement>");
               $$->setValid(false);
               $$->addChild($3);
               $$->addChild($5);
               delete $1;
               delete $2;}
          | RETURN optexp SEMI
              {$$ = new statementNode("optexp");
               $$->addChild($2);
               delete $1;
               delete $3;}
          | RETURN optexp error
              {cerr << endl << "Missing ';' after return statement: line " 
                    << $1->lNum << endl << endl;
               $$ = new errorNode("<Statement>");
               $$->setValid(false);
               $$->addChild($2);
               delete $1;}
          | block
              {$$ = new statementNode("block");
               if(!$1->getValid()) {
                 $$->setValid(false);
               }
               $$->addChild($1);}
          ; 
           
condstatement : IF LPAREN exp RPAREN statement %prec DE
                  {$$ = new condstatementNode("if");
                   if(!$3->getValid()) {
                     $$->setValid(false);
                   }
                   $$->addChild($3);
                   $$->addChild($5);
                   delete $1;
                   delete $2;
                   delete $4;}
              | IF LPAREN exp error statement %prec DE 
                  {cerr << endl 
                        << "Missing ')' after expression in conditional statement: line " 
                        << $2->lNum << endl << endl;
                   $$ = new errorNode("<ConditionalStatement>");
                   $$->setValid(false);
                   $$->addChild($3);
                   $$->addChild($5);
                   delete $1;
                   delete $2;
                   yyerrok;} 
              | IF LPAREN exp RPAREN statement ELSE statement 
                  {$$ = new condstatementNode("if-else");
                   if(!$3->getValid()) {
                     $$->setValid(false);
                   }
                   $$->addChild($3);
                   $$->addChild($5);
                   $$->addChild($7);
                   delete $1;
                   delete $2;
                   delete $4;
                   delete $6;}
              | IF LPAREN exp error statement ELSE statement 
                  {cerr << endl 
                        << "Missing ')' after expression in conditional statement: line " 
                        << $2->lNum << endl << endl;
                   $$ = new errorNode("<ConditionalStatement>");
                   $$->setValid(false);
                   $$->addChild($3);
                   $$->addChild($5);
                   $$->addChild($7);
                   delete $1;
                   delete $2;
                   delete $6;
                   yyerrok;}
              ;
           
block : LBRACE RBRACE
          {$$ = new blockNode("empty");
           delete $1;
           delete $2;}
      | LBRACE locvardecplus RBRACE
          {$$ = new blockNode("locvardecs");
           if(!$2->getValid()) {
             $$->setValid(false);
           }
           $$->addChild($2);
           delete $1;
           delete $3;}
      | LBRACE stateplus RBRACE
          {$$ = new blockNode("statements");
           if(!$2->getValid()) {
             $$->setValid(false);
           }
           $$->addChild($2);
           delete $1;
           delete $3;}
      | LBRACE locvardecplus stateplus RBRACE
          {$$ = new blockNode("both");
           if(!$2->getValid() || !$3->getValid()) {
             $$->setValid(false);
           }
           $$->addChild($2);
           $$->addChild($3);
           delete $1;
           delete $4;}
      ;
           
stateplus : statement
              {$$ = new plusstarNode();
               if(!$1->getValid()) {
                 $$->setValid(false);
               }
               $$->addChild($1);}
          | stateplus statement
              {if(!$2->getValid()) {
                 $$->setValid(false);
               }
               $1->addChild($2);
               $$ = $1;}
          ;
           
locvardecplus : locvardec
                  {$$ = new plusstarNode();
                   if(!$1->getValid()) {
                     $$->setValid(false);
                   }
                   $$->addChild($1);}
              | locvardecplus locvardec
                  {if(!$2->getValid()) {
                     $$->setValid(false);
                   }
                   $1->addChild($2);
                   $$ = $1;}
              ;
           
locvardec : type IDEN SEMI 
              {$$ = new locvardecNode($2->value);
               $$->addChild($1);
               delete $2;
               delete $3;}
          | type IDEN error 
              {cerr << endl << "Missing ';' after local variable identifier: line " 
                    << $2->lNum << endl << endl;
               $$ = new errorNode("<LocalVarDec>");
               $$->addChild($1);
               $$->setValid(false);
               delete $2;
               yyerrok;}
          ;
           
optexp : %empty
           {$$ = new optexpNode("empty");}
       | exp
           {$$ = new optexpNode("exp");
            if(!$1->getValid()) {
              $$->setValid(false);
            }
            $$->addChild($1);}
       ;
           
exp : name 
        {$$ = new expNode("name");
         if(!$1->getValid()) {
           $$->setValid(false);
         }
         $$->addChild($1);}
    | NUM
        {$$ = new expNode("num", $1->value);
         delete $1;}
    | NLL
        {$$ = new expNode("null");
         delete $1;}
    | name LPAREN RPAREN
        {$$ = new expNode("name paren");
         if(!$1->getValid()) {
           $$->setValid(false);
         }
         $$->addChild($1);
         delete $2;
         delete $3;}
    | name LPAREN error
        {cerr << endl << "Missing ')' after name declaration: line " 
              << $2->lNum << endl << endl;
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
        {cerr << endl << "Missing ')' after read: line " << $1->lNum << endl << endl;
         $$ = new errorNode("<Expression>");
         $$->setValid(false);
         delete $1;
         delete $2;
         yyerrok;}
    | READ error RPAREN
        {cerr << endl << "Missing '(' after read: line " << $1->lNum << endl << endl;
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
        {cerr << endl << "Missing ')' after expression: line " << $1->lNum << endl << endl;
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
           {cerr << endl << "Missing ')' after arglist for new expression: line " 
                 << $1->lNum << endl << endl;
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
              {$$ = new plusstarNode();}
          | brackstar DOUBBRACK
              {$1->addChild(new plusstarNode());
               $$ = $1;
               delete $2;}
          ;
          
expstar : %empty
            {$$ = new plusstarNode();}
        | expstar LBRACK exp RBRACK 
            {$1->addChild($3);
             $$ = $1;
             delete $2;
             delete $4;}
        | expstar LBRACK exp error
            {cerr << endl << "Missing ']' after new expression: line " 
                  << $2->lNum << endl << endl;
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
            {$$ = new plusstarNode();
             $$->addChild($1);} 
        | explist COMMA exp 
            {$1->addChild($3);
             $$ = $1;
             delete $2;}
        ;
  
name : THIS  
         {$$ = new nameNode("this", "");
          delete $1;}
     | IDEN 
         {$$ = new nameNode("id", $1->value);
          delete $1;}
     | name DOT IDEN 
         {$$ = new nameNode("dotid", $3->value);
          $$->addChild($1);;
          delete $2;
          delete $3;} 
     | name LBRACK exp RBRACK 
         {$$ = new nameNode("exp", "");
          $$->addChild($1);
          $$->addChild($3);
          delete $2;
          delete $4;}
     | name LBRACK exp error
         {cerr << endl << "Missing ']' after name: line " 
               << $2->lNum << endl << endl;
          $$ = new errorNode("<Name>");
          $$->setValid(false);
          $$->addChild($1);
          $$->addChild($3);
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
