vector<int> par;
vector<int> rankU;

int findPar(int node)
{
    if(node == par[node])
        return node;
    return par[node] = findPar(par[node]);
}

void unionn(int u,int v)
{
    u = findPar(u);
    v = findPar(v);
    par[v] = u;
}


int Solution::solve(vector<int> &A) {
    int n = A.size();
    par.resize(n+1);
    
    for(int i=0; i<=n; i++)
        par[i] = i;

    for(int i=2;i<n+1;i++)
        unionn(A[i-1],i);    
    
    set<int> s;
    for(int i=1;i<n+1;i++)
        s.insert(findPar(i));
        
    return int(s.size())-1;
}
