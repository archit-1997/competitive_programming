/*High school student Vasya got a string of length n as a birthday present. This string consists of letters 'a' and 'b' only. Vasya denotes beauty of the string as the maximum length of a substring (consecutive subsequence) consisting of equal letters.

Vasya can change no more than k characters of the original string. What is the maximum beauty of the string he can achieve?
Input

The first line of the input contains two integers n and k (1 ≤ n ≤ 100 000, 0 ≤ k ≤ n) — the length of the string and the maximum number of characters to change.

The second line contains the string, consisting of letters 'a' and 'b' only.
Output

Print the only integer — the maximum beauty of the string Vasya can achieve by changing no more than k characters.
Examples
Input
Copy

4 2
abba

Output
Copy

4

Input
Copy

8 1
aabaabaa

Output
Copy

5

Note

In the first sample, Vasya can obtain both strings "aaaa" and "bbbb".

In the second sample, the optimal answer is obtained with the string "aaaaabaa" or with the string "aabaaaaa".
*/

#include<bits/stdc++.h>
using namespace std;
map<char,int>m;
int main()
{
	int n,k;
	string str;
	cin>>n>>k>>str;
	int left=0,ans=0,i=0;
	for(i=0;i<n;i++)
	{
		m[str[i]]++;
		if(min(m['a'],m['b'])>k)
		{
			m[str[left]]--;
			left++;
		}
		else
		ans++;
	}
	cout<<ans<<endl;
}
