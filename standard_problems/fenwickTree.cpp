//
// Created by Archit Singh on 16/05/21.
//

#include <bits/stdc++.h>
using namespace std;

int findNext(int n) { return n + (n & -n); }

int findParent(int n) { return n - (n & -n); }

// exactly same as construct fenwick tree
void updateFenwickTree(vector<int> &fenwickTree, int value, int index) {
  int n = fenwickTree.size();
  if (index >= n)
    return;
  fenwickTree[index] += value;
  int pos = findNext(index);
  updateFenwickTree(fenwickTree, value, pos);
}

void constructFenwickTree(vector<int> &fenwickTree, int value, int index) {
  int n = fenwickTree.size();
  if (index >= n)
    return;
  fenwickTree[index] += value;
  // find next position
  int pos = findNext(index);
  constructFenwickTree(fenwickTree, value, pos);
}

void findSum(vector<int> &fenwickTree, int index, int &sum) {
  if (index <= 0)
    return;
  sum += fenwickTree[index];
  int pos = findParent(index);
  findSum(fenwickTree, pos, sum);
}

void init() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}

int main() {

  init();
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  vector<int> fenwickTree(n + 1, 0);

  // construct the fenwick tree
  for (int i = 1; i < n + 1; i++) {
    // fenwicktree : value : start index
    constructFenwickTree(fenwickTree, v[i - 1], i);
  }

  // print the contents of the fenwick tree
  for (int i = 0; i < n + 1; i++)
    cout << fenwickTree[i] << "\n";

  // prefix sum queries
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int index;
    cin >> index;
    // find the sum from 0 to index
    int res = 0;
    findSum(fenwickTree, index + 1, res);
    cout << res << "\n";
  }

  return 0;
}
