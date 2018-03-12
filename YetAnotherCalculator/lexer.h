#pragma once
#include<vector>
#include<string>

enum LexType
{
	kEnd,
	kNumber,
	kAdd,
	kMinus,
	kMutiply,
	kDivision,
	kRightBracket,
	kLeftBracket
};

class LexWord
{
private:
	LexType _type;
	double _value;
public:
	LexWord(LexType type, double value) : _type(type), _value(value) {}
	LexWord(LexType type) :_type(type), _value(0.0) {}
	friend void testLexer(const std::string &str);
};

typedef std::vector<LexWord> LexList;

void Lexer(LexList &list, const std::string &str);
