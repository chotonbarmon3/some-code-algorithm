#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const ll mod = 1000000007;

bool cmp(pair<ll,ll>&a,pair<ll,ll>&b)
{
    return a.second<b.second;
}
void solve() {
 ll n;
 cin>>n;
 vector<pair<ll,ll>>v;
 for(int i=0;i<n;i++)
 {
    ll x,y;
    cin>>x>>y;
    v.push_back({x,y});
 }
 sort(v.begin(),v.end(),cmp);

 ll s=v[0].first,e=v[0].second;
 vector<pair<ll,ll>>p;
 p.push_back({s,e});
 ll i=0;
 for(auto &it:v)
 {
    if(i==0)
{
    i++;
    continue;
}
if(it.first>e)
{
    s=it.first;
    e=it.second;
    p.push_back({s,e});
}
 }
 for(auto &it:p)
 cout<<it.first<<" "<<it.second<<endl;
 cout<<endl;

 
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--)
        solve();  
    return 0;
}
