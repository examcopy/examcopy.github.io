#include<stdio.h>
#include<math.h>
#include<string.h>
struct packet{
char msg[100];
int seqno;
float time;
}p[100],temp;
void quicksort(struct packet p[10], int first, int last);
void main(){
int n,i,j,c;
printf("\nNo of packets : ");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("\nEnter the message : ");
scanf("%s",p[i].msg);
do{
c=0;
p[i].seqno=rand()%99;
for(j=0;j<i;j++){
if(p[i].seqno==p[j].seqno)
c++;
}
printf("\nSequence no : %d",p[i].seqno);
}while(c>0);
p[i].time=rand()%2;
printf("\nTime : %4.2f\n",p[i].time);
}
quicksort(p,0,n-1);
printf("\n\n -------- After Sorting ----------");
for(i=n-1;i>=0;i--){
printf("\n Message : %s",p[i].msg);
printf("\n Sequence Number : %d",p[i].seqno);
printf("\n Time : %4.2f\n",p[i].time);
}
}
void quicksort(struct packet p[10],int first, int last){
if(first<last){
int pivot = first;
int i = first;
int j = last;
while(i<j){
while(p[i].seqno<p[pivot].seqno && i<last)
i++;
while(p[j].seqno<p[pivot].seqno )
j--;
if(i<j){
temp = p[j];
p[j]=p[i];
p[i]=temp;
}
}
temp=p[pivot];
p[pivot]=p[j];
p[j]=temp;
quicksort(p,first,j-1);
quicksort(p,j+1,last);
}
}
