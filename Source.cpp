#include<iostream>
#define MAX 30

using namespace std;

void max_heapify(int array[], int n, int i)
{
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int largest = i;

	
	if ((left < n) && (array[left] > array[largest]))
		largest = left;

	if ((right < n) && ( array[right] > array[largest]))
		largest = right;

	if (largest != i)
	{
		int temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;

		max_heapify(array, n, largest);
	}


}
void heapSort(int array[], int n)
{
	// Build max heap
	for (int i = n / 2 - 1; i >= 0; i--)
		max_heapify(array, n, i);
	
	// Heap sort
	for (int i = n - 1; i >= 0; i--) 
	{
		
		int temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		
		

		// Heapify root element to get highest element at root again
		max_heapify(array, i, 0);
	}
}
int main()
{
	int array[MAX];
	int size;

	cout << "Enter the Size Of Array: ";
	cin >> size;

	cout << "Enter Elements Of Array.\n";
	for (int i = 0; i < size; i++)
		cin >> array[i];

	heapSort(array, size);

	cout << "After Sorting.\n";
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;

	system("pause");
}