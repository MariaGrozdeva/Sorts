#include <iostream>
using namespace std;

template<typename T>
void Swap(T* arr, int x, int y)
{
	T temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

//7.0. Partition function - puts the pivot on the right position and returns its index
template <typename T>
int Partition(T* arr, int len)
{
	T pivot = arr[len / 2];

	int i = 0;
	int j = len - 1;

	while (true)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;

		if (i < j)
			Swap(arr, i, j);
		else
			return j;
	}
}

// 7.1. Quick sort (Complexity - B.C,A.C(the pivot is the average number) - 0(nlog(n))
//                             - W.C(the pivot is the smallest/biggest number) - 0(n^2)
template <typename T>
void QuickSort(T* arr, int len)
{
	if (len <= 1)
		return;

	int pivotIndex = Partition<T>(arr, len);

	QuickSort(arr, pivotIndex);
	QuickSort(arr + pivotIndex + 1, len - pivotIndex - 1);
}

int main()
{
	int arr[8] = { 170, 45, 75, 90, 802, 24, 2, 66 };
	QuickSort(arr, 8);

	for (int i = 0; i < 8; i++)
		cout << arr[i] << " ";
}
