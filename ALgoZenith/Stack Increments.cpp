#include <bits/stdc++.h>
using namespace std;

using lli = long long;

class CustomStack {
public:
    lli maxC;
    vector<pair<lli,lli>> vec;  
	
	CustomStack(lli maxSize){
        maxC = maxSize;
        vec.clear();
	}

	void push(lli x) {
        if(vec.size() < maxC) vec.push_back({x,0});
	}

	lli pop() {
        if(vec.empty()) return -1;
        lli x = vec.back().first + vec.back().second;
        lli y = vec.back().second;
        vec.pop_back();
        if(!vec.empty()) vec[vec.size()-1].second += y;
        return x;
	}

	void increment(lli k, lli val) {
        if(vec.empty()) return;
        k--;
        if(vec.size() < k){
            vec[vec.size()-1].second += val;
        }
		else vec[k].second += val;
	}
};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	lli maxSize;
	cin >> maxSize;

	lli q;
	cin >> q;

	CustomStack* customStack = new CustomStack(maxSize);

	for (lli itr = 0; itr < q; itr++) {
		string op;
		cin >> op;

		if (op == "push") {
			lli x;
			cin >> x;

			customStack->push(x);
		}
		else if (op == "pop") {
			cout << customStack->pop() << "\n";
		}
		else if (op == "inc") {
			lli k, val;
			cin >> k >> val;
			customStack->increment(k, val);
		}
	}

}