#include <iostream>
using namespace std;
int *k, K, max = 0;
int DivideAndConquer(int first, int last)
{
	if (first == last)
		if(k[first] > 0) return k[first];
		else return 0;
	int m = 0, left, right, middle;
	middle = (first + last) / 2;
	left = DivideAndConquer(first, middle);
	right = DivideAndConquer(middle + 1, last);
	for (int i = middle, sum = 0; i >= first; i--)
	{
		sum += k[i];
		if (sum > m) m = sum;
	}
	for (int i = middle + 1, sum = m; i <= last; i++)
	{
		sum += k[i];
		if (sum > m) m = sum;
	}
	return left > (right > m ? right : m) ? left : (right > m ? right : m);
}
int main()
{
	cin >> K; k = new int[K];
	for (int i = 0; i < K; i++)
		cin >> k[i];
	//T( N ) = O( N3 )
	for (int i = 0; i < K; i++)
		for (int j = i; j < K; j++)
			for (int p = i, sum = 0; p <= j; p++)
			{
				sum += k[p];
				if (sum > max)
					max = sum;
			}
	//T( N ) = O( N2 )
	for (int i = 0; i < K; i++)
		for (int j = i, sum = 0; j < K; j++)
		{
			sum += k[j];
			if (sum > max)
				max = sum;
		}
	//O( N log N )
	max = DivideAndConquer(0, K - 1);
	//T( N ) = O( N)
	for (int i = 0, sum = 0; i < K; i++)
	{
		sum += k[i];
		if (sum > max)
			max = sum;
		else if (sum <= 0)
			sum = 0;
	}

	if (max < 0)
		max = 0;
	cout << max << endl;
	return 0;
}