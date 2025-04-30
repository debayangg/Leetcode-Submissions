class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt=0;
        for(int i:nums)
        {
            int v=1e5;
            int n=1;
            while(i/v<1)
            {
                n^=1;
                v/=10;
            }
            if(n)cnt++;
        }
        return cnt;
    }
};