#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

int main() {
    string infix, prefix = "";
    stack<char> st;

    cout << "Enter infix expression: ";
    cin >> infix;

    reverse(infix.begin(), infix.end());

    for (char &c : infix) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }

    for (char c : infix) {
        if (isalnum(c)) {
            prefix += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                prefix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else {
            while (!st.empty() && st.top() != '(' &&
                   (precedence(st.top()) > precedence(c) ||
                   (precedence(st.top()) == precedence(c) && c == '^'))) {
                prefix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        prefix += st.top();
        st.pop();
    }

    reverse(prefix.begin(), prefix.end());

    cout << "Prefix Expression: " << prefix;

    return 0;
}