#pragma once
#include <vector>
#include <string>

enum TokenType
{
	kEnd,
	kNumber,
	kAdd,
	kMinus,
	kMutiply,
	kDivision,
	kRightBracket,
	kLeftBracket,
    kHash
};

class Token
{
private:
	TokenType _type;
	double _value;
public:
	Token(TokenType type, double value) : _type(type), _value(value) {}
	Token(TokenType type) :_type(type), _value(0.0) {}
	TokenType type() { return _type; }
	double value() { return _value; }
    void changeType(TokenType type) { _type = type; }
};

typedef std::vector<Token> TokenList;

void Lexer(TokenList &list, const std::string &str);
