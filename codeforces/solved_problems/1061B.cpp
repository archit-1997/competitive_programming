/*You came to the exhibition and one exhibit has drawn your attention. It consists of 𝑛 stacks of blocks, where the 𝑖-th stack consists of 𝑎𝑖

blocks resting on the surface.

The height of the exhibit is equal to 𝑚
. Consequently, the number of blocks in each stack is less than or equal to 𝑚

.

There is a camera on the ceiling that sees the top view of the blocks and a camera on the right wall that sees the side view of the blocks.

Find the maximum number of blocks you can remove such that the views for both the cameras would not change.

Note, that while originally all blocks are stacked on the floor, it is not required for them to stay connected to the floor after some blocks are removed. There is no gravity in the whole exhibition, so no block would fall down, even if the block underneath is removed. It is not allowed to move blocks by hand either.
Input

The first line contains two integers 𝑛
and 𝑚 (1≤𝑛≤100000, 1≤𝑚≤109

) — the number of stacks and the height of the exhibit.

The second line contains 𝑛
integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤𝑚

) — the number of blocks in each stack from left to right.
Output

Print exactly one integer — the maximum number of blocks that can be removed.
Examples
Input
Copy

5 6
3 3 3 3 3

Output
Copy

10

Input
Copy

3 5
1 2 4

Output
Copy

3

Input
Copy

5 5
2 3 1 4 4

Output
Copy

9

Input
Copy

1 1000
548

Output
Copy

0

Input
Copy

3 3
3 1 1

Output
Copy

1
*/

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m, reqd=0, total=0, ans=0;
int a[N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		total+=a[i];
	}
	sort(a+1, a+n+1);
	reqd=0;
	int prev=0;
	for(int i=1;i<=n;i++)
	{
		reqd+=1;
		if(a[i]>prev)
			prev++;
	}
	reqd+=(a[n]-prev);
	ans=total-reqd;
	cout<<ans;
	return 0;
}
