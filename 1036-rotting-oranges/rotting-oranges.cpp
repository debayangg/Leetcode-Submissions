class Node{
    public:
        int x,y,z;
        Node(int a,int b,int c)
        {
            x=a;
            y=b;
            z=c;
        }
};
class Solution {
public:
    bool isValid(int i, int j, int n, int m, vector<vector<int>>& grid)
    {
        if(i<0 || i>=n)return false;
        if(j<0 || j>=m)return false;
        if(grid[i][j]==1)
        return true;
        else
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<Node> q;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> visited(n, vector(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push(Node(i,j,0));
                }
            }
        }
        int ans=0;
        while(!q.empty())
        {
            Node node = q.front();
            q.pop();
            int i=node.x,j=node.y,k=node.z;
            if(isValid(i-1,j,n,m,grid) && !visited[i-1][j])
            {
                ans=max(ans,k+1);
                q.push(Node(i-1,j,k+1));
                visited[i-1][j]=1;
            }
            if(isValid(i+1,j,n,m,grid) && !visited[i+1][j])
            {
                ans=max(ans,k+1);
                q.push(Node(i+1,j,k+1));
                visited[i+1][j]=1;
            }
            if(isValid(i,j-1,n,m,grid) && !visited[i][j-1])
            {
                ans=max(ans,k+1);
                q.push(Node(i,j-1,k+1));
                visited[i][j-1]=1;
            }
            if(isValid(i,j+1,n,m,grid) && !visited[i][j+1])
            {
                ans=max(ans,k+1);
                q.push(Node(i,j+1,k+1));
                visited[i][j+1]=1;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && visited[i][j]==0)
                return -1;
            }
        }
        return ans;
    }
};