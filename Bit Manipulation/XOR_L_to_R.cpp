#include<bits/stdc++.h>
using namespace std;

int fun(int N){
  if(N % 4 == 1) return 1;
  else if(N % 4 == 2) return (N + 1);
  else if(N % 4 == 3) return 0;
  else if(N % 4 == 0) return N;
}

int xorLToR(int L, int R){
  return fun(L-1) ^ fun(R);
}

int main(){
  int L = 4, R = 7;
  cout << xorLToR(L,R);
}
