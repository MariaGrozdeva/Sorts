#include <iostream>
using namespace std;

// 4. Insertion sort (Complexity - 0(n^2))
template<typename T>
void InsertionSort(T* arr, int len)
{
	for (int i = 1; i < len; i++)
	{
		T element = arr[i];
		int index = i - 1;

		while (index >= 0 && arr[index] > element)
		{
			arr[index + 1] = arr[index];
			index--;
		}
		arr[index + 1] = element;
	}
}

int main()
{
	int arr[8] = { 170, 45, 75, 90, 802, 24, 2, 66 };
	InsertionSort(arr, 8);

	for (int i = 0; i < 8; i++)
		cout << arr[i] << " ";
}