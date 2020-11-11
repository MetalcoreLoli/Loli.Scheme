#pragma once
#include "Token.h"
#include <string>

class Expression
{
private:
	Expression* m_right;
	Expression* m_left;
	Token* m_value;
public:
	Expression* GetRight() const {return m_right;}
	void SetRight(Expression* value) {m_right = value;}

	Expression* GetLeft() const {return m_left;}
	void SetLeft(Expression* value) {m_left = value;}

	Token* GetValue() const {return m_value;}
	void SetValue(Token* value) {m_value = value;}

	Expression();
	Expression(TokenType type);
	Expression(TokenType type, const std::string& value);
    Expression(TokenType type, Expression* left, Expression* right);

	~Expression();
};
