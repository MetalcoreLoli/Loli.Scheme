#pragma once
#include "Token.h"
#include <string>

struct IExpression {
    virtual bool IsReducible() = 0;
    virtual IExpression* Reduce() = 0;
};

class Expression 
{
protected:
	Token* m_value;
public:
	Expression* m_right;
	Expression* m_left;
	Expression* GetRight() const {return m_right;}
	void SetRight(Expression* value) {m_right = value;}

	Expression* GetLeft() const {return m_left;}
	void SetLeft(Expression* value) {m_left = value;}

	Token* GetValue() const {return m_value;}
	void SetValue(Token* value) {m_value = value;}

    virtual bool IsReducible() ; 
    virtual Expression* Reduce();

	Expression();
	Expression(TokenType type);
	Expression(TokenType type, const std::string& value);
    Expression(TokenType type, Expression* left, Expression* right);

	~Expression();
};
