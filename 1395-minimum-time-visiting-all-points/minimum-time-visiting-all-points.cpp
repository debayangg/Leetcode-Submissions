class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size();
        int sum = 0;
        for(int i=0;i<n-1;i++)
        {
            int x1=points[i][0], y1 = points[i][1], x2=points[i+1][0], y2=points[i+1][1];
            sum+=max(abs(x2-x1),abs(y2-y1));
        }
        return sum;
    }
};