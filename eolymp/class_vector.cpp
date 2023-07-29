#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

class Vector
{
  private: 
  int x, y, z;

  public:

  Vector(){
    x = 0;
    y = 0;
    z = 0;
  } 
  Vector(int x1, int y1, int z1){
    x = x1;
    y = y1;
    z = z1;
  }
  Vector(Vector &v){
    x = v.x;
    y = v.y;
    z = v.z;
  }

  void setX(int x1){
    x = x1;
  }
  void setY(int y1){
    y = y1;
  }
  void setZ(int z1){
    z = z1;
  }

  int getX() {return x;}
  int getY() {return y;}
  int getZ() {return z;}

  double length(){
    return sqrt(x*x+y*y+z*z);
  } 
  void Out(){
    string str = "";
    str += to_string(x) + " " + to_string(y) + " " + to_string(z);
    cout<<str<<endl;
  }
};

void solve()
{
    Vector V(3,4,5);
    cout<<V.getX()<<" "<<V.getY()<<" "<<V.getZ();
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
solve();
return 0;
}