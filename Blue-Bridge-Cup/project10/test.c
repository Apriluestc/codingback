一、刷题
1、在西方，星期五和数字13都代表着坏运气，两个不幸的个体最后结合成超级不幸的一天。所以，不管哪个月的十三日又恰逢星期五就叫“黑色星期五”，
要求：输入年份，输出是：判断该年是否包含黑色星期五，给出具体日期；
输入
1998 4
输出
1998-2-13
1998-3-13
1998-11-13
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>  
int days1[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};  
int days2[13]= {0,31,29,31,30,31,30,31,31,30,31,30,31};  
int main()  
{  
    int y,fd;  
    while(~scanf("%d%d",&y,&fd))  
    {  
        if((y%4==0)&&(y%100!=0)||(y%400==0))  
        {  
            for(int i=1; i<=12; i++)  
            {  
                int sum=0;  
                for(int j=1; j<i; j++)  
                {  
                    sum+=days2[j];  
                }  
                sum+=12;//注意是加12不是13  
                if((sum+fd)%7==5)  
                    printf("%d-%d-13\n",y,i);  
            }  
        }  
        else  
        {  
            for(int i=1; i<=12; i++)  
            {  
                int sum=0;  
                for(int j=1; j<i; j++)  
                {  
                    sum+=days1[j];  
                }  
                sum+=12;  
                if((sum+fd)%7==5)  
                    printf("%d-%d-13\n",y,i);  
            }  
        }  
    }  
    return 0;  
}  


