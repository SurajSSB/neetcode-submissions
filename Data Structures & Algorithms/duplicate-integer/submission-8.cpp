class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        unordered_set<int> newSet (nums.begin(), nums.end());
       // for(int& i : nums)
       // {
            //if(newSet.find(i) == newSet.end())
            //    newSet.insert(i);
            //else
            //    return true;
       // }
        if(newSet.size() == nums.size())
            return false;
        else 
            return true;
       // cout << setSize ;
        //return false;
    }
};