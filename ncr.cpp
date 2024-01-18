#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
const int mod = 1e9 + 7;
long long binary_exponentiation(long long a, long long b) {
    long long result = 1;
    long long mod = 1e9 + 7;
    while(b) {
        if(b & 1) {
            b--;
            result = ((result % mod) * (a % mod)) %mod;
        }
        else {
            b = b / 2;
            a = ((a % mod) * (a % mod)) %mod;
        }
    }
    return result;
}
vector<long long>fact(N);
vector<long long>infact(N);
void preFact() {
    fact[0] = 1;
    infact[0] = 1;
    for(int i = 1 ; i < N ; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
        infact[i] = binary_exponentiation(fact[i], mod - 2);
    }
}

int main() {
    int t;
    cin >> t;
    preFact();
    while(t--){
        long long n, r;
        cin >> n >> r;
        cout << fact[n] / (fact[r] * fact[n-r]) << endl;
        long long ans = (fact[n] % mod * infact[r] % mod * infact[n-r] % mod) % mod;
        cout << ans << endl;
    }
}