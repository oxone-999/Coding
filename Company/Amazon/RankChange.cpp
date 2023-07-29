vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int,int>> vec;
        
        int n = arr.size();
        if(n == 0) return {};
        
        for(int i=0;i<n;i++)
        {
            vec.push_back({arr[i],i});
        }
        sort(arr.begin(),arr.end());
        sort(vec.begin(),vec.end());
        
        vec[0].first = 1;
        
        for(int i=1;i<n;i++)
        {
            vec[i].first = (vec[i].first == arr[i-1]) ? vec[i-1].first : vec[i-1].first + 1;
        }
        
        sort(vec.begin(),vec.end(),[](pair<int,int> &a,pair<int,int> &b){
           return a.second < b.second; 
        });
        
        vector<int> v;
        for(auto &it:vec){
            v.push_back(it.first);
        }
        return v;
    }