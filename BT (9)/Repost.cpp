#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int ans = 1;
	map <string,int> dp;
	dp["polycarp"] = 1;
	auto Format = [](string a)
	{
		for(auto &i : a) i = tolower(i);
		return a;
	};
	while(n--)
	{
		string a,b,c;
		cin >> a >> b >> c;
		a = Format(a);
		c = Format(c);
		dp[a] = max(dp[a],dp[c]+1);
		ans = max(ans,dp[a]);
	}
	cout << ans << '\n';
}