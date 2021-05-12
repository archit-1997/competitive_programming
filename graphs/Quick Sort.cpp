// Chochu Singh
// Quick Sort
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

ll partition(V &v, ll a, ll b) {
  if (a < b) {
    ll l = a, m = a, h = b, pivot = v[a];

    while (m <= h) {
      if (v[m] < pivot) {
        swap(v[l], v[m]);
        l++, m++;
      } else if (v[m] == pivot)
        m++;
      else {
        swap(v[m], v[h]);
        h--;
      }
    }

    return m - 1;
  }

  return -1;
}

void quick(V &v, ll l, ll r) {
  if (l < r) {
    ll pivot = partition(v, l, r);

    quick(v, l, pivot - 1);
    quick(v, pivot + 1, r);
  }
}

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

  quick(v, 0, n - 1);

  FOR(i, 0, n)
  cout << v[i] << " ";

  return 0;
}
