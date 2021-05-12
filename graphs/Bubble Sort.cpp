// Chochu Singh
// Bubble sort
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

  for (ll i = 0; i < n - 1; i++) {
    ll flag = 0;
    // last i elements are already in place
    for (ll j = 0; j < n - i - 1; j++) {
      if (v[j] > v[j + 1]) {
        // if the array is already sorted
        flag = 1;
        swap(v[j], v[j + 1]);
      }
    }

    if (!flag)
      break;
  }

  FOR(i, 0, n)
  cout << v[i] << " ";

  return 0;
}
