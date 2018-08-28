#include <iostream>
#include <cmath>
using namespace std;
#define sz 100001
#define modul 2111992
int main()
{
	int n, k;
	int ans;
	cin >> n >> k;
	if (k == 0)
		ans = (int)pow(2, double(n));
	else
	{
		int dp[sz];
		int i;
		dp[0] = 1;
		dp[1] = 2;
		dp[2] = 3;
		for (i = 3; i <= n; i++)
			dp[i] = (dp[i - 1] + dp[i - k - 1]) % modul;
		ans = dp[n];
	}
	cout << ans;
	return 0;
}