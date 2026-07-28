class Solution {
public:
    string smallestPalindrome(string s) {
        string firstHalf;

        for (int i = 0; i < s.size() / 2; i++) {
            firstHalf += s[i];
        }

        sort(firstHalf.begin(), firstHalf.end());

        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());

        if (s.size() % 2 == 1) {
            return firstHalf + s[s.size() / 2] + secondHalf;
        }

        return firstHalf + secondHalf;
    }
};