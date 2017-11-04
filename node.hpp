// Shaya Wolf
// Program 4
// cosc5785 - Compilers
// 10/20/2017
// Based on node.hpp in Dr.Buckners
//   example on WyoCourses

#ifndef NODE_HPP
#define NODE_HPP

#include<iostream>
#include<string>
#include<vector>

using std::string;
using std::endl;
using std::ostream;
using std::vector;
using std::cout;

// Base Class
class Node 
{
  public:
    vector<Node*> children;
  // Constructor
  Node() {
    reset();
    ival = 0;
    dval = 0;
    valid = true;
  }

  // Destructor
  virtual ~Node() {
    //while(!children.empty()) {
      //children.pop_back();
    //}
    for(unsigned int i = 0; i < children.size(); i++) {
      delete children[i]; 
    }
  }

  // Get Functions
  int    getint()   const { return ival; }

  double getdbl()   const { return dval; }

  string getstr()   const { return sval; }
  
  bool   getValid() const { return valid;}

  // Set Functions
  void setVal(int i)          { ival = i; }

  void setVal(double d)       { dval = d; }

  void setVal(const string s) { sval = s; }

  void setVal(const char * c) { sval = c; }
  
  void setValid(const bool b) { valid = b; }

  // Reset
  void reset() {
    lnum = 1;
    cnum = 1;
    sval.clear();
  } 
  
  // Get a Child
  Node* getChild(unsigned index) {
    return children[index];
  }

  // Set a Child
  void setChild(Node *c, unsigned index){
    children[index] = c;
    return;
  }
  
  void addChild(Node *c) {
    if(c != 0) {
      children.push_back(c);
    }
    return;
  }

  // Print Node
  virtual void printNode(ostream * out = 0) {
    *out << sval;
    for(unsigned i = 0; i < children.size(); i++) {
      children[i]->printNode(out);
    }
    return;
  }

  protected:
    int lnum;
    int cnum;

    int ival;
    double dval;
    string sval;

    bool valid;
};

// Node Types ////////////////////////////////////////////
class nodeClass : public Node 
{
  public:
    nodeClass(string t) : Node () {
      type = t;
    } 

    virtual void printNode(ostream * out = 0) {
      // Some stuff
    }
  private:
    string type;
}; 
/////////// inheritence template //////////////////////////

// Node used for all errors so far
class errorNode : public Node 
{
  public:
    errorNode(string er) : Node () {
      errorRed = er;
    } 

    virtual void printNode(ostream * out = 0) {
      cout << errorRed << " -> *** Error Node ***" << endl;
    }
  private:
    string errorRed;
}; 

// Constructor Declaration node that goes to iden ( paramlist ) block
class constdecNode : public Node 
{
  public:
    constdecNode(string i) : Node () {
      id = i;
    } 

    virtual void printNode(ostream * out = 0) {
      cout << endl << "<ConstructorDeclaration> -> identifier (" << id
           << ") ( <ParameterList> ) <Block>" << endl;
      children[0]->printNode();
      children[1]->printNode();
    }
  private:
    string id;
}; 

// Method Declaration node that goes to resulttype iden ( paramlist ) block
class methoddecNode : public Node 
{
  public:
    methoddecNode(string i) : Node () {
      id = i;
    } 

    virtual void printNode(ostream * out = 0) {
      cout << "<MethodDeclaration> -> <ResultType> identifier (" << id
           << ") ( <ParameterList> ) <Block>" << endl;
      children[0]->printNode();
      children[1]->printNode();
      children[2]->printNode();
    }
  private:
    string id;
}; 

// resulttype node that goes to typeNode or token void
class resulttypeNode : public Node 
{
  public:
    resulttypeNode(string t) : Node () {
      type = t;
    } 

    virtual void printNode(ostream * out = 0) {
      if(type == "type") {
        cout << "<ResultType> -> <Type>" << endl;
        children[0]->printNode();
      } else if(type == "void") {
        cout << "<ResultType> -> void" << endl;
      } else {
        cout << "resulttype problem" << endl;
      }
    }
  private:
    string type;
};

// paramlistNode that goes to empty or a paramstarNode
class paramlistNode : public Node 
{
  public:
    paramlistNode(string t) : Node () {
      type = t;
    } 

    void printParamList() {
        cout << "<ParameterList> -> ";
        for(unsigned int i = 0; i < children[0]->children.size() - 1; i++) {
          cout << "<Parameter> , ";
        }
        cout << "<Parameter>" << endl;
    }
    
    void printChildren() {
        for(unsigned int i = 0; i < children[0]->children.size(); i++) {
          children[0]->children[i]->printNode();
        }
    }
    
