#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
 
struct node{
   int num;
   char name[20];
 
   struct node* next;  //指向下一个地址的指针
};  //声明一个链表,此时内存不分配内存
 
typedef struct node Node; //重命名,便于书写,太长了struct node 
typedef struct node* Link;
//构造函数,实现传过来的头指针指向一个空的内容
void creat_node(Link *head); //形参为二级指针,操作的对象是指针变量的指针,这个概念我之前纠结了很久,很容易混.就单纯的理解为对变量的值进行操作,这个变量是指针{*head = NULL; //*head是指针的内容}
//头插,链表中节点的插入方式
void insert_head(Link *head,Link p); //函数操作的形参是头指针和新指针的地址,需要改变头指针的指向,所以调用的是二级指针{Link a;a = *head; if(a == NULL){a = p;p -> next = NULL;}else{p -> next = *head;// *head -> next = NULL;这句被注释掉了,这个是我当时犯的错,这样操作会使链表丢失*head = p;}}
//尾插
void insert_tail(Link *head,Link p) //原理同头插,尾插时注意新节点的next指针要指向NULL,在链表中循环时注意循环结束条件和循环体执行的操作
{
	Link a;
	a = *head;
 
	if( *head == NULL ) //头指针指向空时,没有节点
	{
		*head = p;
		p -> next = NULL;
	}
	else
	{
	//	*head -> next = p; 这句犯错同上,链表会断掉
	    while(a -> next != NULL) //这个循环,是在链表中找到它的最后一位,把新节点连接上去
		{
			a = a -> next;
		}
	    a -> next = p;
	    p -> next = NULL;
    }
 
}
 
//释放链表指针的空间
void release_node(Link head) //释放空间不需要头指针的移动,形参调用head的一级指针,传head的指向地址,头指针的内容改变时,头指针的指向改变,效果就是头指针的移动
{
	Link p;  //定义一个指针,指向head,实现对链表的操作
	p = head;
 
	while(p != NULL)
	{
		free(p); //释放指针变量p指向的空间
		p = p -> next;   // p为变量,更新了p的值,效果是指针变量p现在指向p的下一个节点
	}
}
 
//打印链表中的内容
void display_node(Link head)  //对链表的操作,不需要移动head的位置,形参取head的一级指针
{
	Link a; //定义一个新指针变量a,指向head的位置
	a = head;
 
	while(a != NULL)  //打印节点内容,指针变量a指向下一个节点,实现后移的循环,直到a指向一个NULL
	{
		printf("num = %d name = %s\n",a -> num,a -> name);
		a = a -> next;
	}
}
 
//计算返回一个单向链表的长度
int length_node(Link head)  //对链表的操作,不需要移动head的位置,形参取head的一级指针
{
	Link p;
	int i = 0; //记录节点个数
	p = head;
 
	while(p != NULL)  //直到p指向的空间是NULL
	{
		i++;    //i+1技术
                p = p -> next;  //p指向下一个节点
	}
 
	return i; //返回值i是int的,要声明函数的返回值
}
 
//查找链表中指定节点的内容
void check_node(Link head,int k)  //对链表的操作,不需要移动head的位置,形参取head的一级指针,k为指定节点数
{
        Link p;
	p = head;
 
	if(p == NULL)
		printf("链表为空,无内容可查\n");
	else
	{
		while(p != NULL)  //找到链表中的指定节点打印出来
		{
			if(p -> num == k)
			{
				printf("name = %s\n",p -> name);
				break; //打印完成后要记得退出循环
			}
			else
				p = p -> next; //p指向p的后一位字节
		} 
	}
}
 
//删除指定节点
void delete_node(Link head,int x)  //对链表的操作,不需要移动head的位置,形参取head的一级指针,k为指定节点数
{
	Link p,q;
	p = head;
 
	if(head == NULL)
	{
    	printf("链表为空\n");
		return ;
	}
 
	if(head -> next == NULL)  //链表中只有一个节点
	{
	    if(p -> num == x)
          {
			  free(p);
			  p = NULL;
			  return;
		  }
		else
		{
			printf("没有该节点\n");
			return;
		}
	}
 
	while(p -> num != x) //找到指定节点删除
	{
		q = p; //记录当前p指向的位置,p满足循环条件时,q指向p的前一个节点地址
		p = p -> next;
	}
 
	q -> next = p -> next; 
	p -> next = NULL;     //断开p指向的字节在连边中的连接顺序
	free(p);    //释放空间
 
}
 
//中间插, 新节点插到任意位置
void add_node(Link *head,Link m,int y) //需要讨论head的指向,取二级指针,新节点的指针,插入节点的位置
{
	Link p,q;
	p = *head;
 
    	while(p -> num != (y - 1)) //指针p停在要插入位置的前一个节点
    	{
	    
	    	p = p -> next; 
    	}
 
     	q = p -> next;
	p -> next = m;
    	m -> next = q;
 
	m -> num = y;  //完成指针的指向操作
}
//指针num变量重赋值,
void replay_num(Link head)
{
	int i = 0;
	Link p;
	p = head;
    //int i = 0;
 
	while(p != NULL)
	{
		p -> num = i + 1;
		p = p -> next;
		i++;
	}
 
}
//Link creat_node(&head)
//{
//	
//}
 
//主函数
int main( )
{
	Link head = NULL;//head指向NULL 防止野指针
	Link p = NULL; //定义一个指针P指向NULL,防止野指针
	int k,x,y = 0,i = 0;
	Link m = NULL; //防止野指针
	//CreatNode(&head); //head指向一个空
	printf("请输入姓名:\n");
	for(i = 0;i < 3;i++)
	{
		p = (Link)malloc(sizeof(Node)); //malloc()函数分配Node大小的空间,类型转换为Link型,指赋给p
		
		if(p == NULL)//空间分配失败
		{
			printf("malloc error!\n");
			exit(-1);  //结束进程 文件包含stdlib.h
		}
 
		p -> num = i + 1;
		scanf("%s",p -> name);
 
	//	insert_head(&head,p); //头插
		insert_tail(&head,p); //尾插
	}
 
	display_node(head);
 
	printf("链表长度:%d\n",length_node(head));
 
	printf("请输入想要查询的节点:\n");
	scanf("%d",&k);
	check_node(head,k);
 
	printf("请输入想要删除的节点:\n");
	scanf("%d",&x);
	delete_node(head,x);
 
	display_node(head); 
 
	m = (Link)malloc(sizeof(Node)); //m指向一个新分配的空间
	printf("请输入想要插入的节点内容:\n");
	scanf("%s",m -> name);
	printf("请输入想要插入的节点位置:\n");
	scanf("%d",&y);
	add_node(&head,m,y);
 
	replay_num(head); //调用add_node()函数后把num的内容重新排序
 
    display_node(head);
 
 
	release_node(head); //释放函数要放在最后 所有操作结束后释放空间
    return 0;
}
