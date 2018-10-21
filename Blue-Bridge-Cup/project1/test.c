#include<stdio.h>

int main()
{
    int x, y, z;
    int flag = 0;
    for(x = 1; x < 100; x ++){
        for(y = 1; y < 100; y ++){
            for(z = 1; z < 100; z ++){
                if((18*x == 15*y) && (15*y == 20*z)){
                    if((x+5*y+10*z)%100 == 0){
                        printf("%d %d %d %d\n", x, y, z, (x+5*y+10*z)/10);
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag){
                break;
            }
        }
        if(flag){
            break;
        }
    }
    return 0;
}
