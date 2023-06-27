#include <bits/stdc++.h>
using namespace std;
const int N = 107;
int n,a[N],k;
int state[N], sum;
void Print()
{
    for(int i = 0; i < n; ++i)
    {
        if(state[i]) cout << a[i] << ' ';
    }
    cout << '\n';
}
void Solve(int pos)
{
    if(pos == n)
    {
        if(sum == k) Print();
        return;
    }
    for(int i = 1; i >= 0; --i)
    {
        state[pos] = i;
        sum += i*a[pos];
        if(sum <= k) Solve(pos+1);
        sum -= i*a[pos];
    }
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    cin >> k;
    Solve(0);
}