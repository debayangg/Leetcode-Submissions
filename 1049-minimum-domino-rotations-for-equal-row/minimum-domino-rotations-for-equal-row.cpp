class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) 
    {
        unordered_map<int,set<int>> mp;
        unordered_map<int,int> top;
        unordered_map<int,int> btm;
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