// Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.

// Bonus if you can solve it in O(n^2) or less.

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

int MAH(vector<int> arr, int n)
{
    stack<pair<int,int>> st;
    vector<int> vec1;
    vector<int> vec2;
    
    for(int i=n-1;i>=0;i--)
    {
        if(st.empty()) vec1.push_back(n);
        else if(arr[i]>st.top().first) vec1.push_back(st.top().second);
        else
        {
            while(!st.empty() && arr[i]<=st.top().first)
            {
                st.pop();
            }
            if(st.empty()) vec1.push_back(n);
            else if(arr[i]>st.top().first) vec1.push_back(st.top().second);
        }
        st.push({arr[i],i});
    }
    reverse(vec1.begin(),vec1.end());
    while(!st.empty())
    {
        st.pop();
    }
    
    for(int i=0;i<n;i++)
    {
        if(st.empty()) vec2.push_back(-1);
        else if(arr[i]>st.top().first) vec2.push_back(st.top().second);
        else
        {
            while(!st.empty() && arr[i]<=st.top().first)
            {
                st.pop();
            }
            if(st.empty()) vec2.push_back(-1);
            else if(arr[i]>st.top().first) vec2.push_back(st.top().second);
        }
        st.push({arr[i],i});
    }
    int mx = INT_MIN;
    for(int i=0;i<n;i++)
    {
        mx = max(mx,arr[i] * (abs(vec1[i]-vec2[i])-1));
    }
    return mx;
}

int maximalRectangle(vector<vector<int>> &A) {
    
    int n = A.size();
    int m = A[0].size();
    vector<int> vec(m,0);
    int mx = INT_MIN;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j] == 0) vec[j] = 0;
            else vec[j] += A[i][j];
        }
        mx = max(mx,MAH(vec,m));
    }
    return mx;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> vec(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vec[i][j];
        }
    }    
    cout<<maximalRectangle(vec)<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}