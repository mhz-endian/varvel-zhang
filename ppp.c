/**@pram......
   @author: H.Chang Ma
   @email: mhzever@live.com
   @Completion Time:2014/4/5
*/
#include<stdio.h>
#include<stdlib.h>
typedef int Status;
#define OK 1
#define ERROR 0
struct nodeN{
	int data[5];
	struct nodeN *next;
};
struct nodeL{
	int data[15];
	struct nodeL *next;
};
struct nodeF{
	int data[2][15];
	struct nodeF *next;
};
typedef struct nodeN *LinkListN;
typedef struct nodeL *LinkListL;
typedef struct nodeF *LinkListF;
int count_L=0,count_F=0,cou1=0,cou2=0;
Status LinkListL_Init(LinkListL *L)
{
	(*L) = (LinkListL)malloc(sizeof(struct nodeL));
	if(!(*L))
		return ERROR;
	(*L)->next=NULL;
	return OK;
}
Status LinkListF_Init(LinkListF *F)
{
	(*F) = (LinkListF)malloc(sizeof(struct nodeF));
	if(!(*F))
		return ERROR;
	(*F)->next=NULL;
	return OK;
}
Status LinkListN_Init(LinkListN *N)
{
	(*N) = (LinkListN)malloc(sizeof(struct nodeN));
	if(!(*N))
		return ERROR;
	(*N)->next=NULL;
	return OK;
}
/*
-------------- ------ 
| 0 | 1 | 2 | 3 | 4 | 
————————----- 
*/
void First_Step(int (*a)[2])//生成0，1或者2，3处可能的序列 
{
	int i,j=0,k;
	for(i=0;i<10;i++)
	{
		for(k=0;k<10;k++,j++)
		{
			if(i<k)
			{
				a[j][0]=i;
				a[j][1]=k;
			}
			else if(i>=k)
			{
				j--;
			}
		}
	}
}
void Print_First_Step(int (*a)[2])//打印a[45][2] 
{
	int i,j,cou=0;
	for(i=0;i<45;i++)
		{
			for(j=0;j<2;j++)
				{
					cou++;
					printf("%d ",a[i][j]);
				}
			printf("\n");
		}
		printf("%d\n",cou);	
}
//*********************///
void Second_Step(int (*a)[2],LinkListN *N)//确定可行的序列0，1，2，3，4 
{
	LinkListN p,temp;
	int i,j,k,flag,flag0;
	p=(*N);
	for(i=0;i<45;i++)
	{
		temp=(LinkListN)malloc(sizeof(struct nodeN));
		if(!temp)
		{
			printf("malloc temp ERROR,and located Second_Step()");
			return ;
		}
		flag=0;
		for(j=0;j<45;j++)
		{
			if(flag==1)
			{
				temp=(LinkListN)malloc(sizeof(struct nodeN));
				if(!temp)
				{
					printf("malloc temp ERROR,and located Second_Step()");
					return ;
				}
			}
			flag=0;
			temp->data[0]=a[i][0];
			temp->data[1]=a[i][1];
			if(a[j][0]>a[i][1])
			{
				flag++;
				temp->data[2]=a[j][0];
				temp->data[3]=a[j][1];
			}
			if(flag==1)
			{
				
				for(k=0;k<10;k++)
				{
					flag0=0;
					if(k>temp->data[3])
					{
						temp->data[4]=k;
						p->next=temp;
						p=temp;
						flag0++;
					}
					if(flag0==1)
					{
						temp=(LinkListN)malloc(sizeof(struct nodeN));
						if(!temp)
						{
							printf("malloc temp ERROR,and located Second_Step()");
							return ;
						}
						temp->data[0]=p->data[0];	
						temp->data[1]=p->data[1];
						temp->data[2]=p->data[2];
						temp->data[3]=p->data[3];	
					}
				}
			}
		}
		p->next=NULL;
	}
	p=(*N)->next;
/*	while(p)
	{
		
		int i,flag1=0;
		for(i=0;i<=9;i++)
		{
			if(i>p->data[3])
			{
				if(flag1==0)
				{
					p->data[4]=i;
				}
			}
		}
		p=p->next;
	}*/
}
void Traversal_N(LinkListN N)
{
	LinkListN p;
	int i;
	p=N->next;
	while(p)
	{
		for(i=0;i<5;i++)
		{
			printf("%d",p->data[i]);
		}
		printf("\n");
		p=p->next; 
	}
}
void Traversal_L(LinkListL L)
{
	LinkListL p;
	int i;
	p=L->next;
	while(p)
	{
		for(i=0;i<5;i++)
		{
			printf("%d  ",p->data[i]);
		}
		printf("    ");
		for(i=5;i<10;i++)
		{
			printf("%d  ",p->data[i]);
		}
		printf("    ");
		for(i=10;i<15;i++)
		{
			printf("%d  ",p->data[i]);
		}
		printf("\n");
		p=p->next; 
	}
}
void Traversal_F(LinkListF F)
{
	LinkListF p;
	int i,j;
	p=F->next;
	while(p)
	{
		for(j=0;j<2;j++)
		{
			
			for(i=0;i<5;i++)
			{
				printf("%d  ",p->data[j][i]);
			}
			printf("    ");
			for(i=5;i<10;i++)
			{
				printf("%d  ",p->data[j][i]);
			}
			printf("    ");
			for(i=10;i<15;i++)
			{
				printf("%d  ",p->data[j][i]);
			}
			printf("\n");
		} 
			printf("-------------------------------------------------------\n");
		p=p->next; 
	}
}
int LinkListN_Length(LinkListN N)//计算链表N长度 
{
	LinkListN n=N->next;
	int length=0;
	while(n)
	{
		length++;
		n=n->next;
	}
	return length;
}
int LinkListL_Length(LinkListL L)//计算链表L长度 
{
	LinkListL n=L->next;
	int length=0;
	while(n)
	{
		length++;
		n=n->next;
	}
	return length;
}
int LinkListF_Length(LinkListF F)//计算链表F长度 
{
	LinkListF n=F->next;
	int length=0;
	while(n)
	{
		length++;
		n=n->next;
	}
	return length;
}
void Free_N(LinkListN *N)//êí·?oó?ú??ó?μ?á′±í 
{
	LinkListN temp,p=(*N)->next;
	while(p)
	{
		temp=p;
		p=p->next; 
		free(temp);
	}
	(*N)->next=NULL; 
}
void Free_L(LinkListL *L)//êí·?oó?ú??ó?μ?á′±í 
{
	LinkListL temp,p=(*L)->next;
	while(p)
	{
		temp=p;
		p=p->next; 
		free(temp);
	}
	(*L)->next=NULL; 
}
void Free_F(LinkListF *F)//êí·?oó?ú??ó?μ?á′±í 
{
	LinkListF temp,p=(*F)->next;
	while(p)
	{
		temp=p;
		p=p->next; 
		free(temp);
	}
	(*F)->next=NULL; 
}
//////////////////////////
void Third_Step(int (*val)[3],int *length)//获取n个三位数 
{
       int i,j;
       FILE *fp;
       int input;
       printf("Keep documents need to be calculated in the Current Folder !\nMake sure filename is \"array\",and format is \".txt\"\n");
       printf("Please enter the number of the array to be calculated.\n(Recommended not more than 44)\nhuw many?:");
       scanf("%d",&input);
       if((fp=fopen(".\\array.txt","r"))==NULL)
       {
             printf("File open failed !\n");
             return;
       }
       for(i=0;i<input;i++)//读取
           for(j=0;j<3;j++)
              fscanf(fp,"%d",&val[i][j]);
       for(i=0;i<input;i++)//显示
        {
               for(j=0;j<3;j++)
                    printf("%d ",val[i][j]);
               printf("\n");
 
        }
       printf("\n");
       fclose(fp);
       *length=input;
}
void Forth_Step(LinkListN N,LinkListL *L,int (*val)[3],int length)
{
	LinkListN n1,n2,n3;
	LinkListL p,temp;
	n1=N->next;
	n2=N->next;
	n3=N->next;
	p=(*L);
	int i,j,k;
	int flag0,flag1,flag2,flag;
	double num=0,n=10;
	while(n1)
	{
		n2=N->next;
		num=num+0.390625;
		if((int)(num-n)==0)
		{
			n+=10;
			printf("Calculating of L,Waiting.....%.0lf%%\n",num+1);
		}
		if(num>90&&num<90.5)
		{
				printf("Calculating of L,Waiting.....100%%\n");
		}
		
		while(n2)
		{
			n3=N->next;
			while(n3)
			{
				flag=0;
				for(i=0;i<length;i++)
				{
					flag0=0,flag1=0,flag2=0;
					for(j=0;j<5;j++)
					{
						if(val[i][0]==n1->data[j])
						{
							flag0++;
						}
						if(val[i][1]==n2->data[j])
						{
							flag1++;
						}
						if(val[i][2]==n3->data[j])
						{
							flag2++;
						}
						
					}
					if((flag0==1&&flag1==1&&flag2==1)||(flag0==0&&flag1==0&&flag2==0))
				//	if(flag0==1&&flag1==1&&flag2==1)
					{
					//	do nothing 
					}
				//	if((flag0!=0&&flag1!=0)||(flag0!=0&&flag2!=0)||(flag1!=0&&flag2!=0))
					else
					{
						flag++;					
					}
				}
				if(flag==length)
				{
						temp=(LinkListL)malloc(sizeof(struct nodeL));
						if(!temp)
						{
							printf("malloc temp ERROR,and located Forth_Step()");
							return ;
						}
						for(k=0;k<5;k++)
						{
							temp->data[k]=n1->data[k];
							temp->data[k+5]=n2->data[k];
							temp->data[k+10]=n3->data[k];
							count_L++;
						}
						count_L=count_L-4;
						p->next=temp;
						p=temp;
				}
				n3=n3->next;
			}
			n2=n2->next;
		}
		n1=n1->next;
	} 
	p->next=NULL;
}
void Split_L(LinkListL L,LinkListL *L1,LinkListL *L2,LinkListL *L3,LinkListL *L4,LinkListL *L5,int length)
{
	int mid_one=length/5,mid_two=(length/5)*2,\
	mid_three=(length/5)*3,mid_four=(length/5)*4,start,end=length,i;
	LinkListL p=L->next,p1=(*L1),p2=(*L2),p3=(*L3),p4=(*L4),p5=(*L5),temp;
	for(start=0;start<mid_one;start++)
	{
		temp = (LinkListL)malloc(sizeof(struct nodeL));
		if(!temp)
		{
			printf("malloc temp ERROR,and located split_L()");
			return ;
		}
		for(i=0;i<15;i++)
		{
			temp->data[i]=p->data[i];
		
		}
		p1->next=temp;
		p1=temp;
		p=p->next;
	}
	p1->next=NULL;
	for(start=mid_one;start<mid_two;start++)
	{
		temp = (LinkListL)malloc(sizeof(struct nodeL));
		if(!temp)
		{
			printf("malloc temp ERROR,and located split()");
			return ;
		}
		for(i=0;i<15;i++)
		{
			temp->data[i]=p->data[i];
		}
		p2->next=temp;
		p2=temp;
		p=p->next;
	}
	p2->next=NULL;
	for(start=mid_two;start<mid_three;start++)
	{
		temp = (LinkListL)malloc(sizeof(struct nodeL));
		if(!temp)
		{
			printf("malloc temp ERROR,and located split()");
			return ;
		}
		for(i=0;i<15;i++)
		{
			temp->data[i]=p->data[i];
		}
		p3->next=temp;
		p3=temp;
		p=p->next;
	}
	p3->next=NULL;
	for(start=mid_three;start<mid_four;start++)
	{
		temp = (LinkListL)malloc(sizeof(struct nodeL));
		if(!temp)
		{
			printf("malloc temp ERROR,and located split_F()");
			return ;
		}
		for(i=0;i<15;i++)
		{
			temp->data[i]=p->data[i];
		}
		p4->next=temp;
		p4=temp;
		p=p->next;
	}
	p4->next=NULL;
	for(start=mid_four;start<end;start++)
	{
		temp = (LinkListL)malloc(sizeof(struct nodeL));
		if(!temp)
		{
			printf("malloc temp ERROR,and located split_F()");
			return ;
		}
		for(i=0;i<15;i++)
		{
			temp->data[i]=p->data[i];
		
		}
		p5->next=temp;
		p5=temp;
		p=p->next;
	}
	p5->next=NULL;
}
void Fifth_Step(LinkListL L,LinkListL L1,LinkListF *F)
{
	LinkListL l1=L1->next,l2;
	LinkListF p=(*F),temp;
	int i,j,k,flag0;
	if(p->next!=NULL)
	{
		while(p->next)
		{
			p=p->next;
		}
	}
	while(l1)
	{
		
		l2=L->next;
		while(l2)
		{
			if(l2->data[0]>l1->data[0])
			{
				flag0=0;
				for(i=0;i<5;i++)
				{
					for(j=0;j<5;j++)
					{
						if(l2->data[i]==l1->data[j]||\
						l2->data[i+5]==l1->data[j+5]||\
						l2->data[i+10]==l1->data[j+10])
						{
							flag0++;
						}
					}
				}
			/*	for(i=0;i<5;i++)
				{
					for(j=0;j<5;j++)
					{
						if(l2->data[i+5]==l1->data[j+5])
						{
							flag0++;
						}
					}
				}
				for(i=0;i<5;i++)
				{
					for(j=0;j<5;j++)
					{
						if(l2->data[i+10]==l1->data[j+10])
						{
							flag0++;
						}
					}
				}*/
				if(flag0==0)
				{
					temp=(LinkListF)malloc(sizeof(struct nodeF));
						if(!temp)
						{
							printf("malloc temp ERROR,and located fifth_Step()");
							return ;
						}
						for(k=0;k<15;k++)
						{
							temp->data[0][k]=l1->data[k];
							
							temp->data[1][k]=l2->data[k];
							count_F++;
						}
						count_F=count_F-14;
						p->next=temp;
						p=temp;
				}
			}
			l2=l2->next;
		}
		l1=l1->next;
	}
	p->next=NULL;
}
void Writefile_Final(LinkListF F)
{
	LinkListF p;
	int i,j;
	FILE *fp=fopen(".\\Result.txt","w");
	if(fp==NULL)
	{
		printf("File open or creat failed\n");
		return ;
	}
	if(!F)
	{
		printf("ERROR:linklistF is empty.\n");
		return;
	}
	p=F->next;
	
	while(p)
	{
		for(j=0;j<2;j++)
		{
			
			for(i=0;i<5;i++)
			{
				fprintf(fp,"%d  ",p->data[j][i]);
			}
			fprintf(fp,"    ");
			for(i=5;i<10;i++)
			{
				fprintf(fp,"%d  ",p->data[j][i]);
			}
			fprintf(fp,"    ");
			for(i=10;i<15;i++)
			{
				fprintf(fp,"%d  ",p->data[j][i]);
			}
			fprintf(fp,"\n");
		} 
			fprintf(fp,"-------------------------------------------------------\n");
		p=p->next; 
	}
	fclose(fp); 
}
int main()
{
	int a[45][2],val[100][3],length,lengthlink;
	int flag=0;
	LinkListN N;
	LinkListL L,L1,L2,L3,L4,L5;
	LinkListF F;
	First_Step(a);
	//	 Print_First_Step(a);
//	printf("Do you want to Start calculation?Yes,press Y.  NO,press N :");
	//c=getchar();
	while(flag==0)
	{
		char c;
		if(LinkListN_Init(&N))
	 		printf("Succeed Init N.\n");
		if(LinkListL_Init(&L))
	 		printf("Succeed Init L.\n");
	 	if(LinkListL_Init(&L1))
	 		printf("Succeed Init L1.\n");
	 	if(LinkListL_Init(&L2))
	 		printf("Succeed Init L2.\n");
	 	if(LinkListL_Init(&L3))
	 		printf("Succeed Init L3.\n");
	 	if(LinkListL_Init(&L4))
	 		printf("Succeed Init L4.\n");
	 	if(LinkListL_Init(&L5))
	 		printf("Succeed Init L5.\n");
		if(LinkListF_Init(&F))
	 		printf("Succeed Init F.\n");
		Second_Step(a,&N);
	//	Traversal_N(N);
		Third_Step(val,&length);
//		printf("%d\n", LinkListN_Length(N));
		Forth_Step(N,&L,val,length);
		Free_N(&N);
//	Traversal_L(L);
	
		lengthlink=LinkListL_Length(L);
		printf("count_L= %d\n",lengthlink);
		Split_L(L,&L1,&L2,&L3,&L4,&L5,lengthlink);//讲链表L拆成5部分 
		printf("the length of　L1 = %d ,L2 = %d  L3=%d  L4=%d  L5=%d\n",LinkListL_Length(L1)\
		,LinkListL_Length(L2),LinkListL_Length(L3),LinkListL_Length(L4),LinkListL_Length(L5)); 
		printf("\n*************************************\n"); 
		printf("Run take some time, please wait......\n"); 
		printf("\n*************************************\n\n"); 
		Fifth_Step(L,L1,&F);
		printf("after used L1, the length of　F = %d\n\n",LinkListF_Length(F)); 
		Free_L(&L1);
		
		Fifth_Step(L,L2,&F);
		printf("after used L2, the length of　F = %d\n\n",LinkListF_Length(F)); 
		Free_L(&L2);
		
		Fifth_Step(L,L3,&F);
		printf("after used L3, the length of　F = %d\n\n",LinkListF_Length(F)); 
		Free_L(&L3);
		
		Fifth_Step(L,L4,&F);
		printf("after used L4, the length of　F = %d\n\n",LinkListF_Length(F)); 
		Free_L(&L4);
		
		Fifth_Step(L,L5,&F);
		printf("after used L5, the length of　F = %d\n",LinkListF_Length(F)); 
		Free_L(&L5);
		
		Free_L(&L);
		Traversal_F(F);
		lengthlink=LinkListF_Length(F);
		printf("count_F= %d\n",lengthlink);
		if(lengthlink==0) 
		{
			printf("According to calculations, Does not meet the array.\n\n");
			printf("Do you want to continue?Yes,press any key.  NO,press N \n");
			c=getch();
		}
		else
		{
			Writefile_Final(F);
			printf("_____________________________________________\n");
			printf("Result has stored in Current Folder and named \"Result.txt\"\nNow,you can close program!Thank you for this use.\n");
			printf("---------------------------------------------\n\n");
			printf("Do you want to continue?Yes,press any key.  NO,press N \n");
			c=getch();
		}
		Free_F(&F);
		if(c=='n'||c=='N')
			flag++;
	}
	system("pause");
}
