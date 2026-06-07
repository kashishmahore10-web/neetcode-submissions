class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string str: strs) {
            vector<int> freq(26, 0);
            for(char c : str){
                freq[c - 'a']++;
            }
            string key = "";
            for(int count : freq ){
                key += "#" + to_string(count);
            }
            mp[key].push_back(str);
        }
        vector<vector<string>> result;
        for(auto it : mp){
            result.push_back(it.second);
        }
        return result;
    }
};

