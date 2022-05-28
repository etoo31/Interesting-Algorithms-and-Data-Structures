#include <bits/stdc++.h>
#define endl '\n'
#define etoo ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N = 1e5+1;
int arr[N];
int seg[N*4];
void build(int node , int l , int r)
{
    if (l==r)return void(seg[node] = arr[l]);
    int mid = (l+r)/2;
    build(node*2 , l , mid);//left
    build(node*2+1 , mid+1 , r);//right
    seg[node] = min(seg[node*2] , seg[node*2+1]);
}
int query(int node , int l , int r , int i , int j)
{
    if (r < i || l > j)return 1e9;
    if (l >= i && r <= j)
        return seg[node];
    int mid = (l+r)/2;
    int q1 = query(node*2 , l , mid , i , j);//left
    int q2 = query(node*2+1 , mid+1 , r , i , j);//right
    return min(q1 , q2);
}
void update(int node , int l , int r , int index , int value)
{
    if (r < index || l > index)return;
    if (l == r)return void(seg[node] = value);
    int mid = (l+r)/2;
    update(node*2 , l , mid , index , value);
    update(node*2+1 , mid+1 , r , index , value);
    seg[node] = min(seg[node*2] , seg[node*2+1]);
}
int main() {
   etoo

       int n;
       cin >> n;
       for (int i = 0 ;i  < n; i++)
           cin >> arr[i];
       build(1 , 0 , n-1);
       int q;
       cin >> q;
       while (q--)
       {
           int type;
           cin >> type;
           if (type == 1)
           {
               int i, j;
               cin >> i >> j;
               cout << query(1, 0, n - 1, i, j) << endl;
           }
           else
           {
               int index , value;
               cin >> index >> value;
               update(1 , 0 , n-1 , index , value);

           }

       }




    return 0;
}
