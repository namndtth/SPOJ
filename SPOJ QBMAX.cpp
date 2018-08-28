#include <iostream>
#include <climits>
using namespace std;
int max(int a, int b)
{
	return (a > b ? a : b);
}
int max(int a, int b, int c)
{
	return (max(a, b) > c ? max(a, b) : c);
}
int main()
{
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int A[100][100];
	int rows, cols;
	cin >> rows >> cols;
	int i, j;
	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
			cin >> A[i][j];
	int B[100][100];
	for (i = 0; i < rows; i++)
		B[i][0] = A[i][0];

	for (j = 1; j < cols; j++)
		for (i = 0; i < rows; i++)
		{
			if (i == 0)
				B[i][j] = A[i][j] + max(B[i][j - 1], B[i + 1][j - 1]);
			else
				if (i == rows - 1)
					B[i][j] = A[i][j] + max(B[i - 1][j - 1], B[i][j - 1]);
				else
					B[i][j] = A[i][j] + max(B[i - 1][j - 1], B[i][j - 1], B[i + 1][j - 1]);
		}
	int ans = INT_MIN;
	for (i = 0; i < rows; i++)
		if (ans < B[i][cols - 1])
			ans = B[i][cols - 1];
	cout << ans;
}