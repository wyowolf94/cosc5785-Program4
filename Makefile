##
# Shaya Wolf
# Makefile
# Compilers - Program 4
# 11/1/2017
##

CXX=g++
CXXFLAGS=-std=c++11 -ggdb -Wall
LEX=flex++
LEXFLAGS=--warn
YACC=bison
YACCFLAGS=--report=state -W -d

.PHONY: clean

program4: program4.tab.c program4.tab.h program4_lex.cpp program4.cpp attributes.h node.hpp 
	${CXX} ${CXXFLAGS} program4.cpp program4.tab.c program4_lex.cpp attributes.cpp -o program4

program4.tab.c : program4.y node.hpp attributes.h
	${YACC} ${YACCFLAGS} program4.y

program4_lex.cpp: program4.lpp node.hpp
	${LEX} ${LEXFLAGS} program4.lpp

clean: 
	/bin/rm -f *.o a.out core.* program4 program4_lex.cpp program4.tab.*
