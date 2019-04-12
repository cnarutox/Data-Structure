#include <iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	long int *n = new long int[N];
	for (int i = 0; i < N; i++)
		cin >> n[i];
	//Shell_Sort
	for (int D = 2047; D > 0; D /= 2)
		for (int i = D, j; i < N; i++)
		{
			long int temp = n[i];
			for (j = i; j >= D && n[j - D] > temp; j -= D)
				n[j] = n[j - D];
			n[j] = temp;
		}
	for (int i = 0; i < N - 1; i++)
		cout << n[i] << ' ';
	cout << n[N - 1] << endl;
	return 0;
}