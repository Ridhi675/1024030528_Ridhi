#include <iostream>
#include <stack>
#include <cctype>
#include <cmath>
using namespace std;

// Function to evaluate postfix expression
int evaluatePostfix(string postfix) {
    stack<int> st;

    for (char ch : postfix) {
        // If operand, push (assuming single-digit numbers)
        if (isdigit(ch)) {
            st.push(ch - '0');  // convert char '5' → int 5
        }
        // If operator, pop two operands
        else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            switch (ch) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
                case '^': st.push(pow(val1, val2)); break;
            }
        }
    }

    return st.top(); // final result
}

int main() {
    string
