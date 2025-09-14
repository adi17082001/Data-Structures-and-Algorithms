#include<bits/stdc++.h>
using namespace std;

string postfixToInfix(string s) {
    int n = s.size();
    int i = 0;
    stack<string> st;

    while (i < n) {
        // if operand (letter or digit)
        if ((s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= '0' && s[i] <= '9')) {
            
            st.push(string(1, s[i]));  // convert char to string
        } 
        else {
            // operator: need two operands
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();

            string temp = "(" + t2 + string(1, s[i]) + t1 + ")";
            st.push(temp);
        }
        i++;
    }

    return st.top();
}

int main() {
  string s = "ab-de+f*/";
  cout << postfixToInfix(s);
}
