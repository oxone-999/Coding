//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

void solve()
{
    int n,r,c,x,y;
    cin>>n>>r>>c>>x>>y;
    string s;
    cin>>s;

    map<pair<int,int>,vector<pair<int,int>>> mp;

    for(int i=0;i<n;i++){
        int nX = x;
        int nY = y;
        int Ox = x;
        int Oy = y;

        if(s[i] == 'N'){
            x--;
            if(!mp.count({x,y})){
            }else{
                while(mp.count({x,y})){
                    vector<pair<int,int>> v = mp[{x,nY}];
                    for(auto it:v){
                        if(it.second == nY && it.first < nX){
                            x = it.first;
                            nX = x;
                            break;
                        }
                    }
                    nX--;
                    x--;
                }
            }
        }else if(s[i] == 'E'){
            y++;
            if(!mp.count({x,y})){
            }else{
                while(mp.count({x,y})){
                    vector<pair<int,int>> v = mp[{nX,y}];
                    for(auto it:v){
                        if(it.second > nY && it.first == nX){
                            y = it.second;
                            nY = y;
                            break;
                        }
                    }
                    nY++;
                    y++;
                }
            }
        }else if(s[i] == 'W'){
            y--; 
            if(!mp.count({x,y})){
            }else{
                while(mp.count({x,y})){
                    vector<pair<int,int>> v = mp[{nX,y}];
                    for(auto it:v){
                        if(it.second < nY && it.first == nX){
                            y = it.second;
                            nY = y;
                            break;
                        }
                    }
                    nY--;
                    y--;
                }
            }
        }else {
            x++;
            if(!mp.count({x,y})){
            }else{
                while(mp.count({x,y})){
                    vector<pair<int,int>> v = mp[{x,nY}];
                    for(auto it:v){
                        if(it.second == nY && it.first > nX){
                            x = it.first;
                            nX = x;
                            break;
                        }
                    }
                    nX++;
                    x++;
                }
            }
        }
        mp[{Ox,Oy}].push_back({x,y});
        mp[{x,y}].push_back({Ox,Oy});
    }
    cout<<x<<" "<<y<<endl;
}

signed main(){
    IOS
    int t=1;cin>>t;while(t--) solve();
    return 0;
}