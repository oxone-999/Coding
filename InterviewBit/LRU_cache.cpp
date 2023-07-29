#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

class LRUCache {
    int capacity;
    unordered_map<int, pair<int, list<int>::iterator>> mp;
    list<int> l;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        l.clear();
        mp.clear();
    }

    void touch(int id){ // update the position of the element in the list
        auto it = mp.find(id); // it->second.second is the iterator to the element in the list
        if(it != mp.end()){ // if found
            l.erase(it->second.second); // erase from list
            l.push_front(id); // push to front
            it->second.second = l.begin(); //update the iterator
        }
    }
    
    int get(int key) {
        if(mp.count(key)){
            touch(key);
            return mp[key].first;
        }else return -1;
    }
    
    void put(int key, int value) {
        if(!mp.count(key)){
            int del = l.back();
            mp.erase(del);
            l.pop_back();
        }else touch(key);
        mp[key] = {value, l.begin()};
    }
};

void solve()
{
    
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}