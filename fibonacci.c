#include<stdio.h>
int main()
{
    int a = 0, i = 0, sum = 0;
    int b = 1;
    int arr[6];
    arr[0] = 0;
    arr[1] = 1;
    while(i < 4)
    {
        sum = arr[i] + arr[i+1];
        arr[i+2] = sum;
        i++;
    }
    for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        printf("%d\n", arr[i]);
    }
}