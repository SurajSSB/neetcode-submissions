class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        unordered_set<int> newSet;
        for(int i = 0; i< nums.size();++ i)
        {
            if(newSet.find(nums[i] )== newSet.end())
                newSet.insert(nums[i]);
            else
                return true;
        }
        return false;
    }
};