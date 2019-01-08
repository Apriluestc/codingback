#include <stdio.h>

void shuffle(int cards[], int n){
    if(cards == NULL){
        return;
    } 
    srand(time(0));
    for(int i = 0; i<n - 1; ++i){
        //保证每次第 i 位的值不会涉及到第 i 位以前   
        int index = i + rand() % (n - i);   
        int temp = cards[i];   
        cards[i] = cards[index];   
        cards[index] = temp;   
    } 
}


int main()
{

    //printf("Hello world\n");
    return 0;
}

