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
                if((right - i) > res.length() && res.length() != 0)
                {
                    right--; continue;
                }

               // string newStr (s.begin() + i, s.begin() + right + 1);               
                bool subStrNotFound= true;
                for(char c : t)        
                {
                    int count = std::count(s.begin() + i, s.begin()  + right + 1, c);                                        
                    if(CharCount[c] > count)
                    {         
                        subStrNotFound = false;              
                        break;
                    }
                } 

                if(!subStrNotFound) break;
                string newStr (s.begin() + i, s.begin() + right + 1);  
                if(res.length() == 0) res = newStr; 
                if(res.length() >  newStr.length())
                    res = newStr; 
                right--;
            }
        }

        return res;
    }
};
