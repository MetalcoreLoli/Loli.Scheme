#pragma once
#include <string>

enum class TokenType {Add = 0, Sub = 1, Mul = 2, Div = 3, Lp = 4, Rp = 5, Num = 6};
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

    bool IsOperation() {return TokenType::Add <= m_type && m_type <= TokenType::Num;}

	Token(TokenType type);
	Token(TokenType type, const std::string& value);
};
