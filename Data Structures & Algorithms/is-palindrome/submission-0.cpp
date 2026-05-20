class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> str;
        for (char ch : s)
        {
            int ascii = int(ch);
            if((ascii  >= 48 && ascii <= 57) ||
            (ascii  >= 65 && ascii <= 90) ||
            (ascii  >= 97 && ascii <= 122))
            {
                     str.push_back(tolower(ch));
                     cout << ch;
            }   
        }
        vector<char> revStr (str);
        reverse(revStr.begin(), revStr.end()); 
        if(revStr == str)
        return true;

        return false;
    }
};
