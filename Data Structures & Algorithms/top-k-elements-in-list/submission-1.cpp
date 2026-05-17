class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map <int, int> numSet;
        for(int i = 0; i < nums.size(); ++i)
        {
                numSet[nums[i]]++;
        }  
        vector<int> Output;

        std::vector<std::pair<int, int>> vec(numSet.begin(), numSet.end());
        std::sort(vec.begin(), vec.end(),
              [](const std::pair<int, int>& a,
                 const std::pair<int, int>& b) {
                  return a.second > b.second; // Sorts in descending order of keys
              });

        for(int i = 0; i < k; ++i) 
        {          
            Output.push_back(vec[i].first);
        }

        return Output;
    }
};
