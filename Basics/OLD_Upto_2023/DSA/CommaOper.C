#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x = 20,y = 10,t;
    printf("%d %d\tSwaps -> ",x,y);
    y = t=x,x=y,t;
    printf("%d %d\n",x,y);
    
    x = 20,y = 10;
    printf("%d %d\tSwaps -> ",x,y);
    y = (t=x,x=y,t);
    printf("%d %d\n",x,y);

    x = 20,y = 10;
    printf("%d %d\tSwaps -> ",x,y);
    t=x,x=y,y=t;
    printf("%d %d\n",x,y);

    return 0;
}
