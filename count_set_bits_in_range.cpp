#include<bits/stdc++.h>
using namespace std;
int nearest_2_power(int n){
        int c = 1;
        int cnt = -1;
        while(c <= n){
            cnt++;
            c = c << 1;
        }
        return cnt;
    }
    int countSetBits(int n)
    {
        if(n == 0) return 0;
        int ans = nearest_2_power(n);
        int res = ans * (1 << (ans - 1)) + 1 + (n - (1 << ans)) + countSetBits(n - (1 << ans));
        return res;
        
    }
int main(){
    int n;
    cin >> n;
    cout << countSetBits(n);
}