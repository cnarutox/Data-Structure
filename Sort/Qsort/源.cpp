#include <iostream>
#include <cstdlib>
using namespace std;
void swap(long int *a, long int *b)
{
	long int temp = *a;
	*a = *b;
	*b = temp;
}
long int Pivot(long int *n, int L, int R)
{
	int center = (L + R) / 2;
	if (n[L] > n[center]) swap(&n[L], &n[center]);
	if (n[L] > n[R]) swap(&n[L], &n[R]);
	if (n[center] > n[R]) swap(&n[center], &n[R]);
	swap(&n[center], &n[R - 1]);	
	return n[R - 1];
}
void QSort(long int *n, int L, int R)
{
	if (R - L > 10)
	{
		int i = L, j = R - 1;
		long int pivot = Pivot(n, L, R);
		while (1)
		{
			while (n[++i] < pivot);
			while (n[--j] > pivot);
			if (i < j) swap(&n[i], &n[j]);
			else break;
		}
		swap(&n[i], &n[R - 1]);
		QSort(n, L, i);
		QSort(n, i + 1, R);
	}
	else
		for (int i = L, j; i <= R; i++)
		{
			long int temp = n[i];
			for (j = i; j > L && n[j - 1] > temp; j--)
				n[j] = n[j - 1];
			n[j] = temp;
		}
}
int compare(const void *a, const void *b)
{
	return *(int*)a > *(int*)b;
}
int main()
{
	int N;
	cin >> N;
	long int *n = new long int[N];
	for (int i = 0; i < N; i++)
		cin >> n[i];
	//QSort
	QSort(n, 0, N - 1);
	//qsort(n, N, sizeof(long int), compare);
	for (int i = 0; i < N - 1; i++)
		cout << n[i] << ' ';
	cout << n[N - 1] << endl;
	return 0;
}