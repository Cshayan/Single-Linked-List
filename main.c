#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*start=NULL;
void insertEnd(int val)
{
    struct node *temp,*curr;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        curr=start;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=temp;
    }
    printf("\nValue Inserted Successfully!!\n");
}
void insertBeg(int val)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=start;
    start=temp;
    printf("\nValue Inserted Successfully!!\n");
}

void insertPosition(int val,int pos)
{
    struct node *temp,*curr;
    curr=start;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    if(pos==1)
    {
        temp->next=start;
        start=temp;
        printf("\nValue Inserted Successfully!!\n");
        return;
    }
    while(pos-1>1&&curr!=NULL)
    {
        curr=curr->next;
        pos--;
    }
    if(curr==NULL)
    {
        printf("\nPosition is outside the list");
        return;
    }
    temp->next=curr->next;
    curr->next=temp;
    printf("\nValue Inserted Successfully!!\n");
}
int length()
{
    struct node *curr=start;
    int cnt=0;
    while(curr!=NULL)
        {
            cnt++;
            curr=curr->next;
        }

    return cnt;
}

void display()
{
  struct node *curr=start;
  if(start==NULL)
  {
      printf("\nList is Empty!!\n");
      return;
  }
  printf("\nThe linked list is :-\n");
  while(curr!=NULL)
  {
      printf("%d\t",curr->data);
      curr=curr->next;
  }
  printf("\n\n");
}
void delBeg()
{
    struct node *curr=start;
    if(curr==NULL)
    {
        printf("\nlist is empty!!\n");
        return;
    }
    start=start->next;
    free(curr);
    printf("\nValue Deleted successfully!!\n");
}
void delEnd()
{
    struct node *curr=start;
    struct node *prev;
    if(start==NULL)
  {
      printf("\nList is Empty!!\n");
      return;
  }
  if(curr->next==NULL)
  {
      start=NULL;
      free(curr);
      printf("\nValue Deleted successfully!!\n");
      return;
  }
    while(curr->next!=NULL)
    {
        prev=curr;
        curr=curr->next;
    }
    prev->next=NULL;
    free(curr);
    printf("\nValue Deleted successfully!!\n");
}
void delPosition(int pos)
{
    struct node *curr=start;
    struct node *temp;
    if(curr==NULL)
    {
        printf("\nNo Element Exists\n");
        return;
    }
    if(pos==1)
    {
        start=start->next;
        free(curr);
        printf("\nValue deleted Successfully!!\n");
        return;
    }
    if(pos==length()+1)
    {
        printf("\nPosition is outside the list\n");
        return;
    }
    while((pos-1>1) && (curr!=NULL))
    {
        curr=curr->next;
        pos--;
    }
    if(curr==NULL)
    {
        printf("\nPosition is outside the list\n");
        return;
    }
    temp=curr->next;
    curr->next=temp->next;
    free(temp);
    printf("\nValue deleted Successfully!!\n");
}
void reverse()
{
    struct node *curr=start, *sprev=NULL, *prev=NULL;
    while(curr!=NULL)
    {
        sprev=prev;
        prev=curr;
        curr=curr->next;
        prev->next=sprev;
    }
    start=prev;
    printf("\nReversing of the list done!!\n");
}
void reverseFake(struct node *start1)
{
    struct node *curr=start1;
    if(curr==NULL)
        return;
    reverseFake(curr->next);
    printf("%d\t",curr->data);
}
int main()
{
    int val, ch, pos;
    while(1)
    {
        printf("\n1.Insert at the end");
        printf("\n2.Display");
        printf("\n3.Insert at the beginning");
        printf("\n4.Insert at particular position:- ");
        printf("\n5.Delete Beginning");
        printf("\n6.Delete End");
        printf("\n7.Delete Position");
        printf("\n8.Reverse List");
        printf("\n9.Reverse Fake");
        printf("\n10.Exit");
        printf("\nEnter your choice:- ");
        scanf("%d",&ch);

           switch(ch)
           {
           case 1:
            printf("\nEnter the value to enter at the end:- ");
            scanf("%d",&val);
            insertEnd(val);
            break;
           case 2:
            display();
            break;
           case 3:
            printf("\nEnter the value to enter at the beginning:- ");
            scanf("%d",&val);
            insertBeg(val);
            break;
           case 4:
            printf("\nEnter the value:- ");
            scanf("%d",&val);
            printf("\nEnter the position:- ");
            scanf("%d",&pos);
            insertPosition(val,pos);
            break;
           case 5:
            delBeg();
            break;
            case 6:
            delEnd();
            break;
            case 7:
                printf("Enter the position to delete:- ");
                scanf("%d",&pos);
                delPosition(pos);
                break;
            case 8:
                reverse();
                break;
            case 9:
                reverseFake(start);
                break;
           case 10:
            exit(0);
           }
    }
    return 0;
}
