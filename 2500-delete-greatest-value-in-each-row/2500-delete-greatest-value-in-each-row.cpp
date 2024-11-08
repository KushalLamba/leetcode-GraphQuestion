class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int sum=0;
        while(1==1)
        {
            vector<pair<int,int>> ans(grid.size());
            for(int i=0;i<grid.size();i++)
            {
                int maxcol=0;
                int maxcidx=-1;
                for(int j=0;j<grid[i].size();j++)
                {
                    if(maxcol<grid[i][j])
                    {
                        maxcol=grid[i][j];
                        maxcidx=j;
                    }
                }
                if(maxcol==0) return sum;
                ans[i]={maxcol,maxcidx};
            }
            int maxv=0;
            for(int i=0;i<grid.size();i++)
            {
                if(maxv<ans[i].first)
                {
                    maxv=ans[i].first;
                }
                grid[i][ans[i].second]=0;
            }
            sum+=maxv;
        }
        return sum;
    }
};