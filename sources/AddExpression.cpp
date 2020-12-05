#include "../headers/AddExpression.h"
#include <string>
AddExpression::AddExpression()
{
    m_left = nullptr;
    m_right = nullptr;
    m_value = new Token(TokenType::Add);
}

AddExpression::AddExpression(Expression* left, Expression* right)
{
    m_value = new Token(TokenType::Add);
    m_left = left;
    m_right = right;
}

AddExpression::~AddExpression()
{
    delete m_left;
    delete m_right;
    delete m_value;
}


bool AddExpression::IsReducible()  {return true;}

Expression* AddExpression::Reduce()
{
    if (m_left->IsReducible())
    {
        return new AddExpression(m_left->Reduce(), m_right);
    }
    else if (m_right->IsReducible())
    {
        return new AddExpression(m_left, m_right->Reduce());
    }
    else 
    {
        std::string number;
        int lnum = std::stoi(m_left->GetValue()->GetValue());
        int rnum = std::stoi(m_right->GetValue()->GetValue());
        return new NumberExpression(std::to_string(lnum + rnum));
    }
}
