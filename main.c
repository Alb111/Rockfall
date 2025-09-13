#include <stdio.h>
#include <unistd.h>
int main()
{
    printf("loading\n"); 
    printf("loading\n"); 
    fflush(stdout);
    printf("\033[2A");
    sleep(1);
    printf("\rdone loading\n"); 
    fflush(stdout);
    return 0;
}
