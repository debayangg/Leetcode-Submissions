class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> prev;
        for(int i=0;i<n;i++)
        {
            prev.push_back(matrix[0][i]);
        }
        int mn=INT_MAX;
        for(int i=1;i<n;i++)
        {
            vector<int> tmp(n);
            for(int j=0;j<n;j++)
            {
                if(j==0)
                {
                    tmp[j]=min(matrix[i][j]+prev[j],matrix[i][j]+prev[j+1]);
                }
                else if(j==n-1)
                {
                    tmp[j]=min(matrix[i][j]+prev[j],matrix[i][j]+prev[j-1]);
                }
                else
                {
                    tmp[j]=min(matrix[i][j]+prev[j],
                    min(matrix[i][j]+prev[j+1],matrix[i][j]+prev[j-1]));
                }
            }
            prev=tmp;
        }

        for(int i=0;i<n;i++)
        {
            mn=min(mn,prev[i]);
        }
        return mn;
    }
};