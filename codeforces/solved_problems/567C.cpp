/*Polycarp loves geometric progressions very much. Since he was only three years old, he loves only the progressions of length three. He also has a favorite integer k and a sequence a, consisting of n integers.

He wants to know how many subsequences of length three can be selected from a, so that they form a geometric progression with common ratio k.

A subsequence of length three is a combination of three such indexes i1, i2, i3, that 1 ≤ i1 < i2 < i3 ≤ n. That is, a subsequence of length three are such groups of three elements that are not necessarily consecutive in the sequence, but their indexes are strictly increasing.

A geometric progression with common ratio k is a sequence of numbers of the form b·k0, b·k1, ..., b·kr - 1.

Polycarp is only three years old, so he can not calculate this number himself. Help him to do it.
Input

The first line of the input contains two integers, n and k (1 ≤ n, k ≤ 2·105), showing how many numbers Polycarp's sequence has and his favorite number.

The second line contains n integers a1, a2, ..., an ( - 109 ≤ ai ≤ 109) — elements of the sequence.
Output

Output a single number — the number of ways to choose a subsequence of length three, such that it forms a geometric progression with a common ratio k.
Examples
Input
Copy

5 2
1 1 2 2 4

Output
Copy

4

Input
Copy

3 1
1 1 1

Output
Copy

1

Input
Copy

10 3
1 2 6 2 3 6 9 18 3 9

Output
Copy

6

Note

In the first sample test the answer is four, as any of the two 1s can be chosen as the first element, the second element can be any of the 2s, and the third element of the subsequence must be equal to 4.
*/

#include <iostream>
#include<map>
using namespace std;
long long n,ans,k,a,b,i;
map <long long, long long> m,m1;
int main (){
cin>>n>>k;
for(i=0;i<n;i++){
cin>>a;
if(a%k==0) {ans=ans+m[a/k]; m[a]=m[a]+m1[a/k];}
m1[a]++;
}
cout<<ans;
}
