#include <iostream>
#include <queue>
using namespace std;

int n, m;
int a[111][111];
double d[111];
bool inq[111];
int step[111];

int main()
{
	cin >> n >> m;
	int i, j;
	for (i = 0; i < m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		if (a[u][v] == 0) a[u][v] = c;
		else
			a[u][v] = (a[u][v] > c ? a[u][v] : c);
	}
	double left = 0, right = 1e7;
	for (int kk = 0; kk < 40; kk++)
	{
		double mid = (left + right) / 2;
		queue<int> q;
		for (i = 1; i <= n; i++)
			d[i] = 0, q.push(i);
		memset(inq, true, sizeof(inq));
		memset(step, 0, sizeof(step));
		bool OK = false;
		while (!q.empty())
		{

		}
	}

}