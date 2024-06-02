class Solution {
public:
    string clearStars(string s) {
        vector<vector<int>> m(26); // 2D array with 26 vectors
        set<char> st;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '*') {
                for(char ch : st) {
                    int idx = ch - 'a';
                    if(m[idx].size() > 0) {
                        m[idx].pop_back();
                        if(m[idx].size() == 0) {
                            st.erase(ch);
                        }
                        break;
                    }
                }
            } else {
                int idx = s[i] - 'a';
                m[idx].push_back(i);
                st.insert(s[i]);
            }
        }
        
        string ans = "";
        for(int i = 0; i < s.size(); i++) {
            for(int j = 0; j < 26; j++) {
                if(binary_search(m[j].begin(), m[j].end(), i)) {
                    ans += s[i];
                }
            }
        }
        return ans;
    }
};