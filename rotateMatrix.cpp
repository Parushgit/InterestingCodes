#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

void rotateMatrix_transpose(int ** matrix, int r, int c)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = i; j < c; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    int k;
    for(int i = 0; i < c; i++)
        for (int j=0,  k=c-1; j<k; j++,k--)
        {
            int temp = matrix[j][i];
            matrix[j][i] = matrix[k][i];
            matrix[k][i] = temp;
        }
}

void rotateMatrix(int ** matrix, int r, int c)
{
    for(int i = 0; i < r/2; i++)
        for(int j = i; j < c-i-1; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][c-i-1];
            matrix[j][c-i-1] = matrix[c-i-1][c-j-1];
            matrix[c-i-1][c-j-1] = matrix[c-j-1][i];
            matrix[c-j-1][i] = temp;
        }
}
int main()
{
    int r,c;
    cout<<"Enter num of rows"<<endl;
    cin>>r;
    cout<<"Enter num of columns"<<endl;
    cin>>c;

    int ** matrix = new int*[r];
    for(int i = 0; i < r; i++)
        matrix[i] = new int[c];
    
    cout<<"Enter the matrix"<<endl;

    for(int i = 0; i <r; i++)   
        for(int j = 0; j <c; j++)
            cin>>matrix[i][j];
    
    //rotateMatrix(&(*matrix), r, c);
    rotateMatrix_transpose(&(*matrix), r, c);

    cout<<"Print the matrix"<<endl;

    for(int i = 0; i <r; i++)
    {
        for(int j = 0; j <c; j++)
            cout<<matrix[i][j]<<" ";
    cout<<endl;
    }
    return 0;
}