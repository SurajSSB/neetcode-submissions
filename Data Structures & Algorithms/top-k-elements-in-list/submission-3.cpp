class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

         vector<int> Output;

        //Time Complexity (Average Case): O(nlogm) or O(nlogn) (since m <= n)
        unordered_map <int, int> numMap;
        for(int i = 0; i < nums.size(); ++i)
        {
                numMap[nums[i]]++;
        }         
/*
        std::vector<std::pair<int, int>> vec(numMap.begin(), numMap.end());
        std::sort(vec.begin(), vec.end(),
              [](const std::pair<int, int>& a,
                 const std::pair<int, int>& b) {
                  return a.second > b.second; // Sorts in descending order of keys
              });

        for(int i = 0; i < k; ++i) 
        {          
            Output.push_back(vec[i].first);
        }*/

        priority_queue <pair <int,int>, vector <pair<int, int>>, greater <pair<int, int>>> heap;

        for(auto& num: numMap)
        {
            heap.push({num.second, num.first});
            if(heap.size() > k)
            {
                heap.pop();
            }
        }

        for(int i =0 ; i < k; ++i)
        {
            Output.push_back(heap.top().second);
            heap.pop();
        }
        return Output;
    }
};
