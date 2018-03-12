#include"lexer.h"
#include<cctype>

double GetNumber(std::string::const_iterator &start, const std::string &ori_str);

void Lexer(LexList &list, const std::string &str)
{
	auto i = str.begin();
	while(i != str.end())
	{
		LexWord new_word = LexWord(LexType::kEnd);

		if (isblank(*i))
		{
			i++;
			continue;
		}

		if (isdigit(*i) || *i == '.')
		{
			double val = GetNumber(i, str);
			new_word = LexWord(LexType::kNumber, val);
		}
		else
		{
			LexType type = LexType::kEnd;
			switch (*i)
			{
			case '+':
				type = LexType::kAdd;
				break;
			case '-':
				type = LexType::kMinus;
				break;
			case '*':
				type = LexType::kMutiply;
				break;
			case '/':
				type = LexType::kDivision;
				break;
			case '(':
				type = LexType::kLeftBracket;
				break;
			case ')':
				type = LexType::kRightBracket;
				break;
			default:
				break;
			}
			new_word = LexWord(type);
			i++;
		}

		list.push_back(new_word);
	}

	list.push_back(LexWord(LexType::kEnd));
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

	if (*i == '.')
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