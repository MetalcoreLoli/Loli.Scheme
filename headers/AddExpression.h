#pragma once
#include "Expression.h"
#include "NumberExpression.h"
#include <string>

class AddExpression : public Expression
{
private:
public:
    bool IsReducible() override;
    Expression* Reduce() override;
	AddExpression();
    AddExpression(Expression* left, Expression* right);
	~AddExpression();
};
