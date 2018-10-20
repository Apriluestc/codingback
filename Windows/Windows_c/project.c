#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>

int a[10];
int main(){
	int mark = 10;
	for (a[1] = 0; a[1] <= 1; a[1]++){
		for (a[2] = 0; a[2] <= 1; a[2]++){
			for (a[3] = 0; a[3] <= 1; a[3]++){
				for (a[4] = 0; a[4] <= 1; a[4]++){
					for (a[5] = 0; a[5] <= 1; a[5]++){
						for (a[6] = 0; a[6] <= 1; a[6]++){
							for (a[7] = 0; a[7] <= 1; a[7]++){
								for (a[8] = 0; a[8] <= 1; a[8]++){
									for (a[9] = 0; a[9] <= 1; a[9]++){
										//for (a[10] = 0; a[10] <= 1; a[10]++){
											int i = 0;
											for (i = 0; i <= 10; i++){
												//int mark = 10;
												if (a[i] == 0){
													mark -= i;
												}
												else{
													mark *= 2;
												}
											//}
											if (mark == 100){
												int i = 0;
												for (i = 0; i <= 10; i++){
													printf("%d ", a[i]);
												}
												printf("\n");
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}
								