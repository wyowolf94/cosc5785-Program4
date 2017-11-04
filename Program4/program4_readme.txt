Shaya Wolf
Program 4 Notes
11/3/2017

--> Start State 
I had a hard time deciding whether or not the forest should start with a
program tree and branch from there or if the whole program should be a forest
of ClassDec trees. I decided in the end to have a forest of ClassDecs. I also
don't allow for empty input. It throws and error and prints 
"---syntax error---" is all it prints.

--> "**#**" prints and Extra Lines
I included print outs of blank lines to break up what what printing out 
because the straight block of text was impossible to follow. I also print
out "**#**" between each Class Declaration to help keep track of where I am.
# is the nth class dec.

--> Grammar Additions 
These are the productions that I added to the grammar with a short description
as to what they do 

  1 - Dealing with Class Body 
      I break up class body based on combinations of empty sets then lead
      the rest to one or more of method declarations, constructor declarations
      and variable declarations 
  
        methdecplus: methoddec
                  | methdecplus methoddec

        constdecplus: constdec
                    | constdecplus constdec

        vardecplus: vardec
                  | vardecplus vardec

  2 - Dealing with ParameterList 
      I let paramlist go to empty and paramplus then paramplus creates a
      comma-separated list of one or more parameters
      
        paramstar: param
                | paramstar COMMA param

  3 - Dealing with Block
      I break block up based on combinations of empty sets then let it go
      to one or more statements followed by one or more local variable decs
      
        stateplus: statement
                | stateplus statement

        locvardecplus: locvardec
                    | locvardecplus locvardec

  4 - Dealing with New Expression
      I let "new simpleType" be followed by expstar then brackstar, each
      of which goes to one or more of itself. Brackstar creates zero or
      more empty brackets and expstar creates zero or more bracketed 
      expressions. 
      
        brackstar: %empty
                | brackstar DOUBBRACK

        expstar: %empty
              | expstar LBRACK exp RBRACK
              | expstar LBRACK exp error

  5 - Dealing with ArgList
      ArgList can be empty or a list of comma-separated expressions.
      
        explist: exp
              | explist COMMA exp

--> Grammar Subtractions
I ditched result type and doubled up on production in Method Declaration
to avoid shift-reduce errors.

  methoddec: type IDEN LPAREN paramlist RPAREN block
          | VOID IDEN LPAREN paramlist RPAREN block

--> Printing and Parse Tree Structure
I printed the leafs in parens so that I could keep track of what was going
on in the print outs. I tried to keep children going to there correct parent. 

  1 - Block
      I made Statements and LocalVarDecs children of Block rather than being
      children of stateplus and localvardecplus:
  
 <Statement> -> <Block>
 <Block> -> { <LocalVarDec> <LocalVarDec> <Statement> <Statement> <Statement> }

  2 - New Expression
      I made bracketed statements children of New Expression rather than being
      children of expstar and brackstar:
      
 <NewExpression> -> <SimpleType> [<Expression>] [<Expression>] [] [] [] 

  3 - Parameter List
      I made Parameters children of ParameterList so that I could handle
      epsilon like the grammar does, rather than making them children of
      Method Declaration:
      
 <MethodDeclaration> -> void identifier (iden) ( <ParameterList> ) <Block>
 <ParameterList> -> <Parameter> , <Parameter>
 
  4 - ArgList
      I made Expressions children of ArgList so that I could handle epsilon
      like the grammar does, rather than making them children of Statement:
     
 <Statement> -> <Name> ( <ArgList> ) ;
 <Name> -> identifier (name)
 <ArgList> -> <Expression> , <Expression> , <Expression>
        
  5 - Class Body
      I made Variable Declarations, Constructor Declarations, and Method
      Declarations children of Class Body rather than being children of
      vardecplus, constdecplus, and methdecplus:
      
 <ClassBody> -> { <VarDec> <VarDec> <ConstDec> <MethDec> }

--> Final Note: I submitted the error handling documentation in program4.txt
                because I had such a hard time getting an .odt/.pdf going 
                last time and it's already 6:30... sorry if this causes
                naming conflicts.