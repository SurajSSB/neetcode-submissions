class Solution {
public:
    bool isPalindrome(string s) {

        //MMy algo - O(n)
        /*vector<char> str;
        for (char ch : s)
        {           
            if(isalnum(ch))
            {
                str.push_back(tolower(ch));
            }   
        }
        vector<char> revStr (str);
        reverse(revStr.begin(), revStr.end()); 
        return (revStr == str);*/

        //Two Pointers time = O(n), space - O(1)
        int l = 0, r = s.length()-1; 
        while(l < r )
        {
            while ( l < r && !alphaNum(s[l]))
                l++;
            while ( l < r && !alphaNum(s[r]))
                r--;
            if(tolower(s[l]) != tolower(s[r]))
                return false;

            l++;
            r--;    
        }
        return true;
    }

     bool alphaNum(char c) {
        return (c >= 'A' && c <= 'Z' ||
                c >= 'a' && c <= 'z' ||
                c >= '0' && c <= '9');
    }
};
