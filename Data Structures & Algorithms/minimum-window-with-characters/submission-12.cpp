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
               //  cout << newStr << ", ";
                //if(newStr.length() > res.length() && res.length() != 0)
               // {
               //     right--; continue;
               // }
                 //cout << newStr << ", ";
                bool subStrNotFound= true;
                for(char c : t)        
                {
                    int count = std::count(newStr.begin(), newStr.end(), c);
                    //auto count = newStr.count(c);
                    if (count == std::string::npos)
                     {  
                        subStrNotFound = false; 
                        //cout << "char not found" << "\n";             
                        break;
                    }
                    //cout << CharCount[c] <<" > " << count << "\n";
                    if(CharCount[c] > count)
                    {         
                        subStrNotFound = false;              
                        break;
                    }
                } 
                if(!subStrNotFound) break;
               // if(hasSubstring( newStr, CharCount, t))
               // {
                if(res.length() == 0) res = newStr; 
                if(res.length() >  newStr.length())
                    res = newStr; 

                //cout << "newStr found = " << newStr <<"\n";   
                //cout << "res found = " << res <<"\n";   
               // }
                right--;
            }
        }

        return res;
    }
/*
    bool hasSubstring(const string& s, unordered_map <char, int> &charCount2, const string& t)
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
    }*/
};
