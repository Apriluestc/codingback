1.请写出 : bool, float, *p 与零值比较的 if 语句
	bool flag : if(flag)	if(!flag)
	float x : const float EXP = 0.0000001 ;if((x >= -EXP) && (x <= EXP))
	int *p : if(p == NULL)	if(p != NULL)
2. win32 和 linux 下 : sizeof()	的计算
	见课本;
3.用变量 a 给出下面的定义
	a.一个有10个指针的数组，该指针是指向一个整型数的;
	b.一个指向有10个整型数数组的指针;
	c.一个指向函数的指针，该函数有一个整型参数并返回一个整型数;
	d.一个有10个指针的数组，该指针指向一个函数，该函数有一个整型参数并返回一个整型数;
	int *  a[10];
	int (*a)[10]                                 
	int (*a)(int);
	int (*a[10])(int)
4.结构体.联合.位段.内存大小的计算
	struct A
	{
		int a;
		char b;
		float c;
		struct A d;
		double e;
	};	sizeof(A)
5.代码改错
	涉及到动态内存开辟:
	wap( int* p1,int* p2 )
	{
	int * p;
	*p = *p1;
	*p1 = *p2;
	*p2 = *p;
	}
	p 为野指针（指向一个已删除的对象或未申请访问受限内存区域的指针）
	void swap(int *pa, int *pb)
	{
		int tmp;
		tmp = *pa;
		*pa = *pb;
		*pb = tmp;
	}

	
6.C 和 C++ 的 struct 有什么不同
	c和c++ 中struct的主要区别是c中的struct不可以含有成员函数,而c++ 中的struct可以.
	c++ 中struct和class的主要区别在于默认的存取权限不同，struct默认为public ，而class默认为private
7.会出现什么错误;什么原因?
	char str[10];strcpy(str, "0123456789");
8.数组和链表的区别:
	数组:数据顺序存储，固定大小;
	链表:数据可以随机存储，大小可动态改变;
9.会出现什么问题？打印结果是是多少？
	void main()
	{
		char aa[10];
		printf(“%d”,strlen(aa));
	}
	sizeof()和初不初始化，没有关系,
	strlen()和初始化有关，打印结果值未知.
10.的结果是否相同？其中ptr为同一个指针.
	(void *)ptr 和(*(void**))ptr
	(void *)ptr 和(*(void**))ptr 值是相同的
11.要对绝对地址0x100000赋值，我们可以用
	(unsigned int*)0x100000 = 1234;那么要是想让程序跳转到绝对地址是0x100000去执行,应该怎么做？
	*((void (*)( ))0x100000 ) ( );
	首先要将0x100000强制转换成函数指针,即:
	(void (*)())0x100000
	然后再调用它:
	*((void (*)())0x100000)();
12.关键字 volatile 有什么含意? 并给出三个不同的例子。
	一个定义为volatile的变量是说这变量可能会被意想不到地改变，这样，编译器就不会去假设
	这个变量的值了。精确地说就是，优化器在用到这个变量时必须每次都小心地重新读取这个变量的值,
	而不是使用保存在寄存器里的备份。下面是volatile变量的几个例子：
	1). 并行设备的硬件寄存器（如：状态寄存器）
	2). 一个中断服务子程序中会访问到的非自动变量(Non-automatic variables)
	3). 多线程应用中被几个任务共享的变量
13.头文件中的ifndef/define/endif 干什么用？
	防止该头文件被重复引用:
14.#include  <filename.h>    和#include  “filename.h” 有什么区别？
	对于#include  <filename.h>   ，编译器从标准库路径开始搜索filename.h ;                                
	对于#include  “filename.h” ，编译器从用户的工作路径开始搜索filename.h 。
15.const   有什么用途？（请至少说明两种）
	（1）可以定义const   常量
	（2）const  可以修饰函数的参数、返回值，甚至函数的定义体。被const  修饰的东西都受到强制保护，可
	以预防意外的变动，能提高程序的健壮性。
16.static有什么用途？（请至少说明两种）
	1.限制变量的作用域（static全局变量）；
	2.设置变量的存储域（static局部变量）.
17.如何引用一个已经定义过的全局变量？
	可以用引用头文件的方式，也可以用 extern 关键字，如果用引用头文件方式来引用某个在
	头文件中声明的全局变理，假定你将那个变量写错了,那么在编译期间会报错，如果你用extern 方式引用
	时，假定你犯了同样的错误，那么在编译期间不会报错，而在连接期间报错。
