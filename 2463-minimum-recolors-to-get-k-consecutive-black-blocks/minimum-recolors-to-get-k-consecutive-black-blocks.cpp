class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cnt=0;
        vector<int> cnts(blocks.size()+1);
        cnts[0]=0;
        for(int i=0;i<blocks.size();i++)
        {
            cnt+=((blocks[i]=='B')?1:0);
            cnts[i+1]=cnt;
        }
        int mn=INT_MAX;

        for(int i=k;i<=blocks.size();i++)
        {
            mn=min(mn,k-cnts[i]+cnts[i-k]);
        }
        return mn;
    }
};