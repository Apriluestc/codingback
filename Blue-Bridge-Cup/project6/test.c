#include <stdio.h>

int main()
{
    int a, b, c, d, e, f;
    for(a = 1; a<10; a++){
        for(b = 0; b<10; b++){
            if(a == b){
                continue;
            }
            for(c = 0; c<10; c++){
                if(c == a || c == b){
                    continue;
                }
                for(d = 0; d<10; d++){
                    if(d == a || d == b || d == c){
                        continue;
                    }
                    for(e = 0; e<10; e++){
                        if(e == a || e == b || e == c || e == d){
                            continue;
                        }
                        for(f = 0; f<10; f++){
                            if(f == a || f == b || f == c || f == d || f == f){
                                continue;
                            }
                            if((a*10000+b*1000+c*100+d*10+e)*f == (e*10000+d*1000+c*100+b*10+a)){
                                printf("%d %d %d %d %d\n", a , b, c, d, e);
                            }
                        }
                    }
                }
            }
        }
    }
    //printf("Hello world\n");
    return 0;
}

