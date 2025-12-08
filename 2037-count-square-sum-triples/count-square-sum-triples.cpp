class Solution {
public:
    int countTriples(int n) {
        map<int,int> mp;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            mp[i*i]=1;
            for(int j=1;j<i;j++)
            {
                if(mp[(i*i)-(j*j)])cnt++;
            }
        }
        return cnt;
    }
};