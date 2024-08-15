class Solution {
public:
    bool isValid(int i,int j, int n, int m, vector<vector<int>>& image, int src)
    {
        if(i<0 || i>=n)return false;
        if(j<0 || j>=m)return false;
        if(image[i][j]!=src)return false;
        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(),m=image[0].size();
        queue<pair<int,int>> q;
        map<pair<int,int>,int> visited;
        q.push({sr,sc});
        int src = image[sr][sc];
        while(!q.empty())
        {
            pair<int,int> cell = q.front();
            q.pop();
            int i=cell.first, j=cell.second;
            image[i][j] = color;
            if(isValid(i-1,j,n,m,image,src) && !visited[{i-1,j}])
            {
                q.push({i-1,j});
                visited[{i-1,j}]=1;
            }
            if(isValid(i,j-1,n,m,image,src) && !visited[{i,j-1}])
            {
                q.push({i,j-1});
                visited[{i,j-1}]=1;
            }
            if(isValid(i+1,j,n,m,image,src) && !visited[{i+1,j}])
            {
                q.push({i+1,j});
                visited[{i+1,j}]=1;
            }
            if(isValid(i,j+1,n,m,image,src) && !visited[{i,j+1}])
            {
                q.push({i,j+1});
                visited[{i,j+1}]=1;
            }
        }
        return image;
    }
};