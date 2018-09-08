#include <iostream>
using namespace std;
const int maxs = 1e8 + 1;
const int maxn = 100 + 1;
int min(int x, int y)
{
	return (x < y ? x : y);
}
int sol(int *arr, int n, int S)
{
	int i, j;
	int **dp = new int*[maxn];
	for (i = 0; i < maxn; i++)
		dp[i] = new int[maxs];
	
	for (i = 1; i <= n; i++)
		for (j = 1; j <= S; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (dp[i][j] > dp[i][j - arr[i - 1]] + 1)
				dp[i][j] = dp[i][j - arr[i - 1]] + 1;
		}
	return dp[n][S];
}
int main()
{
	int n, S;
	cin >> n >> S;
	int *arr = new int[n];
	int i;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	cout << sol(arr, n, S);
}