#include <bits/stdc++.h>
using namespace std;

class LFUCache {
public:
    map<int,int> mp;
    map<int,int> freq;
    map<int,list<int>> mp_li;
    map<int,list<int> :: iterator> itr_map;
    int cap;
    int lfu;
    int size;

	LFUCache(int n) {
		cap = n;
        lfu = 0;
        size = 0;
        mp.clear();
        freq.clear();
        mp_li.clear();
	}

	int get(int key) {
        if(!mp.count(key)) return -1;
        update(key);
        return mp[key];
	}

    int update(int key){
        mp_li[freq[key]].erase(itr_map[key]);
        freq[key]++;
        mp_li[freq[key]].push_back(key);
        itr_map[key] = --mp_li[freq[key]].end();
        if(mp_li[lfu].empty()){
            lfu++;
        }
    }

	void put(int key, int value) {
        if(cap == 0) return;
        if(mp.count(key)){
            mp[key] = value;
            update(key);
        }
        else{
            if(size == cap){
                int evict = mp_li[lfu].front();
                mp_li[lfu].pop_front();
                mp.erase(evict);
                freq.erase(evict);
                itr_map.erase(evict);
            }else{
                size++;
            }
            mp[key] = value;
            freq[key] = 1;
            mp_li[freq[key]].push_back(key);
            itr_map[key] = --mp_li[freq[key]].end();
            lfu = 1;
        }
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	LFUCache* obj = new LFUCache(n);
	while (q--) {
		string op;
		cin >> op;
		if (op == "get") {
			int key;
			cin >> key;
			cout << obj->get(key) << "\n";
		}
		else if (op == "put") {
			int key, value;
			cin >> key >> value;
			obj->put(key, value);
		}
	}
}