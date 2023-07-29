#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
    	int n,a,b;
    	cin>>n>>a>>b;
        
        if(a==b){
            cout<<0<<endl;
            continue;
        }

        int cnt = 0;
        while(a!=b){
            if(b > a) b /= 2;
            else if(a > b) a /= 2;
            cnt++;
        }
        cout<<2*cnt - 1<<endl;
    }
    return 0;
}