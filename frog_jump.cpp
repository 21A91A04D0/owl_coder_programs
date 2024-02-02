#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int dp[N];
int frog(vector<int> &nums, int ind) {
  if(ind == nums.size() - 1) return 0;
  if(dp[ind] != -1) return dp[ind];
  int left = abs(nums[ind] - nums[ind + 1]) + frog(nums, ind + 1);
  int right = INT_MAX;
  if(ind + 2 < nums.size()){
    right = abs(nums[ind] - nums[ind + 2]) + frog(nums, ind + 2);
  }
  return dp[ind] = min(left, right);
}
int main() {
  int n;
  cin >> n;
  vector<int> A;
  for(int i = 0 ; i < n ; i++) {
    int val;
    cin >> val;
    A.push_back(val);
  }
  memset(dp, -1, sizeof(dp));
  cout << frog(A, 0);
}