#include <iostream>
using namespace std;

// 5. Shell sort
template<typename T>
void ShellSort(T* arr, int len)
{
	int gap = len / 2;

	while (gap >= 1)
	{
		for (int i = gap; i <= len - gap; i += gap)
		{
			T element = arr[i];
			int index = i - gap;

			while (index >= 0 && arr[index] > element)
			{
				arr[index + gap] = arr[index];
				index -= gap;
			}
			arr[index + gap] = element;
		}

		gap /= 2;
	}
}

int main()
{
	int arr[8] = { 170, 45, 75, 90, 802, 24, 2, 66 };
	ShellSort(arr, 8);

	for (int i = 0; i < 8; i++)
		cout << arr[i] << " ";
}