#include <iostream>
using namespace std;

template<typename T>
void Swap(T* arr, int x, int y)
{
	T temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

// 1. Bubble sort (Complexity - 0(n^2))
template<typename T>
void BubbleSort(T* arr, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		bool isSwapped = false;
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(arr, j, j + 1);
				isSwapped = true;
			}
		}

		if (!isSwapped)
			return;
	}
}

// 2. Cocktail shaker sort (Complexity - 0(n^2))
template<typename T>
void CocktailShakerSort(T* arr, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		bool isSwapped = false;
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(arr, j, j + 1);
				isSwapped = true;
			}
		}
		if (!isSwapped)
			return;

		for (int j = len - 1; j > i; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				Swap(arr, j, j - 1);
				isSwapped = true;
			}
		}
		if (!isSwapped)
			return;
	}
}


// 3. Selection sort (Complexity - 0(n^2))
template<typename T>
void SelectionSort(T* arr, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int minIndex = i;
		for (int j = minIndex + 1; j < len; j++)
		{
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}

		if (minIndex != i)
			Swap(arr, i, minIndex);
	}
}


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


// 6.0. Merge function - merges 2 sorted arrays
template<typename T>
void Merge(int* arr1, int len1, int* arr2, int len2)
{
	T* resultArray = new T[len1 + len2];

	int cursor1 = 0;
	int cursor2 = 0;
	int resultCursor = 0;

	while (cursor1 < len1 && cursor2 < len2)
	{
		if (arr1[cursor1] <= arr2[cursor2])
			resultArray[resultCursor++] = arr1[cursor1++];
		else
			resultArray[resultCursor++] = arr2[cursor2++];
	}

	while (cursor1 < len1)
		resultArray[resultCursor++] = arr1[cursor1++];
	while (cursor2 < len2)
		resultArray[resultCursor++] = arr2[cursor2++];

	for (int i = 0; i < len1 + len2; i++)
		arr1[i] = resultArray[i];
	delete[] resultArray;
}

// 6.1. Merge sort (Complexity - 0(nlog(n)))
template <typename T>
void MergeSort(T* arr, int len)
{
	if (len == 1)
		return;

	int mid = len / 2;

	MergeSort(arr, mid);
	MergeSort(arr + mid, len - mid);

	Merge<T>(arr, mid, arr + mid, len - mid);
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
	/*int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	ShellSort<int>(arr, 10);*/

	int arr[6] = { 5,4,3,2,1,0 };
	SelectionSort<int>(arr, 6);

	for (int i = 0; i < 6; i++)
		cout << arr[i] << " ";
}