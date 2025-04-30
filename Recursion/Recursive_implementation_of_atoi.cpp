#include<bits/stdc++.h>
using namespace std;

int recurAtoi(string str, int len){
  if(len == 1){
    return (str[0] - '0');
  }
  int temp = 10 * recurAtoi(str, len - 1);
  temp = temp + (str[len - 1] - '0');
  return temp;
}

int main(){
  string s = "123";
  cout << recurAtoi(s, s.length());
}
