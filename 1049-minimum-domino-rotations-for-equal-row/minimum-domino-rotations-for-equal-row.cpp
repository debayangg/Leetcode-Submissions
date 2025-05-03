class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) 
    {
        map<int,set<int>> mp;
        map<int,int> top;
        map<int,int> btm;
        int n=tops.size();
        for(int i=0;i<n;i++)
        {
            mp[tops[i]].insert(i);
            mp[bottoms[i]].insert(i);
            top[tops[i]]++;
            btm[bottoms[i]]++;
        }
        int val=0;
        for(auto id:mp)
        {
            if(id.second.size()==n)val=id.first;
        }
        if(val==0)
        return-1;
        else
        {
            return min(n-top[val],n-btm[val]);
        }
    }
};