/*Translator's note: in Russia's most widespread grading system, there are four grades: 5, 4, 3, 2, the higher the better, roughly corresponding to A, B, C and F respectively in American grading system.

The term is coming to an end and students start thinking about their grades. Today, a professor told his students that the grades for his course would be given out automatically  — he would calculate the simple average (arithmetic mean) of all grades given out for lab works this term and round to the nearest integer. The rounding would be done in favour of the student — 4.5
would be rounded up to 5 (as in example 3), but 4.4 would be rounded down to 4

.

This does not bode well for Vasya who didn't think those lab works would influence anything, so he may receive a grade worse than 5
(maybe even the dreaded 2). However, the professor allowed him to redo some of his works of Vasya's choosing to increase his average grade. Vasya wants to redo as as few lab works as possible in order to get 5 for the course. Of course, Vasya will get 5

for the lab works he chooses to redo.

Help Vasya — calculate the minimum amount of lab works Vasya has to redo.
Input

The first line contains a single integer 𝑛
 — the number of Vasya's grades (1≤𝑛≤100

).

The second line contains 𝑛
integers from 2 to 5

 — Vasya's grades for his lab works.
Output

Output a single integer — the minimum amount of lab works that Vasya has to redo. It can be shown that Vasya can always redo enough lab works to get a 5

.
Examples
Input
Copy

3
4 4 4

Output
Copy

2

Input
Copy

4
5 4 5 5

Output
Copy

0

Input
Copy

4
5 3 3 5

Output
Copy

1

Note

In the first sample, it is enough to redo two lab works to make two 4
s into 5

s.

In the second sample, Vasya's average is already 4.75
so he doesn't have to redo anything to get a 5

.

In the second sample Vasya has to redo one lab work to get rid of one of the 3
s, that will make the average exactly 4.5 so the final grade would be 5

.
*/

//Chochu Singh
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

bool check(int sum, int n) {
	// integer representation of sum / n >= 4.5
	return sum * 10 >= n * 45;
}


int main()
{
	//Fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n,sum=0;	cin>>n;
	vector<ll> v;
	
	for(ll i=0;i<n;i++)
	{
		ll num;	cin>>num;
		sum+=num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	int ans = 0;
	while (!check(sum, n)) {
		sum += 5 - v[ans];
		ans++;
	}
	cout << ans;
	
	return 0;
}
