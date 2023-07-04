// from Rajendran, Jayakumar (internal) to Everyone:    10:23  AM
// You are given a list of integers, and your task is to write a function that returns the sum of the two largest integers in the list. 
// For example, given the input [1, 5, 2, 4, 3], the function should return 9, because the two largest integers are 5 and 4, and their sum is 9. 
// You are allowed to use any algorithm and data structure that you see fit, but you should aim to minimize the time and space complexity of your solution. 
// You should also be prepared to discuss the trade-offs and limitations of your solution, and to suggest alternative approaches if applicable. 

/*
[1, 5, 2, 4, 3]
f = MIN
s = MIN

i = 0;
s = MIN
f = 1;

i = 1;
5 > 1
s = 1;
f = 5;

i = 2;
s = 2;
f = 5;

i = 3;
4 > 2 true
s = 4
f = 5

i = 4;
f = 5
s = 4
*/

// TC - O(N), SC - O(1)

#include<vector>
#include<iostream>
#include<climits>

using namespace std;

class TwoLargest {
    public:
        int sumOfTwoLargest(vector<int> arrList) {
            int firstLargest = INT_MIN;
            int secondLargest = INT_MIN;

            if (arrList.size() < 2) {
                return 0; // Base case
            }

            if (arrList.size() == 2) {
                return arrList[0] + arrList[1];
            }

            for(int i = 0; i < arrList.size(); i++) {
                if (arrList[i] > firstLargest) {
                    secondLargest = firstLargest;
                    firstLargest = arrList[i];
                }
                else if (arrList[i] > secondLargest) {
                    secondLargest = arrList[i];
                }
            }
            return ((firstLargest != INT_MIN && secondLargest != INT_MIN) ? (firstLargest + secondLargest) : 0);
        }
};

int main() {
    vector<int> arrList;
    arrList.push_back(1);
    arrList.push_back(2);
    arrList.push_back(3);
    arrList.push_back(4);

    TwoLargest *obj = new TwoLargest();
    cout<<"The sum of two largest numbers in an array is: "<<obj->sumOfTwoLargest(arrList)<<endl;
    return 0;

}
