// Replace every array element by multiplication of previous and next
// 1.5
// Given an array of integers, update every element with multiplication of previous and next elements with following exceptions. 
// a) First element is replaced by multiplication of first and second.
// b) Last element is replaced by multiplication of last and second last.

#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>

using namespace std;

int main()
{
    int arr[] = {2,3,4,5,6};
    int prev = arr[0];
    arr[0] = arr[0] * arr[1];

    for(int i = 1; i < sizeof(arr)/sizeof(arr[0]) - 1; i++)
    {
        int cur = arr[i];
        arr[i] = prev * arr[i+1];
        prev = cur;
    }
    arr[sizeof(arr)/sizeof(arr[0]) - 1] = prev * arr[sizeof(arr)/sizeof(arr[0]) - 1];
    int i = 0;
    while(i != sizeof(arr)/sizeof(arr[0]))
    {
        cout << arr[i]<<endl;
        i++;
    }
}