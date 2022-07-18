class Solution
{
public:
    bool dfs(int i, vector<vector<int>> &graph, vector<int> &colour){
        for (auto it : graph[i]){
            if (colour[it]==-1){
                colour[it] = 1 - colour[i];
                if (!dfs(it, graph, colour))
                    return false;
            }
            else if (colour[it]==colour[i])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph){
        int n=graph.size();
        vector<int> colour(n,-1);
        for(int i=0;i<n;i++){
            if(colour[i]==-1)
                if(!dfs(i,graph, colour))
                    return false;
        }
        return true;
    }
};
