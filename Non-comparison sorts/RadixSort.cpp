#include <iostream>
using namespace std;

int getMax(int* arr, int len)
{
	int max = arr[0];
	for (int i = 1; i < len; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

void CountingSort(int* arr, int len, int range, int exp)
{
	int* enumerativeArray = new int[range] {0};
	int* result = new int[len];

	for (int i = 0; i < len; i++)
		enumerativeArray[(arr[i] / exp) % 10]++;

	for (int i = range - 1; i > 0; i--)
		enumerativeArray[i - 1] += enumerativeArray[i];

	for (int i = 0; i < len; i++)
	{
		int currentDigit = (arr[i] / exp) % 10;
		int index = enumerativeArray[currentDigit]--;
		result[len - index] = arr[i];
	}

	for (int i = 0; i < len; i++)
		arr[i] = result[i];

	delete[] result;
	delete[] enumerativeArray;
}

// 1. Radix sort (Complexity - 0(d(n+m)), d - max number of digits in each number,
//                                        n - size of the array(len), m - restriction for the array's elements (arr[i] = 1,2,..,m)
void RadixSort(int* arr, int len, int d)
{
	int range = 10;
	int maxElement = getMax(arr, len);

	for (int exp = 1; maxElement / exp > 0; exp *= 10) // d iterations
		CountingSort(arr, len, range, exp);
}

int main()
{
	int arr[8] = { 170, 45, 75, 90, 802, 24, 2, 66 };
	RadixSort(arr, 8, 3); // d=3, n=8, m=10

	for (int i = 0; i < 8; i++)
		cout << arr[i] << " ";
}