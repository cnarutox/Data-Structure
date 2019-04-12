#include <iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	long int *n = new long int[N];
	for (int i = 0; i < N; i++)
		cin >> n[i];
	//Bubble_Sort
	for (int i = N - 1, flag; i > 0; i--)
	{
		flag = 0;
		for (int j = 0; j < i; j++)
			if (n[j] > n[j + 1])
			{
				long int temp = n[j];
				n[j] = n[j + 1];
				n[j + 1] = temp;
				flag = 1;
			}
		if(!flag) break;
	}
	//Insert_Sort
	for (long int i = 1, j; i < N; i++)
	{
		long int temp = n[i];
		for (j = i; j > 0 && n[j - 1] > temp; j--)
			n[j] = n[j - 1];
		n[j] = temp;
	}
	for (int i = 0; i < N - 1; i++)
		cout << n[i] << ' ';
	cout << n[N - 1] << endl;
	return 0;
}