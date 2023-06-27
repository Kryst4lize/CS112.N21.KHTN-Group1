#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;
const int N = 5007, M = 1e6+7;
string s;
int n,m,temp,next_pos[M][30],cnt[M];
i64 dp[N],mod=1e9+7;
void Make(string &s)
{
	int pos = 0;
	for(auto &i: s)
	{
		if(next_pos[pos][i-'a'] == 0) next_pos[pos][i-'a'] = ++temp;
		pos = next_pos[pos][i-'a'];
	}
	++cnt[pos];
}
void Run(int h)
{
	int pos = 0;
	for(int i = h; i > 0; i--)
	{
		if(next_pos[pos][s[i]-'a'])
		{
			pos = next_pos[pos][s[i]-'a'];
			dp[h] = dp[h] + dp[i-1]*cnt[pos];
			dp[h] %= mod;
		}
		else break;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s;
	n = s.size();
	s = "$" + s;
	cin >> m;
	for(int i = 0; i < m; ++i)
	{
		string x; cin >> x;
		if(x.size() > n) continue;
		reverse(x.begin(),x.end());
		Make(x);
	}
	dp[0] = 1;
	for(int i = 1; i <= n; ++i)
	{
		Run(i);
	}
	if(dp[n]) cout << "true" << '\n';
	else cout << "false" << '\n';
}