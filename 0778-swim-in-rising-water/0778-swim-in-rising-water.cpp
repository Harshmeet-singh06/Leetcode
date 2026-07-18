class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        priority_queue< 
    pair<int, pair<int, int>>,          // 1. The Data Type
    vector<pair<int, pair<int, int>>>,  // 2. The Underlying Container
    greater<pair<int, pair<int, int>>>  // 3. The Comparison Function
> pq;
        pq.push({grid[0][0],{0,0}});
        dist[0][0] = grid[0][0];
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        while(!pq.empty()){
            int dis = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row == n-1 && col == m-1){
                return dist[row][col];
            }
            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m){
                    int elevation = max(dis,grid[nrow][ncol]);
                    if(elevation < dist[nrow][ncol]){
                    dist[nrow][ncol] = elevation;
                    pq.push({elevation,{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};