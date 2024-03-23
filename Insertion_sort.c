#include<stdio.h>
void main(){
    int i,j,s,a[30],temp;
    printf("Enter size:");
    scanf("%d",&s);
    printf("Enter elements:");
    for (i=0;i<s;i++){
        scanf("%d",&a[i]);
    }
    printf("Unsorted array:");
    for (i=0;i<s;i++){
        printf("%d\t",a[i]);
    }
    for (j=0;j<s;j++){
       temp=a[j];
       i=j-1;
       while(i>=0 && a[i]>temp){
        a[i+1]=a[i];
        i--;}
    a[i+1]=temp;}
    printf("Sorted array:");
    for (i=0;i<s;i++){
        printf("%d\t",a[i]);
    }
}