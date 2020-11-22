#pragma once
#include "Expression.h"

class NumberExpression : public Expression
{
private:
public:
    bool IsReducible() override;
    Expression* Reduce() override;
	NumberExpression(std::string value);
	~NumberExpression();
};
