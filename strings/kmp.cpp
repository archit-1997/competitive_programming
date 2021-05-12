// prefix array of the kmp algorithm
// this is O(n3) complexity

#include <bits/stdc++.h>
using namespace std;

int main() {

  string s;
  cin >> s;
  int n = s.size();

  vector<int> pi(n, 0);

  // we know that by definition, pi[0]=0;

  for (int i = 1; i < n; i++) {
    string str = s.substr(0, i + 1);
    // this string is of length i+1
    int len = i + 1;
    // j indicates the length of the substring
    for (int j = 1; j <= i + 1; j++) {
      string pre = str.substr(0, j);
      string suff = str.substr(len - j);
      if (pre == suff)
        pi[i] = len;
    }
  }

  for (int i = 0; i < n; i++)
    cout << pi[i] << " ";

  return 0;
}