class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        //my algorithm - O(nLogn)
        /*if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int counter = 1, maxSeq = 0;
        for(int i = 1; i < nums.size(); ++i)
        {
            int diff = (nums[i] - nums[i-1]);
            if(diff == 1)
                counter++;             
            else if(diff == 0) ;
            else
            {
                if(counter > maxSeq)
                    maxSeq = counter;
                counter = 1;
            }
        }
        
        if(counter > maxSeq)
            maxSeq = counter; 

        return maxSeq;*/

        //O(n)
        /*unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int length = 1;
                while (numSet.find(num + length) != numSet.end()) {
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;*/

        unordered_map<int, int> mp;
        int res = 0;

        for (int num : nums) {
            if (!mp[num]) {
                mp[num] = mp[num - 1] + mp[num + 1] + 1;
                mp[num - mp[num - 1]] = mp[num];
                mp[num + mp[num + 1]] = mp[num];
                res = max(res, mp[num]);
            }
        }
        return res;
    }
};
