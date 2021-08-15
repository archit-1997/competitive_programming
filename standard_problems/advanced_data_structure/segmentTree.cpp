// Segment Tree : Range Min Query
#include <bits/stdc++.h>

using namespace std;

void init() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}

// 2*(next greater power of 2) -1
int findSize(int n) {
  // if power of two, just return
  int res;
  if (__builtin_popcount(n) == 1)
    res = n;
  else {
    // find the leftmost set bit
    int pos = (int)(log2(n));
    res = (1 << (pos + 1));
  }

  return (2 * res) - 1;
}

void constructSegmentTree(vector<int> &segmentTree, vector<int> &num, int low,
                          int high, int pos) {
  // reached the node
  if (low == high) {
    segmentTree[pos] = num[low];
    return;
  }
  int mid = low + (high - low) / 2;
  // recur for the left subtree
  constructSegmentTree(segmentTree, num, low, mid, 2 * pos + 1);
  // recur for the right subtree
  constructSegmentTree(segmentTree, num, mid + 1, high, 2 * pos + 2);
  segmentTree[pos] = min(segmentTree[2 * pos + 1], segmentTree[2 * pos + 2]);
}

// ql and qr are query parameters
// low and high are the bounds of the given array
int rangeMinQuery(vector<int> &segmentTree, int ql, int qr, int low, int high,
                  int pos) {
  // current tree segment completely outside the query parameter, then this
  // segment is of no use
  if (high < ql || low > qr)
    return INT_MAX;
  // current tree segment completely inside the query parameter, return the
  // value at this pos
  if (low >= ql && high <= qr)
    return segmentTree[pos];
  // partial overlap, recur for the left and right segments and return the min
  // from them
  int mid = low + (high - low) / 2;
  int left = rangeMinQuery(segmentTree, ql, qr, low, mid, 2 * pos + 1);
  int right = rangeMinQuery(segmentTree, ql, qr, mid + 1, high, 2 * pos + 2);
  return min(left, right);
}

// update the value : v[index]=num
void indexUpdateSegmentTree(vector<int> &segmentTree, int low, int high,
                            int index, int value, int pos) {
  if (low == high && low == index) {
    // update the segment tree
    segmentTree[pos] = value;
    return;
  }
  int mid = low + (high - low) / 2;

  if (index <= mid)
    indexUpdateSegmentTree(segmentTree, low, mid, index, value, 2 * pos + 1);
  else
    indexUpdateSegmentTree(segmentTree, mid + 1, high, index, value,
                           2 * pos + 2);

  // update the segment tree
  segmentTree[pos] = min(segmentTree[2 * pos + 1], segmentTree[2 * pos + 2]);
}

void rangeUpdateSegmentTree(vector<int> &segmentTree, int low, int high, int ql,
                            int qr, int value, int pos) {
  if (low == high && (low >= ql && low <= qr)) {
    segmentTree[pos] = value;
    return;
  }

  // if tree segment completely outside the query parameter
  if (high < ql || low > qr)
    return;
  // if tree segment completely lies inside the query parameter ,recur for the
  // left and right child
  int mid = low + (high - low) / 2;
  if (low >= ql && high <= qr) {
    // recur for both left and right segments
    rangeUpdateSegmentTree(segmentTree, low, mid, ql, qr, value, 2 * pos + 1);
    rangeUpdateSegmentTree(segmentTree, mid + 1, high, ql, qr, value,
                           2 * pos + 2);
  }

  // if tree segment partially overlaps with the query segment,
  // check overlap and iterate over only the complete overlap
  // max of the left range and min of the right range
  int left = max(ql, low), right = min(qr, high);
  // recur for the left and right segments which have complete overlap
  rangeUpdateSegmentTree(segmentTree, left, mid, ql, qr, value, 2 * pos + 1);
  rangeUpdateSegmentTree(segmentTree, mid + 1, right, ql, qr, value,
                         2 * pos + 2);

  // update the segment tree
  segmentTree[pos] = min(segmentTree[2 * pos + 1], segmentTree[2 * pos + 2]);
}

int main() {

  init();
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  // constructing the segment tree
  int len = findSize(n);
  // return large number for range min query
  vector<int> segmentTree(len, INT_MAX);

  constructSegmentTree(segmentTree, v, 0, n - 1, 0);

  // doing range query
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    int res = rangeMinQuery(segmentTree, l, r, 0, n - 1, 0);
    cout << res << "\n";
  }

  // these are the index update query
  int iu;
  cin >> iu;
  for (int i = 0; i < iu; i++) {
    int num, pos;
    cin >> num >> pos;
    // updating the array
    v[pos] = num;
    // update the  segment tree
    indexUpdateSegmentTree(segmentTree, 0, n - 1, pos, num, 0);
  }

  // range update query
  int ru;
  cin >> ru;
  for (int i = 0; i < ru; i++) {
    int rl, rr, num;
    cin >> rl >> rr >> num;
    // updating the array
    for (int j = rl; j <= rr; j++)
      v[j] = num;
    // updating the segment tree
    rangeUpdateSegmentTree(segmentTree, 0, n - 1, rl, rr, num, 0);
  }

  return 0;
}