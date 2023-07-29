// The count-and-say sequence is the sequence of integers beginning as follows: 
// 1, 11, 21, 1211, 111221, ...
// 1 is read off as one 1 or 11. 11 is read off as two 1s or 21.
// 21 is read off as one 2, then one 1 or 1211.

// Given an integer n, generate the nth sequence.

// Note: The sequence of integers will be represented as a string.

string countAndSay(int A) {
    int count = 0;
    string s = "1";
    for(int i = 1;i<A;i++)
    {
        char c = s[0];
        int count = 0;
        vector<pair<int,char>> vec;
        for(int j = 0;j<s.size();j++)
        {
            if(s[j] == c) count++;
            else 
            {
                vec.push_back({count,c});
                count = 0;
                c = s[j];
                j--;
            }
        }
        if(count) vec.push_back({count,c});
        s.clear();
        for(int i=0;i<vec.size();i++)
        {
            s += to_string(vec[i].first);
            s.push_back(vec[i].second);
        }
    }
    return s;
}