18.全局变量可不可以定义在可被多个.C 文件包含的头文件中？为什么？
	可以，在不同的C 文件中以static形式来声明同名全局变量。可以在不同的C文件中声明同名的全
	局变量，前提是其中只能有一个C文件中对此变量赋初值，此时连接不会出错
19.栈和队列有什么区别
	队列先进先出，栈后进先出
20.Heap与stack的差别
	Heap是堆，stack是栈。
	Stack的空间由操作系统自动分配/释放，Heap上的空间手动分配/释放。
	Stack空间有限，Heap是很大的自由存储区C 中的malloc 函数分配的内存空间即在堆上,C++中对
	应的是new 操作符。程序在编译期对变量和函数分配内存都在栈上进行,且程序运行过程中函数调用时参数的传递也在栈上进行
21.用宏定义写出swap（x，y），即交换两数
	#define swap(x, y) (x)=(x)+(y);(y)=(x)–(y);(x)=(x)–(y);
22.写一个“标准”宏，这个宏输入两个参数并返回较小的一个。
	#define Min(X, Y) ((X)>(Y)?(Y):(X))
23.带参宏与带参函数的区别(至少说出5点)？
	|	  带参宏	|                带参函数				|
	|    处理时间   |      编译时       |        运行时		|
	|	 参数类型   |        无         | 					|
    |     需定义	|					|					|
	|    程序长度   |       变长        |					|
    |      不变		|					|					|
	|  占用存储空间 |        否         |          是		|
	|    运行时间   |    不占运行时间   |   调用和返回时占	|
24. main() 中，c标准认为0表示成功，非0表示错误。具体的值是某中具体出错信息
25.已知一个数组tabl e ，用一个宏定义，求出数据的元素个数。
	#define NTBL(table) (sizeof(table)/sizeof(table[0]))
26.A.c 和B.c两个c文件中使用了两个相同名字的static变量,编译的时候会不会有问题?这两个static变量会保存到哪里（栈还是堆或者其他的）?
	static的全局变量，表明这个变量仅在本模块中有意义，不会影响其他模块。
	他们都放在静态数据区，但是编译器对他们的命名是不同的。如果要使变量在其他模块也有意义的话，需要使用extern 关键字。
27.static全局变量与普通的全局变量有什么区别？
	static全局变量只初使化一次，防止在其他文件单元中被引用;
28.static局部变量和普通局部变量有什么区别
	static局部变量只被初始化一次，下一次依据上一次结果值；
29.static函数与普通函数有什么区别？
	static函数在内存中只有一份，普通函数在每个被调用中维持一份拷贝
30.static 参考文章:
	全局变量(外部变量)的说明之前再冠以static 就构成了静态的全局变量。全局变量本身就是静态存储方式，静态全局变量当然也是静态存储方
	式。这两者在存储方式上并无不同。这两者的区别虽在于非静态全局变量的作用域是整个源程序，当一个源程序由多个源文件组成时，非静态
	的全局变量在各个源文件中都是有效的。而静态全局变量则限制了其作用域，即只在定义该变量的源文件内有效，在同一源程序的其它源文
	件中不能使用它。由于静态全局变量的作用域局限于一个源文件内，只能为该源文件内的函数公用，因此可以避免在其它源文件中引起错误。
	从以上分析可以看出，把局部变量改变为静态变量后是改变了它的存储方式即改变了它的生存期。把全局变量改变为静态变量后是改变了它的
	作用域，限制了它的使用范围。static函数与普通函数作用域不同。仅在本文件。只在当前源文件中使用的函数应该说明为内部函数(static)，
	内部函数应该在当前源文件中说明和定义。对于可在当前源文件以外使用的函数，应该在一个头文件中说明，要使用这些函数的源文件要包含这个头文件
31.程序的局部变量存在于栈(stack) 中，全局变量存在于静态数据区中，动态申请数据存在于堆（heap）中。
32.程序的预处理,预编译,连接,汇编等
	:见课本;
33.用两个栈实现一个队列的功能？要求给出算法和思路！
	设2个栈为A,B, 一开始均为空.入队:
	将新元素push入栈A;
	出队:
	(1)判断栈B 是否为空；
	(2)如果不为空，则将栈A中所有元素依次pop 出并push到栈B；
	(3)将栈B 的栈顶元素pop 出；
34.对一个频繁使用的短小函数 C语言用什么实现
:	c用宏定义，c++ 用inline
35.1. 用预处理指令#define  声明一个常数，用以表明1年中有多少秒（忽略闰年问题）
	#define SECONDS_PER_YEAR (60 * 60 * 24 * 365)UL
