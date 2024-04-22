#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const ll mod = 1000000007;
bool cmp(vector<ll>&a,vector<ll>&b)
{
return b[2]>a[2];
}
void solve() {
    ll nodes, edges;
    cin >> nodes >> edges;

    
    vector<vector<ll>> graph(edges, vector<ll>(3));
    for (int i = 0; i < edges; i++) {
        ll source, destination, weight;
        cin >> source >> destination >> weight;
        graph[i][0] = source;
        graph[i][1] = destination;
        graph[i][2] = weight;
    }

    sort(graph.begin(), graph.end(), cmp);

    for (int i = 0; i < edges; i++) {
        cout << graph[i][0] << " " << graph[i][1] << " " << graph[i][2] << endl;
    }  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();  
    return 0;
}



