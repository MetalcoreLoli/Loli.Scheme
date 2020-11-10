#pragma once
#include <string>

enum class TokenType {Add, Sub, Mul, Div, Lp, Rp, Num};
class Token
{
private:
	std::string m_value;
	TokenType m_type;
public:
	std::string GetValue() const {return m_value;}
	void SetValue(std::string value) {m_value = value;}
	TokenType GetType() const {return m_type;}
	void SetType(TokenType value);
	Token(TokenType type);
	Token(TokenType type, const std::string& value);
};
