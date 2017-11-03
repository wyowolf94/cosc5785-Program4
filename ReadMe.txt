Shaya Wolf
Program 4 Notes
11/3/2017

--> Add/Explain "**" prints

--> Explain Grammar additions
-expplus
-brackplus
-locvardecplus
-stateplus

--> Explain how block prints and why I didn't make direct children of block

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

--> Explain how newexp prints and why I didn't make direct children of newexp


--> Explain order things print in

