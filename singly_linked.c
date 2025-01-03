#include<stdio.h>
#include <stdlib.h>
  struct node 
   {
         int data;
         struct node *next;
   };
  struct node *create(struct node *head)
   {
          struct node *temp,*newnode;
          int i,n;
          printf("Enter limit= ");
           scanf("%d",&n);
         printf("Enter value= ");
           for(i=0;i<n;i++)
            {
          newnode=(struct node *)malloc(sizeof(struct node));  
                  scanf("%d",&newnode->data);
         if(head==NULL)
          {
                 temp=head=newnode;
          }
       else
          {
                     temp->next=newnode;
                     temp=newnode;
          }
        }
        return head;           
   }
  void disp(struct node *head)
   {
           struct node *temp;
           for(temp=head;temp!=NULL;temp=temp->next)
            {
                     printf("%d\n",temp->data);
            }
   }
 struct node *insertbeg(struct node *head,int val)
  {
         struct node *newnode,*temp;
         newnode=(struct node *)malloc (sizeof(struct node));
         newnode->data=val;
            newnode->next=head;
            head=newnode;
            return head;  
  }
struct node *insertmid(struct node *head,int val,int pos) 
 {
      struct node *temp,*newnode;
      int i;
         newnode=(struct node *)malloc (sizeof(struct node));
         newnode->data=val;
         for(temp=head,i=1;temp->next!=NULL && i<(pos-1);temp=temp->next,i++);
         newnode->next=temp->next;
         temp->next=newnode;
         temp=newnode;
         return head;               
 } 
struct node *insertend(struct node *head,int val)
 {
      struct node *temp,*newnode;
         newnode=(struct node *)malloc (sizeof(struct node));
         newnode->data=val;
         for(temp=head;temp->next!=NULL;temp=temp->next);
         temp->next=newnode;
         temp=newnode;
         return head;      
 } 
struct node *delbeg(struct node *head)
 {
      struct node *temp;
      temp=head;
      head=head->next;
      free(temp);
      return head;
 }
struct node *delmid(struct node *head,int pos) 
 {
      struct node *temp,*temp1;
      int i;
         for(temp=head,i=1;temp->next!=NULL && i<(pos-1);temp=temp->next,i++);   
         temp1=temp->next;
         temp->next=temp1->next;
         free(temp1);
         return head;
 } 
struct node *delend(struct node *head)
 {
      struct node *temp,*temp1;
         for(temp=head;temp->next!=NULL;temp=temp->next);
           temp1=temp->next;
           temp->next=NULL;
           free(temp1);
           return head; 
 }          
 int main()
  {
          struct node *head=NULL;
          int i,ch,val,pos;
          do
           {
                     printf("Enter chioce= 1-create \n 2-disp \n 3-insertbeg \n 4- insertmid \n 5-insert last=");
                      printf("6-delete beg \n 7-delmid \n 8-delend \n 9-invalid= ");
                      scanf("%d",&ch);
                    switch(ch)
                     {
                             case 1:head=create(head);
                                  break;
                            case 2:printf("Singly linked list= ");
                                       disp(head);
                                 break; 
                            case 3:printf("Enter val to insert first= ");
                                          scanf("%d",&val); 
                                        head=insertbeg(head,val); 
                                    break;    
                           case 4:printf("Enter val to insert middle= ");
                                          scanf("%d",&val);
                                      printf("Enter position= ");
                                          scanf("%d",&pos);      
                                        head=insertmid(head,val,pos);
                                        break;
                            case 5:printf("Enter val to insert last= ");
                                          scanf("%d",&val); 
                                        head=insertend(head,val); 
                                       break;   
                             case 6:head=delbeg(head);
                                      printf("Delete succ");
                                  break; 
                             case 7:printf("Enter position= ");
                                          scanf("%d",&pos);   
                                       head=delmid(head,pos);                                     
                                      printf("Delete succ");
                                  break; 
                             case 8:head=delend(head);                                  
                                       printf("Delete succ");                           
                                    break;
                           default:printf("Invalid chioce");          
                     }  
           }while(ch<9);
  }     
