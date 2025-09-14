  #include<bits/stdc++.h>
using namespace std;

string infixToPrefix(string s){
  int n = s.size();
  int i = 0;
  stack<char> st;
  string ans = "";

  // step 1: reverse the string
  reverse(s.begin(), s.end());

  // interchange the closing and opening brackets
  for(int i = 0; i < s.size(); i++){
    if(s[i] == '(') s[i] = ')';
    else if(s[i] == ')') s[i] = '(';
  }

  // step 2: controlled conversion from infix to postfix
  while(i < n){

    char c = s[i];

    // if it is an operand, add it to the answer
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
      ans += c;
    }
    else if(c == '(') st.push(c);
    else if(c == ')'){
      while(!st.empty() && st.top() != '('){
        ans = ans + st.top();
        st.pop();
      }
      st.pop();
    }

    // else it is an operator
    else{
      if(c == '^'){
        while(!st.empty() && priority(c) <= priority(st.top())){
          ans = ans + st.top();
          st.pop();
        }
      }
      else{
        while(!st.empty() && priority(c) < priority(st.top())){
          ans = ans + st.top();
          st.pop();
        }
      }
      st.push(c);
    }

    i++;
  }

  while(!st.empty()){
    ans += st.top();
    st.pop();
  }

  reverse(ans.begin(), ans.end());

  return ans;

}

int main() {
  string s = "(a+b)*c-d+f";
  cout << infixToPrefix(s);
}
