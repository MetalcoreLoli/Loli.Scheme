#pragma once
#include <string>
#include <vector>
#include <stdexcept>

#include "Lexer.h"
#include "Token.h"
#include "Expression.h"
#include "ExpressionTree.h"
#include "Logger.h"

struct Parser
{
    ExpressionTree* Parse(const std::string& expression); 
};
