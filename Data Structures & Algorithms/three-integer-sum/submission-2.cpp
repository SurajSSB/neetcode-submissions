class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
       set<vector<int>> res;
       vector<vector<int>> res1;
        sort(nums.begin(), nums.end());

        //O(n3))
        /*for (int i = 0; i < nums.size(); i++) {
             cout << nums[i] << ", ";
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        res.insert({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }*/

        for (int i = 0; i < nums.size(); i++)
        {
            int  l = i +1, r = nums.size() - 1;
            int sum = -nums[i];

            while( l < r && r > i && l < nums.size())
            {
                cout<< "+";
                if((nums[l]+ nums[r] )== sum)
                {
                    //Insert triplet                    
                    res.insert({nums[i], nums[l], nums[r]});
                    res1.push_back({nums[i], nums[l], nums[r]});
                     l++;
                     r--;
                }
                else if((nums[l]+ nums[r]) > sum)
                    r--;
                else
                    l++;
            }
        }



        return vector<vector<int>>(res.begin(), res.end());
        
    }
};
