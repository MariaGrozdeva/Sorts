#include <iostream>
#include <string>

using namespace std;

struct Student
{
	string name;
	int grade;
};

// 1. Counting sort (Complexity - 0(n+m)) // n - size of the array(len), m - restriction for the array's elements (arr[i] = 1,2,..,m)
void CountingSortForGrades(Student* arr, int len)
{
	const int range = 5;
	int enumerativeArray[range] = { 0 };
	Student* result = new Student[len];

	for (int i = 0; i < len; i++)
		enumerativeArray[arr[i].grade - 2]++;

	for (int i = range - 1; i > 0; i--)
		enumerativeArray[i - 1] += enumerativeArray[i];

	for (int i = 0; i < len; i++)
	{
		Student currentStudent = arr[i];
		int index = enumerativeArray[currentStudent.grade - 2]--;
		result[len - index] = currentStudent;
	}

	for (int i = 0; i < len; i++)
		arr[i] = result[i];
	delete[] result;
}

int main()
{
	Student arr[] = { { "Petur", 4 }, { "Ivan", 6 }, { "Paul", 4 }, { "Vladimir", 5 }, { "Petq", 5 } };

	CountingSortForGrades(arr, 5);

	for (int i = 0; i < 5; i++)
		cout << "Name: " << arr[i].name << ", grade: " << arr[i].grade << endl;
}
