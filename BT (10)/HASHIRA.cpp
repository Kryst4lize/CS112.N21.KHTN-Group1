#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;
using ld = long double;
using point = pair<ld,ld>;
struct Line
{
	ld a,b,c;
};
ld pi = 3.141592653589793238462643383279502884197;
ld eps = 1e-6;
point rotate(point a, ld angle)
{
	point ans;
	ans.first = a.first*cos(angle) - a.second*sin(angle);
	ans.second = a.first*sin(angle) + a.second*cos(angle);
	return ans;
}
Line MakeLine(point direction_vector, point p)
{
	Line ans;
	ans.a = -direction_vector.second;
	ans.b = direction_vector.first;
	ans.c = -ans.a*p.first - ans.b*p.second;
	return ans;
}
ld Get_val(Line a, point p)
{
	return a.a*p.first + a.b*p.second + a.c;
}
point Intersect(Line a, point x, point y)
{
	Line b = MakeLine({y.first-x.first,y.second-x.second},x);
	ld D = a.a*b.b - a.b*b.a;
	ld Dx = (-a.c)*b.b - (-b.c)*a.b;
	ld Dy = a.a*(-b.c) - (-a.c)*b.a;
	return {Dx/D,Dy/D};
}
ld Area(vector <point> &a)
{
	ld area = 0;
	for(int i = 0; i < a.size(); ++i)
	{
		int j = (i+1)%a.size();
		area += (a[i].first*a[j].second - a[i].second*a[j].first);
	}
	return area/2;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		vector <point> a(n);
		for(auto &i : a) cin >> i.first >> i.second;
		point start, direction;
		start.first = (a[0].first+a[1].first)/2;
		start.second = (a[0].second+a[1].second)/2;
		direction.first = a[1].first-a[0].first;
		direction.second = a[1].second-a[0].second;
		Line line = MakeLine(rotate(direction,pi/4),start);
		point intersect_cw, intersect_ccw;
		int idx_cw,idx_ccw;
		vector <point> b;
		for(int i = 1; i < n; ++i)
		{
			int j = (i+1)%n;
			if(Get_val(line,a[i])*Get_val(line,a[j]) < eps)
			{
				idx_ccw = i;
				intersect_ccw = Intersect(line,a[i],a[j]);
				break;
			}
		}
		line = MakeLine(rotate(direction,pi/4*3),start);
		for(int i = n-1; i >= 1; --i)
		{
			int j = (i+1)%n;
			if(Get_val(line,a[i])*Get_val(line,a[j]) < eps)
			{
				idx_cw = i;
				intersect_cw = Intersect(line,a[i],a[j]);
				break;
			}
		}
		b.push_back(intersect_ccw);
		for(int i = idx_ccw+1; i <= idx_cw; ++i) b.push_back(a[i]);
		b.push_back(intersect_cw);
		b.push_back(start);
		cout << fixed << setprecision(10) << Area(b)/Area(a) << '\n';
	}
}