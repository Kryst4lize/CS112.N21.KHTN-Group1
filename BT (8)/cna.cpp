#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string a; cin >> a;
	string b; cin >> b;
	int m = a.size(), n = b.size();
	a = "$" + a;
	b = "$" + b;
	vector<vector<int>> dp(m+1,vector<int>(n+1));
	int ans = 0;
	for(int i = 1; i <= m; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			if(a[i] == b[j]) dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
			ans = max(ans,dp[i][j]);
		}
	}
	cout << ans << '\n';
}