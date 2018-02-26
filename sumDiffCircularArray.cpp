/*
Given an array of n elements. Consider array as circular array i.e element after an is a1. The task is to find maximum sum of the difference between consecutive elements with rearrangement of array element allowed i.e after rearrangement of element find |a1 – a2| + |a2 – a3| + …… + |an – 1 – an| + |an – a1|.

Examples:

Input : arr[] = { 4, 2, 1, 8 }
Output : 18
Rearrange given array as : { 1, 8, 2, 4 }
Sum of difference between consecutive element
= |1 - 8| + |8 - 2| + |2 - 4| + |4 - 1|
= 7 + 6 + 2 + 3
= 18.

Input : arr[] = { 10, 12, 15 }
Output : 10
*/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>

using namespace std;

int main()
{
    int arr[] = {1,2,3,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    vector<int> alternate_sort;
    int i = 0, j = n - 1;
    while(i < j)
    {
        alternate_sort.push_back(arr[i++]);
        alternate_sort.push_back(arr[j--]);
    }

    if(n%2 != 0)
        alternate_sort.push_back(arr[i]);
    int sum = 0;
    for(int i = 0; i < alternate_sort.size(); i++)
    {
        cout<<alternate_sort.at(i)<<endl;
        if(i != n - 1)
            sum = sum + abs(alternate_sort.at(i) - alternate_sort.at(i+1));
    }
    sum = sum + abs(alternate_sort.at(n-1) - alternate_sort.at(0));
    cout << "Sum is: "<<sum<<endl;
}