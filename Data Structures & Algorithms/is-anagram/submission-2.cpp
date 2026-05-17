class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        
        //time Comp - O(n2)
      /*  for (char& c : s)
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
            return true;*/

    unordered_map<char, int> freq;

    for (int i = 0; i < s.length(); i++) {
        freq[s[i]]++;   // No tolower()
        freq[t[i]]--;   // No tolower()
    }

    for (auto& pair : freq)
        if (pair.second != 0) return false;

    return true;

        return false;
    }
};
