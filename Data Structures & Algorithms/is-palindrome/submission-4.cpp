class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> str;
        for (char ch : s)
        {
           // int ascii = int(ch);
           // if((ascii  >= 48 && ascii <= 57) ||
            //(ascii  >= 65 && ascii <= 90) ||
            //(ascii  >= 97 && ascii <= 122))
            
            if(isalnum(ch)){
                     str.push_back(tolower(ch));
            }   
        }
        vector<char> revStr (str);
        reverse(revStr.begin(), revStr.end()); 
        return (revStr == str);
    }
};
