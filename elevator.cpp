/*

down vote
favorite
I was asked a question to write a optimal program that would determine the total number of stops a elevator has taken to serve X number of people. Question description is as below.

There is a elevator in a building with M floors, this elevator can take a max of X people at a time or max of total weight Y. Given that a set of people has arrived and their weight and the floor they need to stop given how many stops has the elevator taken to serve all the people. Consider elevator serves in the first come first serve basis.

E.g. Let Array A be the weight of people to be considered A[] = {60, 80, 40 }

Let Array B be the floors where person needs to be dropped respectively B[] = {2, 3, 5}

Total building floors be 5,max allowed person in elevator be 2 at a time with max weight capacity being 200 For this example the elevator would take total of 5 stops floors ground, 2, 3,ground, 5 , ground


*/

// you can use includes, for example:
// #include <algorithm>
#include<set>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B, int M, int X, int Y) {
    // write your code in C++14 (g++ 6.2.0)
    
    if(A.size() == 0 || B.size() == 0)
        return 0;
        
    if(A.size() != B.size())
        return 0;
        
    set<int> stops; //Used in order to store the number of stops in one round of a lift
    int i = 0, l_count = 0, s_count = 0;
    float l_weight = 0.0;
    int len = A.size();
    
    while (i < len)
    {
        if(l_count + 1 > X || l_weight + A.at(i) > Y) //If it is exceeding the maximum capacity
        {
            s_count += stops.size() + 1;              //Addition of 1 as it will stop at the ground floor
            stops.clear();
            l_count = 0;                              //Offload
            l_weight = 0.0;
        }
        stops.insert(B.at(i));
        l_count ++;
        l_weight += A.at(i);
        i++;
    }
    
    if(stops.size() > 0)
        s_count += stops.size() + 1;                  //Addition of 1 as it will stop at the ground floor
    return s_count;
}