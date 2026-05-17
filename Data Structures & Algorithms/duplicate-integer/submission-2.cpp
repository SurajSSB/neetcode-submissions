class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        unordered_set<int> newSet;
        for(int& i : nums)
        {
            if(newSet.find(i) == newSet.end())
                newSet.insert(i);
            else
                return true;
        }
        int setSize = newSet.size();
        cout << setSize ;
        return false;
    }
};