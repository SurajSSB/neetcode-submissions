class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        vector<int> diff;
        for(int i = 1; i < nums.size(); ++i)
        {
            diff.push_back(nums[i] - nums[i-1]);
        }
        int counter = 1, maxSeq = 0;
        for(int i = 0; i < diff.size(); ++i)
        {
            if(diff[i] == 1)
                counter++;             
            else if(diff[i] == 0)
                ;
            else
            {
                if(counter > maxSeq)
                    maxSeq = counter;
                counter = 1;
            }
        }
        if (counter != 0)
        {
            if(counter > maxSeq)
                maxSeq = counter;         
        }

        return maxSeq;
    }
};
