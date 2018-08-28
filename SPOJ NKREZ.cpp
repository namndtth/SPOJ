#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define sz 10000

struct time
{
	int st;
	int fn;
};
time req[sz];
int n;
bool operator <(const time &x, const time &y)
{
	return (x.fn < y.fn);
}
int solve()
{
	int dp[sz];
	memset(dp, 0, sizeof dp); 
	int i, j;
	for (i = 1; i <= n; i++)
	{
		dp[i] = dp[i - 1];
		for (j = 0; j <= i - 1; j++)
			if (req[j].fn <= req[i].st && dp[j] + (req[i].fn - req[i].st) > dp[i])
				dp[i] = dp[j] + (req[i].fn - req[i].st);
	}
	return dp[n];
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	int i;

	req[0].st = req[0].fn = 0;

	for (i = 1; i <= n; i++)
		cin >> req[i].st >> req[i].fn;

	sort(req, req + n);

	/*for (i = 0; i < n; i++)
		cout << req[i].st << " " << req[i].fn << "\n";*/
	cout << solve();
	return 0;
}
