#include <iostream>
using namespace std;

const int MAXN = 60000;
int fen[MAXN];
void update(int pos, int val)
{
	int i;
	for (i = pos; i <= MAXN; i += i & -i)
		fen[i] += val;
}
int get(int pos)
{
	int i, ans = 0;
	for (i = pos; i; i -= i & -i)
		ans += fen[i];
	return ans;
}
int main()
{
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n; cin >> n;
	int *arr = new int[n];
	int ans = 0;
	int i;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	for (i = 0; i < n; i++)
	{
		ans += get(arr[i] + 1);
		update(arr[i], 1);
	}
	cout << ans << "\n";
	return 0;
}
