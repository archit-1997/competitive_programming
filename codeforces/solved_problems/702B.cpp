/*You are given n integers a1, a2, ..., an. Find the number of pairs of indexes i, j (i < j) that ai + aj is a power of 2 (i. e. some integer x exists so that ai + aj = 2x).
Input

The first line contains the single positive integer n (1 ≤ n ≤ 105) — the number of integers.

The second line contains n positive integers a1, a2, ..., an (1 ≤ ai ≤ 109).
Output

Print the number of pairs of indexes i, j (i < j) that ai + aj is a power of 2.
Examples
Input
Copy

4
7 3 2 1

Output
Copy

2

Input
Copy

3
1 1 1

Output
Copy

3

Note

In the first example the following pairs of indexes include in answer: (1, 4) and (2, 4).

In the second example all pairs of indexes (i, j) (where i < j) include in answer.
*/


#include<bits/stdc++.h>
using namespace std;
map<int,int>m;
long long ans=0;
int main(){
	int n,a;
	cin>>n;
	while(n--){
		cin>>a;
		for(int i=0;i<=31;i++)	ans+=m[(1LL<<i)-a];
		m[a]++;
	}
	cout<<ans;
}
