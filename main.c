#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 80

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct{
char name[8];int sex;	
	char mobphone[12];
	char homephone[12];
    char email[30];	

}DataType;
typedef struct{
DataType data[MaxSize];
int length;	
	
}SeqList;
void CreateList(SeqList *L,DataType a[],int n){
int i;
if(n>MaxSize){printf("error");exit(0);
}	
for(i=0;i<n;i++)
  L->data[i]=a[i];	
	L->length=n;
}

void InsertList(SeqList *L,DataType x,int i){
int j;
if(L->length==MaxSize)
{
printf("���ˣ���");exit(0);	
	}	
if(i<1||i>L->length+1){
printf("����λ�÷Ƿ�:");exit(0);	
}	
	
for(j=L->length-1;j>=i-1;j--)
  L->data[j+1]=L->data[j];
  strcpy(L->data[i-1].name,x.name);
  L->data[i-1].sex=x.sex;
  strcpy(L->data[i-1].mobphone,x.mobphone);	
  strcpy(L->data[i-1].homephone,x.homephone);	
 strcpy(L->data[i-1].email,x.email);	
  L->length++;
}

void DeleteList(SeqList *L,int i){
int j;
if(L->length==0)
{
printf("���Ա�Ϊ�� �Ƴ�");
exit(0);	
	}	
if(i<1||i>L->length){
printf("ɾ��λ�÷Ƿ�");	
	exit(0);
}
for(j=i;j<=L->length-1;j++)
  L->data[j-1]=L->data[j];
  L->length--;
	
}
int LocateList(SeqList L,char name[]){
int i=0;
while(i<L.length&&strcmp(L.data[i].name,name))
  i++;
  	
	if(i<L.length){
printf("%S\t%d\t%s\t%s\t%s\n",L.data[i].name,L.data[i].sex,L.data[i].mobphone,L.data[i].homephone,L.data[i].email);
return i+1;		
		
		
	}
else return 0;}	
void PrintList(SeqList L){
int i;
for(i=0;i<L.length;i++)
  printf("%s %d %s %s %s\n",L.data[i],L.data[i].sex,
  L.data[i].mobphone,L.data[i].homephone,L.data[i].email);
  	printf("\n");
	
}	
int main(int argc, char *argv[]) {
SeqList L;
int i,n=2,m;
DataType x;
DataType a[]={ {"�׽�",0,"1301","8501","baijie.com"},
{"�¸�",1,"1302","8502","chenggang.com"}};
  char name[8];
  CreateList(&L,a,n);

  PrintList(L);
  printf("���������λ��:");
  scanf("%d",&i);
  printf("����������ϵ��������");
  scanf("%s",x.name);
  printf("����������ϵ���Ա�,�У�1,Ů:0:");
  scanf("%d",&x.sex);
  printf("����������ϵ���ֻ�����:");
  scanf("%s",x.mobphone);
  printf("����������ϵ��סլ���룺");
  scanf("%s",x.homephone);
  printf("�������½���ϵ�����䣺");
  scanf("%s",x.email);
  InsertList(&L,x,i);
  printf("ͨѶ¼:\n");
  PrintList(L);
  printf("������Ҫɾ������ϵ������:");
  scanf("%s",name);
  m=LocateList(L,name);
  DeleteList(&L,m); 
  printf("ͨѶ¼:\n");
  PrintList(L);
}