    virtual void printNode(ostream * out = 0) {
      if(type == "empty") {
        cout << "<ParameterList> -> epsilon" << endl;
      } else if (type == "rec") {
        printParamList();
        printChildren();
      } else {
        cout << "paramlist problem" << endl;
      }
    }
  private:
    string type;
}; 

// paramstarNode that goes to one or more comma separated parameters
class paramstarNode : public Node 
{
  public:
    paramstarNode() : Node () {
      // Nada
    } 

    virtual void printNode(ostream * out = 0) {
      // Don't print anything
    }
}; 

// param node which just goes to a type identifier
class paramNode : public Node 
{
  public:
    paramNode(string i) : Node () {
      id = i;
    } 

    virtual void printNode(ostream * out = 0) {
      cout << endl << "<Parameter> -> <Type> identifier (" << id << ")" << endl;
      children[0]->printNode();
    }
  private:
    string id;
}; 

// Statement Node ... for now just a simple statement
class statementNode : public Node 
{
  public:
    statementNode(string t) : Node () {
      type = t;
    } 

    virtual void printNode(ostream * out = 0) {
      cout << endl;
      if(type == "semi") {
        cout << "<Statement> -> ;" << endl;
      } else if(type == "nameeq") {
        cout << "<Statement> -> <Name> = <Expression> ;" << endl;
        children[0]->printNode();
        children[1]->printNode();
      } else if(type == "namearglist") {
        cout << "<Statement> -> <Name> ( <ArgList> ) ;" << endl;
        children[0]->printNode();
        children[1]->printNode();
      } else if(type == "printarglist") {
        cout << "<Statement> -> print ( <ArgList> ) ;" << endl;
        children[0]->printNode();
      }else if(type == "cond") {
        cout << "<Statement> -> <ConditionalStatement>" << endl;
        children[0]->printNode();
      } else if(type == "while") {
        cout << "<Statement> -> while ( <Expression> ) <Statement>" << endl;
        children[0]->printNode();
        children[1]->printNode();
      } else if(type == "optexp") {
        cout << "<Statement> -> return <OptionalExpression> ;" << endl;
        children[0]->printNode();
      } else if (type == "block") {
        cout << "<Statement> -> <Block>" << endl;
        children[0]->printNode();
      } else {
        cout << endl << "statement problem" << endl;
      }
    }
  private:
    string type;
};

// ConditionalStatementNode goes to an if statement or an if-else statement
class condstatementNode : public Node 
{
  public:
    condstatementNode(string t) : Node () {
      type = t;
    } 

    virtual void printNode(ostream * out = 0) {
      if(type == "if") {
        cout << "<ConditionalStatement> -> if ( <Expression> ) <Statement>" << endl;
        children[0]->printNode();
        children[1]->printNode();
      } else if(type == "if-else") {
        cout << "<ConditionalStatement> -> if ( <Expression> ) <Statement> " 
             << "else <Statement>" << endl;
        children[0]->printNode();
        children[1]->printNode();
        children[2]->printNode();
      } else {
        cout << "conditional statement problem" << endl;
      }
    }
  private:
    string type;
};

// Block Node goes to any number of vardecs followed by any number of statements
class blockNode : public Node 
{
  public:
    blockNode(string t) : Node () {
      type = t;
    } 
    
    void printBlock(string nonterm) {
        cout << "<Block> -> { ";
        for(unsigned int i = 0; i < children[0]->children.size(); i++) {
          cout << "<" << nonterm << "> ";
        }
        cout << "}" << endl;
    }
    
    void printBlock() {
        cout << "<Block> -> { ";
        for(unsigned int i = 0; i < children[0]->children.size(); i++) {
          cout << "<LocalVarDec> ";
        }
        for(unsigned int i = 0; i < children[1]->children.size(); i++) {
          cout << "<Statement> ";
        }
        cout << "}" << endl;
    }
    
    void printChildren(int index) {
        for(unsigned int i = 0; i < children[index]->children.size(); i++) {
          children[index]->children[i]->printNode();
        }
    }

    virtual void printNode(ostream * out = 0) {
      cout << endl;
      if(type == "empty") {
        cout << "<Block> -> { }" << endl;
      } else if (type == "locvardecs") {
        printBlock("LocalVarDec");
        printChildren(0);
      } else if (type == "statements") {
        printBlock("Statement");
        printChildren(0);
      } else if (type == "both") {
        printBlock();
        printChildren(0);
        printChildren(1);
      } else {
        cout << "block problem" << endl;
      }
    }
  private:
    string type;
};

// statestar Node with just prints any number of statements
class stateplusNode : public Node 
{
  public:
    stateplusNode() : Node () {
      type = "";
    } 

