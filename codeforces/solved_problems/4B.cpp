/*Tomorrow Peter has a Biology exam. He does not like this subject much, but d days ago he learnt that he would have to take this exam. Peter's strict parents made him prepare for the exam immediately, for this purpose he has to study not less than minTimei and not more than maxTimei hours per each i-th day. Moreover, they warned Peter that a day before the exam they would check how he has followed their instructions.

So, today is the day when Peter's parents ask him to show the timetable of his preparatory studies. But the boy has counted only the sum of hours sumTime spent him on preparation, and now he wants to know if he can show his parents a timetable sсhedule with d numbers, where each number sсhedulei stands for the time in hours spent by Peter each i-th day on biology studies, and satisfying the limitations imposed by his parents, and at the same time the sum total of all schedulei should equal to sumTime.
Input

The first input line contains two integer numbers d, sumTime (1 ≤ d ≤ 30, 0 ≤ sumTime ≤ 240) — the amount of days, during which Peter studied, and the total amount of hours, spent on preparation. Each of the following d lines contains two integer numbers minTimei, maxTimei (0 ≤ minTimei ≤ maxTimei ≤ 8), separated by a space — minimum and maximum amount of hours that Peter could spent in the i-th day.
Output

In the first line print YES, and in the second line print d numbers (separated by a space), each of the numbers — amount of hours, spent by Peter on preparation in the corresponding day, if he followed his parents' instructions; or print NO in the unique line. If there are many solutions, print any of them.
Examples
Input
Copy

1 48
5 7

Output
Copy

NO

Input
Copy

2 5
0 1
3 5

Output
Copy

YES
1 4 
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll d,st;    cin>>d>>st;
    ll max_t=0,min_t=0;
    
    ll v[d][2];
    for(ll i=0;i<d;i++)
    {
        ll a,b; cin>>a>>b;
        v[i][0]=a;
        v[i][1]=b;
        min_t+=a;
        max_t+=b;
    }
    
    //cout<<"HEY"<<endl;
    
    
    if(max_t<st || min_t>st)
        cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        ll rem=st;
        ll time[d];
        for(ll i=0;i<d;i++)
        {
            time[i]=v[i][0];
            rem=rem-v[i][0];
        }
        //cout<<rem<<endl;
        /*for(ll i=0;i<d;i++)
            cout<<time[i]<<" ";
        cout<<endl;*/
            
        ll i=0;
        
        while(1)
        {
            if(rem==0)
                break;
            ll dif=v[i][1]-v[i][0];//bacha hua hai
            //cout<<"i "<<i<<" dif "<<dif<<endl;
            if(rem>=dif)
            {
                time[i]=time[i]+dif;
                rem=rem-dif;
            }
            else
            {
                time[i]+=rem;
                rem=0;
            }
            
            i++;
            if(i==d)
                break;
        }
        for(ll i=0;i<d;i++)
            cout<<time[i]<<" ";
        cout<<endl;
    }
    
    
    
    return 0;
}
