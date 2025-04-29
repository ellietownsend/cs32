//
//  eval.cpp
//  project_two
//
//  Created by Ellie Townsend on 4/27/25.
//
/*char operator1 = '!';
char operator2 = '&';
char operator3 = '^';
if(
   (infixNotation.find(operator1) == string::npos) &&
   (infixNotation.find(operator2) == string::npos) &&
   (infixNotation.find(operator3) == string::npos)
   ){
       return infixNotation;}
*/
#include <string>
#include <stack>
#include <iostream>
#include <cassert>
using namespace std;

string getPostfix(string infixNotation) {

    if (infixNotation.empty()) {
        return "";  // Empty string was given
    }

    string postfixString = "";
    stack<char> operatorStack;
    //Remove any spaces from given string
    for(int i = 0; i < infixNotation.length(); i++){
        if(infixNotation[i] == ' '){
            infixNotation.erase(i,1);
            i--;
        }
    }

    // Check if we are ending with an acceptable value
    if (infixNotation[infixNotation.length() - 1] != 'T' &&
        infixNotation[infixNotation.length() - 1] != 'F' &&
        infixNotation[infixNotation.length() - 1] != ')') {
        return "";
    }

    // Check if we are starting with an acceptable value
    if (infixNotation[0] != 'T' &&
        infixNotation[0] != 'F' &&
        infixNotation[0] != '!' &&
        infixNotation[0] != '(') {
        return "";
    }
    
    // See if parenthesis is even
    int numOfParenthesis = 0;
    for (int i = 0; i < infixNotation.length(); i++) {
        switch (infixNotation[i]) {
            case '!':
                // Handle the case of two operators in a row
                if (i > 0 && (infixNotation[i - 1] == 'F' || infixNotation[i - 1] == 'T' || infixNotation[i - 1] == ')')) {
                    return "";
                }
                while (!operatorStack.empty() && operatorStack.top() != '(' && operatorStack.top() == '!') {
                    postfixString += operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.push('!');
                break;

            case '&':
                if (i == 0 || infixNotation[i - 1] == '(' || infixNotation[i - 1] == '!' || infixNotation[i - 1] == '&') {
                    return "";
                }
                while (!operatorStack.empty() && operatorStack.top() != '(' && (operatorStack.top() == '!' || operatorStack.top() == '&')) {
                    postfixString += operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.push('&');
                break;

            case '^':
                if (i == 0 || infixNotation[i - 1] == '(' || infixNotation[i - 1] == '!' || infixNotation[i - 1] == '^') {
                    return "";
                }
                while (!operatorStack.empty() && operatorStack.top() != '(' && (operatorStack.top() == '!' || operatorStack.top() == '&' || operatorStack.top() == '^')) {
                    postfixString += operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.push('^');
                break;

            case 'T':
                if (i > 0 && (infixNotation[i - 1] == 'T' || infixNotation[i - 1] == 'F' || infixNotation[i - 1] == ')')) {
                    return "";
                }
                postfixString += 'T';
                break;

            case 'F':
                if (i > 0 && (infixNotation[i - 1] == 'T' || infixNotation[i - 1] == 'F' || infixNotation[i - 1] == ')')) {
                    return "";
                }
                postfixString += 'F';
                break;

            case '(':
                if (i > 0 && (infixNotation[i - 1] == 'T' || infixNotation[i - 1] == 'F' || infixNotation[i - 1] == ')')) {
                    return "";
                }
                operatorStack.push('(');
                numOfParenthesis++;
                break;

            case ')':
                if (i == 0 || infixNotation[i - 1] == '(' || infixNotation[i - 1] == '!') {
                    return "";
                }
                while (!operatorStack.empty() && operatorStack.top() != '(') {
                    postfixString += operatorStack.top();
                    operatorStack.pop();
                }
                if (operatorStack.empty()) {
                    return "";
                }
                operatorStack.pop();
                numOfParenthesis--;
                break;

            default:
                return "";
        }
    }

    if (numOfParenthesis != 0) {
        return "";
    }

    // Pop all remaining operators from the stack
    while (!operatorStack.empty()) {
        if (operatorStack.top() == '(' || operatorStack.top() == ')') {
            return "";
        }
        postfixString += operatorStack.top();
        operatorStack.pop();
    }
    return postfixString;
}


int evaluate(string infix, string& postfix, bool& result){
    postfix = getPostfix(infix);
    if(postfix == ""){
        //If we were given back an empty string there was an error
        result = false;
        return 1;
    }
    if(postfix == "T"){
        //If we were given back an empty string there was an error
        result = true;
        return 0;
    }
    if(postfix == "F"){
        //If we were given back an empty string there was an error
        result = false;
        return 0;
    }
    
    stack<char> postFixStack;
    for (int i = 0; i < postfix.length(); i++) {
        if(postfix[i] == 'T' || postfix[i] == 'F'){
            postFixStack.push(postfix[i]=='T');
        }
        else{ // We encountered an operator
            bool operand2;
            bool operand1;
            bool outcome;
            operand2 = postFixStack.top();
            postFixStack.pop();
            
            switch (postfix[i]) {
                case '!':
                    outcome = !operand2;
                    postFixStack.push(outcome);
                    break;
                case '&':
                    operand1 = postFixStack.top();
                    postFixStack.pop();
                    outcome = operand1 && operand2;
                    postFixStack.push(outcome);
                    break;
                case '^':
                    operand1 = postFixStack.top();
                    postFixStack.pop();
                    outcome = operand1 || operand2;
                    postFixStack.push(outcome);
                    break;
                default:
                    cout << "Invalid operator encountered!" << endl;
                    return 1;
            }
        }
    }
    result = postFixStack.top();
    return 0;
}
int main()
       {
       string pf;
       bool answer;
       assert(evaluate("T^ F", pf, answer) == 0  &&  pf == "TF^"  &&  answer);
       assert(evaluate("T^", pf, answer) == 1);
       assert(evaluate("F F", pf, answer) == 1);
       assert(evaluate("TF", pf, answer) == 1);
       assert(evaluate("(T&F)", pf, answer) == 0);
       assert(evaluate("()", pf, answer) == 1);
       assert(evaluate("()T", pf, answer) == 1);
       assert(evaluate("T(F^T)", pf, answer) == 1);
       assert(evaluate("T(&T)", pf, answer) == 1);
       assert(evaluate("(T&(F^F)", pf, answer) == 1);
       assert(evaluate("T|F", pf, answer) == 1);
       assert(evaluate("", pf, answer) == 1);
       assert(evaluate("F  ^  !F & (T&F)", pf, answer) == 0  &&  pf == "FF!TF&&^"  &&  !answer);
       assert(evaluate(" F  ", pf, answer) == 0 &&  pf == "F"  &&  !answer);
       assert(evaluate("((T))", pf, answer) == 0 &&  pf == "T" &&  answer);
       cout << "Passed all tests" << endl;
       }

