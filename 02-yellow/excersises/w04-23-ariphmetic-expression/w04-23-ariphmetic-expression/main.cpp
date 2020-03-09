//
//  main.cpp
//  w04-23-ariphmetic-expression
//
//  Created by Sergey Gordeev on 26.01.2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include <iostream>
#include <string>
#include "test_runner.hpp"
#include "assertation_tools.hpp"

void UpdateExpressionV1(std::string& expression, char op, int rval, bool is_parantness_needed){
    if (is_parantness_needed){
        expression.insert(expression.begin(),'(');
        expression.insert(expression.end(),')');
    }
    
    expression.insert(expression.end(), ' ');
    expression.insert(expression.end(), op);
    expression.insert(expression.end(), ' ');
    expression += std::to_string(rval);

}
void TestPrintExpression(){

    {
        std::string expression  {"8"};
        UpdateExpressionV1(expression, '*', 3, true);
        AssertEq("(8) * 3", expression, "(8) * 3");
    }
    
    {
        std::string expression  {"8"};
        UpdateExpressionV1(expression, '*', 3, true);
        UpdateExpressionV1(expression, '-', 6, true);
        UpdateExpressionV1(expression, '/', 1, true);

        AssertEq("(((8) * 3) - 6) / 1", expression, "(((8) * 3) - 6) / 1");
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    TestRunner r;
    r.RunTest(TestPrintExpression, "TestPrintExpression");
    
    int init, n;
    std::cin >> init >> n;
    std::string e1 = std::to_string(init);
    std::string e2 = std::to_string(init);
    bool is_previous_higest = true;
    for(int idx {0}; idx < n; ++idx){
       
        char op;
        int val;
        std::cin >> op >> val;
        bool is_current_op_with_higest_priority = op == '*' || op == '/';
        UpdateExpressionV1(e1,op,val,true);
        UpdateExpressionV1(e2,op,val,is_current_op_with_higest_priority > is_previous_higest);
        is_previous_higest = is_current_op_with_higest_priority;
    }
    std:: cout << e1 << std::endl;
    std:: cout << e2;
    return 0;
}
