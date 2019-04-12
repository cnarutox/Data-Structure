#include <iostream>
using namespace std;
void Merge(long int *n,long int *temp, int L, int R, int Rend)
{
 	int i = L, l = L, r = R;
	while (l < R && r <= Rend)
	{
		if (n[l] <= n[r])
			temp[i++] = n[l++];
		else temp[i++] = n[r++];
	}
	while (l < R)
		temp[i++] = n[l++];
	while (r <= Rend)
		temp[i++] = n[r++];
	for (i = L; i <= Rend; i++)
		n[i] = temp[i];
}
void Merge_Sort(long int *n, long int *temp, int L, int Rend)
{
	if (L < Rend)
	{
		int center = (L + Rend) / 2;
		Merge_Sort(n, temp, L, center);
		Merge_Sort(n, temp, center + 1, Rend);
		Merge(n, temp, L, center + 1, Rend);
	}
}
int main()
{
	int N;
	cin >> N;
	long int *n = new long int[N], *m = new long int[N];
	for (int i = 0; i < N; i++)
		cin >> n[i];
	//Merge_Sort(µÝ¹é)
	Merge_Sort(n, m, 0, N - 1);
	//Merge_Sort(·ÇµÝ¹é)
	for (int i = 0; i < N - 1; i++)
		cout << n[i] << ' ';
	cout << n[N - 1] << endl;
	return 0;
}