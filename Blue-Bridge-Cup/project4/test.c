#define true 1
#define false 0
//#include<iostream>
#include<stdio.h>
#include<string.h>
//using namespace std;

char a[5][5];
char s1[25], s2[25];
int l;
int judge(char ch){
    int sum = 0;
    int i = 0;
    for(i = 0; i<1; i ++){
        if(ch != s1[i]){
            sum ++;
        }
    }
    if(sum == 1){
        return true;
    }
    return false;
}
int judge2(char ch){
    int sum = 0;
    int i = 0;
    for(i = 0; i<5; i ++){
        int j = 0;
        for(j = 0; j<5; j ++){
            if(a[i][j] != ch){
                sum ++;
            }
        }
    }
    if(sum == 25){
        return true;
    }
    return false;
}
int posi(char ch, int &x, int &y){
    int i = 0;
    for(i = 0; i<5; i ++){
        int j = 0;
        for(j = 0; j<5; j ++){
            if(a[i][j] == ch){
                x = i;
                y = j;
            }
        }
    }
}
int posijudge(char c1, char c2){
    int x1, x2, y1, y2;
    posi(c1, x1, y1);
    posi(c2, x2, y2);
    if(x1 == x2 || y1 == y2){
        return true;
    }
    return false;
}
int main(){
    scanf("%s%s", s1, s2);
    l = strlen(s1);
    int pos = 0;
    char ch = 'a';
    int i = 0;
    for(i = 0; i<5; i++){
        int j = 0;
        for(j = 0; j<5; j ++){
            if(s1[pos] != '\0'){
                a[i][j] = s1[pos];
                pos ++;
            }
            else{
                while(!judge(ch)){
                    ch ++;
                }
            }
        }
    }
    int n = strlen(s2);
    char t1, t2;
    char ans[25];
    //int i = 0;
    for(i = 0; i<n; i += 2){
        t1 = s2[i];
        t2 = s2[i+1];
        if(t1 == t2 || t2 == '\0'){
            ans[i] = t1;
            ans[i+1] = t2;
        }
        else if(posijudge(t1, t2)){
            ans[i] = t2;
            ans[i+1] = t1;
        }
        else{
            int x1, x2, y1, y2;
            posi(t1, x1, y1);
            posi(t2, x2, y2);
            ans[i] = a[x1][y2];
            ans[i+1] = a[x2][y1];
        }
    }
    printf("%s\n", ans);
    return 0;
}
