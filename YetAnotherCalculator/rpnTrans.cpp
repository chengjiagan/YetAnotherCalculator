#include "rpnTrans.h"
#include "rpnOperations.h"

int Precedence(TokenType type);
RpnToken* TokenToRpnToken(Token &token);
void ChangeBracket(Token &token);

void RpnTrans(RpnList & list, TokenList & tokens)
{
    TokenList operations;
    operations.push_back(Token(TokenType::kHash));
	for (auto token_iter = tokens.begin(); token_iter != tokens.end(); token_iter++)
	{
		if (token_iter->type() == TokenType::kNumber)
		{
			list.push_back(new RpnNumber(token_iter->value()));
		}
		else
		{
            if (Precedence(operations.rbegin()->type()) < Precedence(token_iter->type()))
            {
                ChangeBracket(*token_iter);
                operations.push_back(*token_iter);
            }
            else
            {
                while(true)
                {
                    auto i = operations.rbegin();
                    if (i == operations.rend() || Precedence(i->type()) < Precedence(token_iter->type()))
                    {
                        break;
                    }
                    else
                    {
                        RpnToken *rpn_token = TokenToRpnToken(*i);
                        list.push_back(rpn_token);
                        operations.pop_back();
                    }
                }

                if (token_iter->type() == kRightBracket)
                {
                    operations.pop_back();
                }
                else
                {
                    operations.push_back(*token_iter);
                }
            }
		}
	}
}

int Precedence(TokenType type)
{
    switch (type)
    {
    case TokenType::kEnd:
        return -1;
    case TokenType::kAdd:
    case TokenType::kMinus:
        return 1;
    case TokenType::kMutiply:
    case TokenType::kDivision:
        return 2;
    case TokenType::kRightBracket:
        return 0;
    case TokenType::kLeftBracket:
        return 1000;
    case TokenType::kHash:
        return -2;
    default:
        return -1000;
    }
}

RpnToken* TokenToRpnToken(Token &token)
{
    switch (token.type())
    {
    case TokenType::kAdd:
        return new RpnOperAdd();
    case TokenType::kMinus:
        return new RpnOperMinus();
    case TokenType::kMutiply:
        return new RpnOperMultipy();
    case TokenType::kDivision:
        return new RpnOperDivision();
    default:
        return nullptr;
    }
}

void ChangeBracket(Token &token)
{
    if (token.type() == TokenType::kLeftBracket)
    {
        token.changeType(TokenType::kEnd);
    }
}
