class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int totalMult = 1;
        vector<int> zeroIndices;
        for(int i = 0; i< nums.size(); ++i)
        {
            if(nums[i] == 0)
            {
                zeroIndices.push_back(i);
                continue;
            }
            totalMult = totalMult * nums[i];
        } 
        vector<int> output;
        int totalZeros = zeroIndices.size();

         if (totalZeros > 1) {
            return vector<int>(nums.size(), 0);
        }

        for(int i = 0; i< nums.size(); ++i)
        {
            if(totalZeros == 1)
            {
                if (i == zeroIndices[0])
                    output.push_back(totalMult);
                else
                    output.push_back(0);
            }
            else
            {
                int CurTotal = totalMult/nums[i];
                output.push_back(CurTotal);
            }
        }
        return output;
    }
};
