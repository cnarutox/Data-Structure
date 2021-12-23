#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct num
{
	int val;
	int sum;
	num(int val) :val(val), sum(val) {};
};
int n, m = 0;
vector<num> *vec;
int Max(int i, int j)
{
	if (i == 0) return 0;
	if (j == 0) return vec[i - 1][j].sum;
	if (j == i) return vec[i - 1][j - 1].sum;
	return max(vec[i - 1][j - 1].sum, vec[i - 1][j].sum);
}
int main()
{
	cin >> n;
	vec = new vector<num>[n];
	for (int i = 0, t; i < n; i++)
		for (int j = 0; j <= i; j++)
		{
			cin >> t;
			vec[i].push_back(num(t));
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			vec[i][j].sum += Max(i, j);
	for (int i = 0; i < n; i++)
		m = max(vec[n - 1][i].sum, m);
	cout << m << endl;
	return 0;
}