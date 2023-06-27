#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
const int inf=1e9+7;
const ll ll_inf=1e18+7;
const ll MOD=1e9+7;
const int numD=4;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
const char direct[]={'R','L','D','U'};

const int N=7;

string path;
bool mark[N+2][N+2];
int cnt;

void show(){
	for(int i=1;i<=N;i++,cout<<"\n")
		for(int j=1;j<=N;j++)
			cout<<mark[i][j];
	cout<<endl;
}

void dfs(int i,int j,int num){
	if(i==N&&j==1&&num==N*N-1){
		cnt++;
		//cerr << cnt;
		return;
	}

	if(N-i+j-1>N*N-num-1) return;
	mark[i][j]=true;
	//show();
	//cout<<i<<" "<<j<<" "<<num<<endl;
    if((mark[i][j-1])&&(mark[i][j+1])) {
        if((mark[i-1][j])==(mark[i+1][j])) {
            mark[i][j]=false; return;
        }
    }
    if((mark[i-1][j])&&(mark[i+1][j])) {
        if((mark[i][j-1])==(mark[i][j+1])) {
            mark[i][j]=false; return;
        }
    }
	for(int k=0;k<4;k++){
		int x=i+dx[k];
		int y=j+dy[k];
        if(x==N&&y==1&&num<47) continue;
		if(path[num]!='?'&&path[num]!=direct[k]) continue;
		if(!mark[x][y]) dfs(x,y,num+1);
	}
	mark[i][j]=false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>path;
	for(int i=0;i<=N+1;i++)
		mark[i][0]=mark[0][i]=mark[i][N+1]=mark[N+1][i]=true;
	dfs(1,1,0);
	cout<<cnt << '\n';
}