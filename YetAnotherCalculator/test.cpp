#include"test.h"
#include"lexer.h"
#include<iostream>
#include<string>

void testLexer(const std::string & str)
{
	LexList list;
	Lexer(list, str);
	for (auto i = list.begin(); i != list.end(); i++)
	{
		std::string type_str[] = { "End", "Number", "+", "-", "*", "/", ")", "(" };
		std::cout << type_str[i->_type] << '\t' << i->_value << std::endl;
	}
}
