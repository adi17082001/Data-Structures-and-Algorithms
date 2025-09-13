#include<bits/stdc++.h>
using namespace std;


// brute 
// class MinStack {
//     stack<pair<int,int>>st;
// public:
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         if(st.empty()) st.push({val, val});
//         else{
//             st.push({val, min(val, st.top().second)});
//         }
//     }
    
//     void pop() {
//         st.pop();
//     }
    
//     int top() {
//         return st.top().first;
//     }
    
//     int getMin() {
//         return st.top().second;
//     }
// };

// optimal
class MinStack {
    stack<long long> st;
    long long mini = INT_MAX;

public:
    MinStack() { }

    void push(int val) {
        if(st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if(val >= mini) {
                st.push(val);
            } else {
                st.push(2LL * val - mini);  // store encoded value
                mini = val;
            }
        }
    }

    void pop() {
        if(st.empty()) return;
        long long x = st.top();  // FIX: use long long
        st.pop();
        if(x < mini) {  // encoded value, restore old mini
            mini = 2LL * mini - x;
        }
    }

    int top() {
        if(st.empty()) return -1;
        long long x = st.top();
        if(x >= mini) return (int)x;  // normal case
        else return (int)mini;        // encoded case
    }

    int getMin() {
        return (int)mini;
    }
};



int main(){

}
