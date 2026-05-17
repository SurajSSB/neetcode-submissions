class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        
        for (char& c : s)
        {
            auto itr = std::find(t.begin(), t.end(), c);
            if(itr != t.end())
            {
                t.erase(itr);
            }
            else
                return false;
        }

        if(t.length() == 0)
            return true;

        return false;
    }
};
