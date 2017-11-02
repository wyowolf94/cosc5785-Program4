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

    vector<Node*> children;
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

// Statement Node ... for now just a simple statement
class statementNode : public Node 
{
  public:
    statementNode(string t) : Node () {
      type = t;
    } 

    virtual void printNode(ostream * out = 0) {
      if(type == "nameeq") {
        cout << endl << "<Statement> -> <Name> = <Expression> ;" << endl;
        children[0]->printNode();
        children[1]->printNode();
      } else if(type == "optexp") {
        cout << endl << "<Statement> -> return <OptionalExpression> ;" << endl;
        children[0]->printNode();
      } else if (type == "block") {
        cout << endl << "<Statement> -> <Block>" << endl;
        children[0]->printNode();
      } else {
        cout << endl << "oh no good lord hey kids" << endl;
      }
    }
  private:
    string type;
};

// Block Node goes to type identifier semicolon
class blockNode : public Node 
{
  public:
    blockNode() : Node () {
      id = "";
    } 

    virtual void printNode(ostream * out = 0) {
       cout << "<Block> -> { <LocalVarDecStar> <StateStar> }" << endl;
       children[0]->printNode();
       children[1]->printNode();
    }
  private:
    string id;
};

// statestar Node with just prints any number of statements
class statestarNode : public Node 
{
  public:
    statestarNode(string t) : Node () {
      type = t;
    } 

    virtual void printNode(ostream * out = 0) {
      if(type == "empty") {
        cout << "<StateStar> -> epsilon" << endl;
      } else if(type == "rec") {
        cout << "<StateStar> -> <StateStar> <Statement>" << endl;
        children[0]->printNode();
        children[1]->printNode();
      } else {
        cout << "it's going to be fine" << endl;
      }
    }
  private:
    string type;
}; 

// LocalVarDecStar Node with just prints any number of locvardecNodes
class locvardecstarNode : public Node 
{
  public:
    locvardecstarNode(string t) : Node () {
      type = t;
    } 

    virtual void printNode(ostream * out = 0) {
      if(type == "empty") {
        cout << "<LocalVarDecStar> -> epsilon" << endl;
      } else if(type == "rec") {
        cout << "<LocalVarDecStar> -> <LocalVarDecStar> <LocalVarDec>" << endl;
        children[0]->printNode();
        children[1]->printNode();
      } else {
        cout << "definitely going to get this done" << endl;
      }
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
        cout << "so tired. need to finish this. " << endl;
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
        cout << "Something really bad happened :'(" << endl;
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

    virtual void printNode(ostream * out = 0) {
      if(type == "parens") {
        cout << "<NewExpression> -> new identifier (" << id 
             << ") ( <ArgList> )" << endl;
        children[0]->printNode();
      } else if (type == "bracks") {
        cout << "<NewExpression> -> new <SimpleType> <expstar> <brackstar> " 
             << endl;
        children[0]->printNode();
        children[1]->printNode();
        children[2]->printNode();
      } else {
        cout << "oh my god holy hell what is happening" << endl;
      }
    }
  private:
    string type;
    string id;
}; 

// brackstar node because fancy feast
class brackstarNode : public Node 
{
  public:
    brackstarNode(string t) : Node () {
      type = t;
    } 

    virtual void printNode(ostream * out = 0) {
      if(type == "empty") {
        cout << "<brackstar> -> epsilon" << endl;
      } else if (type == "rec") {
        cout << "<brackstar> -> <brackstar> []" << endl;
        children[0]->printNode();
      } else {
        cout << "los problemos es loco" << endl;
      }
    }
  private:
    string type;
}; 

// expstar node because fancy feast
class expstarNode : public Node 
{
  public:
    expstarNode(string t) : Node () {
      type = t;
    } 

    virtual void printNode(ostream * out = 0) {
      if(type == "empty") {
        cout << "<expstar> -> epsilon" << endl;
      } else if (type == "rec") {
        cout << "<expstar> -> <expstar> [<Expression>]" << endl;
        children[0]->printNode();
        children[1]->printNode();
      } else {
        cout << "panic" << endl;
      }
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

    virtual void printNode(ostream * out = 0) {
      if(type == "empty") {
        cout << "<ArgList> -> epsilon" << endl;
      } else if (type == "rec") {
        cout << "<ArgList> -> <explist>" << endl;
        children[0]->printNode();
      } else {
        cout << "some problem message" << endl;
      }
    }
  private:
    string type;
}; 

// expList Node that builds comma-separated lists of expressions
class explistNode : public Node 
{
  public:
    explistNode(string t) : Node () {
      type = t;
    } 

    virtual void printNode(ostream * out = 0) {
      if(type == "exp") {
        cout << "<explist> -> <Expression>" << endl;
        children[0]->printNode();
      } else if (type == "rec") {
        cout << "<explist> -> <explist> , <Expression>" << endl;
        children[0]->printNode();
        children[1]->printNode();
      } else {
        cout << "trouble" << endl;
      }
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
        cout << "Bad news bears" << endl;
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
        cout << "This was unexpected" << endl;
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
        cout << "This is bad" << endl;
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
