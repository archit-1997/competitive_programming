/*Heidi's friend Jenny is asking Heidi to deliver an important letter to one of their common friends. Since Jenny is Irish, Heidi thinks that this might be a prank. More precisely, she suspects that the message she is asked to deliver states: "Send the fool further!", and upon reading it the recipient will ask Heidi to deliver the same message to yet another friend (that the recipient has in common with Heidi), and so on.

Heidi believes that her friends want to avoid awkward situations, so she will not be made to visit the same person (including Jenny) twice. She also knows how much it costs to travel between any two of her friends who know each other. She wants to know: what is the maximal amount of money she will waste on travel if it really is a prank?

Heidi's n friends are labeled 0 through n - 1, and their network of connections forms a tree. In other words, every two of her friends a, b know each other, possibly indirectly (there is a sequence of friends starting from a and ending on b and such that each two consecutive friends in the sequence know each other directly), and there are exactly n - 1 pairs of friends who know each other directly.

Jenny is given the number 0.
Input

The first line of the input contains the number of friends n (3 ≤ n ≤ 100). The next n - 1 lines each contain three space-separated integers u, v and c (0 ≤ u, v ≤ n - 1, 1 ≤ c ≤ 104), meaning that u and v are friends (know each other directly) and the cost for travelling between u and v is c.

It is guaranteed that the social network of the input forms a tree.
Output

Output a single integer – the maximum sum of costs.
Examples
Input
Copy

4
0 1 4
0 2 2
2 3 3

Output
Copy

5

Input
Copy

6
1 2 3
0 2 100
1 4 2
0 3 7
3 5 10

Output
Copy

105

Input
Copy

11
1 0 1664
2 0 881
3 2 4670
4 2 1555
5 1 1870
6 2 1265
7 2 288
8 7 2266
9 2 1536
10 6 3378

Output
Copy

5551

Note

In the second example, the worst-case scenario goes like this: Jenny sends Heidi to the friend labeled by number 2 (incurring a cost of 100), then friend 2 sends her to friend 1 (costing Heidi 3), and finally friend 1 relays her to friend 4 (incurring an additional cost of 2).
*/

#include<bits/stdc++.h>
using namespace std;
int res,n;
vector < pair <int, int>> e[105];
void dfs(int u,int d,int par)
{
  res=max(res,d);
  for(auto p : e[u])
  {
    if(p.first==par) continue;
    dfs(p.first,d+p.second,u);
  }
}
int main()
{
  int a,b,c;
  cin>>n;
  for(int i=0;i<n-1;++i)
  {
    cin>>a>>b>>c;
    e[a].push_back({b,c});
    e[b].push_back({a,c});
  }
  dfs(0,0,-1);
  cout<<res<<endl;
  return 0;
}
