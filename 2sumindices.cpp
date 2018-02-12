//If two indices sum is 0, print that!

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> finalarray;
        
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                if( i != j)
                {
                    if(nums[i] + nums[j] == target) 
                    {
                        finalarray.push_back(i);
                        finalarray.push_back(j);
                        return finalarray;
                    }   
                }
            }
        }
    }
};


public int[] twoSum(int[] nums, int target) {
    Map<Integer, Integer> map = new HashMap<>();
    for (int i = 0; i < nums.length; i++) {
        int complement = target - nums[i];
        if (map.containsKey(complement)) {
            return new int[] { map.get(complement), i };
        }
        map.put(nums[i], i);
    }
    throw new IllegalArgumentException("No two sum solution");
}