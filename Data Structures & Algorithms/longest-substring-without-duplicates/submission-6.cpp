class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //My algo - O(n2)
        /*int maxLength = 0;
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
        return maxLength;*/
/*
        unordered_set<char> str;
        int  i =0, res =0; 
        for (int j =0; j < s.length(); j++)
        {
            while(str.find(s[j]) != str.end())
            {
                str.erase(s[i]);
                i++;
            }

            str.insert(s[j]);
            res = max (res, j-i+1);
        }

        return res;*/

        unordered_map<char, int> mp;
        int l = 0, res = 0;

        for (int r = 0; r < s.size(); r++) {
            if (mp.find(s[r]) != mp.end()) {
                l = max(mp[s[r]] + 1, l);
            }
            mp[s[r]] = r;
            res = max(res, r - l + 1);
        }
        return res;
    }
};
