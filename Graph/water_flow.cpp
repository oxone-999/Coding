#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fori(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>b;i--)
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "


int vis[1001][1001];
int vec[1001][1001];

void bfsCheck(int i, int j ,int n, int m, vector<vector<int>> &A)
{
    queue<pair<int,int>> q;
    q.push({i,j});
    
    while(!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        
        if(!vis[i][j])
        {   
            vis[i][j] = 1;
            vec[i][j]++;
            
            if(i>0 && A[i-1][j] >= A[i][j]) q.push({i-1,j});
            if(i<n-1 && A[i+1][j] >= A[i][j]) q.push({i+1,j});
            if(j>0 && A[i][j-1] >= A[i][j]) q.push({i,j-1});
            if(j<m-1 && A[i][j+1] >= A[i][j]) q.push({i,j+1});   
        }
    }
}

void solve(vector<vector<int>> &A)
{
    int n = A.size();
    int m = A[0].size();
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(i == 0 || j == 0) bfsCheck(i,j,n,m,A);

    memset(vis,0,sizeof(vis));
            
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(i == n-1 || j == m-1) bfsCheck(i,j,n,m,A);
    
    int ans = 0;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(vec[i][j] == 2) ans++;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<vec[i][j]<<" ";
        cout<<endl;
    }
    
    cout<<ans<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t = 1;
    while(t--)
    {
        vector<vector<int>> A(5,vector<int>(5,0));

        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                cin>>A[i][j];
            }
        }

        solve(A);
    }
    return 0;
}

