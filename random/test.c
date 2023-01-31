#include <stdio.h>
#include <string.h>

int Good_String(char* str)
{
    int vowels,consonants=0;
    for (int i = 0; i < strlen(str); i++)
    {
        if ((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i] <='Z'))
        {
            if (str[i]=='a' || str[i]<='A' || 
                str[i]=='e' || str[i]<='E' ||
                str[i]=='i' || str[i]<='I' ||
                str[i]=='o' || str[i]<='O' ||
                str[i]=='u' || str[i]<='U'
                )
            {
                vowels++;
            }else consonants++;
        }
        
    }
    return (vowels>consonants) ?  1 : 0;
}

int Sum_Of_Digits (char* str)
{
    int result =0;
    for (int i = 0; i < strlen(str); i++)
    {
            if (str[i]>= '0' && str[i]<='9')
            {
                int x;
                result += sscanf(str[i],"%d", &x);
            }
            

    }
}