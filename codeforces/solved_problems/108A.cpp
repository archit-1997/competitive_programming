/*Tattah is asleep if and only if Tattah is attending a lecture. This is a well-known formula among Tattah's colleagues.

On a Wednesday afternoon, Tattah was attending Professor HH's lecture. At 12:21, right before falling asleep, he was staring at the digital watch around Saher's wrist. He noticed that the digits on the clock were the same when read from both directions i.e. a palindrome.

In his sleep, he started dreaming about such rare moments of the day when the time displayed on a digital clock is a palindrome. As soon as he woke up, he felt destined to write a program that finds the next such moment.

However, he still hasn't mastered the skill of programming while sleeping, so your task is to help him.
Input

The first and only line of the input starts with a string with the format "HH:MM" where "HH" is from "00" to "23" and "MM" is from "00" to "59". Both "HH" and "MM" have exactly two digits.
Output

Print the palindromic time of day that comes soonest after the time given in the input. If the input time is palindromic, output the soonest palindromic time after the input time.
Examples
Input
Copy

12:21

Output
Copy

13:31

Input
Copy

23:59

Output
Copy

00:00
*/

#include <iostream>
using namespace std;
int main()
{int h,m;
 char c;cin>>h>>c>>m;

while (1>0)
  { m++;
    h+=(m/60);
    m%=60;
    h%=24;
    if (h/10==m%10 && h%10==m/10) break;
  }
 cout<<h/10<<h%10<<":"<<m/10<<m%10;
 return 0;
}
