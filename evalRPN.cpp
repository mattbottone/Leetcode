#include <string>
#include <vector>
#include <stack>
#include <iostream>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> equation;
        int a,b = 0;
        std::string operand;

        for (int i = 0; i < tokens.size(); i++){
            equation.push(tokens[i]);

            if (tokens[i] == "+" ||
                tokens[i] == "-" ||
                tokens[i] == "*" ||
                tokens[i] == "/" ){

                operand = tokens[i];
                equation.pop();

                b = stoi(equation.top());
                equation.pop();

                a = stoi(equation.top());
                equation.pop();

                if (operand == "+") equation.push(std::to_string(a+b));
                else if (operand == "-") equation.push(std::to_string(a-b));
                else if (operand == "*") equation.push(std::to_string(a*b));
                else if (operand == "/") equation.push(std::to_string(a/b));
                else cout << "OPERAND ERROR: " << operand;
            }
        }

        if (equation.size() == 1) return stoi(equation.top());
        else {
            cout << "EQUATION SIZE ERROR: " << equation.size();
            return 0;
        }
    }
};
