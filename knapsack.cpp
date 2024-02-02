#include<bits/stdc++.h>
using namespace std;
#define pb push_back
long long dp[1001][100001];
long long knapsack(vector<long long> &weights, vector<long long> &values, int ind, long long n, long long target) {
    if(target <= 0) {
        return 0;
    }
    if(ind == n) return 0; 
    if(dp[ind][target] != -1) return dp[ind][target];
    long long res=0;
    for(int i = ind ; i < n ; i++) {
        if(weights[i] <= target){
            res=max(res,knapsack(weights, values, i + 1, n, target - weights[i])+values[i]);
        }
    } 
    return dp[ind][target] = res;
}
int main() {
    long long n, we;
    cin >> n >> we;
    vector<long long> weights;
    vector<long long> values;
    memset(dp, -1, sizeof(dp));
    for(int i = 0 ; i < n ; i++) {
        long long w, v;
        cin >> w >> v;
        weights.pb(w);
        values.pb(v);
    }
    long long final_ans = knapsack(weights, values, 0, n, we);
    cout << final_ans;
}