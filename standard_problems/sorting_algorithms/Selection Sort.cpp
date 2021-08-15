// Chochu Singh
// Selection Sort
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
#define VP vector<pair<ll, ll>>
#define VS vector<string>
#define VV vector<vector<ll>>
#define VVP vector<vector<pair<ll, ll>>>
#define pb push_back
#define pf push_front
#define PQ priority_queue<ll>
#define PQ_G priority_queue<ll, vector<ll>, greater<ll>>
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define FAST                                                                   \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);

int main() {
  FAST;

  ll n;
  cin >> n;
  V v;

  FOR(i, 0, n) {
    ll num;
    cin >> num;
    v.pb(num);
  }

  FOR(i, 0, n - 1) {
    ll min = v[i], index = i, flag = 0;
    FOR(j, i + 1, n) {
      if (v[j] < min) {
        flag = 1;
        min = v[j];
        index = j;
      }
    }

    if (flag)
      swap(v[i], v[index]);
  }

  FOR(i, 0, n)
  cout << v[i] << " ";

  return 0;
}
