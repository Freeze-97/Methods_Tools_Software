/*
 * Autor       : Mikael Nilsson
 * Filename    : MathExpression.cpp
 * Description : Implementation av MathExpression
 *
*/

#include "MathExpression.h"
#include <stack>
#include <sstream>

using std::stack;
using std::string;
using std::stringstream;


void skipWhitespace(std::string::iterator& it, const std::string::iterator& end)
{
    while(it + 1 != end && !isdigit(*it) &&
          *it != '+' && *it != '-' && *it != '*' && *it != '/' &&
          *it != '(' && *it != ')' && *it != '.')
    {
        it++;
    }
}

MathExpression::MathExpression(const std::string& expression) : m_infix(expression), m_valid(true)
{
    validate();
    if(m_valid)
    {
        parseInfix();
    }
}

std::string MathExpression::infixNotation() const
{
    return m_infix;
}

std::string MathExpression::postfixNotation() const
{
   return m_postfix;
}

double MathExpression::calculate() const
{
    stack<double> result;

    for(auto it = m_postfix.begin(); it != m_postfix.end(); it++)
    {
        char ch = *it;

        if(isdigit(ch) || ch == '.' || (ch == '-' && isdigit(*(it + 1))))
        {
            std::stringstream output;

            do
            {
                output << ch;
                if(it + 1 != m_postfix.end())
                {
                    it++;
                    ch = *it;
                }
                else
                {
                    break;
                }
            }while(isdigit(ch) || ch == '.');
            result.push(stod(output.str()));
        }
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            double op2 = result.top();
            result.pop();
            double op1 = result.top();
            result.pop();
            switch(ch)
            {
            case '+':
                result.push(op1 + op2);
                break;
            case '-':
                result.push(op1 - op2);
                break;
            case '*':
                result.push(op1 * op2);
                break;
            case '/':
                result.push(op1 / op2);
                break;
            }
        }
    }
    return result.top();
}

bool MathExpression::isValid() const
{
    return m_valid;
}

std::string MathExpression::errorMessage() const
{
    return m_errorMsg;
}

MathExpression &MathExpression::operator=(const std::string &expression)
{
    m_infix = expression;
    validate();
    if(m_valid)
    {
        parseInfix();
    }

    return *this;
}

void MathExpression::parseInfix()
{
    std::stringstream output;
    std::stack<char> op;
    for(auto it = m_infix.begin(); it != m_infix.end(); it++)
    {
        skipWhitespace(it, m_infix.end());
        char ch = *it;

        bool unary = false;
        if(ch == '-')
        {
            string::iterator tmpIt = it;
            tmpIt++;
            skipWhitespace(tmpIt, m_infix.end());
            if(isdigit(*tmpIt))
            {
                unary = true;
            }
        }

        if(isdigit(ch) || ch == '.' || unary)
        {
            do
            {
                output << ch;
                if(it + 1 != m_infix.end())
                {
                    it++;
                    skipWhitespace(it, m_infix.end());
                    ch = *it;
                }
                else
                {
                    break;
                }
            }while(isdigit(ch) || ch == '.');
            output << " ";
        }

        switch(ch)
        {
        case '+':
            if(!op.empty() && (op.top() == '*' || op.top() == '/'))
            {
                output << op.top() << " ";
                op.pop();
            }
            op.push('+');
            break;
        case '-':
            if(!op.empty() && (op.top() == '*' || op.top() == '/'))
            {
                output << op.top() << " ";
                op.pop();
            }
            op.push('-');
            break;
        case '*':
            op.push('*');
            break;
        case '/':
            op.push('/');
            break;
        case '(':
            op.push('(');
            break;
        case ')':
            while(!op.empty() && op.top() != '(')
            {
                output << op.top() << " ";
                op.pop();
            }
            op.pop();
            break;
        }
    }
    while(!op.empty())
    {
        output << op.top();
        op.pop();
        if(!op.empty())
        {
            output << " ";
        }
    }
    m_postfix =  output.str();
}

void MathExpression::validate()
{
    m_valid = true;
    std::stringstream outputMessage;
    int leftParenthesis = 0;
    int rightParenthesis = 0;
    int digits = 0;
    for(auto it = m_infix.begin(); it != m_infix.end(); it++)
    {
        if(*it == '(')
        {
            leftParenthesis++;
            int innerOpperator = 0;
            for(string::iterator tmpIt = it + 1; tmpIt != m_infix.end(); tmpIt++)
            {
                if(*tmpIt == ')')
                {
                    break;
                }
                else if( *tmpIt == '+' || *tmpIt == '-' || *tmpIt == '*' || *tmpIt == '/')
                {
                    innerOpperator++;
                }
            }
            if(innerOpperator == 0)
            {
                outputMessage << "Missing operator inside parantesis" << std::endl;
                m_valid = false;
            }
        }
        else if(*it == ')')
        {
            rightParenthesis++;
        }
        else if(*it == '+' || *it == '*' || *it == '/')
        {
            // Validate right operand
            string::iterator tmpIt = it + 1;
            skipWhitespace(tmpIt,  m_infix.end());
            if(tmpIt != m_infix.end() && !isdigit(*tmpIt) && *tmpIt != '-' && *tmpIt != '(')
            {
                outputMessage << "Syntax error missing valid right operand for operator (" << *it << ")" << std::endl;
                m_valid = false;
            }

            // Validate left operand
            tmpIt = it - 1;
            while(tmpIt != m_infix.begin() && !isdigit(*tmpIt) &&
                  *tmpIt != '+' && *tmpIt != '-' && *tmpIt != '*' && *tmpIt != '/' &&
                  *tmpIt != '(' && *tmpIt != ')' && *tmpIt != '.')
            {
                tmpIt--;
            }
            if(!isdigit(*tmpIt) && *tmpIt != ')')
            {
                outputMessage << "Syntax error missing valid left operand for operator (" << *it << ")" << std::endl;
                m_valid = false;
            }
        }
        else if(*it == '-')
        {
            // Validate right operand (unary operator does not use left operand)
            string::iterator tmpIt = it + 1;
            skipWhitespace(tmpIt,  m_infix.end());
            if(!isdigit(*tmpIt) && *tmpIt != '('  && *tmpIt != '-')
            {
                outputMessage << "Syntax error missing valid right operand for operator (" << *it << ")" << std::endl;
                m_valid = false;
            }
        }
        else if(!isdigit(*it) && *it != '.' && *it != ' ' && *it != '\t' && *it != '\n' )
        {
             outputMessage << "Expression contains illigal character (" << *it << ")" << std::endl;
             m_valid = false;
        }

        if(isdigit(*it))
        {
            digits++;
            int decimal = 0;

            for(string::iterator tmpIt = it + 1; tmpIt != m_infix.end(); tmpIt++)
            {
                if(!isdigit(*tmpIt) && *tmpIt != '.')
                {
                    break;
                }
                else if(*tmpIt == '.')
                {
                    decimal++;
                }
            }

            if(decimal > 1)
            {
                outputMessage << "Syntax error too many decimal separators."  << std::endl;
                m_valid = false;
            }
        }
    }

    if(leftParenthesis != rightParenthesis)
    {
        outputMessage << "Syntax error missing "  << (leftParenthesis < rightParenthesis ? "left" : "right")
                      << " parenthesis." << std::endl;
        m_valid = false;
    }
    if(digits == 0)
    {
        outputMessage << "Expression contains no digits!";
        m_valid = false;
    }
    m_errorMsg = outputMessage.str();
}
