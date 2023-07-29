// Thomas is a Tank engine on the island of Sodor. There are total ‘N’ cities on this island connected with ‘m’ tracks. 
// All the cities on this island are connected to each other, directly or indirectly. Thomas and all his engine friends 
// travel from city ‘a’ to city ‘b’ daily but might use different routes. Some of these tracks are present on all the paths
// from the city ‘a’ to ‘b’. Due to excessive load on these tracks, all of these tracks are not in good condition, so one day 
// Thomas asks The Fat Controller to repair all the tracks that are present on all the paths from ‘a’ to ‘b’. Help the Fat 
// controller to count all these tracks.

#include<unordered_map>

int timer, ans;
vector<int> vis, tin, tout, low;
unordered_map<int, vector<int>> v;

void dfs(int i, int b, int par)
{
    vis[i] = true;
    tin[i] = low[i] = timer++;
    for(auto it : v[i])
    {
        if(it == par)
            continue;
        if(vis[it] == 0)
        {
            dfs(it, b, i);
            if(low[it] > tin[i])
                if(tin[it]<=tin[b] && tout[it]>=tout[b])
                    ans++;
            low[i] = min(low[i], low[it]);
        }
        else
            low[i] = min(low[i], tin[it]);
    }
    tout[i] = timer++;
}

int getMinDistance(int n, int m, vector<int> &v1, vector<int> &v2, int a, int b) {
    v.clear();
    for(int i=0; i<m; i++)
    {
        v[v1[i]].push_back(v2[i]);
        v[v2[i]].push_back(v1[i]);
    }
    timer = 0, ans = 0;
    vis.assign(n, 0), tin.assign(n, 0), tout.assign(n, 0), low.assign(n, 0);
    dfs(a, b, -1);
    return ans;
}
