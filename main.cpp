/*
///

""""the problem"""""
if n=3 the resultat is 4
1+1+1
1+2
2+1
3

#include <unordered_map>
#include "bits\stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
const ll M=1e9 + 7;
ll sol(vector<ll>& d, ll n)
{
    if(n==0)return 1;
    if(n<0)return 0;
    if(d[n] != -1)return d[n];
    ll res =0;
    for(ll i=1;i<=6;i++)
        res+= sol(d,n-i),res %=M;
    return d[n]=res;
}

int main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   ll n;
   cin>>n;
   vector<ll>d(n+1,-1);
   cout<<sol(d,n);
    return 0;
}
*/


/*
"""""the problme"""
input n: nbr of coins x:sum finale
      enter n type of coins
output minimum nbr of coins to obtain the number x
exemple 3 , 11
        {1,5,7}
        result: 3::5+5+1
#include <unordered_map>
#include "bits\stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
const ll M=1e9 + 7;
int main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int n,x;
   cin >> n >> x;
   vector<ll>a(n+1);
   for(ll i=1;i<=n;i++)cin>>a[i];
   vector<vector<ll>>  d(2,vector<ll>(x+1,LLONG_MAX));
   for (ll i=0;i<=1;i++)d[i][0]=0;
   for (ll i=1;i<=n;i++)
   {
       for(ll j=1;j<=x;j++)
       {
           d[1][j]=min(d[1][j],d[0][j]);
           if(j -a[i] >= 0 && d[1][j- a[i]] != LLONG_MAX) d[1][j]=min(d[1][j],d[1][j- a[i]]+1);

       }
       swap(d[1],d[0]);
       fill(d[1].begin(),d[1].end(),LLONG_MAX);
       d[1][0]=0;
   }
   if (d[0][x]==LLONG_MAX)cout<<-1;
   else cout<< d[0][x];
   return 0;
}

//vector<int> d(4,100); akavector contains four ints with value of 100



"""""the problem"""
input n nbr of coins x sum finale
liste of n coins
output the nbr of combination existe
exemple
3 9
2 3 5
res=8
        |2+2+5
        |2+5+2
        |5+2+2
        |3+3+3
        |2+2+2+3
        |2+2+3+2
        |2+3+2+2
        |3+2+2+2

#include <unordered_map>
#include "bits\stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
const ll M=1e9 + 7;
int main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int n,x;
   cin >> n >> x;
   vector<ll>a(n+1);
   for(ll i=1;i<=n;i++)cin>>a[i];
   vector<ll>d(x+1,0);
   d[0] = 1;
   for(ll j=1;j<=x;j++)
    for(ll i=1;i<=n;i++)if(j-a[i]>=0)d[j]+=d[j-a[i]], d[j] %=M;
   cout << d[x];
   return 0;
}
*/


////the same problem but witout repetition
/*
#include <unordered_map>
#include "bits\stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
const ll M=1e9 + 7;
int main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int n,x;
   cin >> n >> x;
   vector<ll>a(n+1);
   for(ll i=1;i<=n;i++)cin>>a[i];
   vector<vector<ll>>d(2, vector<ll>(x+1,0));
   for(ll i=0;i<=1;i++)d[i][0]=1;
   for(ll i=1;i<=n;i++)
   {
       for(ll j=1;j<=x;j++)
       {
           d[1][j]=d[0][j];
           if (j-a[i]>=0)d[1][j]+=d[1][j-a[i]];
           d[1][j] %=M;
       }
       swap(d[1],d[0]);
       fill(d[1].begin(),d[1].end(),0);
       d[1][0]=1;

   }
   cout<<d[0][x];
   return 0;


}
*/
/*demoving digits
#include <unordered_map>
#include "bits\stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
const ll M=1e9 + 7;
int main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int n;
   cin>>n;
   vector<ll>d(n+1,LLONG_MAX);
   d[0]=0;
   for(ll i=1;i<=n;i++)
   {
       ll t=i;
       ll mx=LLONG_MAX;
       while(t!=0)
       {
           ll dv = t%10;
           t/= 10;
           if(i-dv>=0)
              mx=min(mx,d[i-dv]);

       }
       d[i]= mx +1;
   }
   cout<<d[n];
   return 0;

}
*/
/*
"" grid path""
#include <unordered_map>
#include "bits\stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
const ll M=1e9 + 7;
int main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int n;
   cin>>n;
   vector<string>a(n);
   for(ll i=0;i<= n-1;i++)cin>> a[i];
   vector<vector<ll>>d(n,vector<ll>(n,0));
   d[0][0] =1;
   if(a[0][0]=='*' || a[n-1][n-1]== '*')
   {
       cout<< 0;
       return 0;
   }
   for(ll i=0;i<= n-1;i++)
   {
       for(ll j=0;j<= n-1;j++)
       {
           if(a[i][j]!= '*')
           {
               if(i-1>=0 &&a[i-1][j]!= '*')
               {
                   d[i][j]+=d[i-1][j],d[i][j] %=M;
               }
                if(j-1>=0 &&a[i][j-1]!= '*')
               {
                   d[i][j]+=d[i][j-1],d[i][j] %=M;
               }
           }
       }
   }
   cout<<d[n-1][n-1];
   return 0;
}
*/
/* """problem name : Book Shop"""
#include <unordered_map>
#include "bits\stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
const ll M=1e9 + 7;
int main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   ll n;
   cin>>n;
   ll x;
   cin>>x;
   vector<vector<ll>>a(2, vector<ll>(n+1));
   for(ll i=1;i<=n;i++)
      cin>>a[0][i];
   for(ll i=1;i<=n;i++)
      cin>>a[1][i];
   vector<vector<ll>>d(2, vector<ll>(x+1,0));
   for(ll i=1;i<=n;i++)
   {
       for(ll j=1;j<=x;j++)
       {
           d[1][j]=d[0][j];
           if(j- a[0][i]>=0)d[1][j]=max(d[0][j],d[0][j-a[0][i]] + a[1][i]);

       }
       swap(d[0],d[1]);
       fill(d[1].begin(),d[1].end(),0);

   }
   cout<<d[0][x];
   return 0;

}
*/
#include <unordered_map>
#include "bits\stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
const ll M=1e9 + 7;
int main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int n,m;
   cin>>n>>m;
   vector<string>a(n);
   for(ll i=0;i<= n-1;i++)cin>> a[i];


}
