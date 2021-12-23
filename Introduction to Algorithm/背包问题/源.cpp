#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int n, W, *v, *w, **M;
	string **bag;
	cin >> W >> n;
	v = new int[n];
	w = new int[n];
	M = new int*[n + 1];
	bag = new string*[n + 1];
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
		cin >> v[i];
		M[i] = new int[W + 1];
		bag[i] = new string[W + 1];
	}
	M[n] = new int[W + 1];
	bag[n] = new string[W + 1];
	for (int i = 0; i <= n; i++)
	{
		s.clear();
		for (int k = 0; k < i; k++)
			s.append("0");
		for (int j = 0; j <= W; j++)
		{
			M[i][j] = 0;
			bag[i][j] = s;
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= W; j++)
		{
			if (w[i - 1] > j)
			{
				M[i][j] = M[i - 1][j];
				bag[i][j] = bag[i - 1][j] + "0";
			}
			else
				if (M[i - 1][j] > v[i - 1] + M[i - 1][j - w[i - 1]])
				{
					M[i][j] = M[i - 1][j];
					bag[i][j] = bag[i - 1][j] + "0";
				}
				else {
					M[i][j] = v[i - 1] + M[i - 1][j - w[i - 1]];
					bag[i][j] = bag[i - 1][j - w[i - 1]] + "1";
				}
		}
	cout << bag[n][W] << endl << M[n][W] << endl;
	return 0;
}