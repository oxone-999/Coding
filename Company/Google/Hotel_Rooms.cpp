// You are the manager of a hotel having 10 floors numbered 0-9. Each floor has 26 rooms [A-Z]. You will be given a sequence of strings
//  of the room where ‘+’ suggests the room is booked and ‘-’ suggests the room is freed. You have to find which room is booked the
//   maximum number of times.

// Note:

// You may assume that the sequence is always correct, i.e., every booked room was previously free, and every freed room was
//  previously booked.
// In case, 2 rooms have been booked the same number of times, you have to return Lexographically smaller room.

// A string 'a' is lexicographically smaller than a string 'b' (of the same length) if in the first position where 
// 'a' and 'b' differ, string 'a' has a letter that appears earlier in the alphabet than the corresponding letter in string 
// 'b'. For example, "abcd" is lexicographically smaller than "acbd" because the first position they differ in is at the 
// second letter, and 'b' comes before 'c'.

#include<bits/stdc++.h>

string maxRoomBooked(vector<string> arr, int n) {
    map<string,int> mp;
    
    for(int i=0;i<n;i++)
    {
        string s;
        s.push_back(arr[i][1]);
        s.push_back(arr[i][2]);
        if(arr[i][0] == '+') mp[s]++;
    }
    
    int ans = INT_MIN;
    for(auto it:mp)
    {
        if(ans < it.second){
            ans = it.second;
        }
    }
    vector<string> vec;
    for(int i=n-1;i>=0;i--)
    {
        string s;
        s.push_back(arr[i][1]);
        s.push_back(arr[i][2]);
        if(mp[s] == ans) vec.push_back(s);
    }
    sort(vec.begin(),vec.end());
    return vec[0];
}