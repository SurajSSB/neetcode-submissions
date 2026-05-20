class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        //my algorithm - O(nLogn)
        if(nums.size() == 0) return 0;
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

        return maxSeq;
    }
};
