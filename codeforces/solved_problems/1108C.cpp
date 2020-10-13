/*You have a garland consisting of 𝑛 lamps. Each lamp is colored red, green or blue. The color of the 𝑖-th lamp is 𝑠𝑖

('R', 'G' and 'B' — colors of lamps in the garland).

You have to recolor some lamps in this garland (recoloring a lamp means changing its initial color to another) in such a way that the obtained garland is nice.

A garland is called nice if any two lamps of the same color have distance divisible by three between them. I.e. if the obtained garland is 𝑡
, then for each 𝑖,𝑗 such that 𝑡𝑖=𝑡𝑗 should be satisfied |𝑖−𝑗| 𝑚𝑜𝑑 3=0. The value |𝑥| means absolute value of 𝑥, the operation 𝑥 𝑚𝑜𝑑 𝑦 means remainder of 𝑥 when divided by 𝑦

.

For example, the following garlands are nice: "RGBRGBRG", "GB", "R", "GRBGRBG", "BRGBRGB". The following garlands are not nice: "RR", "RGBG".

Among all ways to recolor the initial garland to make it nice you have to choose one with the minimum number of recolored lamps. If there are multiple optimal solutions, print any of them.
Input

The first line of the input contains one integer 𝑛
(1≤𝑛≤2⋅105

) — the number of lamps.

The second line of the input contains the string 𝑠
consisting of 𝑛

characters 'R', 'G' and 'B' — colors of lamps in the garland.
Output

In the first line of the output print one integer 𝑟

— the minimum number of recolors needed to obtain a nice garland from the given one.

In the second line of the output print one string 𝑡
of length 𝑛

— a nice garland obtained from the initial one with minimum number of recolors. If there are multiple optimal solutions, print any of them.
Examples
Input
Copy

3
BRB

Output
Copy

1
GRB

Input
Copy

7
RGBGRBB

Output
Copy

3
RGBRGBR

*/

#include<bits/stdc++.h>
using namespace std;
int main()
{ int n;
cin>>n;
string s;
cin>>s;     int min=INT_MAX; int t;   
string s1[]={"RGB","RBG","BGR","BRG","GRB","GBR"};
for(int j=0;j<6;++j)
{ int sum=0;
for(int i=0;i<n;++i)
{ if(s[i]!=s1[j][i%3])
   sum++;
	
	
}
if(sum<min)
{min=sum;t=j;
}
}
cout<<min<<endl;
for(int i=0;i<n;++i)
{ cout<<s1[t][i%3];
	
	
}}
