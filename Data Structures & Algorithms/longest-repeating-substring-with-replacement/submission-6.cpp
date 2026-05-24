class Solution {
public:
    int characterReplacement(string s, int k) {
        
      /*  int maxSubStrLen = 0;
        int strLength = s.length();
        for (int i =0; i < strLength; ++i)
        {
            char test = s[i];
            int otherCharCount = 0;
            for(int  j =  i; j < strLength; j++)
            {
                if(s[i] != s[j])
                //    continue;
                //else
                    otherCharCount++;
                //cout << "["<<i <<","<< j << "] = " << otherCharCount <<"\n ";
                //maxSubStrLen = max (maxSubStrLen, j - i);
                if(otherCharCount > k)
                {
                   // maxSubStrLen = max (maxSubStrLen, j - i);
                    //cout << "maxSubStrLen = " <<  maxSubStrLen << "\n" ;
                    break;
                }
                maxSubStrLen = max (maxSubStrLen, j - i + 1);
                // maxSubStrLen = max(maxSubStrLen, strLength - i);
            }
            //
        }

        return maxSubStrLen;*/

        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, int> count;
            int maxf = 0;
            for (int j = i; j < s.size(); j++) {
                count[s[j]]++;
                maxf = max(maxf, count[s[j]]);
                if ((j - i + 1) - maxf <= k) {
                    res = max(res, j - i + 1);
                }
                else
                 break;
            }
        }
        return res;

/*        int left = 0;
        unordered_set<char> window;
        for (int right = 0; right < s.length(); ++right)
        {                        
            //window.insert(s[right]);
            
        }*/
    }
};
