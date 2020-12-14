#pragma once
#include "Expression.h"
#include "AddExpression.h"
#include "NumberExpression.h"


class ExpressionTree
{
private:
	Expression* m_root;
public:
	Expression* Root() const {return m_root;}
	void SetRoot(Expression* value) {m_root = value;}

    ExpressionTree& Insert(const Token& token);
    ExpressionTree& Insert(Expression* value);

    void Inorder(bool (* action)(const Token* pData));

    Expression* Eval();

    std::string ToString();

	ExpressionTree();
	~ExpressionTree();
};
