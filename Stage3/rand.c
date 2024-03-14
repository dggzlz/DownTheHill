#include <stdio.h>

unsigned int rand();
void srand(unsigned int x);


unsigned int rseed = 0;
#define RAND_MAX 0xA
void srand(unsigned int x){
    rseed = x;
}


unsigned int rand(unsigned int x)
{   
    rseed = (rseed * 1103515245 + 12345);
    return rseed % (RAND_MAX + 1);
}

int main(){
    
    int i, n;
    printf("select a number: ");
    scanf("%d", &n);
    srand(n);

    for (i=0; i < 11; i++)
        printf("%d\n",rand(n));
    return 0;
}

/*https://rosettacode.org/wiki/Linear_congruential_generator#C*/