#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,k; cin >> n >> k;
	vector <vector<int>> a(n,vector<int>(n));
	for(auto &i: a)
	{
		for(auto &j : i) cin >> j;
	}
	vector <int> dp((1<<n),1e9);
	dp[(1<<n)-1] = 0;
	int ans = 1e9;
	for(int state = (1<<n)-1; state >= 0; --state)
	{
		vector <int> b;
		for(int i = 0; i < n; ++i) if((state>>i)&1) b.push_back(i);
		if(b.size() == k) ans = min(ans,dp[state]);
		for(auto &x : b)
		{
			for(auto &y: b)
			{
				if(x == y) continue;
				int new_state = state - (1<<x);
				dp[new_state] = min(dp[new_state],dp[state]+a[x][y]);
			}
		}
	}
	cout << ans << '\n';
}