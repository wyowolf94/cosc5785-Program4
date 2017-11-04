Shaya Wolf
Program 4 Notes
11/3/2017

--> Explain start state
I had a hard time deciding whether or not the forest should start with a program tree and
branch from there or if the whole program should be a forest of ClassDec trees. I decided
in the end to have a forest of ClassDecs. I also don't allow for empty input. It throws 
and error and prints "---syntax error---" is all it prints.

--> Explain "**" prints and extra lines

--> Explain Grammar additions 
-expplus
-brackplus
-locvardecplus
-stateplus
-explist
-vardecstar
-constdecstar
-methdecstar

--> Explain Grammar subtractions
-resulttype

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

--> Explain how class body prints

        {
          int iden1;
          type iden2;
          iden4(type1 iden1, int iden2){x=5;}
          rtype4 iden4(type1 iden1, int iden2){x=5;}
        }
        {}

        <ClassBody> -> { <VarDec> <VarDec> <ConstDec> <MethDec> }

        <VarDec> -> <Type> identifier (iden1) semi
        <Type> -> <SimpleType>
        <SimpleType> -> int

        <VarDec> -> <Type> identifier (iden2) semi
        <Type> -> <SimpleType>
        <SimpleType> -> identifier (type)

        <ConstDec> -> identifier (iden4) ( <ParameterList> ) <Block>
        <ParameterList> -> <Parameter> , <Parameter>

        <Parameter> -> <Type> identifier (iden1)
        <Type> -> <SimpleType>
        <SimpleType> -> identifier (type1)

        <Parameter> -> <Type> identifier (iden2)
        <Type> -> <SimpleType>
        <SimpleType> -> int

        <Block> -> { <Statement> }

        <Statement> -> <Name> = <Expression> ;
        <Name> -> identifier (x)
        <Expression> -> Number (5)

        <MethDec> -> <Type> identifier (iden4) ( <ParameterList> ) <Block>
        <Type> -> <SimpleType>
        <SimpleType> -> identifier (rtype4)
        <ParameterList> -> <Parameter> , <Parameter>

        <Parameter> -> <Type> identifier (iden1)
        <Type> -> <SimpleType>
        <SimpleType> -> identifier (type1)

        <Parameter> -> <Type> identifier (iden2)
        <Type> -> <SimpleType>
        <SimpleType> -> int

        <Block> -> { <Statement> }

        <Statement> -> <Name> = <Expression> ;
        <Name> -> identifier (x)
        <Expression> -> Number (5)

        ***

        <ClassBody> -> { }


--> Explain order things print in

--> print leaves in parens