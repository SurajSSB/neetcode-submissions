class Solution {
public:

    string encode(vector<string>& strs) 
    {
        string output;
        int size = strs.size();

        for (int i =0; i < size; ++i)
        {
            auto& str = strs[i];
            int strSize = str.size();

            string s = to_string(strSize);

            output =  output + s;

            output = output + "#";
            output = output + str;

        }

        return output;
    }

    vector<string> decode(string s) 
    {
        vector<string> output;

        int counter = 0, length = s.length();
        while(counter < length)
        {

            string strNum;
           
            while(counter < length && s[counter] != '#')
            {   
                strNum = strNum + s[counter];
                counter++;
            }
            int num = atoi (strNum.data());
            counter++;
            string newStr = s.substr(counter, num);
            output.push_back(newStr);    
            counter = counter + num;
        }
        return output;
        }
};
