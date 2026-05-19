class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0) return 0;

        sort(nums.begin(), nums.end());
        vector<int> diff;
        for(int i = 1; i < nums.size(); ++i)
        {
            int temp = nums[i] - nums[i-1];
            diff.push_back(temp);
            cout << temp << ", ";
        }
        cout << endl;
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
            cout <<counter <<", "; 
        }
        if (counter != 0)
        {
            if(counter > maxSeq)
                maxSeq = counter;
         
            counter = 0;
        }

        //if(maxSeq > 0)
        //    maxSeq++;
        return maxSeq;
    }
};
