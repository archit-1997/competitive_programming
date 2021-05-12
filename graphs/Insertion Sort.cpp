// Chochu Singh
// Insertion Sort
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

  FOR(i, 1, n) {
    ll tmp = v[i], j = i - 1;
    while (j >= 0 && v[j] > tmp) {
      // Shifting j by replicating value
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = tmp;
  }

  FOR(i, 0, n)
  cout << v[i] << " ";

  return 0;
}
