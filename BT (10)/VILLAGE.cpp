#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;
i64 mod = 1e9+7;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,m; cin >> n >> m;
	vector <vector<i64>> a(n,vector<i64>(n));
	for(int i = 0; i < m; ++i)
	{
		int x,y; cin >> x >> y;
		++a[x-1][y-1];
	}
	vector <vector<i64>> dp(n,vector<i64>(1<<n));
	dp[0][1] = 1;
	for(int state = 1; state < (1 << n); ++state)
	{
		vector <int> x,y;
		for(int bit = 0; bit < n; ++bit)
		{
			if((state>>bit)&1) x.push_back(bit);
			else y.push_back(bit);
		}
		for(auto &i : x)
		{
			for(auto &j: y)
			{
				int new_state = state + (1<<j);
				dp[j][new_state] += (dp[i][state]*a[i][j]);
				if(dp[j][new_state] > 1e15) dp[j][new_state] %= mod;
			}
		}
	}
	cout << dp[n-1][(1<<n)-1] % mod << '\n';
}