#include<stdio.h>
void main(){
    int ptime[20],psize[20];
    int bucket_size,time_interval,out_rate,num_packets;
    int interval,filled=0,free_space=0;
    printf("\nEnter the bucket size : ");
    scanf("%d",&bucket_size);
    printf("Enter the outrate : ");
    scanf("%d",&out_rate);
    printf("Enter the time interval : ");
    scanf("%d",&time_interval);
    printf("Enter the number of packets : ");
    scanf("%d",&num_packets);

    for(int i=0;i<num_packets;i++)
    {
        printf("\nEnter the Time and Size of Process %d :",i+1);
        scanf("%d%d",&ptime[i],&psize[i]);
    }
    interval=time_interval;
    printf("\nOperation\tTime \tFilled \tFree-Space");
    printf("\n------------------------------------------");
    for(int i=0;i<num_packets;i++)
    {
        while(ptime[i]>=interval)
        {
            filled=filled-out_rate;
            if(filled<0)filled=0;
            free_space=bucket_size-filled;
            printf("\nDeletion\t%d\t%d\t%d",interval,filled,free_space);
            if(interval>ptime[i])
                break;
            else
                interval=interval+time_interval;
        }
        if((filled+psize[i])>bucket_size)
        {
            printf("\nInsertion\t%d\tOverflow",ptime[i]);
        }
        else
        {
            filled=filled+psize[i];
            free_space=bucket_size-filled;
            printf("\nInsertion\t%d\t%d\t%d",ptime[i],filled,free_space);
        }
    }
    while(filled!=0)
    {
        filled=filled-out_rate;
        if(filled<0)filled=0;
        free_space=bucket_size-filled;
        printf("\nDeletion\t%d\t%d\t%d",interval,filled,free_space);
    }
}
