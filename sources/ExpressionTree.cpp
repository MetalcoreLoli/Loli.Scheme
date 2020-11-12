#include "../headers/ExpressionTree.h"
#include <stdexcept>

ExpressionTree::ExpressionTree()
{
    m_root = nullptr;
}

ExpressionTree::~ExpressionTree()
{
    delete m_root;
}

bool InsertHelper(Expression* link, const Token& token)
{
    if (link == nullptr)
    {
        link = new Expression(token.GetType(), token.GetValue());
    }
    else 
    {
        if (link->GetLeft() == nullptr) 
        {
            return InsertHelper(link->GetLeft(), token);
        }
        else if (link->GetRight() == nullptr)
        {
            return InsertHelper(link->GetRight(), token);
        }
    }
    return true;
}

ExpressionTree& ExpressionTree::Insert(const Token& token)
{
    if (InsertHelper(m_root, token))
        return static_cast<ExpressionTree&>(*this);
    else 
        throw std::runtime_error{"insert operation was failed"};
}
