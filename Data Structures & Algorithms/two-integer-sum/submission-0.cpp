class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int omega = nums.size();
        unordered_map<int, int> mapPrev;

        for(int i = 0; i < omega; ++i)
        {
            int diff = target - nums[i];
            if(mapPrev.find(diff) != mapPrev.end())
                    return {mapPrev[diff], i};
            mapPrev.insert({nums[i], i});
        }
            return {};
    }
};
