#include <stdio.h>
#define MAXS 15

void StringCount( char s[] );
void ReadString( char s[] ); /* 由裁判实现，略去不表 */

int main()
{
    char s[MAXS];

    ReadString(s);
    StringCount(s);

    return 0;
}

/* Your function will be put here */

void StringCount(char s[])
{
    int letter_count = 0,blank_count = 0,digit_count = 0,other_count = 0;
    
    //’0‘是字符串结束的标志
    for(int i = 0;s[i] != '\0';i++)
    {
        if(s[i] == ' ' || s[i] == '\n')
            blank_count++;
        else if(s[i] <= '9' && s[i] >= '0')
            digit_count++;
        else if((s[i] <= 'z' && s[i] >= 'a') || (s[i] <= 'Z' && s[i] >= 'A'))
            letter_count++;
        else
            other_count++;   
    }
    printf("letter = %d, blank = %d, digit = %d, other = %d",letter_count,blank_count,digit_count,other_count);
}