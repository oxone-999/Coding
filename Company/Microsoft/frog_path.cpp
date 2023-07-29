#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,p,f,u,d;
    cin>>n>>p>>f>>u>>d;

    if(n == 0 || n == 1 || p == f) 
    {
        cout<<0<<endl;
        return 0;
    }

    queue<pair<int,int>> q;
    vector<int> vis(n+1,0);

    q.push({p,0});

    while(!q.empty()){
        int num = q.front().first;
        int level = q.front().second;
        q.pop();

        if(num == f){
            cout<<level;
            break;
        }

        if(num >= 1 && num <= n && !vis[num]){
            vis[num] = 1;
            q.push({num+u,level+1});
            q.push({num-d,level+1});
        }
    }
    return 0;
}