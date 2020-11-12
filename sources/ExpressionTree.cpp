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

static bool InsertHelper(Expression** ppLink, const Token& token)
{
    Expression* link = *ppLink;
    if (link == nullptr)
    {
        link = new Expression(token.GetType(), token.GetValue());
        *ppLink = link;
    }
    else 
    {
        if (link->GetLeft() == nullptr) 
        {
            return InsertHelper(&(link->m_left), token);
        }
        else if (link->GetRight() == nullptr)
        {
            return InsertHelper(&(link->m_right), token);
        }
    }
    return true;
}

ExpressionTree& ExpressionTree::Insert(const Token& token)
{
    if (InsertHelper(&m_root, token))
        return static_cast<ExpressionTree&>(*this);
    else 
        throw std::runtime_error{"insert operation was failed"};
}