36.在C++  程序中调用被C 编译器编译后的函数，
为什么要加extern “C”？
	C++ 语言支持函数重载，C 语言不支持函数重载。函数被C++ 编译后在库中的名字与 C 语言的
	不同。假设某个函数的原型为：void foo(int x, int y); 该函数被C 编译器编译后在库中的名字为_foo ，而
	C++ 编译器则会产生像_foo_int_int之类的名字。 C++提供了C 连接交换指定符号extern“C”来解决名字匹配问题。
37.以下是求一个数的平方的程序,请找出错误:
	#define SQUARE(a)((a)*(a))
	int a=5;
	int b;
	b=SQUARE(a++);
	宏在预编译时会以替换的形式展开，仅仅会替换。涉及到宏的地方，不要用++-- ，标准中对此
	没有规定，因此最终结果将会依赖于不同的编译器。执行程序的答案可能是25、也有可能是36。
38.编写strcpy 函数
	已知strcpy 函数的原型是 char *strcpy(char *strDest, const char *strSrc);其中strDest是目的字符串，strSrc 是源字符串。
	不调用C++/C 的字符串库函数，请编写函数strcpy 。
	strcpy 能把 strSrc 的内容复制到strDest，为什么还要char *  类型的返回值？
39.写出二分查找的代码。
int b inary_search(int* arr, int k ey, int n){
	int low =  0;int h igh = n - 1 ;int mid;
	while (low <= high){
		mid = (high + low) / 2;
		if (arr[mid] > k) high = mid -1 ;
		else if (arr[mid] < k) low = mid + 1;
		else return mid;
	}
	return -1;
}
40.请编写一个C 函数，该函数给出一个字节中被置1  的位的个数。
unsigned int T estAsOne0(char log) { 
	int i; unsigned int num=0, val; 
	for(i=0; i<8; i++) { 
		va l =  log >>  i;  // 移位
		val & = 0x01;  // 与1 相与
		if(val) num++; 
	} 
	return num; 
} 
41.请编写一个C 函数，该函数将给定的一个字符串转换成整数。
int Invert(char* str) { 
	int num =0; 
	while(*str!='\0') { 
		int d igital=*str-48; num=num*10+digital; str=str+1; 
	} 
	return num; 
} 
42.请编写一个C 函数，该函数将给定的一个整数转换成字符串。
void IntToCharChange(int num,  char* pval) { 
	char strval[100]; int i , j; int val0 = 0; int val1 = 0; val0 = num; 
	for(i=0; i<100; i++) { 
	val1 = val0 % 10; //取余
	val0 = val0 / 10; // 取整
	strval[i] = val1 + 48;  // 数字—字符
		if(val0 < 10) { i++; strval[i] = val0 + 48; break; 
		} 
	} 
	for(j=0; j<=i; j++)  // 倒置
		pval[j] = strval[i-j]; pval[j] = '\0'; 
}
43.实现strcmp 函数。
int m ystrcmp(const c har* str1, const char* str2){
	assert((str1 != NULL) && (str2 != NULL));int r et = 0;
	while (!(ret = *(unsigned char*)str1 - * (unsigned char*)str2) && *str2){str1++;str2++;}
	if (ret > 0)ret = 1;
	else if (ret < 0)ret = -1;
	return ret;
}
44.请编写一个C 函数，该函数将一个字符串逆序。
void AntitoneValue(cha r* father, char* child) { 
	int i ; char source[100]; int j = 0; 
	while(father[j]) //放入source ，[j] 为长度
	{ source[j] = father[j]; j++; 
		if(j > 99) return; 
	} 
	source[j] = '\0'; 
	for(i=0; i<j; i++) 
		child[i] = source[j-i-1];  // 反序
	child[i] = '\0'; 
} 
45.请编写一个C 函数，该函数在给定的内存区域搜索给定的字符，并返回该字符所在位置索引值。
int s earch(char* cpSource, intn , char ch)  // 起始地址，搜索长度，目标字符
{
	int i;
	for(i=0; i<n && *(cpSource+i) != ch; ++i);return i;
}
46.请编写一个C 函数，该函数在一个字符串中找到可能的最长的子字符串，该字符串是由同一字符组成的
int C hildString(char*p)     // 自己写
{   char *q =p;int s tringlen=0, i=0,j=1,len=0,maxlen=1;   
	while(*q!=’\0’)          //不能用strlen, 求得长度stringlen
	{Stringlen++;q++;}
	while( i<  String len )    {   
		if(*(p+i)==*(p+j)& & j< St ri ngle n )   {   len++;                    // 统计子串长度
			i++;j++;   
		}   
		else   {   
			if(len>maxlen)           // 统计最大子串长度
			{   
				maxlen=len+1;   len=0;		}  
			else len=0;
			i++;j++;
		}   
	}  
	return   maxlen;    
}
47.华为面试题：怎么判断链表中是否有环？
	答：用两个指针来遍历这个单向链表，第一个指针p1，每次走一步；第二个指针p2，每次走两
	步；当p2 指针追上p1的时候，就表明链表当中有环路了。
