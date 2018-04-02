#pragma once
#include <vector>
#include <initializer_list>
#include "lexer.h"

class RpnToken
{
protected:
	int _operand_num;
public:
	int operandNum() { return _operand_num; }
    virtual double calculate(std::initializer_list<double> operands) = 0;
};

typedef std::vector<RpnToken*> RpnList;

void RpnTrans(RpnList &list, TokenList &tokens);