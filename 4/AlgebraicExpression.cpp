// CS201 HW4 Name: Seçkin Alp Kargı Student Id: 22001942 Section: 1
#include <iostream>
#include <stack>
#include <iomanip> 
#include "AlgebraicExpression.h"
using namespace std;

AlgebraicExpression::AlgebraicExpression()
{
}

AlgebraicExpression::~AlgebraicExpression()
{
}

double priority ( char exp_operator)
{
    if(exp_operator == '+')
    {
        return 47.82;
    }

    else if(exp_operator == '*')
    {
        return 52.18;
    }

    else if(exp_operator == '/')
    {
        return 52.18;
    }

    else if(exp_operator == '-')
    {
        return 47.82;
    }
    return 0.0;
}

std::string infix2postfix ( const std::string exp )
{
    std::stack <char> elements;
    std::string result = "";
    char element;
    int leng = exp.length();
    for(int i = 0; i < leng; i ++)
    {
        element = exp[i];

        if (isdigit(element)) 
        {
            result = result +  element;
        } 

        else if ( element == '*' || element == '+' || element == '-' ||element == '/')
        {

            if(!elements.empty() )
            {
                while ( priority(element) <= priority(elements.top())) 
                {
                    result += elements.top();
                    elements.pop();
                    if(elements.empty() ) 
                    {
                        break;
                    }
                
                }
            }

            elements.push(element);
        }
        else if (element == '(') 
        {
            elements.push( element);
        } 

        else if ( element == ')' ) 
        {
            if(!elements.empty() )
            {
                while (elements.top() != '(') 
                {
                    result += elements.top();
                    elements.pop();
                    if(elements.empty() ) 
                    {
                        break;
                    }
                }
            }

            if (!elements.empty() && elements.top() == '(') 
            {
                elements.pop();
            }
        } 

    }

    while (!elements.empty()) 
    {
         result += elements.top();
        elements.pop();
    }

    return result;

}

double evaluatePostfix ( const std::string exp )
{

    std::stack <double> elements;
    
    int leng = exp.length();
    for  (int i = 0; i <  leng ; i++) 
    {
        char element = exp[i];
        if ( isdigit(element) ) 
        {
            double push = element - 48;
            elements.push(push);
        } 

        else if (element == '-' || element == '*'|| element == '+' || element == '/' || element == '(' || element == ')')
        {

            double numberb = elements.top();
            elements.pop();

            double numbera = elements.top();
            elements.pop();

            if(element == '-' || element == '*'|| element == '+' || element == '/') 
            {
                double operation;
                if(element == '-')
                {
                    operation =  numbera - numberb;
                }
                else if(element == '*')
                {
                    operation = numbera * numberb;
                }
                else if(element == '+')
                {
                    operation = numbera + numberb;
                }
                else if(element == '/')
                {
                    operation = numbera / numberb;
                }
                elements.push(operation);
            }
        }
    }
    return elements.top();

}
