#include<stdio.h>
#include<stdlib.h>
typedef int Status;
#define OK 1
#define ERROR 0
struct node{
	int data[6];
	struct node *next;
};
struct nodeF{
	int data[5][6];
	struct nodeF *next;
};
typedef struct node *LinkList;
typedef struct nodeF *LinkListF;
int count=0;
Status LinkList_Init(LinkList *L)
{
	(*L) = (LinkList)malloc(sizeof(struct node));
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
void First_Step(int (*a)[2])//生成序列 
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
void Print_Three_Step(int (*val)[3],int length)//打印val[][3]
{
	int i,j;
	for(i=0;i<length;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",val[i][j]);
		}
		printf("\n");
	}
	printf("\n");
} 
void Second_Step_0(int (*a)[2],LinkList *L)//存入链表L
{
	int i,j,k;
	LinkList temp,p;
//	p = (LinkList)malloc(sizeof(struct node));
//	if(!p)
//	{
//		printf("malloc p ERROR");
//		return ;
//	}
	p=(*L);
	for(i=0;i<45;i++)
	{
		for(j=0;j<45;j++)
		{
			for(k=0;k<45;k++)
			{
				temp = (LinkList)malloc(sizeof(struct node));
				if(!temp)
				{
					printf("malloc temp ERROR,and located %d,%d,%d",i,j,k);
					return ;
				}
				temp->data[0]=a[i][0];
				temp->data[1]=a[i][1];
				temp->data[2]=a[j][0];
				temp->data[3]=a[j][1];
				temp->data[4]=a[k][0];
				temp->data[5]=a[k][1];
				p->next=temp;
				p=temp;
			}
		}
	}
	p->next=NULL;
} 
int LinkList_Length(LinkList L)//计算链表L长度 
{
	LinkList p=L->next;
	int length=0;
	while(p)
	{
		length++;
		p=p->next;
	}
	return length;
}
long LinkListF_Length(LinkListF F)//计算链表F长度 
{
	LinkListF f=F->next;
	long length=0;
	while(f)
	{
		length++;
		f=f->next;
	}
	return length;
}
void Print_Second_Step(LinkList L)//打印链表L 
{
	int i;
	if(!L)
	{
		printf("ERROR:linklist is empty.\n");
		return;
	}
	LinkList p=L->next;
	while(p)
	{
		for(i=0;i<6;i++)
		{
			if(i<2)
				printf("%d",p->data[i]);
			printf(" ");
			if(i<4&&i>=2)
				printf("%d",p->data[i]);
			printf("   ");
			if(i<6&&i>=4)
				printf("%d",p->data[i]);		
		}
			printf("\n");	
		p=p->next;
	}
}
void Print_LinkListF(LinkListF F)//打印链表F
{
	int i,k;;
	if(!F)
	{
		printf("ERROR:linklistF is empty.\n");
		return;
	}
	LinkListF f=F->next;
	while(f)
	{
		for(k=0;k<2;k++)
		{
			for(i=0;i<6;i++)
			{
				if(i<2)
					printf("%d",f->data[k][i]);
				printf("   ");
				if(i<4&&i>=2)
					printf("%d",f->data[k][i]);
				printf("   ");
				if(i<6&&i>=4)
					printf("%d",f->data[k][i]);		
			}
			printf("\n");
		}
			printf("\n----------------------------------\n");	
		f=f->next;
	}
}
void Print_LinkListF1(LinkListF F)//打印链表F1
{
	int i,k;;
	if(!F)
	{
		printf("ERROR:linklistF is empty.\n");
		return;
	}
	LinkListF f=F->next;
	while(f)
	{
		for(k=0;k<5;k++)
		{
			for(i=0;i<6;i++)
			{
				if(i<2)
					printf("%d",f->data[k][i]);
				printf("   ");
				if(i<4&&i>=2)
					printf("%d",f->data[k][i]);
				printf("   ");
				if(i<6&&i>=4)
					printf("%d",f->data[k][i]);		
			}
			printf("\n");
		}
			printf("\n----------------------------------\n");	
		f=f->next;
	}
}
void Free_Fn(LinkListF *F)//释放后期没用的链表 
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
void Free_L(LinkList *L)//释放后期没用的链表 
{
	LinkList temp,p=(*L)->next;
	while(p)
	{
		temp=p;
		p=p->next; 
		free(temp);
	}
	(*L)->next=NULL; 
}
void Third_Step(int (*val)[3],int *length)//获取n个三位数 
{
	/*int input;
	int i,j;
	printf("Input how many three-figure?::"); 
	scanf("%d",&input);
	printf("Input %d three-figure!\n",input);
	for(i=0;i<input;i++)
		for(j=0;j<3;j++)
		{
			scanf("%d",&val[i][j]);
		}
	*length=input;*/
       int i,j;
       FILE *fp;
       int input;
       printf("Keep documents need to be calculated in the Current Folder !\nMake sure filename is \"array\",and format is \".txt\"\n");
       printf("Please enter the number of the array to be calculated.\n(Recommended not more than 34)\nhuw many?:");
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
void Forth_Step_0(int (*val)[3],LinkList *L,int length)//针对第一行的筛选 (L)
{
	
/*	int i,flag=0,flag0=0;
	LinkList p,s,temp;
	p=(*L);
	while(p)
	{
		s=p->next;
		if(s)
		for(i=0;i<length;i++)
		{
			flag0=0;
			if(flag!=0)
			{
				i=0;
				flag=0;
			}//一旦节点被删除，重头开始循环 
			if(s)//确保s不为NULL 
			if(val[i][0]==s->data[0]||val[i][0]==s->data[1])	
				if(val[i][1]==s->data[2]||val[i][1]==s->data[3])
				{
					flag0++;
				}
		    if(s)//确保s不为NULL 
		   	if(val[i][0]==s->data[0]||val[i][0]==s->data[1])
			    if(val[i][2]==s->data[4]||val[i][2]==s->data[5])
				{
					flag0++;
				//	printf("bbb %d %d %x\n",i,val[i][0],s->next);
				}
			if(s)
	        if(val[i][1]==s->data[2]||val[i][1]==s->data[3])			
				if(val[i][2]==s->data[4]||val[i][2]==s->data[5])
				{
					flag0++;
				} 
			if(flag0!=0)
			{
					temp=s;
					if(s->next==NULL)
						p->next=NULL;
					else
						p->next=p->next->next;
					free(temp);
					flag++;
					flag0=0;
					s=p->next;
			}
			
		} 
		p=p->next;
	}
//	printf("cou1=%d\n",cou1++);*/
LinkList pCur = (*L);
	LinkList pPrev = NULL;
	LinkList pTmp;
	int i = 0;
	int eqc = 0;
	while (pCur)
	{
		for(i = 0;i< length;i++)
		{
			eqc = 0;
			if (pCur->data[0] == val[i][0] || pCur->data[1] == val[i][0])
			{
				eqc++;
			}
			if (pCur->data[2] == val[i][1] || pCur->data[3] == val[i][1])
			{
				eqc++;
			}
			if (pCur->data[4] == val[i][2] || pCur->data[5] == val[i][2])
			{
				eqc++;
			}
			if (eqc >1)
			{
				if (pPrev != NULL)
				{
					pPrev->next = pCur->next;
					
				}
				else
				{
					(*L) = pCur->next;
				}
				pTmp = pCur;
				pCur = pCur->next;
				free(pTmp);
				break;
			}
		}
		if (i != length)
		{
			continue;
		}
		pPrev = pCur;
		pCur = pCur->next;
	}
}
void Split_L(LinkList L,LinkList *L1,LinkList *L2,LinkList *L3,int length)
{
	int mid_front=length/3,mid_behind=(length/3)*2,start,end=length,i;
	LinkList p=L->next,p1=(*L1),p2=(*L2),p3=(*L3),temp;
	for(start=0;start<mid_front;start++)
	{
		temp = (LinkList)malloc(sizeof(struct node));
		if(!temp)
		{
			printf("malloc temp ERROR,and located split()");
			return ;
		}
		for(i=0;i<6;i++)
			temp->data[i]=p->data[i];
		p1->next=temp;
		p1=temp;
		p=p->next;
	}
	p1->next=NULL;
	for(start=mid_front;start<mid_behind;start++)
	{
		temp = (LinkList)malloc(sizeof(struct node));
		if(!temp)
		{
			printf("malloc temp ERROR,and located split()");
			return ;
		}
		for(i=0;i<6;i++)
			temp->data[i]=p->data[i];
		p2->next=temp;
		p2=temp;
		p=p->next;
	}
	p2->next=NULL;
	for(start=mid_behind;start<end;start++)
	{
		temp = (LinkList)malloc(sizeof(struct node));
		if(!temp)
		{
			printf("malloc temp ERROR,and located split()");
			return ;
		}
		for(i=0;i<6;i++)
			temp->data[i]=p->data[i];
		p3->next=temp;
		p3=temp;
		p=p->next;
	}
	p3->next=NULL;
}
void Split_F(LinkListF F,LinkListF *Fs1,LinkListF *Fs2,LinkListF *Fs3,LinkListF *Fs4,LinkListF *Fs5,int length)
{
	int mid_one=length/5,mid_two=(length/5)*2,\
	mid_three=(length/5)*3,mid_four=(length/5)*4,start,end=length,i;
	LinkListF p=F->next,p1=(*Fs1),p2=(*Fs2),p3=(*Fs3),p4=(*Fs4),p5=(*Fs5),temp;
	for(start=0;start<mid_one;start++)
	{
		temp = (LinkListF)malloc(sizeof(struct nodeF));
		if(!temp)
		{
			printf("malloc temp ERROR,and located split_F()");
			return ;
		}
		for(i=0;i<6;i++)
		{
			temp->data[0][i]=p->data[0][i];
			temp->data[1][i]=p->data[1][i];
		}
		p1->next=temp;
		p1=temp;
		p=p->next;
	}
	p1->next=NULL;
	for(start=mid_one;start<mid_two;start++)
	{
		temp = (LinkListF)malloc(sizeof(struct nodeF));
		if(!temp)
		{
			printf("malloc temp ERROR,and located split()");
			return ;
		}
		for(i=0;i<6;i++)
		{
			temp->data[0][i]=p->data[0][i];
			temp->data[1][i]=p->data[1][i];
		}
		p2->next=temp;
		p2=temp;
		p=p->next;
	}
	p2->next=NULL;
	for(start=mid_two;start<mid_three;start++)
	{
		temp = (LinkListF)malloc(sizeof(struct nodeF));
		if(!temp)
		{
			printf("malloc temp ERROR,and located split()");
			return ;
		}
		for(i=0;i<6;i++)
		{
			temp->data[0][i]=p->data[0][i];
			temp->data[1][i]=p->data[1][i];
		}
		p3->next=temp;
		p3=temp;
		p=p->next;
	}
	p3->next=NULL;
	for(start=mid_three;start<mid_four;start++)
	{
		temp = (LinkListF)malloc(sizeof(struct nodeF));
		if(!temp)
		{
			printf("malloc temp ERROR,and located split_F()");
			return ;
		}
		for(i=0;i<6;i++)
		{
			temp->data[0][i]=p->data[0][i];
			temp->data[1][i]=p->data[1][i];
		}
		p4->next=temp;
		p4=temp;
		p=p->next;
	}
	p4->next=NULL;
	for(start=mid_four;start<end;start++)
	{
		temp = (LinkListF)malloc(sizeof(struct nodeF));
		if(!temp)
		{
			printf("malloc temp ERROR,and located split_F()");
			return ;
		}
		for(i=0;i<6;i++)
		{
			temp->data[0][i]=p->data[0][i];
			temp->data[1][i]=p->data[1][i];
		}
		p5->next=temp;
		p5=temp;
		p=p->next;
	}
	p5->next=NULL;
}
void Second_Step_1_4(LinkList *Ln,LinkList L)//复制L,存入链表L1,L2,L3,L4. 
{
	LinkList p=L->next,pn=(*Ln),temp;
	while(p)
	{
		int i;
		temp = (LinkList)malloc(sizeof(struct node));
		if(!temp)
		{
			printf("malloc temp ERROR,and located funtiom Second_Step_1_4\n");
			return ;
		}
		for(i=0;i<6;i++)
			temp->data[i]=p->data[i];//先复制链表L 
		pn->next=temp;
		pn=temp;
		p=p->next;
	}
	pn->next=NULL;
//	printf("%x  %x\n",(*L1),p1); 
} 
void Froth_Step_1(LinkListF *F,LinkList L,LinkList L1)//针对第二行，将第一行和第二行合并 
{
	LinkList p=L1->next,p1;
	LinkListF pf=(*F),tempf;
	int i,flag=0;
	while(p)
	{
		p1=L->next;
		while(p1)
		{
			flag=0;
			if(p1->data[0]> p->data[0]\
			 &&p1->data[0]!=p->data[1]\
			 &&p1->data[1]!=p->data[0]\
			 &&p1->data[1]!=p->data[1])
			{
			//	printf("aaa\n")
				flag++;
			}
		    if(p1->data[2]!=p->data[2]\
				  &&p1->data[2]!=p->data[3]\
				  &&p1->data[3]!=p->data[2]\
				  &&p1->data[3]!=p->data[3])
			{
			 	flag++;	
			}
			if(p1->data[4]!=p->data[4]\
				  &&p1->data[4]!=p->data[5]\
				  &&p1->data[5]!=p->data[4]\
				  &&p1->data[5]!=p->data[5])
			{
				flag++;	 
			}
			if(flag==3)
			{
				tempf = (LinkListF)malloc(sizeof(struct nodeF));
				if(!tempf)
				{
					printf("malloc tempf ERROR.");
					return ;
				}
				for(i=0;i<6;i++)
				{
					tempf->data[0][i]=p->data[i];
					tempf->data[1][i]=p1->data[i];
				}
				pf->next=tempf;
				pf=tempf;
				pf->next=NULL;
			} 			
				p1=p1->next;			
		}
		p=p->next;
	}
}
void Froth_Step_2(LinkListF *F1,LinkListF F,LinkList L)//针对第三行，将第一、二行和第三行合并 
{
	LinkList p2;
	LinkListF p=F->next,tempf,pf=(*F1);
	int i,flag=0;
	while(p)
	{
		p2=L->next;
		while(p2)
		{
			flag=0;
			if(p2->data[0]!=p->data[0][0]\
			 &&p2->data[0]!=p->data[0][1]\
			 &&p2->data[1]!=p->data[0][0]\
			 &&p2->data[1]!=p->data[0][1])
			{
				flag++;
			}
		    if(p2->data[2]!=p->data[0][2]\
			 &&p2->data[2]!=p->data[0][3]\
			 &&p2->data[3]!=p->data[0][2]\
			 &&p2->data[3]!=p->data[0][3])
			{
			 	flag++;	
			}
			if(p2->data[4]!=p->data[0][4]\
			 &&p2->data[4]!=p->data[0][5]\
		     &&p2->data[5]!=p->data[0][4]\
		     &&p2->data[5]!=p->data[0][5])
			{
				flag++;	 
			}
			
			
			if(p2->data[0]> p->data[1][0]\
			 &&p2->data[0]!=p->data[1][1]\
			 &&p2->data[1]!=p->data[1][0]\
			 &&p2->data[1]!=p->data[1][1])
			{
				flag++;
			}
		    if(p2->data[2]!=p->data[1][2]\
			 &&p2->data[2]!=p->data[1][3]\
			 &&p2->data[3]!=p->data[1][2]\
			 &&p2->data[3]!=p->data[1][3])
			{
			 	flag++;	
			}
			if(p2->data[4]!=p->data[1][4]\
			 &&p2->data[4]!=p->data[1][5]\
		     &&p2->data[5]!=p->data[1][4]\
		     &&p2->data[5]!=p->data[1][5])
			{
				flag++;	 
			}
			if(flag==6)
			{
				tempf = (LinkListF)malloc(sizeof(struct nodeF));
				if(!tempf)
				{
					printf("malloc tempf ERROR.");
					return ;
				}
				for(i=0;i<6;i++)
				{
					tempf->data[0][i]=p->data[0][i];
					tempf->data[1][i]=p->data[1][i];
					tempf->data[2][i]=p2->data[i];
				}
				pf->next=tempf;
				pf=tempf;
				pf->next=NULL;
			} 			
				p2=p2->next;			
		}
		p=p->next;
	}
}

void Froth_Step_3(LinkListF *F2,LinkListF F1,LinkList L)//针对第四行，将第一、二、第三行和第四行合并 
{
	LinkList p3;
	LinkListF p=F1->next,tempf,pf=(*F2);
	int i,flag=0;
	while(p)
	{
		p3=L->next;
		while(p3)
		{
			flag=0;
			if(p3->data[0]!=p->data[0][0]\
			 &&p3->data[0]!=p->data[0][1]\
			 &&p3->data[1]!=p->data[0][0]\
			 &&p3->data[1]!=p->data[0][1])
			{
				flag++;
			}
		    if(p3->data[2]!=p->data[0][2]\
			 &&p3->data[2]!=p->data[0][3]\
			 &&p3->data[3]!=p->data[0][2]\
			 &&p3->data[3]!=p->data[0][3])
			{
			 	flag++;	
			}
			if(p3->data[4]!=p->data[0][4]\
			 &&p3->data[4]!=p->data[0][5]\
		     &&p3->data[5]!=p->data[0][4]\
		     &&p3->data[5]!=p->data[0][5])
			{
				flag++;	 
			}
			//////////////////////////////////
			
			if(p3->data[0]!=p->data[1][0]\
			 &&p3->data[0]!=p->data[1][1]\
			 &&p3->data[1]!=p->data[1][0]\
			 &&p3->data[1]!=p->data[1][1])
			{
				flag++;
			}
		    if(p3->data[2]!=p->data[1][2]\
			 &&p3->data[2]!=p->data[1][3]\
			 &&p3->data[3]!=p->data[1][2]\
			 &&p3->data[3]!=p->data[1][3])
			{
			 	flag++;	
			}
			if(p3->data[4]!=p->data[1][4]\
			 &&p3->data[4]!=p->data[1][5]\
		     &&p3->data[5]!=p->data[1][4]\
		     &&p3->data[5]!=p->data[1][5])
			{
				flag++;	 
			}
			//////////////////////////////
			if(p3->data[0]> p->data[2][0]\
			 &&p3->data[0]!=p->data[2][1]\
			 &&p3->data[1]!=p->data[2][0]\
			 &&p3->data[1]!=p->data[2][1])
			{
				flag++;
			}
		    if(p3->data[2]!=p->data[2][2]\
			 &&p3->data[2]!=p->data[2][3]\
			 &&p3->data[3]!=p->data[2][2]\
			 &&p3->data[3]!=p->data[2][3])
			{
			 	flag++;	
			}
			if(p3->data[4]!=p->data[2][4]\
			 &&p3->data[4]!=p->data[2][5]\
		     &&p3->data[5]!=p->data[2][4]\
		     &&p3->data[5]!=p->data[2][5])
			{
				flag++;	 
			}
			
			if(flag==9)
			{
				tempf = (LinkListF)malloc(sizeof(struct nodeF));
				if(!tempf)
				{
					printf("malloc tempf ERROR.");
					return ;
				}
				for(i=0;i<6;i++)
				{
					tempf->data[0][i]=p->data[0][i];
					tempf->data[1][i]=p->data[1][i];
					tempf->data[2][i]=p->data[2][i];
					tempf->data[3][i]=p3->data[i];
				}
				pf->next=tempf;
				pf=tempf;
				pf->next=NULL;
			} 			
				p3=p3->next;			
		}
		p=p->next;
	}
}

void Froth_Step_4(LinkListF *F3,LinkListF F2,LinkList L)//针对第四行，将第一、二、三、四行和第五行合并 
{
	LinkList p4;
	LinkListF p=F2->next,tempf,pf=(*F3);
	int i,flag=0;
	while(p)
	{
		
		p4=L->next;
		while(p4)
		{
		//	cou2++;
			flag=0;
			if(p4->data[0]!=p->data[0][0]\
			 &&p4->data[0]!=p->data[0][1]\
			 &&p4->data[1]!=p->data[0][0]\
			 &&p4->data[1]!=p->data[0][1])
			{
				flag++;
			}
		    if(p4->data[2]!=p->data[0][2]\
			 &&p4->data[2]!=p->data[0][3]\
			 &&p4->data[3]!=p->data[0][2]\
			 &&p4->data[3]!=p->data[0][3])
			{
			 	flag++;	
			}
			if(p4->data[4]!=p->data[0][4]\
			 &&p4->data[4]!=p->data[0][5]\
		     &&p4->data[5]!=p->data[0][4]\
		     &&p4->data[5]!=p->data[0][5])
			{
				flag++;	 
			}
			//////////////////////////////////
			
			if(p4->data[0]!=p->data[1][0]\
			 &&p4->data[0]!=p->data[1][1]\
			 &&p4->data[1]!=p->data[1][0]\
			 &&p4->data[1]!=p->data[1][1])
			{
				flag++;
			}
		    if(p4->data[2]!=p->data[1][2]\
			 &&p4->data[2]!=p->data[1][3]\
			 &&p4->data[3]!=p->data[1][2]\
			 &&p4->data[3]!=p->data[1][3])
			{
			 	flag++;	
			}
			if(p4->data[4]!=p->data[1][4]\
			 &&p4->data[4]!=p->data[1][5]\
		     &&p4->data[5]!=p->data[1][4]\
		     &&p4->data[5]!=p->data[1][5])
			{
				flag++;	 
			}
			//////////////////////////////
		if(p4->data[0]!=p->data[2][0]\
			 &&p4->data[0]!=p->data[2][1]\
			 &&p4->data[1]!=p->data[2][0]\
			 &&p4->data[1]!=p->data[2][1])
			{
				flag++;
			}
		    if(p4->data[2]!=p->data[2][2]\
			 &&p4->data[2]!=p->data[2][3]\
			 &&p4->data[3]!=p->data[2][2]\
			 &&p4->data[3]!=p->data[2][3])
			{
			 	flag++;	
			}
			if(p4->data[4]!=p->data[2][4]\
			 &&p4->data[4]!=p->data[2][5]\
		     &&p4->data[5]!=p->data[2][4]\
		     &&p4->data[5]!=p->data[2][5])
			{
				flag++;	 
			}
			//////////////////////////////////////////
			if(p4->data[0]> p->data[3][0]\
			 &&p4->data[0]!=p->data[3][1]\
			 &&p4->data[1]!=p->data[3][0]\
			 &&p4->data[1]!=p->data[3][1])
			{
				flag++;
			}
		    if(p4->data[2]!=p->data[3][2]\
			 &&p4->data[2]!=p->data[3][3]\
			 &&p4->data[3]!=p->data[3][2]\
			 &&p4->data[3]!=p->data[3][3])
			{
			 	flag++;	
			}
			if(p4->data[4]!=p->data[3][4]\
			 &&p4->data[4]!=p->data[3][5]\
		     &&p4->data[5]!=p->data[3][4]\
		     &&p4->data[5]!=p->data[3][5])
			{
				flag++;	 
			}
			/////////////////////////////////
			if(flag==12)
			{
				count++;
				tempf = (LinkListF)malloc(sizeof(struct nodeF));
				if(!tempf)
				{
					printf("malloc tempf ERROR.");
					return ;
				}
				for(i=0;i<6;i++)
				{
					tempf->data[0][i]=p->data[0][i];
					tempf->data[1][i]=p->data[1][i];
					tempf->data[2][i]=p->data[2][i];
					tempf->data[3][i]=p->data[3][i];
					tempf->data[4][i]=p4->data[i];
				}
				pf->next=tempf;
				pf=tempf;
				pf->next=NULL;
			} 			
				p4=p4->next;			
		}
		p=p->next;
	}
}
void Final_Step(LinkListF *Final,LinkListF F3)
{
	LinkListF f=F3->next,p=(*Final),temp;
	int i;
	//int flag=0;
	while(p->next)
	{
		p=p->next;
	}
	
	while(f)
	{
			
		temp = (LinkListF)malloc(sizeof(struct nodeF));
		if(!temp)
		{
			printf("malloc temp ERROR,and located split()");
			return ;
		}
		for(i=0;i<6;i++)
		{
			temp->data[0][i]=f->data[0][i];
			temp->data[1][i]=f->data[1][i];
			temp->data[2][i]=f->data[2][i];
			temp->data[3][i]=f->data[3][i];
			temp->data[4][i]=f->data[4][i];
		}
		p->next=temp;
		p=temp;
		f=f->next;
	}			
	p->next=NULL;
	 
}
void Writefile_Final(LinkListF Final)
{
	int i,k;
	FILE *fp=fopen(".\\Result.txt","w");
	if(!fp)
	{
		printf("create and open file failed\n");
  		return;
	}
	if(!Final)
	{
		printf("ERROR:linklistF is empty.\n");
		return;
	}
	LinkListF f=Final->next;
	
	while(f)
	{
		for(k=0;k<5;k++)
		{
			for(i=0;i<6;i++)
			{
				if(i<2)
					fprintf(fp,"%d",f->data[k][i]);
				fprintf(fp,"  ");
				if(i<4&&i>=2)
					fprintf(fp,"%d",f->data[k][i]);
				fprintf(fp,"  ");
				if(i<6&&i>=4)
					fprintf(fp,"%d",f->data[k][i]);		
			}
			fprintf(fp,"\n");
		}
			fprintf(fp,"\n-------------------------------------\n");	
		f=f->next;
	}
	fclose(fp);
}
int main()
{
	char c;
	int a[45][2],val[100][3],length,length_of_L,length_of_F;
	int flag=0; 
	while(flag==0)
	{
	char c;
	LinkList L,L1,L2,L3;
	LinkListF F,F1,F2,F3,Fs1,Fs2,Fs3,Fs4,Fs5,Final;
	First_Step(a);
	
//	Print_First_Step(a);
	if(LinkList_Init(&L))//初始化L 
		printf("Succeed Init L.\n");
	if(LinkList_Init(&L1))
		printf("Succeed Init L1.\n");
	if(LinkList_Init(&L2))
		printf("Succeed Init L2.\n");
	if(LinkList_Init(&L3))
		printf("Succeed Init L3.\n");
//	if(LinkList_Init(&L4))
//		printf("Succeed Init L4.\n");
	if(LinkListF_Init(&F))
		printf("Succeed Init F.\n");
	if(LinkListF_Init(&F1))
		printf("Succeed Init F1.\n");
	if(LinkListF_Init(&F2))
		printf("Succeed Init F2.\n");
	if(LinkListF_Init(&F3))
		printf("Succeed Init F3.\n");
	if(LinkListF_Init(&Fs1))
		printf("Succeed Init Fs1.\n");
	if(LinkListF_Init(&Fs2))
		printf("Succeed Init Fs2.\n");
	if(LinkListF_Init(&Fs3))
		printf("Succeed Init Fs3.\n");
	if(LinkListF_Init(&Fs4))
		printf("Succeed Init Fs4.\n");
	if(LinkListF_Init(&Fs5))
		printf("Succeed Init Fs5.\n");
		if(LinkListF_Init(&Final))
		printf("Succeed Init Final.\n");
	Third_Step(val,&length);
	printf("\n*************************************\n"); 
	printf("Run take some time, please wait......\n"); 
	printf("\n*************************************\n"); 
	Second_Step_0(a,&L);
	printf("the length of　L = %d\n",LinkList_Length(L)); 
//	Print_Second_Step(L);
//	Third_Step(val,&length);
//		printf("\n");
//	printf("kfakfkakfak\n");
//	Print_Three_Step(val,length);
//	printf("kfakfkakfak");
//	Print_Three_Step(val,length);

	Forth_Step_0(val,&L,length);
	printf("the length of　L = %d ,the number of three-figure: %d \n",LinkList_Length(L),length); 
//	Print_Second_Step(L);
	//为了程序效率，将L拆分成3部分 
	
	length_of_L=LinkList_Length(L);
	Split_L(L,&L1,&L2,&L3,length_of_L);
	
	printf("the length of　L1 = %d ,L2 = %d  L3=%d %d\n",LinkList_Length(L1),LinkList_Length(L2),LinkList_Length(L3),length); 
	
/*	printf("是否遍历L1？？(y/n)：");
	scanf("%c",&c);
	if(c=='y')
	Print_Second_Step(L1);
	
	printf("是否遍历L2？？(y/n)：");
	scanf("%c",&c);
	if(c=='y')
	Print_Second_Step(L2);
	
	printf("是否遍历L3？？(y/n)：");
	scanf("%c",&c);
	if(c=='y')
	Print_Second_Step(L3); */
	/*-------------------------我是华丽的分割线-L1---------------*/
	Froth_Step_1(&F,L,L1);
	//	Print_Second_Step(L);
	//	printf("after \"Froth_Step_1(&L1,L)\",the length of　L1 = %d\n",LinkList_Length(L1)); 
	printf("used L1 the length of　F = %ld\n",LinkListF_Length(F)); 
	//为了程序效率，将F拆分成3部分 
	length_of_F=LinkListF_Length(F);
	Split_F(F,&Fs1,&Fs2,&Fs3,&Fs4,&Fs5,length_of_F);
	printf("the length of　Fs1 = %d ,Fs2 = %d  Fs3=%d Fs4=%d Fs5=%d \n",\
	LinkListF_Length(Fs1),LinkListF_Length(Fs2),LinkListF_Length(Fs3),LinkListF_Length(Fs4),LinkListF_Length(Fs5)); 
	//拆分后分别使用 
	/*-------------------------我是华丽的小小分割线Fs1----------------*/
	Froth_Step_2(&F1,Fs1,L);
	printf("used L1 and Fs1 the length of　F1 = %ld\n",LinkListF_Length(F1)); 
	Free_Fn(&Fs1);
	//	Print_LinkListF1(F1);
	Froth_Step_3(&F2,F1,L); 
	printf("used L1 and Fs1 the length of　F2 = %ld\n",LinkListF_Length(F2)); 
	Free_Fn(&F1);
	//	Print_LinkListF1(F2);
	Froth_Step_4(&F3,F2,L); 
	printf("used L1 and Fs1 the length of　F3 = %ld\n",LinkListF_Length(F3)); 
	Free_Fn(&F2);
	//if(LinkListF_Length(F3)!=0)
	if(1) 
	{
		Final_Step(&Final,F3);
		Free_Fn(&F3);
			/*-------------------------我是华丽的小小分割线-Fs2---------------*/
		Froth_Step_2(&F1,Fs2,L);
		printf("used L1 and Fs2 the length of　F1 = %ld\n",LinkListF_Length(F1)); 
		Free_Fn(&Fs1);
		//	Print_LinkListF1(F1);
		Froth_Step_3(&F2,F1,L); 
		printf("used L1 and Fs2 the length of　F2 = %ld\n",LinkListF_Length(F2)); 
		Free_Fn(&F1);
		//	Print_LinkListF1(F2);
		Froth_Step_4(&F3,F2,L); 
		printf("used L1 and Fs2 the length of　F3 = %ld\n",LinkListF_Length(F3)); 
		Free_Fn(&F2);
	//	if(LinkListF_Length(F3)!=0)
		if(1) 
		{
			Final_Step(&Final,F3);
			Free_Fn(&F3);
				/*-------------------------我是华丽的小小分割线Fs3----------------*/
			Froth_Step_2(&F1,Fs3,L);
			printf("used L1 and Fs3 the length of　F1 = %ld\n",LinkListF_Length(F1)); 
			Free_Fn(&Fs1);
			//			Print_LinkListF1(F1);
			Froth_Step_3(&F2,F1,L); 
			printf("used L1 and Fs3 the length of　F2 = %ld\n",LinkListF_Length(F2)); 
			Free_Fn(&F1);
			//			Print_LinkListF1(F2);
			Froth_Step_4(&F3,F2,L); 
			printf("used L1 and Fs3 the length of　F3 = %ld\n",LinkListF_Length(F3)); 
			Free_Fn(&F2);
		//	if(LinkListF_Length(F3)!=0)
			if(1) 
			{
				Final_Step(&Final,F3);
				Free_Fn(&F3);
					/*-------------------------我是华丽的小小分割线-Fs4---------------*/
				Froth_Step_2(&F1,Fs4,L);
				printf("used L1 and Fs4 the length of　F1 = %ld\n",LinkListF_Length(F1)); 
				Free_Fn(&Fs4);
				//	Print_LinkListF1(F1);
				Froth_Step_3(&F2,F1,L); 
				printf("used L1 and Fs3 the length of　F2 = %ld\n",LinkListF_Length(F2)); 
				Free_Fn(&F1);
				//	Print_LinkListF1(F2);
				Froth_Step_4(&F3,F2,L); 
				printf("used L1 and Fs3 the length of　F3 = %ld\n",LinkListF_Length(F3)); 
				Free_Fn(&F2);
			//	if(LinkListF_Length(F3)!=0)
				if(1) 
				{
					Final_Step(&Final,F3);
					Free_Fn(&F3);
					/*-------------------------我是华丽的小小分割线-Fs5---------------*/
					Froth_Step_2(&F1,Fs5,L);
					printf("used L1 and Fs5 the length of　F1 = %ld\n",LinkListF_Length(F1)); 
					Free_Fn(&Fs5);
					//	Print_LinkListF1(F1);
					Froth_Step_3(&F2,F1,L); 
					printf("used L1 and Fs3 the length of　F2 = %ld\n",LinkListF_Length(F2)); 
					Free_Fn(&F1);
					//	Print_LinkListF1(F2);
					Froth_Step_4(&F3,F2,L); 
					printf("used L1 and Fs3 the length of　F3 = %ld\n",LinkListF_Length(F3)); 
					Free_Fn(&F2);
				//	if(LinkListF_Length(F3)!=0)
					if(1) 
					{
						Final_Step(&Final,F3);
						Free_Fn(&F3);
						
					/*--------------------我是华丽的分割线-----------------------------*/
						Froth_Step_1(&F,L,L2);
//						Print_Second_Step(L);
//						printf("after \"Froth_Step_1(&L1,L)\",the length of　L1 = %d\n",LinkList_Length(L1)); 
	
						printf("used L2 the length of　F = %ld\n",LinkListF_Length(F)); 
						Froth_Step_2(&F1,F,L);
						printf("used L2 the length of　F1 = %ld\n",LinkListF_Length(F1)); 
						Free_Fn(&F);
//						Print_LinkListF1(F1);
						Froth_Step_3(&F2,F1,L); 
						printf("used L2 the length of　F2 = %ld\n",LinkListF_Length(F2)); 
						Free_Fn(&F1);
//						Print_LinkListF1(F2);
						Froth_Step_4(&F3,F2,L); 
						printf("used L2 the length of　F3 = %ld\n",LinkListF_Length(F3)); 
						Free_Fn(&F2);
					//	if(LinkListF_Length(F3)!=0)
						if(1) 
						{
							Final_Step(&Final,F3);
							Free_Fn(&F3);
								/*-------------------------我是华丽的分割线----------------*/
							Froth_Step_1(&F,L,L3);
//							Print_Second_Step(L);
//							printf("after \"Froth_Step_1(&L1,L)\",the length of　L1 = %d\n",LinkList_Length(L1)); 
							printf("used L3 the length of　F = %ld\n",LinkListF_Length(F)); 
							Froth_Step_2(&F1,F,L);
							printf("used L3 the length of　F1 = %ld\n",LinkListF_Length(F1)); 
							Free_Fn(&F);
//							Print_LinkListF1(F1);
							Froth_Step_3(&F2,F1,L); 
							printf("used L3 the length of　F2 = %ld\n",LinkListF_Length(F2)); 
							Free_Fn(&F1);
//							Print_LinkListF1(F2);
							Froth_Step_4(&F3,F2,L); 
							printf("used L3 the length of　F3 = %ld\n",LinkListF_Length(F3)); 
							Free_Fn(&F2);
						//	if(LinkListF_Length(F3)!=0)
							if(1) 
							{
								Final_Step(&Final,F3);
								Free_Fn(&F3);
							}
						}
					}
				}
			}
		}
	}
	Free_L(&L);
//	Print_LinkListF1(F3);
//	p=L->next;
//	printf("cou1 = %d,cou2 = %d\n",cou1,cou2);


//	Print_LinkListF1(F3);
//	p=L->next;
//	printf("cou1 = %d,cou2 = %d\n",cou1,cou2);


//	Print_LinkListF1(F3);
//	p=L->next;
//	printf("cou1 = %d,cou2 = %d\n",cou1,cou2);


//	Print_LinkListF1(F3);
//	p=L->next;
//	printf("cou1 = %d,cou2 = %d\n",cou1,cou2);
	

//	Print_LinkListF1(F3);
//	p=L->next;
//	printf("cou1 = %d,cou2 = %d\n",cou1,cou2);
//	printf("%d  %d  %d  %d  %d  %d\n",p->data[0],p->data[1],p->data[2],p->data[3],p->data[4],p->data[5]);


//	Print_LinkListF1(F3);
//	p=L->next;
//	printf("cou1 = %d,cou2 = %d\n",cou1,cou2);
	
	

//	Print_LinkListF1(Final);
//	p=L->next;
	printf("the final count = %d\n",count);
	if(count==0) 
		{
			printf("According to calculations, Does not meet the array.\n\n");
			printf("Do you want to continue?Yes,press any key.  NO,press N \n");
			c=getch();
		}
	else
	{
		Writefile_Final(Final);
		printf("_____________________________________________\n");
		printf("Result has stored in Current Folder and named \"Result.txt\"\nNow,you can close program!Thank you for this use.\n");
		printf("---------------------------------------------\n\n");
		printf("Do you want to continue?Yes,press any key.  NO,press N \n");
		c=getch();
	}
	Free_Fn(&Final);
		if(c=='n'||c=='N')
			flag++;
	//getchar();
	count=0;
	}
	system("pause");
	return 0;
} 
