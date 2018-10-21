#include <stdio.h>

int main()
{
    int a, b, c, d;
    for(a = 20; a>=4; a--){
        for(b = a-1; b>=3; b--){
            for(c = b-1; c>=2; c--){
                for(d = c-1; d>=1; d--){
                    if(1.0/a+1.0/b+1.0/c+1.0/d == 1.0){
                        printf("%d %d %d %d 0\n", a, b, c, d);
                    }
                }
            }
        }
    }
    //printf("Hello world\n");
    return 0;
}

