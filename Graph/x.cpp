#include<bits/stdc++.h>
using namespace std;

void process(string **matrix, size_t size){
    set<string> st;
    map<string, int> m[size];
    for(size_t i=0;i<size;i++){
        for(size_t j=0;j<size;j++){
            st.insert(matrix[i][j]);
            m[i][matrix[i][j]]++;
        }
    }
    int sum = 0;
    for(auto it:st){
        int count = 0;
        for(size_t i=0;i<size;i++){
            if(m[i].find(it) != m[i].end()) count++;
        }
        if(count == size/2) sum += stoi(it); 
    }

    cout<<sum<<endl;
}

void solve()
{
    int n;
    cin>>n;
    string **matrix;

    matrix = new string*[n];

    for(int i=0;i<n;i++){
        string *row = new string[n];
        for(int j=0;j<n;j++){
            cin>>row[j];
        }
        matrix[i] = row;
    }

    process(matrix,n);
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    solve();
    return 0;
}