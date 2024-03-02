// CS201 HW4 Name: Seçkin Alp Kargı Student Id: 22001942 Section: 1
#include <string>

class AlgebraicExpression
{
   
private:
    /* data */
public:
    AlgebraicExpression(/* args */);
    ~AlgebraicExpression();
    
};


 double priority (char exp_operator);
std::string infix2postfix ( const std::string exp );
        
double evaluatePostfix ( const std::string exp );

