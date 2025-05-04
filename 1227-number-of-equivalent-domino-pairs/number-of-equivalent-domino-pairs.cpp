class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) 
    {
        map<pair<int,int>,int>m;
        int ans=0;
        for(int i=0; i<dominoes.size(); i++)
        {
            int a=dominoes[i][0], b=dominoes[i][1];
            pair<int,int> x;
            x.first=(a>b)?a:b;
            x.second=(a>b)?b:a;
            ans+=m[x];
            m[x]++;
        }
        return ans;
        
        
    }
};