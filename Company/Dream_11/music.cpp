// A music player allows users to choose songs to play, but only in pairs and only pairs of songs with durations that
//  add up to a multiple of 60 seconds (e.g., 60,120,180). Given a list of song durations, calculate the total number
//   of different song pairs that can be chosen.

#include <bits/stdc++.h>

using namespace std;
int playlist(vector<int> &songs)
{
    vector<int> count(60);
    int ans = 0;

    for(auto it:songs){
        it %= 60;
        ans += count[(60-(it%60))%60];
        count[it]++;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<int> songs(n);
    for(int i=0;i<n;++i)
    cin>>songs[i];
    cout<<playlist(songs); 
    return 0;
}