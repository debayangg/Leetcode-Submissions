class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) 
    {
        long long mx=0,curr=0,mn=0;
        for(int i=0;i<differences.size();i++)
        {
            curr+=differences[i];
            mx=max(mx,curr);
            mn=min(mn,curr);
        }
        return max(0LL,upper-lower-(mx-mn)+1);
    }
};