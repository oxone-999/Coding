#include <bits/stdc++.h>
using namespace std;

int FindRepeated(vector<int> &a)
{
    int n = a.size();
    int XOR = 0;
    for(auto it:a){
        XOR = XOR^it;
    }
    
    for(int i=0;i<n;i++)
    {
        XOR = XOR^i;
    }
    return XOR;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << FindRepeated(a) << "\n";
}