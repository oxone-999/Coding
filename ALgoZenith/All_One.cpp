#include <bits/stdc++.h>
using namespace std;

class AllOne
{
public:
	
    map<string,int> mp;
    set<pair<int,string>> s1;
    set<pair<int,string>> s2;

	AllOne() {
        mp.clear();
        s1.clear();
        s2.clear();
	}

	void inc(string key) {
		int x = mp[key];
		if(mp[key] > 0){
			auto it = s1.lower_bound({x,key});
			auto it2 = s2.lower_bound({-x,key});
            s1.erase(*it);
            s2.erase(*it2);
        }
		mp[key]++;
		s1.insert({mp[key],key});
		s2.insert({-mp[key],key});
	}

	void dec(string key) {
		int x = mp[key];
        mp[key]--;
		auto it = s1.lower_bound({x,key});
		auto it2 = s2.lower_bound({-x,key});
		s1.erase(*it);
		s2.erase(*it2);

        if(mp[key] == 0){
            mp.erase(key);
        }
        else {
            s1.insert({mp[key],key});
            s2.insert({-mp[key],key});
        } 
	}

	string getMaxKey() {
		if(s1.empty()) return "";
        return (*s1.rbegin()).second;
	}

	string getMinKey() {
		if(s2.empty()) return "";
		return (*s2.rbegin()).second;
	} 
	
};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int Q;
	cin >> Q;
	
	AllOne allOne;

	while (Q--)
	{
		string op;
		cin >> op;

		if (op == "inc") {
			string key;
			cin >> key;

			allOne.inc(key);
		}
		else if (op == "dec") {
			string key;
			cin >> key;

			allOne.dec(key);
		}
		else if (op == "getMaxKey") {
			cout << allOne.getMaxKey() << "\n";
		}
		else if (op == "getMinKey") {
			cout << allOne.getMinKey() << "\n";
		}
	}

	return 0;
}