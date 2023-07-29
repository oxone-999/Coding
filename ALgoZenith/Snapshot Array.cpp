#include <bits/stdc++.h>
using namespace std;

class SnapshotArray
{
public:

    unordered_map<int,unordered_map<int,int>> mp;
    int id;
	
	SnapshotArray(int length)
	{
		id = 0;
        mp.clear();
	}

	void set(int index, int val)
	{
        mp[index][id] = val;
	}

	int snap()
	{
		id++;
        return id-1;
	}

	int get(int index, int snap_id)
	{
		if(mp[index].size() == 0){
			return 0;
		}
		else return mp[index][snap_id];
	}
};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int Q, L;
	cin >> Q >> L;

	SnapshotArray snapshotArray(L);

	while (Q--)
	{
		string op;
		cin >> op;

		if (op == "set")
		{
			int index, val;
			cin >> index >> val;

			snapshotArray.set(index, val);
		}
		else if (op == "get")
		{
			int index, snap_id;
			cin >> index >> snap_id;

			cout << snapshotArray.get(index, snap_id) << "\n";
		}
		else if (op == "snap")
		{
			cout << snapshotArray.snap() << "\n";
		}
	}

	return 0;
}