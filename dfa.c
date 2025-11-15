#include<stdio.h>
#define max 100

int main()
{
    int i;
    char str[max],f='a';
    printf("Enter a string:");
    scanf("%s",str);

    for(i=0;str[i]!='\0';i++)
    {
        switch(f)
        {
            case 'a':
                if(str[i]=='0')
                {
                    f='b';
                }
                else
                {
                    f='a';
                }
                break;
            
            case 'b':
                if(str[i]=='0')
                {
                    f='b';
                }
                else
                {
                    f='c';
                }
                break;
            case 'c':
                if(str[i]=='0')
                {
                    f='b';
                }
                else
                {
                    f='a';
                }
                break;
            default:
                printf("Invalid Input");
                break;

        }
    }

    //print
    if(f=='c')
    {
        printf("String %s is accepted",str);
    }
    else{
        printf("String %s is not accepted",str);
    }
}