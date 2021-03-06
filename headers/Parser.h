#pragma once
#include <string>
#include <vector>
#include <stdexcept>

#include "Lexer.h"
#include "Token.h"
#include "Logger.h"
#include "Helper.h"
#include "Expression.h"
#include "ExpressionTree.h"

struct Parser
{
    ExpressionTree* Parse(const std::string& expression); 
};
