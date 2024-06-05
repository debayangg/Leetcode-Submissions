class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int,int> m;
        int mn=INT_MAX;
        for(int i=0;i<cards.size();i++)
        {
            if(m[cards[i]]>0)
            {
                mn=min(mn,i+2-m[cards[i]]);
                m[cards[i]]=i+1;
            }
            else
            m[cards[i]]=i+1;
        }
        if(mn==INT_MAX)
        mn=-1;
        return mn;
    }
};