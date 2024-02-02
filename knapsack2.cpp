#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
long long dp[101][100001];
long long knapsack2(vector<int> &weights, vector<int> &values, int ind , int sm, int n) {
    if(ind >= n) {
        if(sm == 0) return 0;
        return INT_MAX;
    }
    if(dp[ind][sm] != -1) return dp[ind][sm];
    long long a = INT_MAX;
    long long b = INT_MAX;
    // pick
    if(sm >= values[ind]) {
        a = knapsack2(weights, values, ind + 1, sm - values[ind], n) + weights[ind];
    }
    // non-pick
    b = knapsack2(weights, values, ind + 1, sm, n);
    return dp[ind][sm] = min(a, b);
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> weights;
    vector<int> values;
    int sm = 0;
    for(int i = 0 ; i < n ; i++) {
        int w, v;
        cin >> w >> v;
        weights.pb(w);
        values.pb(v);
        sm += v;
    }
    memset(dp, -1, sizeof(dp));
    for(int i = sm ; i >= 0 ; i--) {
        long long ans = knapsack2(weights, values, 0, i, n);
        if(ans <= k){
            cout << i << " ";
            break;
        }
    }



}