#include<stdio.h>
#include<malloc.h>
struct tree
{
	int r;
	struct tree *left;
	struct tree *right;
};
typedef struct tree node;
node* create(int data)
{
	node* n1=(node *)malloc(sizeof(node));
	n1->r=data;
	n1->left=NULL;
	n1->right=NULL;
	return n1;
}
node* insert(node* root,int data)
{
   if(root==NULL)
   {
   	root=create(data);
   }	
   else if(data<root->r)
   {
   	root->left=insert(root->left,data);
   }
   else
   {
   	root->right=insert(root->right,data);
   }
   return root;
}
void inorder(node* root)
{
    if(root==NULL)
	return;
    inorder(root->left);
	printf("%d ",root->r);
    inorder(root->right);
}
void preorder(node* root)
{
    if(root==NULL)
    return;
    
    printf("%d ",root->r);
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root)
{
    if(root==NULL)
	return;
	
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->r);
}
node* serach(node* root,int s)
{
	if(root==NULL || root->r==s)
	{
		return root;
	}		
	if(s<root->r){
	  return serach(root->left,s);}
	else
	{
	  return serach(root->right,s);}
}
node *delet(struct tree *ptr,int v)
{
	 node *p1,*p2;
	  if(!ptr)
	  {
	  	   printf("\nNODE IS NOT FOUND");
	  	   return(ptr);
	  }
	  else if(ptr->r<v)
	  {
	  	 ptr->right=delet(ptr->right,v);
	  	 return(ptr);
	  }
	  else if(ptr->r>v)
	  {
	  	ptr->left=delet(ptr->left,v);
	  	return(ptr);
	  }
	  else 
	  {
	  	    if(ptr->r==v)
	  	    {
	  	    	 if(ptr->left==ptr->right)
	  	    	 {
	  	    	 	  free(ptr);
	  	    	 	  return(NULL);
				 }
				 else if(ptr->left==NULL)
				 {
				 	p1=ptr->right;
				 	free(ptr);
				 	return(p1);
				 }
				 else if(ptr->right==NULL)
				 {
				 	p1=ptr->left;
				 	free(ptr);
				 	return(p1);
				 }  
				 else
				 {
				 	 p1=ptr->right;
				 	 p2=ptr->left;
				 	 if(p1->left!=NULL)
				 	 {
				 	 	p1=p1->left;
				 	 	p1->left=p2;
				 	 	free(ptr);
				 	 	return(p2);
					  }
				 }
			  }
	  }
}
node* update(node *root,int u)
{
	node* ptr;
	ptr=root;
	if(root==NULL || root->r==u)
	  return root;
	  
	if(u<root->r)
	 return update(root->left,u);
	else// if(u>root->r)
	 return update(root->right,u);

	  
}
int main()
{
	node* root=NULL;
	int n,i,data,j,s,d,u;
	printf("enter number of node = ");
	scanf("%d",&j);
	h:
	printf("1.create\n2.print in inorder\n3.print in preorder\n4.print in postorder\n5.Exit\n6.search number\n7.Delet Node\n8.update\nenter number of node = ");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			for(i=1;i<=j;i++)
			{
	            printf("value %d = ",i);
	            scanf("%d",&data);
	            root=insert(root,data);
	         }  
	            goto h;
	    case 2:
	            printf("node in inorder...\n");
                inorder(root);
                printf("\n");
                goto h;
        case 3:
	            printf("node in preorder...\n");
	            preorder(root);
	            printf("\n");
	            goto h;
	    case 4:
	            printf("node in postorder...\n");
  	            postorder(root);
  	            printf("\n");
  	            goto h;
  	    case 6:
  	    	    printf("enter search number :- ");
	            scanf("%d",&s);
  	    	   node* p=serach(root,s);
  	    	    if(p!=NULL)
				{
  	    	      printf("%d is in list..\n",s);
				}
  	    	    else
				{
  	    	      printf("%d is not in list..\n",s);
				}
  	    	    goto h; 
  	    case 5:
  	    	    printf("Exit..");
  	    	    goto y;
  	    case 7:
  	    	    printf("enter value which you have to delete :- ");
  	    	    scanf("%d",&d);
  	    	    root=delet(root,d);
  	            goto h;
  	    case 8:
  	    	   printf("enter value which you have to update :- ");
  	    	   scanf("%d",&u);
  	    	   node *l=update(root,u);
  	    	   if(u==l->r)
  	    	     {
  	    	     	 printf("enter new value :- ");
  	    	     	 scanf("%d",&l->r);
				 }
			   goto h;
    }
        y:
	return 0;
}
