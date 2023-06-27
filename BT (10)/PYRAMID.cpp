#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;
int mod = 3;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	vector <_ii> split(n);
	split[0] = {0,1};
	for(int i = 1; i < n; ++i)
	{
		int x = 0, y = i;
		while(y % mod == 0)
		{
			++x;
			y /= mod;
		}
		split[i].first = split[i-1].first + x;
		split[i].second = (split[i-1].second*y) % mod;
	}
	auto C = [&](int n, int k)
	{
		int x = split[n].first;
		x -= split[k].first;
		x -= split[n-k].first;
		int temp = (split[k].second*split[n-k].second) % mod;
		if(x > 0) return 0;
		else
		{
			if(temp == 0) return split[n].second;
			else
			{
				if(split[n].second % temp == 0) return split[n].second/temp;
				else return mod-1;
			}
		}
	};
	vector <int> val(256,-1);
	val['B'] = 0;
	val['W'] = 1;
	val['R'] = 2;
	i64 ans = 0;
	for(int i = 0; i < n; ++i)
	{
		ans = ans + val[s[i]]*C(n-1,i);
		ans %= mod;
	}
	ans = (ans+mod) % mod;
	if(n % 2 == 0)
	{
		ans = (-ans) % mod;
		ans = (ans+mod) % mod;
	}
	char result;
	for(int i = 0; i < 256; ++i)
	{
		if(val[i] == ans) result = i;
	}
	cout << result << '\n';
}