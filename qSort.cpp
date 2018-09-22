
#include<stdlib.h>
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

/*C++ Program for Quick Sort*/
int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int i = l - 1;

    for(int j = l; j < r; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i + 1;
}
void quickSort(int arr[], int l, int r) {
    int index;
    if(l < r) {
        index = partition(arr, l, r); 
        quickSort(arr, l, index - 1);
        quickSort(arr, index + 1, r);
    }
}
int main() {
	int arr[] = {2,1,3,4,-1,-9,10,22,13};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
	return 0;
}
