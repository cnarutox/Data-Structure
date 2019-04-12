#include <iostream>
#include<windows.h>
using namespace std;
void adjust(long int *n, int i, int N)
{
	long int temp = n[i];
	for (int child; 2 * i + 1 < N; i = child)
	{
		child = 2 * i + 1;
		if (child != N - 1 && n[child + 1] > n[child])
			child++;
		if (temp >= n[child]) break;
		else n[i] = n[child];
	}
	n[i] = temp;
}
int main()
{
	int N;
	cin >> N;
	long int *n = new long int[N];
	for (int i = 0; i < N; i++)
		cin >> n[i];
	//Heap_Sort 对数组从小到大排序就需要构造最大堆
	for (int i = N / 2; i >= 0; i--)
		adjust(n, i, N);
	//对数组排序
	for (int i = N - 1; i > 0; i--)
	{
		long int temp = n[0];
		n[0] = n[i]; n[i] = temp;
		adjust(n, 0, i);
	}
	for (int i = 0; i < N - 1; i++)
		cout << n[i] << ' ';
	cout << n[N - 1] << endl;
// 	int q = 1, w = 1, e = 1;
// 	while (true) {
// 		if (q++ == 9)
// 		{
// 			q = 1;
// 			keybd_event('Q', 0, 0, 0);
// 			
// 			keybd_event('Q', 0, KEYEVENTF_KEYUP, 0);
// 		}
// 		if (w++ == 11)
// 		{
// 			w = 1;
// 			keybd_event('W', 0, 0, 0);
// 			keybd_event('W', 0, KEYEVENTF_KEYUP, 0);
// 		}
// 		if (e++ == 16)
// 		{
// 			e = 1;
// 			keybd_event('E', 0, 0, 0);
// 			keybd_event('E', 0, KEYEVENTF_KEYUP, 0);
// 		}
// 		Sleep(1000);
// 	}
	return 0;
}