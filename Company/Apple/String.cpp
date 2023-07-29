#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    string s1;
    cin>>s1;

    int n = s.size();
    int m = s1.size();

    if(n != m) 
    {
        cout<<"NO"<<endl;
        return 0;
    }

    map<int,int> m1;
    map<int,int> m2;

    for(int i=0;i<n;i++){
        m1[s[i]]++;
    }

    for(int i=0;i<n;i++){
        m2[s1[i]]++;
    }

    for(auto it:m1)
    {
        if(it.first - 'a' > 96){
            if(abs(m1[it.first]-m2[it.first]) > 3) {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }

    // for(auto it:m2)
    // {
    //     if(it.first - 'a' > 96){
    //         if(m2[it.first]-m1[it.first] > 3) {
    //             cout<<"NO"<<endl;
    //             return 0;
    //         }
    //     }
    // }
    cout<<"YES"<<endl;

    return 0;
}