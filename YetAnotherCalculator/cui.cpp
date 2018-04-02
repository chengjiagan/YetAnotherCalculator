#include "cui.h"
#include "lexer.h"
#include "rpnTrans.h"
#include "rpnCalculate.h"
#include <iostream>
#include <string>

void Cui()
{
    while (true)
    {
        std::cout << ">";

        std::string str;
        std::getline(std::cin, str);

        std::string next_str;
        while ((*str.rbegin()) == '\\' )
        {
            std::cout << "\t";
            std::getline(std::cin, next_str);
            str.erase(str.end() - 1);
            str.append(next_str);
        }

        if (str == "exit")
        {
            break;
        }

        TokenList tokens;
        Lexer(tokens, str);

        RpnList rpn_list;
        RpnTrans(rpn_list, tokens);

        double ans = RpnCalculate(rpn_list);

        std::cout << "= " << ans << std::endl;
    }
}
