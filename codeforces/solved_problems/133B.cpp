/*Unary is a minimalistic Brainfuck dialect in which programs are written using only one token.

Brainfuck programs use 8 commands: "+", "-", "[", "]", "<", ">", "." and "," (their meaning is not important for the purposes of this problem). Unary programs are created from Brainfuck programs using the following algorithm. First, replace each command with a corresponding binary code, using the following conversion table:

    ">"  →  1000,
    "<"  →  1001,
    "+"  →  1010,
    "-"  →  1011,
    "."  →  1100,
    ","  →  1101,
    "["  →  1110,
    "]"  →  1111. 

Next, concatenate the resulting binary codes into one binary number in the same order as in the program. Finally, write this number using unary numeral system — this is the Unary program equivalent to the original Brainfuck one.

You are given a Brainfuck program. Your task is to calculate the size of the equivalent Unary program, and print it modulo 1000003 (106 + 3).
Input

The input will consist of a single line p which gives a Brainfuck program. String p will contain between 1 and 100 characters, inclusive. Each character of p will be "+", "-", "[", "]", "<", ">", "." or ",".
Output

Output the size of the equivalent Unary program modulo 1000003 (106 + 3).
Examples
Input
Copy

,.

Output
Copy

220

Input
Copy

++++[>,.<-]

Output
Copy

61425

Note

To write a number n in unary numeral system, one simply has to write 1 n times. For example, 5 written in unary system will be 11111.

In the first example replacing Brainfuck commands with binary code will give us 1101 1100. After we concatenate the codes, we'll get 11011100 in binary system, or 220 in decimal. That's exactly the number of tokens in the equivalent Unary program.
*/

#include <cstdio>

int main()
{
    char p[101];
    scanf("%s", p);
    int size(0);
    for (size_t i = 0; p[i] != 0; ++i)
    {
        size *= 16;
        switch (p[i])
        {
        case '>':
            size += 8;
            break;

        case '<':
            size += 9;
            break;

        case '+':
            size += 10;
            break;

        case '-':
            size += 11;
            break;

        case '.':
            size += 12;
            break;

        case ',':
            size += 13;
            break;

        case '[':
            size += 14;
            break;

        case ']':
            size += 15;
            break;

        default:
            break;
        }

        size %= 1000003;
    }
    printf("%d\n", size);
    return 0;
}
