#include <bits/stdc++.h>

using namespace std;

int m, n;
int a[222][222];
int b[222][222], bluu[222][222];
bool daxong;

bool inside( int i,int j) {
    return (i>=0) && (i<m) && (j>=0) && (j<n);
}

int check(int i,int j) {
    int total = a[i][j];
    for(int di=-1;di<=1;++di) for(int dj=-1;dj<=1;++dj) if(di!=0 || dj!=0) {
        int x = i + di;
        int y = j + dj;
        if(inside( x, y)) total -= b[x][y];
    }
    return total;
}

bool process(int i) {
    for(int j=1;j<i;++j) if(inside(i,j)) {
        b[i][j] = 0;
        int t = check( i-1, j-1);
        if(t!=0 && t!=1) return false;
        b[i][j] = t;
    }

    for(int j=1;j<i;++j) if(inside(j,i)) {
        b[j][i] = 0;
        int t = check( j-1, i-1);
        if(t!=0 && t!=1) return false;
        b[j][i] = t;
    }
    if(inside(i,i)) {
        b[i][i] = 0;
        int t = check(i-1,i-1);
        if(t!=0 && t!=1) return false;
        b[i][i] = t;
    }
    return true;
}

//int dem = 0;

void duyet(int i) {
    //cerr << i << '\n';
    if(daxong) return;
    if(i>=m && i>=n) {
        //++dem;
        bool ok = true;
        for(int j=0;j<m;++j) if(inside(j,n-1) &&  check(j,n-1)!=0) {
            //if(dem==2) cout << j << " " << n-1 << " " << check(j,n-1) << " " << a[j][n-1] << endl;
            ok = false;
            break;
        }
        for(int j=0;j<n;++j) if(inside(m-1,j) && check(m-1,j)!=0) {
            //if(dem==2) cout << m-1 << " " << j << " " << check(m-1,j) << " " << a[m-1][j] << endl;
            ok = false;
            break;
        }
        cerr << ok << '\n';
        if(!ok) return;
        daxong = true; 

        //for(int i=0;i<m;++i) { for(int j=0;j<n;++j) printf("%d ", b[i][j]); puts(""); }
        //puts("");

        //cout << check(0, 3) << " " << a[0][3] << endl << endl;

        memmove( bluu, b, sizeof(b));
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j) cout << bluu[i][j] << ' ';
            cout << '\n';
        }
        exit(0);
    }

    if(i==0) {
        b[0][0] = 0;
        duyet(i+1);
        b[0][0] = 1;
        duyet(i+1);
        return;
    }

    for(b[i][0]=0;b[i][0]<2;++b[i][0]) for(b[0][i]=0;b[0][i]<2;++b[0][i]) {
        bool ok = process(i);
        if(ok) duyet(i+1);
    }

}
const int N = 207;
int cnt[N][N], c[N][N];
int _x[] = {-1,-1,-1,0,0,1,1,1,0};
int _y[] = {-1,0,1,-1,1,-1,0,1,0};
bool Check(int x, int y, int val)
{
    if(x < 1 || y < 1 || x > n || y > m) return true;
    for(int i = 0; i < 8; ++i)
    {
        int u = x + _x[i];
        int v = y + _y[i];
        if(u < 1 || v < 1 || u > n || v > m) continue;
        if(cnt[u][v] + val > a[u][v]) return false;
    }
    return true;
}
void Update(int x, int y, int val)
{
    if(x < 1 || y < 1 || x > n || y > m) return;
    for(int i = 0; i < 8; ++i)
    {
        int u = x + _x[i];
        int v = y + _y[i];
        if(u < 1 || v < 1 || u > n || v > m) continue;
        cnt[u][v] += val;
    }
}
bool Verify(int x, int y)
{
    return a[x][y] == cnt[x][y];
}
void Out()
{
    if(!Verify(n,m)) return;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            cout << b[i][j] << ' ';
        }
        cout << '\n';
    }
    exit(0);
}
void Try(int x, int y)
{
    bool check = Verify(x-1,y-1);
    if(y == m) check &= Verify(x-1,y);
    if(x == n) check &= Verify(x,y-1);
    if(check)
    {
        if(y == m)
        {
            if(x == n) Out();
            else Try(x+1,1);
        }
        else Try(x,y+1);
    }
    if(!Check(x,y,1)) return;
    b[x][y] += 1;
    Update(x,y,1);
    check = Verify(x-1,y-1);
    if(y == m) check &= Verify(x-1,y);
    if(x == n) check &= Verify(x,y-1);
    if(check)
    {
        if(y == m)
        {
            if(x == n) Out();
            else Try(x+1,1);
        }
        else Try(x,y+1);
    }
    b[x][y] -= 1;
    Update(x,y,-1);
}
int main()
{
    //freopen("input2.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j) cin >> a[i][j];
    }
    if(m == 1 || n == 1)
    {
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j) c[i][j] = a[i][j];
        }
        memset(a,0,sizeof(a));
        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                a[i][j] = c[i-1][j-1];
            }
        }
        swap(m,n);
        Try(1,1);
        exit(0);
    }
    daxong = false;
    duyet(0);
}