#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *head=NULL;
void create()
{
       struct node *temp,*ptr;
       int data;
       printf("enter -1 to exit\n");
       printf("enter data\n");
       scanf("%d",&data);
       while(data!=-1)
       {
       ptr=(struct node *)malloc(sizeof(struct node ));
       ptr->data=data;
       ptr->next=NULL;
       if(head==NULL)
       {
              head=ptr;
              ptr->next=head;
       }
       else
       {
              temp=head;
              while(temp->next!=head)
              {
                     temp=temp->next;
              }
              temp->next=ptr;
              ptr->next=head;
       }
       printf("enter -1 to exit\n");
       printf("enter data\n");
       scanf("%d",&data);

       }
}

void display()
{
       struct node *temp;
       temp=head;
       if(head==NULL)
       {
              printf("head is empty");
       }
       else
{
       temp=head;
       while (temp->next!=head)
       {
              printf("data->%d\n",temp->data);
              temp=temp->next;
       }
       printf("data->%d\n",temp->data);


}

}
void insert_beg()
{
       int data;
       struct node *temp,*new_node;
       printf("enter data you want to insert at beginning");
       scanf("%d",&data);
       new_node=(struct node *)malloc(sizeof(struct node));
       new_node->data=data;
       temp=head;
       while(temp->next!=head)
       {
              temp=temp->next;
       }
       new_node->next=head;
       temp->next=new_node;
       head=new_node;
       printf("data is inserted successfully");
}
void insert_end()
{
       int data;
       struct node *temp,*new_node;
       printf("enter data\n");
       scanf("%d",&data);
       new_node=(struct node *)malloc(sizeof(struct node));
       new_node->data=data;
       new_node->next=head;
       temp=head;
       while(temp->next!=head)
       {
              temp=temp->next;
       }
       temp->next=new_node;
       printf("new data is inserted at end succesfully \n");

}
void insert_pos()
{
       int pos,data,i;
       struct node *temp,*pretemp,*new_node;
       printf("enter data to insert");
       scanf("%d",&data);
       new_node=(struct node *)malloc(sizeof(struct node));
       new_node->data=data;
       printf("enter position to insert data");
       scanf("%d",&pos);
       if(pos==1)
       {
              insert_beg();
       }
       else
       {
              temp=head;
              pretemp=temp;
              for(i=2;i<=pos;i++)
              {
                     pretemp=temp;
                     temp=temp->next;
              }

              new_node->next=temp;
              pretemp->next=new_node;
              printf("data is inserted\n");
       }


}
void delete_beg()
{
       struct node*temp;
       temp=head;
       if(head==NULL)
       {
              printf("UNDERFLOW");
       }
       else
              {
                     temp=head;
                      while(temp->next!=head)
                      {
                             temp=temp->next;
                      }
                      temp->next=head->next;
                      free(head);
                      head=temp->next;
                      printf("data is deleted successfully\n");
              }
}
void delete_end()
{
       struct node *temp,*pretemp;
       temp=head;
       pretemp=temp;
       if(head==NULL)
       {
              printf("underflow");
       }
       else
              {
                     temp=head;
                     pretemp=temp;
                     while(temp->next!=head)
                     {
                            pretemp=temp;
                            temp=temp->next;
                     }
                     pretemp->next=head;
                     free(temp);
                     printf("data is deleted successfully");

              }
}
void delete_pos()
{
       struct node*temp,*pretemp;
       int pos,count=0,i;
       printf("enter position to delete");
       scanf("%d",&pos);
       if(pos==1)
       {
              delete_beg();

       }
       else
       {
              temp=head;
              pretemp=temp;
              for(i=2;i<=pos;i++)
              {
                     pretemp=temp;
                     temp=temp->next;
              }
              pretemp->next=temp->next;
              free(temp);
              printf("data is deleted successfully");
       }
}

void invalid_choice()
{
       printf("invalid choice");

}

int main()
{
       int option;
       do
       {
              printf("main menu\n");
              printf("1.create\n");
              printf("2.display\n3.insert_beg\n4. insert_end\n 5.insert_aft \n6.delete beg\n7.delete_end\n8.delete any  position \n9.invalid choice\n");
              printf("enter option\n");
              scanf("%d",&option);
              switch (option)
              {
              case 1:
                     create();
                     break;
              case 2:

                     display();
                     break;
              case 3:
                     insert_beg();
                     break;
              case 4:
                    insert_end();
                    break;
              case 5:
                     insert_pos();
                    break;
              case 6:
                     delete_beg();
                     break;
               case 7:
                     delete_end();
                     break;
              case 8:
                     delete_pos();
                     break;
              case 9:
                     invalid_choice();
                     break;

              }
       }while(option!=9);
       return 0;
}
