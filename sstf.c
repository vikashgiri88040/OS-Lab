#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,head,i,j,min,pos;
    int visited[100]={0};
    printf("Enter no of request:");
    scanf("%d",&n);
    int req[n];
    printf("Enter request queue:");
    for(i=0;i<n;i++)
        scanf("%d",&head);
    int seek=0;
    for(i=0;i<n;i++){
        min=9999;
    for(j=0;j<n;j++){
        if(!visited[j]&& abs(head-req[j])< min){
            min=abs(head-req[j]);
            pos=j;
        }
    }
    visited[pos]=1;
    seek +=abs(head-req[pos]);
    head=req[pos];
    }
    printf("Total seek time=%d\n",seek);
    return 0;
}
