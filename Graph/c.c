#include <stdio.h>

main()
{
    char str[] = "foryoureyesonly";
    int i;
    char *p;
    int n = strlen(str);

    for (p=str,i=0;p+i<=str+n;p++,i++){
        printf ("%c", *(p+1));
    }
    printf("\n");
}
