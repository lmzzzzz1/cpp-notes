#include <stdio.h>
#include <time.h>

extern unsigned int rand0();
extern void srand0(unsigned int);

int main(){
    int cnt;
    unsigned t = time(0);

    srand0(t);
    for(cnt=0;cnt<5;cnt++){

        printf("%d\n",rand0());
    }
    return 0;
}