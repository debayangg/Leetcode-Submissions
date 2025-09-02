class Solution {
public:
    int characterReplacement(string s, int k) {
        int mp[26] = {0};
        int i = 0, j = 0, mx = 0;

        while (j < s.size()) {
            mp[s[j] - 'A']++;

            // Recompute the true maximum frequency in current window
            int mx1 = 0;
            for (int c = 0; c < 26; c++) {
                mx1 = max(mx1, mp[c]);
            }

            // If replacements needed > k, shrink from left
            while ((j - i + 1) - mx1 > k) {
                mp[s[i] - 'A']--;
                i++;

                // Recompute max again after shrinking
                mx1 = 0;
                for (int c = 0; c < 26; c++) {
                    mx1 = max(mx1, mp[c]);
                }
            }

            mx = max(mx, j - i + 1);
            j++;
        }
        return mx;
    }
};
