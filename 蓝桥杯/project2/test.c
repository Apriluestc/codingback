#include<stdio.h>

    int days1[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days2[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main(){
    int y, fd;
    while(~scanf("%d%d", &y, &fd)){
        if((y%4 == 0) && (y%100 != 0) || (y%400 == 0)){
            int i = 0;
            for(i = 1; i <= 12; i ++){
                int sum = 0;
                int j = 0;
                for(j = 1; j < i; j ++){
                    sum += days2[j];
                }
                sum += 12;
                if((sum + fd)%7 == 5){
                    printf("%d-%d-13\n", y, i);
                }
            }
        }
        else{
            int i = 0;
            for(i = 1; i <= 12; i ++){
                int sum = 0;
                int j = 0;
                for(j = 1; j < i; j ++){
                    sum += days1[j];
                }
                sum += 12;
                if((sum + fd)%7 == 5){
                    printf("%d-%d-13\n", y, i);
                }
            }
        }
    }
    return 0;
}
