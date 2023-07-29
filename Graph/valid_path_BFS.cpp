#include<bits/stdc++.h>
using namespace std;


string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

bool isInside(int x,int y,int cx,int cy,int r)
{
    int R = r*r;
    int dist = (x-cx)*(x-cx) + (y-cy)*(y-cy);
    if(dist > R) return 0;
    else return 1;
}

bool isValid(int x,int y,int X,int Y)
{
    if(x>=0 && x<=X && y>=0 && y<=Y) return true;
    else return false;
}

string solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    int dx[] = {1,-1,-1,1,0,1,0,-1};
    int dy[] = {1,-1,1,-1,1,0,-1,0};
    
    int n = C; //number of points
    int r = D; //radius of the circle
    
    queue<pair<int,int>> q;
    vector<vector<int>> vis(A+2,vector<int>(B+2,0));
    
    q.push({0,0});
    vis[0][0] = 1;
    int x,y;
    
    for(int i=0;i<n;i++)
    {
        if(isInside(0,0,E[i],F[i],r)) return "NO";
    }
    
    for(int i=0;i<n;i++)
    {
        if(isInside(A,B,E[i],F[i],r)) return "NO";
    }
    
    while(!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        if(x == A && y == B) 
            return "YES";
        
        for(int i=0;i<8;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(!isValid(nx,ny,A,B)) continue;
            
            bool val = true;
            for(int j=0;j<n;j++)
            {
                if(isInside(nx,ny,E[j],F[j],r))
                {
                    val = false;
                    break;
                }
            }
            
            if(!val) continue;
            
            if(!vis[nx][ny])
            {
                if(nx == A && ny == B) return "YES";
                vis[nx][ny] = 1;
                q.push({nx,ny});
            }        
        }
    } 
    return "NO";
}


signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--)
    {
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        int n = C;

        vector<int> E(C,0);
        vector<int> F(C,0);

        for(int i=0;i<n;i++)
        {
            cin>>E[i];
        }

        for(int i=0;i<n;i++)
        {
            cin>>F[i];
        }

        cout<<solve(A,B,C,D,E,F);
    }
    return 0;
}