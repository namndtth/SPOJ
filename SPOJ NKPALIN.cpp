#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#define SZ 2005
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define max(a, b) ((a) > (b) ? (a) : (b))
int f[SZ][SZ], n;
string s;

int main()
{
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> s; n = s.length();
	//FOR(len, 1, n) FOR(i, 0, n - len)
	//{
	//	int j = i + len - 1;
	//	if (len == 1) f[i][j] = 1;
	//	else
	//	{
	//		f[i][j] = (s[i] == s[j] ? f[i + 1][j - 1] + 2 : max(f[i][j - 1], f[i + 1][j]));
	//	}
	//}
	for (int len = 1; len <= n; len++)
		for (int i = 0; i <= n - len; i++)
		{
			int j = i + len - 1;
			if (len == 1) f[i][j] = 1;
			else
			{
				f[i][j] = (s[i] == s[j] ? f[i + 1][j - 1] + 2 : max(f[i][j - 1], f[i + 1][j]));
			}
		}
	cout << f[0][n - 1];
	return 0;
}