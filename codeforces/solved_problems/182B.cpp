/*Vasya lives in a strange world. The year has n months and the i-th month has ai days. Vasya got a New Year present — the clock that shows not only the time, but also the date.

The clock's face can display any number from 1 to d. It is guaranteed that ai ≤ d for all i from 1 to n. The clock does not keep information about the current month, so when a new day comes, it simply increases the current day number by one. The clock cannot display number d + 1, so after day number d it shows day 1 (the current day counter resets). The mechanism of the clock allows you to increase the day number by one manually. When you execute this operation, day d is also followed by day 1.

Vasya begins each day checking the day number on the clock. If the day number on the clock does not match the actual day number in the current month, then Vasya manually increases it by one. Vasya is persistent and repeats this operation until the day number on the clock matches the actual number of the current day in the current month.

A year passed and Vasya wonders how many times he manually increased the day number by one, from the first day of the first month to the last day of the n-th month inclusive, considering that on the first day of the first month the clock display showed day 1.
Input

The first line contains the single number d — the maximum number of the day that Vasya's clock can show (1 ≤ d ≤ 106).

The second line contains a single integer n — the number of months in the year (1 ≤ n ≤ 2000).

The third line contains n space-separated integers: ai (1 ≤ ai ≤ d) — the number of days in each month in the order in which they follow, starting from the first one.
Output

Print a single number — the number of times Vasya manually increased the day number by one throughout the last year.
Examples
Input
Copy

4
2
2 2

Output
Copy

2

Input
Copy

5
3
3 4 3

Output
Copy

3

Input
Copy

31
12
31 28 31 30 31 30 31 31 30 31 30 31

Output
Copy

7

Note

In the first sample the situation is like this:

    Day 1. Month 1. The clock shows 1. Vasya changes nothing.
    Day 2. Month 1. The clock shows 2. Vasya changes nothing.
    Day 1. Month 2. The clock shows 3. Vasya manually increases the day number by 1. After that the clock shows 4. Vasya increases the day number by 1 manually. After that the clock shows 1.
    Day 2. Month 2. The clock shows 2. Vasya changes nothing. 

In total, Vasya manually changed the day number by 1 exactly 2 times.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll d;   cin>>d;
    ll n;   cin>>n;
    vector<ll> v;

    for(ll i=0;i<n;i++)
    {
        ll num;cin>>num;
        v.push_back(num);
    }
    
    ll ans=0;
    
    for(ll i=0;i<n-1;i++)
    {
        ans+=(d-v[i]);
    }
    
    cout<<ans<<endl;
    
    return 0;
}
