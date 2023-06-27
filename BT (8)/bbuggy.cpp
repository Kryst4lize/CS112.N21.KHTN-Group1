#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,m; cin >> n >> m;
	vector <vector<int>> graph(n+1);
	for(int i = 0; i < m; ++i)
	{
		int x,y; cin >> x >> y;
		graph[x].push_back(y);
	}
	vector <int> visited(n+1), dp(n+1);
	function<void(int)> DP;
	DP = [&](int h)
	{
		visited[h] = 1;
		for(auto &i: graph[h])
		{
			if(!visited[i]) DP(i);
			dp[h] = max(dp[h],dp[i]+1);
		}
	};
	for(int i = 1; i <= n; ++i)
	{
		if(!visited[i]) DP(i);
	}
	cout << *max_element(dp.begin(),dp.end());
}