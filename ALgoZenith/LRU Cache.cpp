#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:

    int cap;
    int size;
    unordered_map<int,int> mp;
    unordered_map<int,list<int> :: iterator> mp2;
    list<int> l;

    LRUCache(int capacity)
    {
        mp.clear();
        l.clear();
        mp2.clear();
        cap = capacity;
        size = 0;
    }

    int get(int key)
    {
        if(!mp.count(key)){
            return -1;
        }
        l.erase(mp2[key]);
        mp2.erase(key);
        l.push_front(key);
        mp2[key] = l.begin();
        return mp[key];
    }

    void put(int key, int value)
    {
        if(mp.count(key)){
            l.erase(mp2[key]);
            mp2.erase(key);
            l.push_front(key);
            mp2[key] = l.begin();
        }else{
            if(size == cap){
                int x = l.back();
                l.erase(mp2[x]);
                mp.erase(x);
                mp2.erase(x);
                size--;
            }
            size++;
            l.push_front(key);
            mp2[key] = l.begin();
        }
        mp[key] = value;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q, cap;
    cin >> q >> cap;
    LRUCache *obj = new LRUCache(cap);
    for (int i = 0; i < q; i++)
    {
        string op;
        cin >> op;
        if (op == "get")
        {
            int key;
            cin >> key;
            cout << obj->get(key) << '\n';
        }
        else
        {
            int key, val;
            cin >> key >> val;
            obj->put(key, val);
        }
    }

    return 0;
}