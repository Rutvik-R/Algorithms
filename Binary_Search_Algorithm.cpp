#include <bits/stdc++.h>
using namespace std;

int n ;

int binary_search_algo(int arr[] , int vel ) {
	int num;
	int left = 0 , right = n ;

	do
	{
		num = (left + right) / 2;
		if (arr[num] == vel) return num;
		else if (arr[num] < vel) left = num;
		else if (arr[num] > vel) right = num;

	} while ((right - left) > 1);

	return -1;
}


int main() {
	cin >> n ;
	int arr[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	sort(arr , arr + n);
	cout << binary_search_algo(arr , 4);
	return 0;
}