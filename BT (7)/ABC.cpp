#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;
int n, tmp_cnt, ans_cnt = 1e9;
string ans,temp;
void Update()
{
	if(tmp_cnt < ans_cnt)
	{
		ans = temp;
		ans_cnt = tmp_cnt;
	}
}
bool Check(int pos)
{
	int len = 0;
	while(true)
	{
		++len;
		int y = pos-len+1;
		int x = y-len;
		if(x < 0) break;
		bool match = true;
		for(int j = 0; j < len; ++j)
		{
			match &= (temp[x+j] == temp[y+j]);
		}
		if(match) return false;
	}
	return true;
}
void Try(int pos)
{
	if(pos == n)
	{
		Update();
		return;
	}
	else
	{
		for(int i = 'A'; i <= 'C'; ++i)
		{
			temp[pos] = i;
			if(tmp_cnt + (n-pos)/4 + 1 > ans_cnt) continue;
			if(temp[pos] == 'C') ++tmp_cnt;
			if(Check(pos)) Try(pos+1);
			if(temp[pos] == 'C') --tmp_cnt;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	ans = string(n,'C');
	temp = string(n,'A');
	ans_cnt = 1e9;
	Try(0);
	cout << ans << '\n';
}