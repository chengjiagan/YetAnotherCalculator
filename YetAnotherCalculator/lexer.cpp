#include<vector>
#include<string>

enum LexType
{
	//TODO
};

class LexWord
{
private:
	LexType _type;
	double _value;
public:
	LexWord(LexType type, std::string ori_str);
	LexWord(LexType type) :_type(type), _value(0.0){};
};

typedef std::vector<LexWord> LexList;

void Lexer(LexList &list, std::string str);