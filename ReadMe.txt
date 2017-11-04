Shaya Wolf
Program 4 Notes
11/3/2017

--> Explain "**" prints

--> Explain Grammar additions 
-expplus
-brackplus
-locvardecplus
-stateplus
-explist

--> Explain how block prints and why I didn't make direct children of block (keep sep)

{type1 name1;
type2 name2;
name1 = 4+5;
name2 = bill;
bill = 4;}

<Statement> -> <Block>
<Block> -> { <LocalVarDec> <LocalVarDec> <Statement> <Statement> <Statement> }

<LocalVarDec> -> <Type> identifier (name1) ;
<Type> -> <SimpleType>
<SimpleType> -> identifier (type1)

<LocalVarDec> -> <Type> identifier (name2) ;
<Type> -> <SimpleType>
<SimpleType> -> identifier (type2)

<Statement> -> <Name> = <Expression> ;
<Name> -> identifier (name1)
<Expression> -> <Expression> + <Expression>
<Expression> -> Number (4)
<Expression> -> Number (5)

<Statement> -> <Name> = <Expression> ;
<Name> -> identifier (name2)
<Expression> -> <Name>
<Name> -> identifier (bill)

<Statement> -> <Name> = <Expression> ;
<Name> -> identifier (bill)
<Expression> -> Number (4)

--> Explain how newexp prints and why I didn't make direct children of newexp (keep sep)

{name = new type[4][5+6][][][];}

<Statement> -> <Block>
<Block> -> { <Statement> }

<Statement> -> <Name> = <Expression> ;
<Name> -> identifier (name)
<Expression> -> <NewExpression>
<NewExpression> -> <SimpleType> [<Expression>] [<Expression>] [] [] [] 
<SimpleType> -> identifier (type)
<Expression> -> Number (4)
<Expression> -> <Expression> + <Expression>
<Expression> -> Number (5)
<Expression> -> Number (6)

--> Explain how arglist and paramlist prints and 
why I left epsilon alone (in grammar like in opt exp)

name ();
name (1+5, 6, bill);

<Statement> -> <Name> ( <ArgList> ) ;
<Name> -> identifier (name)
<ArgList> -> epsilon

***

<Statement> -> <Name> ( <ArgList> ) ;
<Name> -> identifier (name)
<ArgList> -> <Expression> , <Expression> , <Expression>
<Expression> -> <Expression> + <Expression>
<Expression> -> Number (1)
<Expression> -> Number (5)
<Expression> -> Number (6)
<Expression> -> <Name>
<Name> -> identifier (bill)

void iden (type1 iden1, type2 iden2) {x=5;}
iden () {}

<MethodDeclaration> -> <ResultType> identifier (iden) ( <ParameterList> ) <Block>
<ResultType> -> void
<ParameterList> -> <Parameter> , <Parameter>

<Parameter> -> <Type> identifier (iden1)
<Type> -> <SimpleType>
<SimpleType> -> identifier (type1)

<Parameter> -> <Type> identifier (iden2)
<Type> -> <SimpleType>
<SimpleType> -> identifier (type2)

<Block> -> { <Statement> }

<Statement> -> <Name> = <Expression> ;
<Name> -> identifier (x)
<Expression> -> Number (5)

***

<ConstructorDeclaration> -> identifier (iden) ( <ParameterList> ) <Block>
<ParameterList> -> epsilon

<Block> -> { }

--> Explain order things print in

--> print leaves in parens