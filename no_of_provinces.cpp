
// leetcode solution

class Solution
{

private:
    void dfs(int node, vector<int> adjLs[], int vis[])
    {
        vis[node] = 1;

        // traverse all its neighbours
        for (auto it : adjLs[node])
        {
            // if the neighbour is not visited
            if (vis[it] == 0)
            {
                dfs(it, adjLs, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {

        vector<int> adjLs[isConnected.size()];

        for (int i = 0; i < isConnected.size(); i++)
        {
            for (int j = 0; j < isConnected.size(); j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        int vis[205] = {0};
        int count = 0;
        for (int i = 0; i < isConnected.size(); i++)
        {
            if (vis[i] == 0)
            {
                count++;
                dfs(i, adjLs, vis);
            }
        }
        return count;
    }
};

// ***********************************


//  gfg solution

class Solution
{

private:
    void dfs(int node, vector<int> adjLs[], int vis[])
    {
        vis[node] = 1;

        // traverse all its neighbours
        for (auto it : adjLs[node])
        {
            // if the neighbour is not visited
            if (vis[it] == 0)
            {
                dfs(it, adjLs, vis);
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        // code here
        vector<int> adjLs[V];

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1 && i != j)
                {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        int vis[V] = {0};
        int count = 0;
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                count++;
                dfs(i, adjLs, vis);
            }
        }
        return count;
    }
};