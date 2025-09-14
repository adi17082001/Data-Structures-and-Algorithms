#include<bits/stdc++.h>

string prefixToInfix(string s) {
    int n = s.size();
    int i = n-1;
    stack<string> st;

    while (i >= 0) {
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

          string temp = "(" + t1 + string(1, s[i]) + t2 + ")";
          st.push(temp);
      }
        
      i--;
    }

  return st.top();
}

int main() {
  string s = "*+pq-mn";
  cout << prefixToInfix(s);
}
