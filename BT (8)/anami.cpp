#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;
const int N = 3007;
i64 dp[N][N],mod=1e9+7;
i64 Solve(i64 n, i64 S)
{
    if (n == S) return 1;
    if (S > n) return 0;
    if (n == 0 || S == 0) return 0;
    if (dp[n][S] >= 0) return dp[n][S];
    dp[n][S] = (Solve(n - 1, S - 1) + Solve(n, 2 * S)) % mod;
    return dp[n][S];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(dp,-1,sizeof(dp));
	i64 n,S; cin >> n >> S;
	cout << Solve(n,S) << '\n';
}