/*
A rectangular map consisting of N rows and M columns of square areas 
is given. Each area is painted with a certain color. 

Two areas on the map belong to the same country if the following 
conditions are met: 

they have the same color; 
it is possible to travel from one area to the other by moving only 
north, south, west or east without moving over areas of a different 
color. 

The map can be described by a zero-indexed matrix consisting of N rows 
and M columns of integers. The color of each area is described by the 
corresponding element of the matrix. Two areas have the same color if 
and only if their corresponding matrix elements have the same value. 

For example, consider the following matrix A consisting of seven rows 
and three columns: 

A[0][0] = 5    A[0][1] = 4    A[0][2] = 4 
A[1][0] = 4    A[1][1] = 3    A[1][2] = 4 
A[2][0] = 3    A[2][1] = 2    A[2][2] = 4 
A[3][0] = 2    A[3][1] = 2    A[3][2] = 2 
A[4][0] = 3    A[4][1] = 3    A[4][2] = 4 
A[5][0] = 1    A[5][1] = 4    A[5][2] = 4 
A[6][0] = 4    A[6][1] = 1    A[6][2] = 1 

Matrix A describes a map that is colored with five colors. Areas on 
the map belong to eleven different countries: 

area A[0][0] forms a one-area country; 
areas A[0][1], A[0][2], A[1][2], A[2][2] belong to the same country; 
area A[1][0] forms a one-area country; 
area A[1][1] forms a one-area country; 
area A[2][0] forms a one-area country; 
areas A[2][1], A[3][0], A[3][1], A[3][2] belong to the same country; 
areas A[4][0], A[4][1] belong to the same country; 
areas A[4][2], A[5][1], A[5][2] belong to the same country; 
area A[5][0] forms a one-area country; 
area A[6][0] forms a one-area country; 
areas A[6][1], A[6][2] belong to the same country. 

Write a function 

int countries_count(const vector< vector<int> > &A); 

that, given a zero-indexed matrix A consisting of N rows and M columns 
of integers, returns the number of different countries that the areas 
of the map described by matrix A belong to. 

Assume that: 

N is an integer within the range [1..1,000,000]; 
M is an integer within the range [1..1,000,000]; 
the number of elements in matrix A is within the range [1..1,000,000]; 
each element of matrix A is an integer within the range 
[-1,000,000,000..1,000,000,000]. 

For example, given matrix A consisting of seven rows and three columns 
corresponding to the example above, the function should return 11. 

Complexity: 

expected worst-case time complexity is O(N*M); 
expected worst-case space complexity is O(N*M). 
*/

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

void findNeighbour(vector< vector<int> > &A, vector< vector<int> > &B, int i, int j, int len1, int len2)
{
    //Neighbouring according to the same color and orthogonal direction
    if(B[i][j] == -1) return;
    B[i][j] = -1;
    if(i + 1 < len1)
        if(A[i+1][j] == A[i][j]) findNeighbour(A, B, i+1, j, len1, len2);
    if(j + 1 < len2)
        if(A[i][j+1] == A[i][j]) findNeighbour(A, B, i, j+1, len1, len2);
    if(i - 1 >= 0)
        if(A[i-1][j] == A[i][j]) findNeighbour(A, B, i-1, j, len1, len2);
    if(j - 1 >= 0)
        if(A[i][j-1] == A[i][j]) findNeighbour(A, B, i, j-1, len1, len2);
}

int solution(vector< vector<int> > &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    int countries = 0;
    if(A.empty()) return 0;
    int len1 = A.size(), len2= A[0].size();
    vector< vector<int> > B(A);
    
    for(int i = 0; i < len1; i++)
        for(int j = 0; j < len2; j++)
            if(B[i][j] >= 0)
            {
                findNeighbour(A, B, i, j, len1, len2);
                countries++;
            }
    return countries;
}