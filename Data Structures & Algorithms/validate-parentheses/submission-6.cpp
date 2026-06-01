class Solution {
public:
    bool isValid(string s) {

        

        std::stack<char> braces;
        for(char ch : s)
        {
            if(ch == '(' || ch == '[' || ch == '{')
            {  
                braces.push(ch);
                //cout << ch << ", ";
            }
            else if(ch == ')' || ch == ']' || ch == '}')
            {
                char lastChar = '\0';
                if(!braces.empty())
                {
                    lastChar= braces.top();
                    braces.pop();
                }

                if(ch == ')' && lastChar == '(')
                    continue;

                 if(ch == ']' && lastChar == '[')
                    continue;

                 if(ch == '}' && lastChar == '{')
                    continue;

                 return false;
            }
        }

        if(braces.empty())
            return true;
        else
            return false;        
    }
};