int testLinkRing(Link *head){
	Link *t1=head,*t2=head;
	while( t1->next && t2->next){
		t1 = t1->next;
		if (NULL == (t2 = t2->next->next))
			return 0; // 无环
		if (t1 == t2)
			return 1;
	}
	return 0;
}
48.有一浮点型数组A, 用C 语言写一函数实现对浮点数组A进行降序排序,并输出结果,要求要以数组A 作为函数的入口.( 建议用冒泡排序法)
void BubbleSort(double a rr[], int n) { 
	int i，j ；
	int e xchange = 1 ；// 交换标志
	for(i=1;i<n;i++)
	{ // 最多做n-1趟排序
	exchange=0 ；// 本趟排序开始前，交换标志应为假
		for(j=n-1;j>=i ；j--) //对当前无序区R[i..n]自下向上扫描
			if(arr[j+1] > arr [ j])
			{// 交换记录
				arr[0]=arr[j+1]；//R[0]不是哨兵，仅做暂存单元
				arr[j+1]=arr[j]；
				arr[j]=arr[0]；
				exchange=1 ；// 发生了交换，故将交换标志置为真
			} 
			if(!exchange) // 本趟排序未发生交换，提前终止算法
				return ；
	} //endfor(外循环) 
}
49.实现双向链表删除一个节点P，在节点P 后插入一个节点，写出这两个函数。
// 删除操作
Status ListDelete_DuL(DuLinkList &L,inti,Ele mType &e){
	if(!(p=G e tElemP_DuL(L,i))) return ERROR;
	e=p->data;p->prior->next=p->next;p->next->prior=p->pror;free(p);
	return OK;
}
// 插入操作
Status ListInsert_DuL(DuLinkList &L,inti,ElemType &e){
	if(!(p=G e tElemP_DuL(L,i)))
		return ERROR;
	if(!(s=(DuLinkList)malloc(sizeof(DuLNode))))
		return ERROR;
	s->data=e;s->pri or =p;p-> next -> prior =s;p->next=s;s->next=p->next->next;
	return OK;
}
50.把一个链表反向。
从第一个元素开始，ps指向他，将他（ps）指向头节点(ps->next = head) ，将ps设为头节点
（head = ps; ）操作下一个元素（ps= pe->next;）等于是依次将每个元素翻到原头节点前面。
void reverse(test* head){
	test* pe = head;test* ps = head->next;
	while(ps)
	{ pe->next = ps->next;ps->next = head;head = ps;ps =  pe->next;	}
}
51.将二维数组行列元素互换，存到另一个数组中。
int main(){   
	int a [2][3]={{1,2,3},{4,5,6}};int b[3][2],i,j;printf("array a :\n");
	for(i=0;i<=1;i++){
		for(j=0;j<=2;j++){printf("%5d",a[i][j]);b[j][i]=a[i][j];}
		printf("\n");}    
	printf("array b :\n");
	for(i=0;i<=2;i++){
		for(j=0;j<=1;j++)
			printf("%5d",b[i][j]);
		printf("\n");
	}
}
52.输入一行字符，统计其中有多少个单词。
#include <stdio.h>
main()
{   
	char str i ng[81];int i,num=0,word=0;char c;gets(string);
	for(i=0;(c=string[i])!='\0';i++)
	if(c==' ')  
		word=0;
	else if(word==0){   word=1;  num++;   }
	printf("There are %d word s in the line\n",num);
}
53.写一个内存拷贝函数,不用任何库函数.就是前些时候本版讨论的那个问题。
void* memcpy(void* pvTo, const void* pvFrom, size_t size)
{
	assert((pvTo != NULL) && (pvFrom ! = NULL));
	byte* pbTo= pvTo;
	byte* pbFrom = pbFrom;
	while (size-- >  0)
	{
		*pbTo++ = *pbFrom++;
	}
	return pvTo;
}
54.有1、2、3 、4个数字，能组成多少个互不相同且无重复数字的三位数？
#inc lude  "stdio.h"
#include "conio.h"
main()
{
	int i,j,k;printf("\n");
	for(i=1;i<5;i++) /* 以下为三重循环*/
		for(j=1;j<5;j++)
			for (k=1;k<5;k++)
			{
				if (i!=k&&i!=j&&j!=k) /* 确保i、j、k三位互不相同*/
					printf("%d,%d,%d\n",i,j,k);
			}
			getch();
}
55.取一个整数a从右端开始的4～7位。
	main(){	unsigned a,b,c,d;scanf("%o",&a);b=a>>4;c=~(~0<<4);d=b&c;printf("%o\n%o\n",a,d);}
