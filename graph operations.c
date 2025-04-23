#include<stdio.h>
#include<conio.h>
#define max 100
int n_ver=0;
int a[max][max];
void addvertices(int count)
{
int i;
 if(n_ver+count > max)
 printf("canot hold more than 100 value\n");
 else
 {
 for(i=0;i<=count-1;i++)
 {
 n_ver++;
 printf("%d is successfully add ..\n",n_ver-1);
 }
 }
}
void addedge(int src, int dest)
{
  if(src >= n_ver || dest >= n_ver || src < 0 || dest < 0)
  printf("positions is not stand..\n");
  else
  {
   a[src][dest]=1;
   a[dest][src]=1;
  }
}
void removeedge(int src,int dest)
{
 if(src >= n_ver || dest >= n_ver || src < 0 || dest < 0)
  printf("positions is not stand..\n");
  else
  {
   a[src][dest]=0;
   a[dest][src]=0;
  }
}
void removevertices(int count)
{
 int i,j;
 if(count >= n_ver || count<0)
  printf("invelid number.. \n");
  else
  {
   a[i][j]=a[i+1][j];
   a[j][i]=a[j][i+1];
  }
  n_ver--;
  printf("%d is removed form array...\n",count);
}
void dis()
{
 int i,j;
 if(n_ver==0)
 {
  printf("graph is MT..\n");
  //return;
 }
 else
 {
  for(i=0;i<n_ver;i++)
  {
   for(j=0;j<n_ver;j++)
   {
    printf("%d ",a[i][j]);
   }
   printf("\n");
  }
 }
}
void main()
{
   int choice,v,src,dest,re;
   printf("1.add vertices\n2.remove verticse\n3.add edges\n4.remove edgs\n5.display\nenter your choice:- ");
   scanf("%d",&choice);
   while(1)
   {
    switch(choice)
    {
    case 1:
    printf("enter vertices you have to add :-");
    scanf("%d",&v);
    addvertices(v);
    main();
    break;
    case 2:
    printf("enter vertices you have to remove :-");
    scanf("%d",&v);
    removevertices(v);
    main();
    break;
    case 3:
    printf("enter source and destination which you have to add = ");
    scanf("%d %d",&src,&dest);
    addedge(src,dest);
    main();
    break;
    case 4:
    printf("enter source and destination which you have to remove = ");
    scanf("%d %d",&src,&dest);
    removeedge(src,dest);
    main();
    break;
    case 5:
    printf("display value \n");
    dis();
    main();
    break;
    }
   }
   getch();
}