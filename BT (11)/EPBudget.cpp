#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;
int inf = 1e9;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,k; cin >> n >> k;
	vector <vector<int>> a(n,vector<int>(n,inf));
	for(auto &i: a)
	{
		for(auto &j :i) cin >> j;
	}
	auto d = a;
	for(int k = 0; k < n; ++k)
	{
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	vector <int> p(k);
	bool mark = true;
	for(auto &i: p)
	{
		cin >> i;
		if(i == 1) mark = false;
		--i;
	}
	if(mark) p.push_back(0);
	sort(p.begin(),p.end());
	k = p.size();
	vector <vector<int>> dp(n,vector<int>(1<<k,1e9));
	dp[0][1] = 0;
	int ans = 1e9;
	for(int state = 1; state < (1 << k); ++state)
	{
		vector <int> x,y;
		for(int bit = 0; bit < k; ++bit)
		{
			if((state>>bit)&1) x.push_back(bit);
			else y.push_back(bit);
		}
		if(x.size() == k)
		{
			for(auto &i: x) ans = min(ans,dp[i][state]);
		}
		else
		{
			for(auto &i : x)
			{
				for(auto &j: y)
				{
					int new_state = state + (1<<j);
					dp[j][new_state] = min(dp[j][new_state],dp[i][state]+d[p[i]][p[j]]);
				}
			}
		}
	}
	cout << ans << '\n';
}