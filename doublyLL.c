#include<stdio.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head=NULL;
struct node *temp=NULL;  
int main(){
    while (1)
    {
        
        printf("choose one option from the followin list\n1)Insert At Front\n2)Insert at Specific Location\n3)Insert At Last\n4)Delete from Beginning\n5)Delete Specific\n6)Delete From Last\n7)Display\n8)Search ");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter data : ");
            int data ;
            scanf("%d",&data);
            insertAtBegin(head,data,temp);
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
            case 6:
            break;
            case 7:
            display(head,temp);
            break;
            case 8:
            break;
            default:
                    printf("Invalid Choice");
        }
    }
}



void createDLL(struct node *head,int data,struct node *temp){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    if(ptr==NULL)
    {
        printf("Memory Overflow.....");
    }else{
    ptr->data=data;
    ptr->next=NULL;
    ptr->prev=NULL;
    printf("List created Successfully...");
       
    printf("\n printing values...\n");  

    temp = head;  
    while(temp!= NULL)  
    {  
        printf("%d\n",temp->data);  
        temp=temp->next;  
    }  
    }
    
}

void insertAtBegin(struct node *head,int data, struct node *temp){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    if(ptr==NULL)
    {
        printf("Memory Overflow.....");
    }else{
        if(head==NULL){
            printf("Head is Empty");
            printf("\nYou want create list with this element\n1)Yes\n2)No\nEnter your choice here:");

            int ch1;
            scanf("%d",&ch1);
            switch(ch1){
                case 1:
                    createDLL(head,data,temp);
                break;
                case 2:
                break;
                default:
                printf("Invalid Choice");
            }

        }else{
            ptr->data=data;
            ptr->next=head;
            head->prev=ptr;
            head=ptr;
        printf("Element inserted Successfully at the beginning...");
         struct node *temp;  
    printf("\n printing values...\n");  
    temp = head;  
    while(temp != NULL)  
    {  
        printf("%d\n",temp->data);  
        temp=temp->next;  
    }  

        }
    }
}

void display(struct node *head,struct node *temp){
    struct node *ptr;  
    printf("\n printing values...\n");  
    ptr = head;  
    while(ptr != NULL)  
    {  
        printf("%d\n",ptr->data);  
        ptr=ptr->next;  
    }  
    
}