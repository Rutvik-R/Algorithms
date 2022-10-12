#include <iostream>
using namespace std;


/*
Types of algo :


Selection Sort 						O(n^2)
Bubble Sort 						O(n^2)
Insertion Sort 						<= O(n^2)
Merge Sort 							O(nlog(n))
Quick sort 							O(nlog(n))
Counting Sort 						O(n+k)  k=> range of input
Radix Sort 							O(d)(n+k)  d=> no of digit of maximum no

*/

int n ;

/*

// Selection Sort

void selection_Sort(int arr[]) {
	for (int i = 0; i < n; i++) {
		int min = i;

		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		if (min != i) {
			int temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}

*/
/*
//insertion sort
void insertion_Sort(int arr[]) {
	int key;
	int j = 0;
	for (int i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
*/


/*
//bubble_sort
void bubble_Sort(int arr[]) {
	for (int i = 0; i < n; i++) {
		bool a = true;
		for (int j = 0; j < (n - i - 1); j++) {
			if (arr[j] > arr[j + 1]) {
				a = false ;
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		if (a == true) break ;
	}
}

*/

/*
// merge sorting

void merge(int arr[] , int left , int right) {
	int mid = (left + right) / 2 ;
	int i = left , j = 0 , k = mid + 1 ;
	int temp[right - left + 1];
	while (j <= (right - left )) {
		if (arr[i] <= arr[k] && i <= mid  && k <= right) {
			temp[j] = arr[i];
			i++;

		}
		else if (i < mid + 1 && k <= right) {

			temp[j] = arr[k];
			k++;
		}
		else if (i > mid ) {
			temp[j] = arr[k] ;
			k++;
		}
		else {
			temp[j] = arr[i];
			i++;
		}
		j++;
	}
	for (int it = left; it < right + 1; ++it)
	{
		arr[it]  = temp[it - left];
	}
}

void merge_sort(int arr[] , int left , int right) {

	if (left < right) {
		int mid = (left + right) / 2 ;
		merge_sort(arr , left , mid);
		merge_sort(arr , mid + 1 , right);
		merge(arr , left , right);
	}
}
*/

/*
// Qiuck sort
int partition(int arr[] , int left , int right) {
	int dumi[n];
	int t = left , j = right ;

	for (int i = left; i < right + 1; ++i)
	{
		if (arr[i] < arr[right]) {
			dumi[t] = arr[i];
			t++;
		}
		else {
			dumi[j] = arr[i];
			j--;
		}

	}
	for (int i = left; i < right + 1; ++i)
	{
		arr[i] = dumi[i];
	}
	return t - 1;
}

void qiuck_sort(int arr[] , int left  , int right) {
	if (right > left) {
		int p = partition(arr , left , right);
		qiuck_sort(arr , left , p - 1);
		qiuck_sort(arr , p + 1 , right);
	}


}

*/


/*
// counting sort
void counting_sort(int arr[] , int max) {
	int dumi[max + 1];
	for (int i = 0; i < max + 1; ++i)
		dumi[i] = 0;

	for (int i = 0; i < n; ++i)
	{
		dumi[arr[i]]++;
	}
	int k = 0 ;
	for (int i = 0; i < max + 1; ++i)
	{
		for (int j = 0; j < dumi[i]; ++j)
		{
			arr[k] = i ;
			k++;
		}
	}
}
*/


/*
//radix sort
void countingSort(int arr[] , int div) {
	int temp[10];
	int arr1[n] ;
	for (int i = 0; i < 10; ++i)
		temp[i] = 0;

	for (int i = 0; i < n; ++i)
	{
		temp[(arr[i] / div) % 10]++;
	}

	for (int i = 1; i < 10; ++i)
	{
		temp[i] = temp[i - 1] + temp[i] ;
	}

	for (int i = n - 1; i + 1 ; i--)
	{
		temp[(arr[i] / div) % 10]--;
		arr1[temp[(arr[i] / div) % 10]] = arr[i] ;
	}

	for (int i = 0; i < n; ++i)
	{
		arr[i] = arr1[i];
	}
	// arr = arr1;
}


void radix_sort(int arr[] , int max) {
	// cout << "hi";
	for (int div = 1 ; max / div > 0; div *= 10)
	{
		countingSort(arr , div);
	}

}

*/


int main() {
	cin >> n;
	int arr[n] ;
	int max = 0 ;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if (max < arr[i]) max = arr[i];
	}

	// selection_sort(arr);
	// insertionSort(arr);
	// bubble_Sort(arr);
	// merge_sort(arr , 0 , n - 1);
	// qiuck_sort(arr , 0 , n - 1);
	// counting_sort(arr , max);
	// radix_sort(arr , max);
	for (int i = 0; i < n; ++i) cout << arr[i] << " ";

	return 0;
}