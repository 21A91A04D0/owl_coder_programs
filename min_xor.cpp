#include<bits/stdc++.h>
using namespace std;
int minVal(int a, int b) {
        // code here
        int cnt = 0;
        while(b){
            if(b & 1 == 1){
                cnt++;
            }
            b = b >> 1;
        }
        vector<int> A(32,0);
        int copy = a;
        int k = 31;
        while(copy){
            // cout << copy << "->";
            if(copy & 1 == 1){
                A[k] = 1;
            }
            copy = copy >> 1;
            k--;
        }
        int res = 0;
        bool flag = false;
        for(int i = 0 ; i < 32 ; i++){
            int ind = 32 - i;
            if(flag) break;
            if(ind == cnt){
                flag = true;
                while(cnt){
                    res += (1 << (cnt - 1));
                    cnt--;
                }
                
            }
            else if(A[i] == 1 and cnt){
                res += (1 << (ind - 1));
                cnt--;
            }
        }
        return res;
    }
int main(){
    int a, b;
    cin >> a >> b;
    cout << minVal(a, b);
}