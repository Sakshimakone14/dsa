#include<stdio.h>
#include<stdlib.h>
  struct node
   {
      struct node *next,*prev;
      int data;
   };
 struct node *create(struct node *head)
   {
         struct node *temp,*newnode;
          int n,i;
          printf("Enter limit= ");
            scanf("%d",&n);
         printf("Enter value= ");
           for(i=0;i<n;i++)
             {
               newnode=(struct node *)malloc(sizeof(struct node));
                scanf("%d",&newnode->data);
                newnode->next=NULL;
          if(head==NULL)
            {
                temp=head=newnode;
            }     
       else
           {
                  temp->next=newnode;
                  newnode->prev=temp;
                  temp=newnode;
           }
           }
           return head;
   }
   void disp(struct node *head) 
   {
    struct node *temp = head;
    while (temp != NULL) 
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
  struct node *insertbeg(struct node *head,int num)
    {
       struct node *newnode;
       newnode=(struct node *)malloc(sizeof(struct node));
       newnode->data=num;
       newnode->next=head;
       head->prev=newnode;
       head=newnode;
       return head;
    }
 struct node *insertmid(struct node *head,int num,int pos)
   {
        struct node *temp,*newnode;
        int i;
       newnode=(struct node *)malloc(sizeof(struct node));
       newnode->data=num;
       for(i=1,temp=head;temp->next!=NULL && i<(pos-1);i++,temp=temp->next);
       newnode->next=temp->next;
       temp->next->prev=newnode;
       temp->next=newnode;
       newnode->prev=temp;
       return head;
   }
 struct node *insertend(struct node *head,int num)
   {
      struct node *temp,*newnode;
       newnode=(struct node *)malloc(sizeof(struct node));
       newnode->data=num;
       for(temp=head;temp!=NULL;temp=temp->next);
       temp->next=newnode;
       newnode->prev=temp;
       return head; 
   }
  struct node *deletebeg(struct node *head)
    {
       struct node *temp,*newnode;
           temp=head;
           head=head->next;
           free(temp);
           return head;
    }
   struct node *deletemid(struct node *head,int pos)
     {
         struct node *temp,*temp1;
         int i;
         for(i=1,temp=head;temp!=NULL && i<(pos-1);i++,temp=temp->next);
         temp1=temp->next;
         temp->next=temp1->next;
         temp1->next->prev=temp;
         free(temp1);
         return head;
     }
     struct node *deleteend(struct node *head)
      {
          struct node *temp,*temp1;
          for(temp=head;temp->next!=NULL;temp=temp->next);
            temp1=temp->next;
            temp->next->prev=NULL;
            free(temp1);
            return head;
      }          
 int main()
   {
           struct node *head=NULL;
           int ch,pos,num;
             do
             {
                  printf("Enter chioce=\n ");
                   printf("1-create \n 2-display \n 3-inserteg \n 4-insertmid \n 5-insertend= \n 6-deletebeg \n 7-deletemid \n 8-deleteend= ");
                    scanf("%d",&ch);
                    switch(ch)
                      {
                             case 1:head=create(head);
                                break;
                             case 2:disp(head);
                                  break;
                            case 3:printf("Enter val to insert at beg= ");
                                               scanf("%d",&num);
                                         head=insertbeg(head,num); 
                                      break; 
                          case 4:printf("Enter val to insert at mid= ");
                                               scanf("%d",&num);
                                        printf("Enter position= ");
                                               scanf("%d",&pos);       
                                         head=insertmid(head,num,pos); 
                                      break;   
                             case 5:printf("Enter val to insert at end= ");
                                               scanf("%d",&num);
                                         head=insertend(head,num); 
                                         break;
                           case 6:head=deletebeg(head);
                                break;
                          case 7:int pos;
                                    printf("Enter position= ");
                                       scanf("%d",&pos);
                                    head=deletemid(head,pos);
                                   break;             
                          case 8:head=deleteend(head);
                                   break;   
                                   default:printf("Invalid chioce.");                 
             }
   }while(ch<9);   
   }  
