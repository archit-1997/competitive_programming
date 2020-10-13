/*Recently Monocarp got a job. His working day lasts exactly 𝑚 minutes. During work, Monocarp wants to drink coffee at certain moments: there are 𝑛 minutes 𝑎1,𝑎2,…,𝑎𝑛

, when he is able and willing to take a coffee break (for the sake of simplicity let's consider that each coffee break lasts exactly one minute).

However, Monocarp's boss doesn't like when Monocarp takes his coffee breaks too often. So for the given coffee break that is going to be on minute 𝑎𝑖
, Monocarp must choose the day in which he will drink coffee during the said minute, so that every day at least 𝑑 minutes pass between any two coffee breaks. Monocarp also wants to take these 𝑛 coffee breaks in a minimum possible number of working days (he doesn't count days when he is not at work, and he doesn't take coffee breaks on such days). Take into account that more than 𝑑

minutes pass between the end of any working day and the start of the following working day.

For each of the 𝑛

given minutes determine the day, during which Monocarp should take a coffee break in this minute. You have to minimize the number of days spent.
Input

The first line contains three integers 𝑛
, 𝑚, 𝑑 (1≤𝑛≤2⋅105,𝑛≤𝑚≤109,1≤𝑑≤𝑚)

 — the number of coffee breaks Monocarp wants to have, the length of each working day, and the minimum number of minutes between any two consecutive coffee breaks.

The second line contains 𝑛
distinct integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤𝑚), where 𝑎𝑖

is some minute when Monocarp wants to have a coffee break.
Output

In the first line, write the minimum number of days required to make a coffee break in each of the 𝑛

given minutes.

In the second line, print 𝑛
space separated integers. The 𝑖-th of integers should be the index of the day during which Monocarp should have a coffee break at minute 𝑎𝑖. Days are numbered from 1

. If there are multiple optimal solutions, you may print any of them.
Examples
Input
Copy

4 5 3
3 5 1 2

Output
Copy

3
3 1 1 2 

Input
Copy

10 10 1
10 5 7 4 6 3 2 1 9 8

Output
Copy

2
2 1 1 2 2 1 2 1 1 2 

Note

In the first example, Monocarp can take two coffee breaks during the first day (during minutes 1
and 5, 3 minutes will pass between these breaks). One break during the second day (at minute 2), and one break during the third day (at minute 3

).

In the second example, Monocarp can determine the day of the break as follows: if the minute when he wants to take a break is odd, then this break is on the first day, if it is even, then this break is on the second day.
*/

#include <bits/stdc++.h>

using namespace std;
int ans;
long long a,b;
void foo(int v){
int x=0,y=0;
while(a%v==0) a/=v,x++;
while(b%v==0) b/=v,y++;
ans+=abs(x-y);
}
int main()
{
cin>>a>>b;
foo(2);
foo(3);
foo(5);
cout<<(a==b ? ans:-1);
}
