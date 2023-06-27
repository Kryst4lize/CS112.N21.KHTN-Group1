#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector <int> p(n);
    for(int i = 0; i < n; ++i) p[i] = i;
    vector <vector<int>> ans;
    do
    {
        bool able = true;
        for(int i = 0; i < n; ++i)
        {
            if(!able) break;
            for(int j = 0; j < i; ++j)
            {
                if(!able) break;
                if(i-j == abs(p[i]-p[j])) able = false;
            }
        }
        if(able) ans.push_back(p);
    }while(next_permutation(p.begin(),p.end()));
    if(!ans.size()) cout << "No solution found.";
    else
    {
        for(auto &a: ans)
        {
            cout << '[';
            for(int i = 0; i < n; ++i)
            {
                if(i) cout << ' ';
                cout << '(' << i+1 << ", " << a[i]+1 << ')';
            }
            cout << "]\n";
        }
    }
}