    virtual void printNode(ostream * out = 0) {
      // Nothing Prints
    }
  private:
    string type;
}; 

// LocalVarDecStar Node with just print  one or more locvardecNodes
class locvardecplusNode : public Node 
{
  public:
    locvardecplusNode() : Node () {
      type = "";
    } 

    virtual void printNode(ostream * out = 0) {
      // Nothing Prints 
    }
  private:
    string type;
}; 


// LocalVarDec Node with just prints type identifier;
class locvardecNode : public Node 
{
  public:
    locvardecNode(string i) : Node () {
      id = i;
    } 

    virtual void printNode(ostream * out = 0) {
      cout << endl;
      cout << "<LocalVarDec> -> <Type> identifier (" << id << ") ;" << endl;
      children[0]->printNode();
    }
  private:
    string id;
}; 

// Optional Expression Node that goes to epsilon or exp
class optexpNode : public Node 
{
  public:
    optexpNode(string t) : Node () {
      type = t;
    } 

    virtual void printNode(ostream * out = 0) {
      if(type == "empty") {
        cout << "<OptionalExpression> -> epsilon" << endl;
      } else if (type == "exp") {
        cout << "<OptionalExpression> -> <Expression>" << endl;
        children[0]->printNode();
      } else {
        cout << "optional expression problem" << endl;
      }
    }
  private:
    string type;
}; 

// Expression Op Node where t tells us what kind of expression it is
class expNode : public Node 
{
  public:
    expNode(string t) : Node () {
      expType = t;
      num = 0;
    } 
    
    expNode(string t, string n) : Node () {
      expType = t;
      num = atoi(n.c_str());
    }

    virtual void printNode(ostream * out = 0) {
      if(expType == "relop" || expType == "sumop"
           || expType == "proop") {
        cout << "<Expression> -> <Expression>";
        children[1]->printNode();
        cout << "<Expression>";
        cout << endl;
        children[0]->printNode();
        children[2]->printNode();
      } else if (expType == "unyop") {
        cout << "<Expression> -> ";
        children[0]->printNode();
        cout << " <Expression>";
        cout << endl;
        children[1]->printNode();
      } else if (expType == "name") {
        cout << "<Expression> -> <Name>" << endl;
        children[0]->printNode();
      } else if (expType == "name paren") {
        cout << "<Expression> -> <Name> ()" << endl;
        children[0]->printNode();
      } else if (expType == "read") {
        cout << "<Expression> -> read ()" << endl;;
      } else if (expType == "newexp") {
        cout << "<Expression> -> <NewExpression>" << endl;
        children[0]->printNode();
      } else if (expType == "paren") {
        cout << "<Expression) -> ( <Expression> )" << endl;
        children[0]->printNode();
      } else if (expType == "null") {
        cout << "<Expression> -> null" << endl;
      } else if (expType == "num") {
        cout << "<Expression> -> Number (" << num << ")" << endl;
      }  else {
        cout << "expression problem" << endl;
      }
    }
  private:
    string expType;
    int num;
}; 

// NewExpression node 
class newexpNode : public Node 
{
  public:
    newexpNode(string t) : Node () {
      type = t;
      id = "";
    }
    
    newexpNode(string t, string i) : Node () {
      type = t;
      id = i;
    } 
    
    void printNewExp() {
        cout << "<NewExpression> -> <SimpleType> ";
        for(unsigned int i = 0; i < children[1]->children.size(); i++) {
          cout << "[<Expression>] ";
        }
        for(unsigned int i = 0; i < children[2]->children.size(); i++) {
          cout << "[] ";
        }
        cout << endl;
    }
    
    void printChildren(int index) {
        for(unsigned int i = 0; i < children[index]->children.size(); i++) {
          children[index]->children[i]->printNode();
        }
    }

    virtual void printNode(ostream * out = 0) {
      if(type == "parens") {
        cout << "<NewExpression> -> new identifier (" << id 
             << ") ( <ArgList> )" << endl;
        children[0]->printNode();
      } else if(type == "empty") {
        cout << "<NewExpression> -> new <SimpleType>" << endl;
        children[0]->printNode();
      } else if(type == "bracks") {
        printNewExp();
        children[0]->printNode();
        printChildren(1);
        printChildren(2);
      } else {
        cout << "new expression problem" << endl;
      }
    }
  private:
    string type;
    string id;
}; 

// brackstar node goes to one or more bracket pairs
class brackstarNode : public Node 
{
  public:
    brackstarNode() : Node () {
      type = "";
    } 

    virtual void printNode(ostream * out = 0) {
      // Don't print anything
    }
  private:
    string type;
}; 

// expstar node goes to one or more bracketed expressions
class expstarNode : public Node 
{
  public:
    expstarNode() : Node () {
      type = "";
    } 

