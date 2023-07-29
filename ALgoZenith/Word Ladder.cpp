#include <bits/stdc++.h>
using namespace std;

class WordLadder
{
public:
	int getMinMoves(string beginWord, string endWord, vector<string> &dictionary)
	{
		queue<pair<string,int>> q;
        q.push({beginWord,1});

        unordered_map<string,int> mp2;

        for(auto it:dictionary){
            mp2[it];
        }

        unordered_map<string,int> mp;
        mp[beginWord];

        while(!q.empty()){
            string s = q.front().first;
            int dis = q.front().second;
            q.pop();

            if(s == endWord){
                return dis;
            }

            for(int i=0;i<s.size();i++){
                for(int j=0;j<26;j++){
                    string str = s;
                    str[i] = j + 'a';
                    if(mp2.count(str) && !mp.count(str)){
                        mp[str];
                        q.push({str,dis+1});
                    }
                }
            }
        }
        return 0;
	}
};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<string> dictionary;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		dictionary.push_back(s);
	}

	string beginWord, endWord;
	cin >> beginWord >> endWord;

	WordLadder wordLadder;

	cout << wordLadder.getMinMoves(beginWord, endWord, dictionary) << "\n";

	return 0;
}