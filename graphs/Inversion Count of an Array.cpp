// Chochu Singh
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

void merge(V &v, ll l, ll m, ll r, ll &count) {
  ll n1 = m - l + 1, n2 = r - m;

  V left(n1), right(n2);

  FOR(i, 0, n1)
  left[i] = v[l + i];
  FOR(i, 0, n2)
  right[i] = v[m + 1 + i];

  ll i = 0, j = 0, index = l;

  while (i < n1 && j < n2) {
    if (left[i] <= right[j])
      v[index++] = left[i++];
    else {
      v[index++] = right[j++];
      count += (n1 - i);
    }
  }

  while (i < n1)
    v[index++] = left[i++];

  while (j < n2)
    v[index++] = right[j++];
}

void mergeSort(V &v, ll l, ll r, ll &count) {
  if (l < r) {
    ll m = l + (r - l) / 2;

    mergeSort(v, l, m, count);
    mergeSort(v, m + 1, r, count);
    merge(v, l, m, r, count);
  }
}

int main() {
  FAST;

  ll n;
  cin >> n;

  V v(n);

  FOR(i, 0, n)
  cin >> v[i];

  ll count = 0;

  mergeSort(v, 0, n - 1, count);

  // FOR(i,0,n)
  //     cout<<v[i]<<" ";
  // cout<<endl;
  cout << count << endl;

  return 0;
}
