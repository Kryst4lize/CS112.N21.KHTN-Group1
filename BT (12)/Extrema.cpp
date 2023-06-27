#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,q; cin >> n >> q;
	vector <int> a(n);
	for(auto &i : a) cin >> i;
	int ans = 0;
	auto Update = [&](int pos)
	{
		if(pos <= 0 || pos >= n-1) return;
		if(a[pos] > max(a[pos-1],a[pos+1])) ++ans;
		if(a[pos] < min(a[pos-1],a[pos+1])) ++ans;
	};
	auto Restore = [&](int pos)
	{
		if(pos <= 0 || pos >= n-1) return;
		if(a[pos] > max(a[pos-1],a[pos+1])) --ans;
		if(a[pos] < min(a[pos-1],a[pos+1])) --ans;
	};
	for(int i = 0; i < n; ++i) Update(i);
	while(q--)
	{
		char type;
		int x,y;
		cin >> type >> x >> y;
		--x;
		int temp = a[x];
		for(int i = x-1; i <= x+1; ++i) Restore(i);
		a[x] = y;
		for(int i = x-1; i <= x+1; ++i) Update(i);
		cout << ans << '\n';
		if(type == 'T')
		{
			for(int i = x-1; i <= x+1; ++i) Restore(i);
			a[x] = temp;
			for(int i = x-1; i <= x+1; ++i) Update(i);
		}
	}
}