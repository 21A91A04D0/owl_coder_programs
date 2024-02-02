#include<bits/stdc++.h>
using namespace std;
// long long dp[101][100001];
long long coins(vector<int> &nums, int n, int ind, int target, vector<int> &dp) {
    if(target < 0) return INT_MAX;
    if(target == 0) return 0;
    if(dp[target] != -1) return dp[target];
    long long left = INT_MAX;
    // pick
    for(int i = ind ; i < n ; i++) {
        if(nums[i] <= target) {
            left = min(left,1 + coins(nums, n, ind, target - nums[i], dp));
        }
    }
    return dp[target] = left;
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> A;
    for(int i = 0 ; i < n ; i++) {
        int val;
        cin >> val;
        A.push_back(val);
    }
    // memset(dp, -1, sizeof(dp));
    vector<int> dp(k + 1, -1);
    long long ans = coins(A, n, 0, k, dp);
    if(ans == INT_MAX) cout << -1;
    else cout << ans;
}