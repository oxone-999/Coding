#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

struct LinkedList{
    int val;
    int next*;
    LinkedList(int x){
        val = x;
        next* = NULL;
    }
}
a->b
curr=  a;
prev - NULL
temp = b;
curr->prev
a->NULL;
prev = curr;
curr = temp;
curr = b;
a->NULL;
temp = NULL
curr->next = prev;
b - >a;
prev = b;
curr-= NULL;
b->a->null;

void func(Head){
    if(head->next == NULL){  
        head->next = prev;
        return head;                p h
    }/// 0->head<-head1NULL     0<1<2<3<4;
                       //         0>1<2<3<4;
    lIst  prev = Listnode(0);
    List temp = prev;
    temp->next= head;
    List* res = listNode(0);
    
    res->next = func(head->next);
    return res->next;
}

void solve()
{
    //prev
    //curr
    List* curr = head; // 
    List* prev = NULL;

    while(curr){
        List* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }//curr = NULL;
    temp NULL
    return prev;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}