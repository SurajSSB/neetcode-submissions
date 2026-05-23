class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int maxLength = 0;
        for (int  i =0; i < s.length(); i++)
        {
           string substr;
           substr.push_back(s[i]);
           for(int j = i+1; j < s.length() ;j++)  
           {
                if(substr.find(s[j]) == std::string::npos) // not found
                    substr.push_back(s[j]);
                else                
                    break;     
            }
             if(substr.length() > maxLength)
                maxLength = substr.length();
        }
        return maxLength;
    }
};
