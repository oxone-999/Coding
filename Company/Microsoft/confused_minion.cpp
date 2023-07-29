#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t=1;
    // cin>>t;
    while(t--)
    {
    	int N,L;
        cin>>N>>L;

        vector<pair<int,int>> vec;

        for(int i=0;i<L;i++)
        {
            int t,d;
            cin>>t>>d;

            vec.push_back({t,d});
        }

        sort(vec.begin(),vec.end());

        int x = 0;
        int y = 0;
        int dir = 1;
        int prev = 0;
        for(auto it:vec){
            if(dir == 0){
                y += it.first-prev;
            }else if(dir == 1){
                x += it.first-prev;
            }else if(dir == 2){
                y -= it.first-prev;
            }else if(dir == 3){
                x -= it.first-prev;
            }

            prev = it.first;

            if(it.second == 0) dir = (dir-1+4)%4;
            else dir = (dir+1)%4;
        }
        if(dir == 0){
            y += N-prev;
        }else if(dir == 1){
            x += N-prev;
        }else if(dir == 2){
            y -= N-prev;
        }else if(dir == 3){
            x -= N-prev;
        }
        
        cout<<(x+y)<<endl;
    }
    return 0;
}