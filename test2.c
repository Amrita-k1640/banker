#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<pthread.h>
const int a=5;
const int b=3;
int k;
pthread_mutex_t l;
void calneed(int need[a][b],int maxi[a][b],int allot[a][b])
{
	pthread_mutex_lock(&l);
	int i,j;
for(i=0;i<a;i++)
for(j=0;j<b;j++)
need[i][j]=maxi[i][j]-allot[i][j];
pthread_mutex_unlock(&l);
}
bool safe(int process[],int availbility[],int maxi[][b],int allot[][b])
{
	pthread_mutex_lock(&l);
int need[a][b];
calneed(need,maxi,allot);
bool finish[a]={0};
int safesequence[a];
int workdone[b];
for(i=0;i<b;i++)
workdone[i]=avail[i];
int count=0;
while(count<a)
{
bool found=false;
for(a=0;a<a1;a++)
{
if(finish[a]==0)
{
int j;
for(j=0;j<b;j++)
if(need[a][j]>workdone[j])
break;
if(j==b)
{
for(k=0;k<b;k++)
workdone[k]=workdone[k]+allot[a][k];
safesequence[count++]=a;
finish[a]=1;
found=true;

}
}
}
if(found==false)
{
printf("system is  not in the safe state");
return false;
}
}
printf("system is in safe state.\n safe sequence is/;");
for(int i=0;i<a;i++)
printf("%d\n",safesequence[i]);
return true;
pthread_mutex_unlock(&l);
}
int main()
{
pthread_t th1,th2;
printf("in main thread\n");
pthread_mutex_init(&l,NULL);
pthread_create(&th1,NULL,fun1,NULL);
pthread_create(&th2,NULL,fun2,NULL);
pthread_join(th1,NULL);
pthread_join(th2,NULL);
int processes[10]={0,1,2,3,4};
int avail[10]={10,10,5};
int maxi[10][b]={{1,2,3},{4,5,6},{6,7,8},{1,4,6},{3,7,9}};
int allot[10][b]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
safe(processes,avail,maxi,allot);
return 0;
}


