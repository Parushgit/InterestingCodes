
#include<stdlib.h>
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

/*C++ Program for merge sort*/
void mergingTheArrays(int arr[], int l, int mid, int r) {
    int i, j, k;
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int arr1[n1];
    int arr2[n2];

    for(i = 0; i < n1; i++) {
        arr1[i] = arr[l+i];
    }

    for(i = 0; i < n2; i++) {
        arr2[i] = arr[mid+1+i];
    }

    i = 0;
    j = 0;
    k = l;
    
    while(i < n1 && j < n2) {
        if(arr1[i] <= arr2[j]) {
            arr[k] = arr1[i];
            i++;
        }
        else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int len) {
    int mid;
    if(l < len) {
        mid = l + (len - l)/2; //To save overflow
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, len);

        mergingTheArrays(arr, l, mid, len);
    }
}
int main() {
	int arr[] = {2,1,3,4,-1,-9,10,22,13};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
	return 0;
}
