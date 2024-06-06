class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        multiset<int> s;
        for(int i:hand)
        {
            s.insert(i);
        }
        if(hand.size()%groupSize==0)
        {
            int ngroups=hand.size()/groupSize;
            int j=1;
            for(int i=0;i<ngroups;i++)
            {
                int val=*s.begin();
                s.erase(s.begin());
                for(int j=1;j<groupSize;j++)
                {
                    if(s.find(val+1)==s.end())
                    return false;
                    else
                    {
                        val++;
                        s.erase(s.find(val));
                    }
                }
            }
            return true;
        }
        else
        return false;
    }
};