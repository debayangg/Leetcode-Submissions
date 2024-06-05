class Solution {
public:
    string removeDigit(string number, char digit) {
        string ans = "";
        for (int i = 0; i < number.length(); i++) {
            if (number[i] == digit) {
                if (ans.length() == 0)
                    ans = number.substr(0, i) + number.substr(i + 1);
                else {
                    string s = number.substr(0, i) + number.substr(i + 1);
                    if (ans.compare(s) < 0) {
                        ans = s;
                    }
                }
            }
        }
        return ans;
    }
};
