/*Nauuo is a girl who loves playing cards.

One day she was playing cards but found that the cards were mixed with some empty ones.

There are 𝑛
cards numbered from 1 to 𝑛, and they were mixed with another 𝑛 empty cards. She piled up the 2𝑛 cards and drew 𝑛 of them. The 𝑛 cards in Nauuo's hands are given. The remaining 𝑛

cards in the pile are also given in the order from top to bottom.

In one operation she can choose a card in her hands and play it — put it at the bottom of the pile, then draw the top card from the pile.

Nauuo wants to make the 𝑛
numbered cards piled up in increasing order (the 𝑖-th card in the pile from top to bottom is the card 𝑖

) as quickly as possible. Can you tell her the minimum number of operations?
Input

The first line contains a single integer 𝑛
(1≤𝑛≤2⋅105

) — the number of numbered cards.

The second line contains 𝑛
integers 𝑎1,𝑎2,…,𝑎𝑛 (0≤𝑎𝑖≤𝑛) — the initial cards in Nauuo's hands. 0

represents an empty card.

The third line contains 𝑛
integers 𝑏1,𝑏2,…,𝑏𝑛 (0≤𝑏𝑖≤𝑛) — the initial cards in the pile, given in order from top to bottom. 0

represents an empty card.

It is guaranteed that each number from 1
to 𝑛 appears exactly once, either in 𝑎1..𝑛 or 𝑏1..𝑛

.
Output

The output contains a single integer — the minimum number of operations to make the 𝑛

numbered cards piled up in increasing order.
Examples
Input
Copy

3
0 2 0
3 0 1

Output
Copy

2

Input
Copy

3
0 2 0
1 0 3

Output
Copy

4

Input
Copy

11
0 0 0 5 0 0 0 4 0 0 11
9 2 6 0 8 1 7 0 3 0 10

Output
Copy

18

Note

Example 1

We can play the card 2
and draw the card 3 in the first operation. After that, we have [0,3,0] in hands and the cards in the pile are [0,1,2]

from top to bottom.

Then, we play the card 3
in the second operation. The cards in the pile are [1,2,3]

, in which the cards are piled up in increasing order.

Example 2

Play an empty card and draw the card 1
, then play 1, 2, 3 in order.
*/


#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 200010;

int n, a[N], b[N], p[N], ans;

int main()
{
    int i, j;

    scanf("%d", &n);

    for (i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        p[a[i]] = 0;
    }

    for (i = 1; i <= n; ++i)
    {
        scanf("%d", b + i);
        p[b[i]] = i;
    }

    if (p[1])
    {
        for (i = 2; p[i] == p[1] + i - 1; ++i);
        if (p[i - 1] == n)
        {
            for (j = i; j <= n && p[j] <= j - i; ++j);
            if (j > n)
            {
                printf("%d", n - i + 1);
                return 0;
            }
        }
    }

    for (i = 1; i <= n; ++i) ans = max(ans, p[i] - i + 1 + n);

    printf("%d", ans);

    return 0;
}
