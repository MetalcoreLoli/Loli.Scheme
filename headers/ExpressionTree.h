#pragma once
#include "Expression.h"

class ExpressionTree
{
private:
	Expression* m_root;
public:
	Expression* GetRoot() const {return m_root;}
	void SetRoot(Expression* value) {m_root = value;}

    ExpressionTree& Insert(const Token& token);

    void Inorder(bool (* action)(const Token* pData));

	ExpressionTree();
	~ExpressionTree();
};
