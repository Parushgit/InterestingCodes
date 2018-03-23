#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;

void zeroMatrix(int ** matrix, int r, int c)
{
    vector<int> row_col;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(matrix[i][j] == 0)
            {
                row_col.push_back(i);
                row_col.push_back(j);
            }
        }
    }

    for(int i = 0; i<row_col.size(); i+=2)
    {
        for(int k = 0; k < c; k++)
            matrix[row_col.at(i)][k] = 0;
        for(int k = 0; k < r; k++)
            matrix[k][row_col.at(i+1)] = 0;
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
    zeroMatrix(&(*matrix), r, c);

    cout<<"Print the matrix"<<endl;

    for(int i = 0; i <r; i++)
    {
        for(int j = 0; j <c; j++)
            cout<<matrix[i][j]<<" ";
    cout<<endl;
    }
    return 0;
}