//#include <iostream>
//#include <queue>
//#define MAX 100100
//using namespace std;
//
//typedef pair <int, int> ii;
//bool b[MAX];
//int n, c;
//priority_queue<ii, vector<ii>, greater<ii>> q;
//void init(void)
//{
//	int i, x;
//	cin >> n;
//	for (i = 1; i <= n; i++)
//	{
//		cin >> x;
//		q.push(ii(x, i));
//		b[i] = true;
//	}
//}
//void process(void)
//{
//	c = 0;
//	ii x;
//	int i;
//	while (!q.empty())
//	{
//		while ((!q.empty()) && (!b[q.top().second]))
//			q.pop();
//		if (!q.empty())
//		{
//			x = q.top();
//			q.pop();
//			c = c + 1;
//			for (i = -1; i <= 1; i++)
//				b[x.second + i] = false;
//		}
//	}
//	cout << c;
//}
//int main(void)
//{
//	init();
//	process();
//}
#include <iostream>
using namespace std;
struct rec
{
	int val, pos;
};
const int maxn = 100001, maxv = 10000000;

int a[maxn];
rec s[8 * maxn];
int n, res, u, v;

void init()
{
	int i;
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> a[i];
	for (i = 1; i <= 8 * maxn; i++)
		s[i].val = maxv;
}
int min(int x, int y)
{
	return (x > y ? y : x);
}
void combine(int i)
{
	s[i].val = min(s[2 * i].val, s[2 * i + 1].val);
	if (s[2 * i + 1].val < s[2 * i].val)
		s[i].pos = s[2 * i + 1].pos;
	else
		s[i].pos = s[2 * i].pos;
}
void build(int i, int low, int high)
{
	int mid;
	if (low > high) return;
	if (low == high)
	{
		s[i].val = a[low];
		s[i].pos = low;
		return;
	}
	mid = (low + high) / 2;
	build(2 * i, low, mid);
	build(2 * i + 1, mid + 1, high);
	combine(i);
}
void update(int i, int low, int high)
{
	int mid;
	if (v < low || high < u) return;
	if (s[i].val == maxv) return;
	if (u <= low && high <= v)
	{
		s[i].val = maxn;
		s[i].pos = 0;
		return;
	}
	mid = (low + high) / 2;
	update(2 * i, low, mid);
	update(2 * i + 1, mid + 1, high);
	combine(i);
}
void solve()
{
	int t;
	res = 0;
	do {
		t = s[1].pos;
		if (t != 0)
		{
			res++;
			u = t - 1;
			v = t + 1;
			if (t == 1) u = 1;
			else
				if (t == n) v = n;
			update(1, 1, n);
		}
	} while (s[1].pos != 0);
}
int main()
{
	init();
	build(1, 1, n);
	solve();
	cout << res;
	return 0;
}