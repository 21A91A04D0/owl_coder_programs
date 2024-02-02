#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int dp[N];
int frog(vector<int> &nums, int ind, int k) {
  if(ind == nums.size() - 1) return 0;
  if(dp[ind] != -1) return dp[ind];
  int right = INT_MAX;
  for(int i = 1 ; i <= k ; i++) {
    if(ind + i < nums.size()) {
        right = min(right, abs(nums[ind] - nums[ind + i]) + frog(nums, ind + i, k));
    }
  }
  return dp[ind] = right;
}
int main() {
  int n;
  cin >> n;
  vector<int> A;
  int k;
  cin >> k;
  for(int i = 0 ; i < n ; i++) {
    int val;
    cin >> val;
    A.push_back(val);
  }
  memset(dp, -1, sizeof(dp));
  cout << frog(A, 0, k);
}