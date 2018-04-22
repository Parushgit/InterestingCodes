class Solution {
public:
    void rotateByOne(vector<int>& array, int len)
    {
        int last_elem = array.at(len - 1);
        for(int i = len - 1; i > 0; i--)
        {
            array.at(i) = array.at(i-1);
        }
        array.at(0) = last_elem;
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        while(k--)
            rotateByOne(nums, n);
    }
};