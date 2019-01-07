#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void swap(int *, int *);
int partition(int [], int, int);
void printArray(int [], int);
void quickSort(int [], int, int);

int MAX_1 = 20;

int main() {
	int d1[MAX_1];
	
	// Initialize random seed
	srand(time(NULL));

// D[20]
	cout << "Generating first array of 20 random integers..." << endl;
	for (int i = 0; i < MAX_1; i++) {
		// Generate a random number between 0 and 200 for every new index
		int r = (rand() % 200) + 1;

		d1[i] = r;
	}

	// Display the array of 20 random integers
	cout << "D[20] = {";
	for (int i = 0; i < MAX_1; i++) {
		cout << d1[i] << ", ";

		if (i == MAX_1 - 1) {
			cout << d1[i] << "}";
			cout << endl;
		}
	}
	cout << endl;
	cout << endl;

	cout << "Performing quick sort..." << endl;
	quickSort(d1, 0, MAX_1 - 1);
	cout << endl;
	cout << "SORTED: D[20] = {";
	printArray(d1, MAX_1);

	return 0;
}

void quickSort(int d[], int low, int high) {
	if (low < high) {
		// pi = partitioning index
		int pi = partition(d, low, high);

		// Separately sort elements before partition and after partition
		quickSort(d, low, pi - 1);
		quickSort(d, pi + 1, high);
	}
}

int partition(int d[], int low, int high) {
	int pivot = d[high];	// Pivot
	int i = (low - 1);	// Index of smaller element
	
	for (int j = low; j <= high - 1; j++) {
		// If current element is <= pivot
		if (d[j] <= pivot) {
			i++;
			swap(&d[i], &d[j]);
		}
	}

	swap(&d[i + 1], &d[high]);
	return (i + 1);
}

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void printArray(int d[], int MAX) {
	for (int i = 0; i < MAX; i++) {
		cout << d[i] << ", ";
		
		if (i == MAX - 1) {
			cout << d[i] << "}";
			cout << endl;
		}
	}
}

