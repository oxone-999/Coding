//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()

float func(int noOfElements,vector<int> &bucketArray,vector<float> &percentageList,int size){
    if(noOfElements == 0) return 0.0;
    if(noOfElements > bucketArray[size-1]){
        return func(noOfElements - bucketArray[size-1],bucketArray,percentageList,size-1) + percentageList[size-1] * (bucketArray[size-1]) / 100;
    }else{
        return func(0,bucketArray,percentageList,size-1) + (float) percentageList[size-1] * (noOfElements) / 100;
    }
}

void solve()
{
    int noOfBuckets;
    int noOfElements;
    cin>>noOfBuckets>>noOfElements;

    float ans = 0.0;

    vector<int> bucketSizeArray;
    vector<float> percentageList;

    for(int i=0;i<noOfBuckets;i++){
        int size,percent;
        cin>>size>>percent;
        bucketSizeArray.push_back(size);
        percentageList.push_back(percent);
    }

    if(noOfElements <= bucketSizeArray[0]){
        cout<<noOfElements<<endl;
        return;
    }else{
        noOfElements -= bucketSizeArray[0];
        ans += bucketSizeArray[0];
    }

    reverse(all(bucketSizeArray));
    bucketSizeArray.pop_back();

    //Logic Function
    cout<<ans + func(noOfElements,bucketSizeArray,percentageList,noOfBuckets);
}

signed main(){
    solve();
    return 0;
}