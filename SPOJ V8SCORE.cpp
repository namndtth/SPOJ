#include <iostream>
#include <string>
using namespace std;

#define sz 20

int S;
int k, n;
int **A;
int sum = 0;
string ans = "NO";
int *res;
void backtrack(int col)
{
	if (col == k && sum == S)
	{
		ans = "YES";
		return;
	}
	if (col == k)
		return;
	for (int row = 0; row < n; row++)
	{
		if ((col == 0) || (col != 0 && A[row][col] >= res[col - 1]))
		{
			sum += A[row][col];
			res[col] = A[row][col];
			if (col < k - 1 && sum >= S)
				return;
			if (col < k)
				backtrack(col + 1);
			sum -= A[row][col];
		}
	}
}
int main()
{
	int i, j;
	cin >> S >> k >> n;
	A = new int*[n];	
	res = new int[k];
	for (i = 0; i < n; i++)
		A[i] = new int[k];
	for (i = 0; i < n; i++)
		for (j = 0; j < k; j++)
			cin >> A[i][j];
	backtrack(0);
	if (ans == "YES")
	{
		cout << ans << "\n";
		for (int i = 0; i < k; i++)
			cout << res[i] << " ";
	}
	else
		cout << ans << "\n";
	return 0;
}