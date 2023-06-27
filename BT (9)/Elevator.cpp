#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,x; cin >> n >> x;
	vector <int> a(n);
	for(auto &i : a) cin >> i;
	vector <_ii> dp(1<<n,{1e9,0});
	dp[0] = {0,1e9};
	for(int state = 0; state < (1<<n); ++state)
	{
		vector <int> b;
		for(int i = 0; i < n; ++i) if(!((state>>i)&1)) b.push_back(i);
		for(auto &i : b)
		{
			int new_state = state|(1<<i);
			if(dp[state].second+a[i] <= x) dp[new_state] = min(dp[new_state],{dp[state].first,dp[state].second+a[i]});
			else dp[new_state] = min(dp[new_state],{dp[state].first+1,a[i]});
		}
	}
	cout << dp[(1<<n)-1].first << '\n';
}