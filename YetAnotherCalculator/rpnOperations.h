#pragma once
#include "rpnTrans.h"

class RpnNumber :public RpnToken
{
private:
    double _value;
public:
    double calculate(std::initializer_list<double> operands) { return _value; }
    RpnNumber(double value) : _value(value)
    {
        _operand_num = 0;
    }
};


class RpnOperAdd :public RpnToken
{
public:
    double calculate(std::initializer_list<double> operands)
    {
        auto oper = operands.begin();
        return *oper + *(oper + 1);
    }
    RpnOperAdd()
    {
        _operand_num = 2;
    }
};

class RpnOperMinus :public RpnToken
{
public:
    double calculate(std::initializer_list<double> operands)
    {
        auto oper = operands.begin();
        return *oper - *(oper + 1);
    }
    RpnOperMinus()
    {
        _operand_num = 2;
    }
};

class RpnOperMultipy :public RpnToken
{
public:
    double calculate(std::initializer_list<double> operands)
    {
        auto oper = operands.begin();
        return *oper * *(oper + 1);
    }
    RpnOperMultipy()
    {
        _operand_num = 2;
    }
};

class RpnOperDivision :public RpnToken
{
public:
    double calculate(std::initializer_list<double> operands)
    {
        auto oper = operands.begin();
        return *oper / *(oper + 1);
    }
    RpnOperDivision()
    {
        _operand_num = 2;
    }
};