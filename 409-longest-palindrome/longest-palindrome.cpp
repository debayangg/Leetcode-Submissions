class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        map<char,int> m;
        for(int i=0;i<n;i++)
        {
            m[s[i]]++;
        }
        int count=0;
        for(auto i: m)
        {
            while(m[i.first]>1)
            {
                m[i.first]-=2;
                count+=2;
            }
        }
        if(n-count>0)
        count++;

        return count;
    }
};