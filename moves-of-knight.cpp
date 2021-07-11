// https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // we use breadth first search
        queue<int> qx, qy;
        vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));
        qx.push(KnightPos[0]);
        qy.push(KnightPos[1]);
        
        vector<int> dx = {2, 2, -2, -2, 1, 1, -1, -1};
        vector<int> dy = {1, -1, 1, -1, 2, -2, 2, -2};
        
        int x, y, xx, yy;
        int moves = -1;
        visited[qx.front()][qy.front()] = true;
        while(!qx.empty())
        {
            int sz = qx.size();
            moves++;
            for(int i = 0; i < sz; i++)
            {
                x = qx.front(); qx.pop();
                y = qy.front(); qy.pop();
                
                if(x == TargetPos[0] && y == TargetPos[1]) return moves;
                // go through all the neighbours
                for(int i = 0; i < 8; i++)
                {
                    xx = x + dx[i], yy = y + dy[i];
                    if(xx < 1 || xx > N || yy < 1 || yy > N || visited[xx][yy])
                        continue;
                    visited[xx][yy] = true;
                    qx.push(xx);
                    qy.push(yy);
                }
            }
        }
        return -1;
	}
};