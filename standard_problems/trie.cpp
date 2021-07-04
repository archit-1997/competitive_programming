/*
 * @author      : archit1997
 * @created     : Wednesday May 12, 2021 09:45:52 IST
 * @problem     : Trie Implementation : insertion , deletion and searching of
 * strings
 */

// NOTE : This code only searches, inserts and deletes strings into the dictionary
//  Prefix operation hasn't been implemented yet

#include <bits/stdc++.h>
using namespace std;

// assumption: only small letters of the english alphabet
#define max_size 26

void init() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}

struct Trie {
  // array of pointers of type Trie
  Trie *child[max_size];
  bool leaf;
};

// create node : returns a pointer to a structure of type Trie
Trie *createNode() {
  Trie *newNode = new Trie();
  // marking the pointers at each alphabet as NULL
  for (int i = 0; i < max_size; i++)
    newNode->child[i] = NULL;
  newNode->leaf = false;
  return newNode;
}

void insert(Trie *root, string s) {
  int n = s.size();
  Trie *cur = root;
  for (int i = 0; i < n; i++) {
    int index = s[i] - 'a';
    // if this character was already present at the position in the dictionary
    if (cur->child[index] == NULL)
      cur->child[index] = createNode();
    cur = cur->child[index];
  }
  // marking as end of word
  cur->leaf = true;
}

// searching for the current string
bool search(Trie *root, string s) {
  int n = s.size();
  Trie *cur = root;
  for (int i = 0; i < n; i++) {
    int index = s[i] - 'a';
    if (cur->child[index] == NULL)
      return false;
    cur = cur->child[index];
  }
  // node should not be null and should be a leaf node as well
  if (cur != NULL && cur->leaf == true)
    return true;
  return false;
}

bool isEmpty(Trie *root) {
  for (int i = 0; i < 26; i++) {
    if (root->leaf == true)
      return false;
  }
  return true;
}

Trie *deleteNode(Trie *root, string s, int depth) {
  Trie *cur = root;
  if (cur == NULL)
    return root;
  // if this is the last character of the string
  if (depth == s.size()) {
    if (cur->leaf == true)
      cur->leaf = false;
    // check if the current node does not have any further branching
    if (isEmpty(cur)) {
      delete (cur);
      cur = NULL;
    }
    return cur;
  }

  // in case this is not the last character
  int index = s[depth] - 'a';
  cur->child[index] = deleteNode(cur->child[index], s, depth + 1);
  // if root does not have any child and is also not the end of any word
  if (isEmpty(cur) && cur->leaf == false) {
    delete (cur);
    cur = NULL;
  }
  return cur;
}

void solve() {

  int n;
  cin >> n;
  // we will polulate these strings in a trie named dictionary
  // create a new trie node for the dictionary
  Trie *root = createNode();
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    // insert into the dictionary
    insert(root, s);
  }
  // going to search for m words in the dictionary
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    bool res = search(root, s);
    if (res)
      cout << "Found";
    else
      cout << "Not Found";
    cout << "\n";
  }

  // delete p words from the dictionary
  int p;
  cin >> p;
  for (int i = 0; i < p; i++) {
    string s;
    cin >> s;
    // only possible if this is found in the dictionary
    if (search(root, s)) {
      // passing the third paramter as the depth of the string
      deleteNode(root, s, 0);
      cout << "Successfully deleted";
    } else
      cout << "Not found in the dictionary";
    cout << "\n";
  }
}

int main() {

  init();

  solve();

  return 0;
}