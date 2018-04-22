#include <stdio.h>
#include <time.h>

void printlocaltime(void)
{
    struct tm *timeptr;
    time_t secsnow;

    time(&secsnow);
    timeptr = localtime(&secsnow);
    printf("The date is %d/%d/20%d\n",
           timeptr->tm_mon + 1,
           timeptr->tm_mday,
           timeptr->tm_year - 100); //year返回的是118,就是说是从1900年开始算的，因此这里减去100
    printf("The time is %02d:%02d:%02d\n",
           timeptr->tm_hour,
           timeptr->tm_min,
           timeptr->tm_sec);
}

int main()
{
    printlocaltime();
    return 0;
}