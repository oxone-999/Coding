#include <bits/stdc++.h>
using namespace std;

class FindPairswithSum
{
public:

    map<int,int> mp;
    map<int,int> mp2;
    vector<int> a;

    FindPairswithSum(vector<int> &A, vector<int> &B)
    {
        a = A;
        for(auto it:B){
            mp2[it]++;
        }

        for(int i=0;i<(int)B.size();i++){
            mp[i] = B[i];
        }
    }

    void add(int index, int val)
    {
        mp2[mp[index]]--;
        mp[index] += val;
        mp2[mp[index]]++;   
    }

    int count(int total)
    {
        int ans = 0;
        for(auto it:a){
            ans += mp2[total-it];
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> A(n), B(m);

    for (auto &i : A)
    {
        cin >> i;
    }

    for (auto &i : B)
    {
        cin >> i;
    }

    FindPairswithSum *obj = new FindPairswithSum(A, B);

    for (int i = 0; i < q; i++)
    {
        string op;
        cin >> op;
        if (op == "add")
        {
            int index, val;
            cin >> index >> val;
            obj->add(index, val);
        }
        else
        {
            int total;
            cin >> total;
            cout << obj->count(total) << '\n';
        }
    }

    return 0;
}