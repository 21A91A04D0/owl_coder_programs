#include<bits/stdc++.h>
using namespace std;
vector<int> sieve(int n) {
    vector<int> A(n + 1,1);
    vector<int> B;
    A[0] = 0;
    A[1] = 0;
    for(int i = 2 ; i <= n ; i++) {
        if(A[i] == 1){
            for(int j = i * i ; j <= n ; j += i){
                A[j] = 0;
            }
        }
    }
    for(int j = 0 ; j <= n ; j++) {
        if(A[j] == 1) B.push_back(j);
    }
    return B;
}
int main() {
    int t;
    cin >> t;
    while(t) {
        int n;
        cin >> n;
        vector<int> ans = sieve(n);
        int cnt = 0;
        for(int j = 2 ; j < ans.size() ; j++) {
            for(int i = 1; i < j ; i++) {
                if(ans[j] - ans[i] == 2) cnt++;
            }
        } 
        cout << cnt;
        t--;
    }
}