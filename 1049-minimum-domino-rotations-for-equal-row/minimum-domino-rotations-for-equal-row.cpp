class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) 
    {
        unordered_map<int,set<int>> mp;
        unordered_map<int,int> top;
        unordered_map<int,int> btm;
        int n=tops.size();
        int val=0,a=tops[0],b=bottoms[0];
        top[tops[0]]++;
        btm[bottoms[0]]++;
        bool flag=false;
        for(int i=1;i<n;i++)
        {
            top[tops[i]]++;
            btm[bottoms[i]]++;
            if(!(tops[i]==a || bottoms[i]==a))a=0;
            if(!(tops[i]==b || bottoms[i]==b))b=0;
            if(a==0 && b==0){
                flag=true;
                break;
            }
        }
        if(flag)return -1;

        val=(a!=0)?a:b;
        if(val==0)
        return-1;
        else
        {
            return min(n-top[val],n-btm[val]);
        }
    }
};