#include<stdio.h>
#include<stdlib.h>

typedef struct nodeTree{
int num;
struct nodeTree *left, *right ;
} nodeTree;


void Insert (nodeTree **pp , int num)
{
if (! *pp)
{
*pp= (nodeTree *) malloc (sizeof (nodeTree ));
(*pp)->num = num;
(*pp)->left = NULL;
(*pp)->right = NULL;
}
 else
if (num <(*pp)->num)
{
Insert ( &((*pp)->left) , num);
}
else  if (num > (*pp)->num)
{
Insert ( & ((*pp)->right), num);
}
else if(num == (*pp)->num)
    { printf("Repeated numbers cannot be inserted\n"); }
}

void  Inorder (nodeTree * p)
{
if (p)
{
Inorder (p->left);
printf (" %d", p->num);
Inorder (p->right);
}
}

void  preOrder (nodeTree * p)
{
if (p)
{
printf ( " %d", p->num);
preOrder (p->left);
preOrder (p->right);
} }

void  postOrder ( nodeTree * p)
{
if (p)
{
postOrder (p->left);
postOrder (p->right);
printf ( " %d", p->num);
}}

int nodesAccount(nodeTree *p)
{
if(p){
    return(1+nodesAccount(p->left)+nodesAccount(p->right));
}else return 0; }

int destroyNumber (nodeTree *p, int num)
{
if (p)
{
if (p->num == num)
{ free(p);
return 1;
}
else
if (num < p->num)
return (destroyNumber (p->left, num) );
else

return(destroyNumber (p->right,num));
}
else   return 0;
}

int minNumber(nodeTree *p)
{
  while(p->left!=NULL)
{ p=p->left; }
printf("\n- Lower number: %d\n", *p);
}

void maxNumber(nodeTree *p)
{ while(p->right!=NULL)
{
    p=p->right; }
    printf("\n- Maximun num: %d\n", *p);
}

void destroyTree(nodeTree *p)
{ if(p){
    destroyTree(p->left);
    destroyTree(p->right);
    free(p); } }


void Root(nodeTree *p)
{  if(p){
    printf("\n- Root: %d\n", *p);
}}



int main()
{ int num, Search, auxNum, Exists, Option, auxCount;
nodeTree *nodo=NULL, *aux=NULL;
printf("- Sign in a number (exit 0): ");
scanf("%d",&num);
while(num!=0)
{
Insert(&nodo,num);
printf("- Sign in a number (exit 0): ");
scanf("%d",&num);
}

printf("Options: \n     0: EXIT\n     1: Delete number\n     2: Search maximum\n     3: Search minimum\n     4: Destroy tree \n     5: See root\n     6: Pre-order\n     7: Post-order\n     8: In-order\n     9: Total numer of nodes\n     10: Ask for options again\n");
printf("\nOption: ");scanf("%d", &Option);
while (Option!=0)
{
switch(Option)
{
    case 1: printf("\n- Number to be deleted: "); scanf("%d",&auxNum);
Exists=destroyNumber(nodo, auxNum);
if(Exists==1)
printf("- The number searched (%d) exists and it was correctly deleted-\n",auxNum);
else
printf ("- The searched number (%d) does not exists-\n",auxNum); break;

    case 2: maxNumber(nodo); break;
    case 3: minNumber(nodo); break;
    case 4: destroyTree(nodo); return 0; break;
    case 5: Root(nodo);break;
    case 6: preOrder(nodo);break;
    case 7: postOrder(nodo);break;
    case 8: Inorder(nodo); break;
    case 9: auxCount=nodesAccount(nodo);
    printf("\n- Total number of nodes: %d\n",auxCount); break;
    case 10: printf("Options: \n     0: EXIT\n     1: Delete number\n     2: Search maximum\n     3: Search minimum\n     4: Destroy tree \n     5: See root\n     6: Pre-order\n     7: Post-order\n     8: In-order\n     9: Total numer of nodes\n     10: Ask for options again\n"); break;
    default: printf("\nTHAT OPTION DOES NOT EXISTS");
}
printf("\nChoose an option (10: Ask for options again): ");
scanf("%d", &Option);
}
}

