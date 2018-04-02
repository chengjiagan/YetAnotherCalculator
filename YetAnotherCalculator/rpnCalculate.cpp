#include "rpnCalculate.h"
#include "rpnOperations.h"
#include <stack>

double RpnCalculate(const RpnList & list)
{
    std::stack<double> numbers;
    double num_1 = 0.0, num_2 = 0.0;
    for (auto i = list.begin(); i != list.end(); i++)
    {

        switch ((*i)->operandNum())
        {
        case 0:
            numbers.push((*i)->calculate({}));
            break;
        case 1:
            num_1 = numbers.top();
            numbers.pop();
            numbers.push((*i)->calculate({ num_1 }));
            break;
        case 2:
            num_2 = numbers.top();
            numbers.pop();
            num_1 = numbers.top();
            numbers.pop();
            numbers.push((*i)->calculate({ num_1,num_2 }));
        }
    }
    return numbers.top();
}
