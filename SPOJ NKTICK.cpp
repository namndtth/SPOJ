#include <iostream>
using namespace std;
int main()
{
	int n, t[60000], r[60000], a[60000];
	long m = 0, f[60000];
	cin >> n;
	int i;
	for (i = 0; i < n; i++)
		cin >> t[i];
	for (i = 0; i < n - 1; i++)
		cin >> r[i];
	for (i = 0; i < n - 1; i++)
	{
		a[i] = t[i] + t[i + 1] - r[i];
		if (a[i] < 0)
			a[i] = 0;
	}
	f[0] = 0;
	f[1] = a[0];
	for (i = 2; i < n; i++)
	{
		if (f[i - 2] + a[i - 1] > f[i - 1])
			f[i] = f[i - 2] + a[i - 1];
		else
			f[i] = f[i - 1];
	}
	for (i = 0; i < n; i++)
		m += t[i];
	m = m - f[n - 1];
	cout << m;
	return 0;
}