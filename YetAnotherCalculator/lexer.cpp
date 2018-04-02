#include "lexer.h"
#include <cctype>

double GetNumber(std::string::const_iterator &start, const std::string &ori_str);

void Lexer(TokenList &list, const std::string &str)
{
	auto i = str.begin();
	while(i != str.end())
	{
		Token new_token = Token(TokenType::kEnd);

		if (isblank(*i))
		{
			i++;
			continue;
		}

		if (isdigit(*i) || *i == '.')
		{
			double val = GetNumber(i, str);
			new_token = Token(TokenType::kNumber, val);
		}
		else
		{
			TokenType type = TokenType::kEnd;
			switch (*i)
			{
			case '+':
				type = TokenType::kAdd;
				break;
			case '-':
				type = TokenType::kMinus;
				break;
			case '*':
				type = TokenType::kMutiply;
				break;
			case '/':
				type = TokenType::kDivision;
				break;
			case '(':
				type = TokenType::kLeftBracket;
				break;
			case ')':
				type = TokenType::kRightBracket;
				break;
			default:
				break;
			}
			new_token = Token(type);
			i++;
		}

		list.push_back(new_token);
	}

	list.push_back(Token(TokenType::kEnd));
}

double GetNumber(std::string::const_iterator &i, const std::string &ori_str)
{
	auto start = i;
	for (; i != ori_str.end(); i++)
	{
		if (!isdigit(*i))
		{
			break;
		}
	}

	if (i != ori_str.end() && *i == '.')
	{
		i++;
		for (; i != ori_str.end(); i++)
		{
			if (!isdigit(*i))
			{
				break;
			}
		}
	}

	return std::stod(ori_str.substr(std::distance(ori_str.begin(), start), std::distance(start, i)));
}