    virtual void printNode(ostream * out = 0) {
      // Don't print anything
    }
  private:
    string type;
}; 

// argList node that either prints to epsilon or to expList
class arglistNode : public Node 
{
  public:
    arglistNode(string t) : Node () {
      type = t;
    } 

    void printArgList() {
        cout << "<ArgList> -> ";
        for(unsigned int i = 0; i < children[0]->children.size() - 1; i++) {
          cout << "<Expression> , ";
        }
        cout << "<Expression>" << endl;
    }
    
    void printChildren() {
        for(unsigned int i = 0; i < children[0]->children.size(); i++) {
          children[0]->children[i]->printNode();
        }
    }
    
    virtual void printNode(ostream * out = 0) {
      if(type == "empty") {
        cout << "<ArgList> -> epsilon" << endl;
      } else if (type == "rec") {
        printArgList();
        printChildren();
      } else {
        cout << "arglist problem" << endl;
      }
    }
  private:
    string type;
}; 

// expList Node that builds comma-separated lists of expressions
class explistNode : public Node 
{
  public:
    explistNode() : Node () {
      type = "";
    } 
    
    virtual void printNode(ostream * out = 0) {
      // Don't print anything
    }
  private:
    string type;
}; 

// Name Node
class nameNode : public Node 
{
  public:
    nameNode(string t, string i) : Node () {
      type = t;
      id = i;
    } 

    virtual void printNode(ostream * out = 0) {
      cout << "<Name> -> ";
      if(type == "this") {
        cout << "this" << endl;
      } else if (type == "id") {
        cout << "identifier (" << id << ")" << endl;
      } else if (type == "dotid") {
        cout << "<Name> . identifier (" << id << ")" << endl;
        children[0]->printNode();
      } else if (type == "exp") {
        cout << "<Name> [ <Expression> ]" << endl;
        children[0]->printNode();
        children[1]->printNode();
      } else {
        cout << "name problem" << endl;
      }
    }
  private:
    string type;
    string id;
}; 

// VarDec Node which just needs to print <VarDec>
class varDecNode : public Node 
{
  public:
    varDecNode(string i) : Node () {
      identifier = i;
    } 

    virtual void printNode(ostream * out = 0) {
      cout << endl << "<VarDeclaration> -> <Type> identifier (" 
           << identifier << ") semi" << endl;
      children[0]->printNode();
    }
  private:
    string identifier;
}; 

// Type node where t defines either a simpleType or a 
// recursive type [] 
class typeNode : public Node 
{
  public:
    typeNode(string t) : Node () {
      type = t;
    } 

    virtual void printNode(ostream * out = 0) {
      cout << "<Type> -> ";
      if(type == "simpleType") {
        cout << "<SimpleType>" << endl;
        children[0]->printNode();
      } else if (type == "type") {
        cout << "<Type> []" << endl;
        children[0]->printNode();
      } else {
        cout << "type problem" << endl;
      }
    }
  private:
    string type;
}; 

// SimpleType Node which right now is just int
class simpleTypeNode : public Node 
{
  public:
    simpleTypeNode(string t, string i) : Node () {
      type = t;
      id = i;
    } 

    virtual void printNode(ostream * out = 0) {
      if(type == "int") {
        cout << "<SimpleType> -> " << type << endl; 
      } else if (type == "id") {
        cout << "<SimpleType> -> identifier (" << id << ")" << endl;
      } else {
        cout << "simpleType problem" << endl;
      }
    }
  private:
    string type;
    string id;
}; 

// Product Op Node where t tells us what kind of operator it is
class proopNode : public Node 
{
  public:
    proopNode(string t) : Node () {
      type = t;
    } 

    virtual void printNode(ostream * out = 0) {
      cout << " " << type << " ";
    }
    
  private:
    string type;
};

// Sum Op Node where t tells us what kind of operator it is
class sumopNode : public Node 
{
  public:
    sumopNode(string t) : Node () {
      type = t;
    } 

    virtual void printNode(ostream * out = 0) {
      cout << " " << type << " ";
    }
    
  private:
    string type;
};

// Relation Op Node where t tells us what kind of operator it is
class relopNode : public Node 
{
  public:
    relopNode(string t) : Node () {
      type = t;
    } 

    virtual void printNode(ostream * out = 0) {
      cout << " " << type << " ";
    }
    
  private:
    string type;
}; 

// Unary Op Node where t tells us what kind of operator it is
class unyopNode : public Node 
{
  public:
    unyopNode(string t) : Node () {
      type = t;
    } 

    virtual void printNode(ostream * out = 0) {
      cout << type;
    }
    
  private:
    string type;
};

#endif
