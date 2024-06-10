class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count=0;
        vector<int> h(heights.begin(),heights.end());
        sort(h.begin(),h.end());
        for(int i=0;i<heights.size();i++)
        {
            if(h[i]!=heights[i])
            count++;
        }
        return count;
    }
};