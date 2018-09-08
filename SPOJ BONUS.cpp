#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1000;


int max(int x, int y)
{
	return (x > y ? x : y);
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	
	int n, k, i, j, res = -1, x;
	cin >> n >> k;
	vector< vector<int> > dp(n + 1, vector<int>(n + 1, 0));
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cin >> x;
			dp[i][j] = x + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
			if (i >= k && j >= k)
			{
				res = max(res, dp[i][j] - (dp[i - k][j] + dp[i][j - k] - dp[i - k][j - k]));
			}
		}
	}
	cout << res;
	return 0;
}