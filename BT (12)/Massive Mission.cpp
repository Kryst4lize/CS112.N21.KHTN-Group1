#include <bits/stdc++.h>
#define fo(i,m,n) for(int i = m; i <= n; i++)
#define fod(i,m,n) for(int i = m; i >= n; i--)
#define fov(i,x) for(auto &i : x)
#define x first
#define y second
using namespace std;
typedef int64_t i64;
typedef long double ld;
typedef pair<int,int> _ii;
typedef pair<ld,ld> _ld;
int T,n,pos;
ld pi,Ox,Oy,w,h,phi;
ld S,sum;
int deq[50000];
vector <_ld> a;
bool Clock_Wise_Check(ld x1, ld y1, ld x2, ld y2)
{
	return ((x1*y2)-(x2*y1)) <= 0;
}
void Run()
{
	deq[1] = 0;
	deq[2] = 1;
	pos = 2;
	int i = 2;
	while(i <= n-1)
	{
		while(pos >= 2 && !Clock_Wise_Check(a[deq[pos]].x - a[deq[pos-1]].x,a[deq[pos]].y - a[deq[pos-1]].y,a[i].x-a[deq[pos]].x,a[i].y-a[deq[pos]].y)) pos--;
		deq[++pos] = i;
		i++;
	}
	int temp = pos;
	i = n-2;
	while(i >= 0)
	{
		while(pos > temp && !Clock_Wise_Check(a[deq[pos]].x - a[deq[pos-1]].x,a[deq[pos]].y - a[deq[pos-1]].y,a[i].x-a[deq[pos]].x,a[i].y-a[deq[pos]].y)) pos--;
		deq[++pos] = i;
		i--;
	}
	/*fo(i,1,pos)
	{
		cout << a[deq[i]].x << ' ' << a[deq[i]].y << '\n';
	}*/
}
void P_Add()
{
	w /= 2.0;
	h /= 2.0;
	a.push_back({Ox+w,Oy+h});
	a.push_back({Ox-w,Oy-h});
	a.push_back({Ox-w,Oy+h});
	a.push_back({Ox+w,Oy-h});
}
void Add()
{
	ld q1,q2,p1,p2;
	q1 = h*sin(phi);
	q2 = w*cos(phi);
	p1 = h*cos(phi);
	p2 = w*sin(phi);
	//cout << q1 << ' ' << q2 << ' ' << p1 << ' ' << p2 << '\n';
	ld xA = Ox + (q1+q2)/2 - q2;
	ld yA = Oy + (p1+p2)/2;
	ld xB = Ox - (q1+q2)/2;
	ld yB = Oy + (p1+p2)/2 - p1;
	a.push_back({xA,yA});
	a.push_back({xB,yB});
	a.push_back({Ox*2.0-xA,Oy*2.0-yA});
	a.push_back({Ox*2.0-xB,Oy*2.0-yB});
}
void Input()
{
	S = 0.0;
	cin >> n;
	while(n--)
	{
		cin >> Ox >> Oy >> w >> h >> phi;
		S += w*h;
		if(phi == 0.0) 
		{
			P_Add();
			continue;
		}
		if(phi == 90.0)
		{
			swap(w,h);
			P_Add();
			continue;
		}
		if(phi < 0)
		{
			phi = abs(phi);
			phi = 90.0 - phi;
			swap(w,h);
		}
		phi = phi/180.0 * pi;
		Add();
	}
}
void Cal()
{
	sum = 0.0;
	fo(i,1,pos-1)
	{
		sum += (a[deq[i]].x*a[deq[i+1]].y - a[deq[i]].y*a[deq[i+1]].x);
	}
	sum = fabs(sum);
	sum /= 2.0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	pi = acos(-1);
	cin >> T;
	while(T--)
	{
		a.clear();
		Input();
		sort(a.begin(),a.end());
		n = unique(a.begin(),a.end()) - a.begin();
		Run();
		Cal();
		cout << fixed << setprecision(2) << S*100.0/sum << '\n';
	}
}