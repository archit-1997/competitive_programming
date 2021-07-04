// Archit Singh
// Djikstras Algorithm
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define line cout << "-------------" << endl;
#define F first
#define S second
#define P pair<ll, ll>
#define PP pair<pair<ll, ll>, ll>
#define V vector<ll>
#define VV vector<vector<ll>>
#define pb push_back
#define pf push_front

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vector<vector<P>> v(n + 1);

    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        v[a].pb({b, c});
        v[b].pb({a, c});
    }

    V vis(n + 1, 0);
    V dis(n + 1, INT_MAX);
    V par(n + 1, 0);

    multiset<P > s;

    // pair-->(distance,node name)
    s.insert({0, 1});
    dis[1] = 0;
    par[1] = -1;

    // Running the djikstras algorithm
    while (!s.empty()) {
        P p = *s.begin();

        s.erase(s.begin());

        ll x = p.S, wt = p.F;

        // If already visited , then continue
        if (vis[x])
            continue;

        vis[x] = 1;

        for (ll i = 0; i < v[x].size(); i++) {
            ll e = v[x][i].F, w = v[x][i].S;

            if (dis[x] + w < dis[e]) {
                dis[e] = dis[x] + w;
                s.insert({dis[e], e});
                par[e] = x;
            }
        }
    }

    // Printing the distances and the parents
    cout << "Node A\tNode B\tDistance(A->B)\tParent of Node B\n";
    for (ll i = 1; i <= n; i++)
        cout << "1\t\t\t" << i << "\t\t\t" << dis[i] << "\t\t\t\t" << par[i]
             << endl;

    return 0;
}
