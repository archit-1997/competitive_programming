// Archit Singh
// architsingh456@gmail.com
// GitHub : archit-1997

// Segment tree : Range min query

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>

using namespace std;
using namespace __gnu_pbds;

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
#define line cout << "-------------" << endl;
#define mod 1000000007
#define inf 1e18

#define setbits(x) __builtin_popcount(x)
#define zerobits(x) __builtin_ctzll(x)
#define ps(x, y) fixed << setprecision(y) << x
#define w(x)                                                                   \
  ll x;                                                                        \
  cin >> x;                                                                    \
  while (x--)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define ma(arr, n, type) type *arr = new type[n]
#define pbds                                                                   \
  tree<int, null_type, less<int>, rb_tree_tag,                                 \
       tree_order_statistics_node_update>

void init() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}

// index stores the index of the given element in the array(or you can say the
// node) s and e store the starting and ending index of the array elements that
// the tree node will store
void build_tree(V &tree, V &a, ll index, ll s, ll e) {
  // now if we reach the end of the array
  if (s == e) {
    tree[index] = a[s];
    return;
  }

  // another base case
  if (s > e)
    return;

  // recursive case
  int m = s + (e - s) / 2;

  // build the left subtree
  build_tree(tree, a, 2 * index, s, m);
  // build the right subtree
  build_tree(tree, a, 2 * index + 1, m + 1, e);

  // now compute the values for the current node
  int l = tree[2 * index], r = tree[2 * index + 1];
  tree[index] = min(l, r);
}

ll query(V &tree, ll index, ll s, ll e, ll qs, ll qe) {
  // qs and qe are the range on which we have to query for the answer
  // s and e are for the tree

  // query on the tree
  // any query can be of three types:
  // 1. complete overlapp -> return the value of tree[index] in this case
  // 2. partial overlapp -> in this case, individually call for both the
  // subtrees
  // 3. no overlapp -> in this case, return INF in case of range min query

  if (qs > e || qe < s) {
    // if there is no overlapp
    return INT_MAX;
  }

  if (s >= qs && e <= qe) {
    // if this is a complete overlapp
    return tree[index];
  }

  // if partial overlapp, call both sides
  ll m = s + (e - s) / 2;
  // note that we are only changing the index of the tree nodes and not of the
  // query that we are sending down the tree
  ll l = query(tree, 2 * index, s, m, qs, qe);
  ll r = query(tree, 2 * index + 1, m + 1, e, qs, qe);
  return min(l, r);
}

void update_node(V &tree, ll index, ll s, ll e, ll i, ll val) {
  // element at index i needs to be updated with value val
  // building a tree takes O(n) time while updating takes only O(log(n) time
  if (i < s || i > e)
    return;

  // if we reach a leaf node
  if (s == e) {
    // index here is for the segment tree
    tree[index] = val;
    return;
  }

  // otherwise it is a partial overlap
  ll m = s + (e - s) / 2;
  // update the left subtree
  update_node(tree, 2 * index, s, m, i, val);
  // update the right subtree
  update_node(tree, 2 * index + 1, m + 1, e, i, val);

  // update the new values in the tree
  tree[index] = min(tree[2 * index], tree[2 * index + 1]);
  return;
}

// now lets talk about range update
// you have to increment every value in the range by v
void update_range(V &tree, ll index, ll s, ll e, ll rs, ll re, ll inc) {
  // no overlap
  if (re < s || rs > e)
    return;

  // if we have reached the leafnode
  if (s == e) {
    tree[index] += inc;
    return;
  }

  // partial overlap, call both sides
  ll m = s + (e - s) / 2;
  update_range(tree, 2 * index, s, m, rs, re, inc);
  update_range(tree, 2 * index + 1, m + 1, e, rs, re, inc);

  // now update the node of the tree
  tree[index] = min(tree[2 * index], tree[2 * index + 1]);

  return;
}

int main() {

  init();

  ll n;
  cin >> n;
  V a(n);
  FOR(i, 0, n)
  cin >> a[i];

  // build the tree array
  V tree(4 * n + 1, 0);

  // call the build_tree method
  build_tree(tree, a, 1, 0, n - 1);

  ll q;
  cin >> q;
  while (q--) {
    ll qs, qe;
    cin >> qs >> qe;
    ll ans = query(tree, 1, 0, n - 1, qs, qe);
    cout << ans << "\n";
  }

  // updating the segment tree
  // there are two types of updates
  // 1. index updates
  // 2. range updates

  return 0;
}
