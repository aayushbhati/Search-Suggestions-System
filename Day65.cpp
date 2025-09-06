class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& items, string query) {
        auto it = items.begin();
        sort(it, items.end());
        vector<vector<string>> result;
        vector<string> candidates;
        string prefix = "";
        
        for (auto ch : query) {
            prefix += ch;
            candidates.clear();
            it = lower_bound(it, items.end(), prefix);
            
            for (int k = 0; k < 3 && it + k != items.end(); k++) {
                string word = *(it + k);
                if (word.find(prefix)) break;
                candidates.push_back(word);
            }
            result.push_back(candidates);
        }
        return result;
    }
};
