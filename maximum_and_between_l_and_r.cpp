#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> A;
    for(int i = 0 ; i < n ; i++){
        int val;
        cin >> val;
        A.push_back(val);
    }
    vector<vector<int>>arr(n, vector<int>(32, 0));
    for(int i = 0 ; i < 32 ; i++){
        int cnt = 0;
        for(int j = 0 ; j < n ; j++){
            if(A[j] & 1 == 1)
            {
                cnt++;  
            }
            A[j] = (A[j] >> 1);
            arr[j][31-i] = cnt;
        }
    }
    int q;
    cin >> q;
    for(int i = 0 ; i < q ; i++){
        int l, r;
        cin >> l >> r;
        int res = 0;
        int k = 31;
        for(int i = 0 ; i < 32 ; i++){
            int len = r - l + 1;
            if(l != 0){
                int ans = arr[r][31 - i] - arr[l - 1][31 - i];
                if(ans == len){
                    res += (1 << i);
                }
            }
            if(l == 0){
                int ans = arr[r][31 - i];
                if(ans == len){
                    res += (1 << i);
                }
            }
        }
        cout << res << " ";
    }
}