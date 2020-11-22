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
        switch (token.GetType())
        {
        case TokenType::Num:
            link = new NumberExpression(token.GetValue());
            break;
        case TokenType::Add:
            link = new AddExpression();
            break;
        default: 
            link = new Expression(token.GetType(), token.GetValue());
        }
        *ppLink = link;
    }
    else 
    {
        if (link->GetLeft() == nullptr) 
        {
            return InsertHelper(&(link->m_left), token);
        }
        else 
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


static void InorderHelper(Expression* pLink, bool (* action)(const Token* pData))
{
    if (pLink == nullptr) return;
    InorderHelper(pLink->m_left, action);
    action(pLink->GetValue());
    InorderHelper(pLink->m_right, action);
}

void ExpressionTree::Inorder(bool (* action)(const Token* pData))
{
    InorderHelper(m_root, action);
}

static std::string ToStringHelper(Expression *pLink)
{
    std::string expr = "";
    if (!pLink) return expr; 
    if (pLink->GetValue()->GetType() == TokenType::Num)
    {
        return expr.append(pLink->GetValue()->GetValue());
    }
    else 
    {
        return expr
            .append("(")
            .append(pLink->GetValue()->GetValue())
            .append(" ")
            .append(ToStringHelper(pLink->m_left))
            .append(" ")
            .append(ToStringHelper(pLink->m_right))
            .append(")");    
    }
}

std::string ExpressionTree::ToString()
{
    return ToStringHelper(m_root);
}
