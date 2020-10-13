/*In Summer Informatics School, if a student doesn't behave well, teachers make a hole in his badge. And today one of the teachers caught a group of 𝑛

students doing yet another trick.

Let's assume that all these students are numbered from 1
to 𝑛. The teacher came to student 𝑎 and put a hole in his badge. The student, however, claimed that the main culprit is some other student 𝑝𝑎

.

After that, the teacher came to student 𝑝𝑎
and made a hole in his badge as well. The student in reply said that the main culprit was student 𝑝𝑝𝑎

.

This process went on for a while, but, since the number of students was finite, eventually the teacher came to the student, who already had a hole in his badge.

After that, the teacher put a second hole in the student's badge and decided that he is done with this process, and went to the sauna.

You don't know the first student who was caught by the teacher. However, you know all the numbers 𝑝𝑖
. Your task is to find out for every student 𝑎, who would be the student with two holes in the badge if the first caught student was 𝑎

.
Input

The first line of the input contains the only integer 𝑛
(1≤𝑛≤1000

) — the number of the naughty students.

The second line contains 𝑛
integers 𝑝1, ..., 𝑝𝑛 (1≤𝑝𝑖≤𝑛), where 𝑝𝑖 indicates the student who was reported to the teacher by student 𝑖

.
Output

For every student 𝑎
from 1 to 𝑛 print which student would receive two holes in the badge, if 𝑎

was the first student caught by the teacher.
Examples
Input
Copy

3
2 3 2

Output
Copy

2 2 3 

Input
Copy

3
1 2 3

Output
Copy

1 2 3 
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;   cin>>n;
    vector<vector<ll>> v(n+1);
    
    for(ll i=1;i<=n;i++)
    {
        ll num; cin>>num;
        v[i].push_back(num);
    }
    
    for(ll i=1;i<=n;i++)
    {
        stack<ll> s;
        vector<bool> vis(n+1,false);
        s.push(i);
        vis[i]=true;
        while(!s.empty())
        {
            ll t=s.top();
            s.pop();
            for(ll i=0;i<v[t].size();i++)
            {
                if(vis[v[t][i]]==false)
                {
                    s.push(v[t][i]);
                    vis[v[t][i]]=true;
                }
                else
                {
                    cout<<v[t][i]<<" ";
                    break;
                }
            }
        }
    }
    
    return 0;
}
