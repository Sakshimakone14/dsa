#include<stdio.h>
#include<stdlib.h>
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
                    newnode->next=head;
             if(head==NULL)
               {
                       temp=head=newnode;
               }
             else
               {
                  temp->next=newnode;
                  temp=newnode;
                  newnode->next=head;
               }  
            }
         return head;       
   }
void disp(struct node *head)
  {
          struct node *temp=head;
            do
             {
                        printf("%d\t",temp->data);
                        temp=temp->next;
             }while(temp!=head);
  } 
struct node *search(struct node *head)
  {
      struct node *temp;
      int key,f=0;
      printf("Enter key to search= ");
         scanf("%d",&key); 
      for(temp=head;temp->next!=NULL;temp=temp->next)
        {
               if(temp->data==key)
                {
                         f=1;
                         break;
                }
        }
    if(f==1)
      {
            printf("Key found");
      }
   else
     {
          printf("key not found");
     }       
  }
  struct node *insertbeg(struct node *head,int val)
   {
       struct node *temp,*newnode;
       newnode=(struct node *)malloc(sizeof(struct node));
       newnode->data=val;
       for(temp=head;temp->next!=head;temp=temp->next);
       newnode->next=head->next;
       head->next=newnode;
       return head;
   }
  struct node *insertmid(struct node *head,int val,int pos)
    {
       struct node *temp,*newnode;
       int i;
       newnode=(struct node *)malloc(sizeof(struct node));
       newnode->data=val;
       for(i=1,temp=head;(temp!=NULL) && (i<pos-1);i++,temp=temp->next);
       newnode->next=temp->next;
       temp->next=newnode;
       return head;
    } 
   struct node *insertend(struct node *head,int val)
    {
       struct node *temp,*newnode;
       newnode=(struct node *)malloc(sizeof(struct node));
       newnode->data=val;
       for(temp=head;temp->next!=head;temp=temp->next);
       temp->next=newnode;
     newnode->next=head;  
        return head;  
    }
  struct node *delbeg(struct node *head)
   {
          struct node *temp;
           for(temp=head;temp->next!=head;temp=temp->next);
           temp=head->next;
           head->next=temp->next;
           free(temp);
           return head; 
   }
 struct node *delmid(struct node *head,int pos)
   {
          struct node *temp,*temp1;
          int i;
           for(i=1,temp=head;(temp!=NULL) && (i<pos-1);i++,temp=temp->next);
           temp1=temp->next;
           temp->next=temp1->next;
           free(temp1);
           return head;
   }
 struct node *delend(struct node *head)
   {
          struct node *temp,*temp1;
          for(temp=head;temp->next->next!=head;temp=temp->next);
          temp1=temp->next;
          temp->next=head;
          free(temp1);
           return head;
   }       
  int main()
 {
             struct node *head=NULL;
             int ch,val,pos;
             do
              {
                    printf("Enter your chioce= 1-create \n 2-disp \n 3-search \n 4-insertstart \n 5-insertmid \n 6-insertend \n 7-delbeg\n ");
                    printf("8-delmid \n 9-delend== ");
                       scanf("%d",&ch);
                    switch(ch) 
                       {
                                 case 1:head=create(head);
                                            break;
                                case 2:disp(head);
                                            break;
                                case 3:search(head);   
                                            break; 
                               case 4:printf("Enter a value to insert= ");
                                             scanf("%d",&val);  
                                head=insertbeg(head,val); 
                                break; 
                            case 5: printf("Enter a value to insert= ");
                                             scanf("%d",&val); 
                                         printf("Enter position= ");
                                            scanf("%d",&pos);
                                            head=insertmid(head,val,pos);       
                                           break;  
                            case 6:printf("Enter a value to insert= ");
                                             scanf("%d",&val);  
                                          head=insertend(head,val); 
                                            break;  
                             case 7:head=delbeg(head); 
                                            break;
                              case 8:printf("Enter pos= ");
                                             scanf("%d",&pos);
                                            head=delmid(head,pos);  
                                            break;
                              case 9:head=delend(head); 
                                            break;                                                                         
                       }  
              }while(ch<10);
 }        
