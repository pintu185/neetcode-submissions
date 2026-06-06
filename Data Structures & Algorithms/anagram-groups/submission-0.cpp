class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>>m;
        for(string str: strs)
        {
            int count[26] = {0};
            for(char ch : str)
            {
                count[ch - 'a']++;
            }
            string key = "";
            for(int i = 0; i < 26; i++)
            {
                key = key + "#" + to_string(count[i]);
            }

            m[key].push_back(str);
        }

        vector<vector<string>> res;
        for(auto &it: m )
        {
            res.push_back(it.second);
        }
        return res;
    }
};
