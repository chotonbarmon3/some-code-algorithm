#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MX INT64_MAX
#define MI INT64_MIN

#define all(x) x.begin(),x.end()
#define bt(x) __builtin_popcountll(x)

#define in(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define print(a) for(auto &it:a)cout<<it<<" ";cout<<endl;






void solve()
{
ll n;
cin>>n;
ll k;
cin>>k;
vector<vector<ll>>v(n,vector<ll>(k));
for(int i=0;i<n;i++)
{
    for(int j=0;j<k;j++)
    {
        cin>>v[i][j];
    }
}
vector<ll>r,c;
ll ans=0;
for(int i=0;i<n;i++)
{
    ll rr=0,cc=0;
    for(int j=0;j<k;j++)
    {
rr=(rr^v[i][j]);
//cc=(cc^v[j][i]);
    }
    r.push_back(rr);
   // c.push_back(cc);
    ans+=rr;
    ans+=cc;
}

for(int i=0;i<k;i++)
{
    ll rr=0,cc=0;
    for(int j=0;j<n;j++)
    {
//rr=(rr^v[i][j]);
cc=(cc^v[j][i]);
    }
    //r.push_back(rr);
    c.push_back(cc);
    ans+=rr;
    ans+=cc;
}
// sort(all(r));
// sort(all(c));
// print(r);
// print(c);
ll xx=ans;
//cout<<(28^29)<<endl;
for(int i=0;i<n;i++)
{
    for(int j=0;j<k;j++)
    {
        ll anss=(ans-r[i]-c[j]);
        anss+=(r[i]^c[j]);
        xx=min(xx,anss);
    }

}
cout<<xx<<endl;



}

int main()
{
ios_base :: sync_with_stdio(false);
cin.tie(nullptr);
ll t;
t=1;
cin>>t;
while(t--)
{
solve();
}
return 0;
}