56.打印出杨辉三角形（要求打印出10行如下图）。
main(){int i,j;int a [10][10];printf("\n");
	for(i=0;i<10;i++){a[i][0]=1;a[i][i]=1;}
	for(i=2;i<10;i++)
		for(j=1;j<i;j++)
			a[i][j]=a[i-1][j-1]+a[i-1][j];
		for(i=0;i<10;i++)
		{
			for(j=0;j<=i;j++)
				printf("%5d",a[i][j]);
			printf("\n");
		}
		getch(); 
}
57.实现strcmp 函数。
58.实现strlen 函数.
59.809*??=800*??+9*??+1  其中??代表的两位数,8*?? 的结果为两位数，9*??的结果为3位数。求??代表的两位数，及809*??后的结果。
output(long b,long i){
	printf("\n%ld/%ld=809*%ld+%ld",b,i,i,b%i);
}
main(){
	long int a ,b,i;
	a=809;
	for(i=10;i<100;i++){
		b=i*a+1;
		if(b>=1000&&b<=10000&&8*i<100&&9*i>=100)
			output(b,i);
	}
	getch();
}
60.某个公司采用公用电话传递数据，数据是四位的整数，在传递过程中是加密的，加密规则如下：每位数字都加上5, 然后
用和除以10的余数代替该数字，再将第一位和第四位交换，第二位和第三位交换。
main(){
	int a ,i,aa[4],t;scanf( " % d " ,&a) ;aa[0]=a %10;aa[1]=a %100/10;aa[2]=a %1000/100;aa[3]=a /1000;
	for(i=0 ; i<=3 ;i++){aa [i]+=5;aa[i] %=10;}
	for(i=0;i<=3/2;i++){t=aa[i];aa[i]= aa[3- i];aa[3- i]= t ;}
	for(i=3;i>=0;i--)
		printf("% d ", a [i]);
	getch();
}
61.计算字符串中子串出现的次数。
main(){
	char str1[20],str2[20],*p1,*p2;
	int sum=0;
	printf("please input two strings\n");
	scanf("%s%s",str1,str2);
	p1=str1;p2=str2;
	while(*p1!='\0'){
		if(*p1==*p2){
			while(*p1==*p2&&*p2!='\0')
			{
				p1++;
				p2++;
			}
		}
		else
			p1++;
		if(*p2=='\0')
			sum++;
			p2=str2;
	}
	printf("%d",sum);
	getch();
} 
62.有两个磁盘文件A和B, 各存放一行字母，要求把这两个文件中的信息合并（按字母顺序排列），输出到一个新文件C 中。
main()
{
	FILE *fp;
	int i,j,n,ni;
	char c[160],t,ch;
	if((fp=fopen("A","r "))==NULL)
	{
		printf("file A cannot  be opened\n");exit(0);
	}
	printf("\nA contents are :\n");
	for(i=0;(ch=fgetc(fp))!=EOF ; i++)
	{
		c[i]=ch;pu tchar(c[i]);
	}
	fclose(fp);
	ni=i;
	if((fp=fopen("B","r "))==NULL)
	{
		printf("file B cannot  be opened\n");exit(0);
	}
	printf("\nB contents are :\n");
	for(i=0;(ch=fgetc(fp))!=EOF ; i++)
	{
		c[i]=ch;pu tchar(c[i]);
	}
	fclose(fp);
	n=i;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(c[i]>c[j]){t=c[i ];c[i]=c[j];c[j]=t;}
			printf("\nC file is:\n");
			fp =f open("C","w");
			for(i=0;i<n;i++){putc(c[i ],fp);putchar(c[i]);}
			fclose(fp);
			getch();
}