#include<stdio.h>

int main()
{
    int x, y;
    while(~scanf("%d%d", &x, &y)){
        int i = 0;
        for(i = 1; i<=120; i ++){
            if(i%2){
                y -= x;
            }
            if(i%6 == 0){
                x *= 2;
            }
            if(i%4 == 0){
                y *= 2;
            }
        }
        printf("%d\n", y);
    }
    return 0;
}
