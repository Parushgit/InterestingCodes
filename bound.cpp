#include <iostream>
#include <vector>

using namespace std;

/*
lower bound
    - if match then return the first index matched in case of single or duplicate
    - if not match then return the next smallest element just greater than or equal to the match.

upper bound
    - if match then return the last index + 1 matched in case of single or duplicate
    - if not match then return the first index which has a number in the matching range. Out of index if range is beyond array

*/
class Bound {
public:
    pair<int, int> bound(vector<int> arr, int target) {
        int n = arr.size();
        int low = 0, high = n;
        int lower = -1, upper = -1;

        // Lower Bound
        while(low < high) {
            int mid = low + (high - low) / 2;
            if (target <= arr[mid]) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        // For cases when target is multiple or not found
        if (low < n && arr[low] < target)
            low++;

        lower = low;

        // Upper Bound
        low = 0, high = n;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if (target >= arr[mid]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }

        // For cases when target is multiple or not found
        if (low < n && arr[low] <= target)
            low++;

        upper = low;

        return make_pair(lower, upper);
    }
};

int main() {
    Bound *obj = new Bound();
    
    vector<int> arr;
    arr.push_back(10);
    arr.push_back(12);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);
    int target = 13;

    cout<<"The lower bound: "<<obj->bound(arr, target).first<<" The upper bound: "<<obj->bound(arr, target).second<<endl;
    return 0;
}