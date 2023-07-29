#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        int i,j;
        int A,B;

        cin>>i>>j;
        cin>>A>>B;

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n+1,vector<int>(n+1,0));

        q.push({{i,j},0});
        vis[i][j] = 1;

        while(!q.empty()){
            int X = q.front().first.first;
            int Y = q.front().first.second;
            int level = q.front().second;
            q.pop();

            // cout<<level<<" ";
            if(X == A && Y == B){
                cout<<level;
                return 0;
            }

            if(X-2>=0&&X-2<n&&Y-1>=0&&Y-1<n&&!vis[X-2][Y-1]) q.push({{X-2,Y-1},level+1}), vis[X-2][Y-1] = 1;
            if(X-2>=0&&X-2<n&&Y+1>=0&&Y+1<n&&!vis[X-2][Y+1]) q.push({{X-2,Y+1},level+1}), vis[X-2][Y+1] = 1;
            if(X+2>=0&&X+2<n&&Y-1>=0&&Y-1<n&&!vis[X+2][Y-1]) q.push({{X+2,Y-1},level+1}), vis[X+2][Y-1] = 1;
            if(X+2>=0&&X+2<n&&Y+1>=0&&Y+1<n&&!vis[X+2][Y+1]) q.push({{X+2,Y+1},level+1}), vis[X+2][Y+1] = 1;
            if(X-1>=0&&X-1<n&&Y+2>=0&&Y+2<n&&!vis[X-1][Y+2]) q.push({{X-1,Y+2},level+1}), vis[X-1][Y+2] = 1;
            if(X-1>=0&&X-1<n&&Y-2>=0&&Y-2<n&&!vis[X-1][Y-2]) q.push({{X-1,Y-2},level+1}), vis[X-1][Y-2] = 1;
            if(X+1>=0&&X+1<n&&Y-2>=0&&Y-2<n&&!vis[X+1][Y-2]) q.push({{X+1,Y-2},level+1}), vis[X+1][Y-2] = 1;
            if(X+1>=0&&X+1<n&&Y+2>=0&&Y+2<n&&!vis[X+1][Y+2]) q.push({{X+1,Y+2},level+1}), vis[X+1][Y+2] = 1;
        }
        cout<<(-1)<<endl;
    }
    return 0;
}