/*Today in the scientific lyceum of the Kingdom of Kremland, there was a biology lesson. The topic of the lesson was the genomes. Let's call the genome the string "ACTG".

Maxim was very boring to sit in class, so the teacher came up with a task for him: on a given string 𝑠
consisting of uppercase letters and length of at least 4, you need to find the minimum number of operations that you need to apply, so that the genome appears in it as a substring. For one operation, you can replace any letter in the string 𝑠

with the next or previous in the alphabet. For example, for the letter "D" the previous one will be "C", and the next — "E". In this problem, we assume that for the letter "A", the previous one will be the letter "Z", and the next one will be "B", and for the letter "Z", the previous one is the letter "Y", and the next one is the letter "A".

Help Maxim solve the problem that the teacher gave him.

A string 𝑎
is a substring of a string 𝑏 if 𝑎 can be obtained from 𝑏

by deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.
Input

The first line contains a single integer 𝑛
(4≤𝑛≤50) — the length of the string 𝑠

.

The second line contains the string 𝑠
, consisting of exactly 𝑛

uppercase letters of the Latin alphabet.
Output

Output the minimum number of operations that need to be applied to the string 𝑠

so that the genome appears as a substring in it.
Examples
Input
Copy

4
ZCTH

Output
Copy

2

Input
Copy

5
ZDATG

Output
Copy

5

Input
Copy

6
AFBAKC

Output
Copy

16

Note

In the first example, you should replace the letter "Z" with "A" for one operation, the letter "H" — with the letter "G" for one operation. You will get the string "ACTG", in which the genome is present as a substring.

In the second example, we replace the letter "A" with "C" for two operations, the letter "D" — with the letter "A" for three operations. You will get the string "ZACTG", in which there is a genome.
*/

#include<bits/stdc++.h>
using namespace std;

int f(int a)
{
	a=abs(a);
	return min(a,26-a);
}

int main()
{
	int n,i,temp=0,ans=999999;
	string s;
	cin>>n;
	cin>>s;
	for(i=0;i<n-3;i++)
	{
		temp=0;
		temp+=f(s[i]-'A');
		temp+=f(s[i+1]-'C');
		temp+=f(s[i+2]-'T');
		temp+=f(s[i+3]-'G');
		ans=min(ans,temp);
	}
	cout<<ans<<endl;
	return 0;
}
