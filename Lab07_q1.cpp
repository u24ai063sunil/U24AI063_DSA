/*
Write a C/C++ code to evaluate the Postfix Expression using Stack.
Example:
Input: 34*25*+
Output: 22
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to evaluate postfix expression
int evaluatePostfix(string postfix) {
    stack<int> st;
    
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        
        // If character is an operand, push it to stack
        if (isdigit(c)) {
            st.push(c - '0');
        }
        // If character is an operator, pop two operands and perform operation
        else {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            
            switch (c) {
                case '+': st.push(op1 + op2); break;
                case '-': st.push(op1 - op2); break;
                case '*': st.push(op1 * op2); break;
                case '/': st.push(op1 / op2); break;
            }
        }
    }
    
    return st.top();
}


int main() {
    cout << "Enter postfix expression: ";
    string postfix;
    cin >> postfix;
    cout << "Output: " << evaluatePostfix(postfix) << endl;
    
    return 0;
}