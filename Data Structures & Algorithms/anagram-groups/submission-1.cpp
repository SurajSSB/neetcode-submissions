class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strings) {
        
        vector<vector<string>> output;
        auto strs = strings;
        unordered_map <char, int> freq;
        auto totalStrs = strs.size(); 
        for(int i =0; i < totalStrs; ++i)
        {
            vector<string> outputVec {strs[i]};            
            auto strSizeI = strs[i].size();
            for(int j = i +1; j <  totalStrs; ++j)
            {
                auto strSizeJ = strs[j].size();
                if(strSizeI != strSizeJ)
                    continue;

                freq.clear();

                for( int k =0 ; k < strSizeI; ++k)
                {
                    freq[strs[i][k]]++; 
                    freq[strs[j][k]]--; 
                }    
                
                bool isAnagram = true;
                for(auto &pair : freq)
                 {   
                    if(pair.second != 0 ) 
                    {
                        isAnagram = false;
                        break;
                    }
                 }

                 if(isAnagram)
                 {
                    outputVec.push_back(strs[j]);
                    strs.erase(strs.begin() + j);  
                    totalStrs--;
                    j--;
                 }
            }
            output.push_back(outputVec);
        }
    return output;
    }
};
