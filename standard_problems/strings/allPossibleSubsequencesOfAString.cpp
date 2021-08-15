#include <bits/stdc++.h>
using namespace std;

void init() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}

void findSubsequence(string s, string str, int index, vector<string> &ans) {
  // if we have reached end
  if (index == s.size()) {
    ans.push_back(str);
    return;
  }

  // recursive call with including this index
  findSubsequence(s, str + s[index], index + 1, ans);

  // without including the index
  findSubsequence(s, str, index + 1, ans);
}

int main() {

  init();

  string s;
  cin >> s;

  vector<string> ans;

  string str = "";
  findSubsequence(s, str, 0, ans);

  cout << "Number of subsequences : " << ans.size() << "\n1";

  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";

  return 0;
}
