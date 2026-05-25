class Solution {
public:
    string minWindow(string s, string t) {        


        unordered_map <char, int> CharCount;
        for(char c : t)
        {
            CharCount[c]++;
        }
        string res;
        for (int i =0; i < s.length(); ++i)
        {
            int  right = s.length() -1;
            while( i <= right)
            {
                string newStr (s.begin() + i, s.begin() + right + 1);
                // cout << newStr << ", ";
                if(newStr.length() > res.length() && res.length() != 0)
                    {
                         right--; continue;
                    }
                 //cout << newStr << ", ";
                if(hasSubstring( newStr, CharCount, t))
                {
                    if(res.length() == 0) res = newStr; 
                    if(res.length() >  newStr.length())
                       res = newStr; 
                }
                right--;
            }
        }

        return res;
    }

    bool hasSubstring(string s, unordered_map <char, int> &charCount2,  string t)
    {
        bool res = false;
        unordered_map <char, int> CharCount;
        for(char c : s)
        {
            CharCount[c]++;
        }       
        for (char c : t)
        {
            if(charCount2[c] > CharCount[c])
                return false;
        }
        return true;
    }
};
