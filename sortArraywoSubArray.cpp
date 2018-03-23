/* 
Sorting array except elements in a subarray
Given an array A positive integers, sort the array in ascending order such that element in given subarray (start and end indexes are input) in unsorted array stay unmoved and all other elements are sorted.
*/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

void sortArrayExceptUandL(int *array, int l, int u, int len)
{
    int *new_array = NULL;
    int new_len = len-(u-l+1);
    new_array = new int[new_len];
    int j = 0;
    for(int i = 0; i < len; i++)
    {
        if((i == l-1) || (i == u-1))
            continue;
        new_array[j] = array[i];
        j++;
    }
    j = 0;

    sort(new_array, new_array + new_len);

    for(int i = 0; i < len; i++)
    {
        if((i == l-1) || (i == u-1))
            continue;
        array[i] = new_array[j];
        j++;
    }
    delete [] new_array;
}

int main()
{
    int *array = NULL;
    int len, l, u;
    cout<<"Enter the array size:\n";
    cin>>len;
    if(len == 0)
        return 0;
    array = new int[len];
    for(int i = 0; i < len; i++)
        cin>>array[i];
    cout<<"Enter l and u:\n";
    cin>>l>>u;
    sortArrayExceptUandL(array, l, u, len);
    cout<<"New array:\n";
    for(int i = 0; i < len; i++)
        cout<<array[i]<<endl;
    delete [] array;
    return 0;
}