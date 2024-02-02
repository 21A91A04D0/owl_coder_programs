#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int dp[N][3];
int vacation(vector<vector<int>> &mat, int r, int c) {
    if(r >= mat.size()) return 0;
    if(dp[r][c] != -1) return dp[r][c];
    int ans = 0;
    int left;
    int right;
    if(c == 0) {
        left = vacation(mat, r + 1, c + 1);
        right = vacation(mat, r + 1, c + 2);
    }
    else if(c == 1) {
        left = vacation(mat, r + 1, c - 1);
        right = vacation(mat, r + 1, c + 1);
    }
    else {
        left = vacation(mat, r + 1, c - 2);
        right = vacation(mat, r + 1, c - 1);
    }
    return dp[r][c] = mat[r][c] + max(left, right);
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> ans;
    vector<int> A;
    int res = INT_MIN;
    for(int i = 0 ; i < n ; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        A.push_back(a);
        A.push_back(b);
        A.push_back(c);
        ans.push_back(A);
        A.clear();
    }
    memset(dp,-1,sizeof(dp));
    for(int i = 0 ; i < 3 ; i++) {
       
        res = max(res, vacation(ans, 0, i));
    }
    cout << res;
}