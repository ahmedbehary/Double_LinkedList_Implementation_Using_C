#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"
listNode *head = NULL;
uint32 length = 0;
int main()
{
    Insert_AtBegining(&head, 11);
    Insert_AtBegining(&head, 22);
    Insert_AtTail(&head, 88);
    Insert_AtBegining(&head, 33);
    Display_List(head);
    length = List_Length(head);
    printf("%i\n", length);
    Insert_AtTail(&head, 55);
    Display_List(head);
    length = List_Length(head);
    printf("%i\n", length);
    Insert_After(head, 99);
    Display_List(head);
    Insert_After(head, 77);
    Display_List(head);
    length = List_Length(head);
    printf("%i\n", length);
    Delete_AtBegining(&head);
    Display_List(head);
    length = List_Length(head);
    printf("%i\n", length);
    Delete_Node(head);
    Display_List(head);
    // Inverse_List(&head);
    // Display_List(head);
    Insert_Before(&head,66);
    Display_List(head);
    Delete_AtBegining(&head);
    Display_List(head);


    return 0;
}

uint8 List_Length(listNode *headNode)
{
    uint32 countNum = 0;
    listNode *temp = headNode;
    while (temp != NULL)
    {
        countNum++;
        temp = temp->nodeNext;
    }
    return countNum;
}
void Display_List(listNode *headNode)
{
    listNode *temp = headNode;
    if (temp == NULL)
    {
        printf("Empty List!\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%i\t", temp->nodeData);
            temp = temp->nodeNext;
        }
        printf("\n");
    }
}
void Insert_AtBegining(listNode **headNode, uint32 data)
{
    listNode *temp = NULL;
    listNode *count = NULL;
    temp = (listNode *)malloc(sizeof(listNode));
    if (temp != NULL)
    {
        temp->nodeData = data;
        if (*headNode == NULL)
        {
            temp->nodeNext = NULL;
            temp->nodePrevious = NULL;
            *headNode = temp;
        }
        else
        {
            count = *headNode;
            temp->nodePrevious = NULL;
            temp->nodeNext = count;
            count->nodePrevious = temp;
            *headNode = temp;
        }
    }
    else
    {
        printf("Error! Memory Allocation.\n");
    }
}
void Insert_AtTail(listNode **headNode, uint32 data)
{
    listNode *temp = NULL;
    listNode *count = NULL;
    temp = (listNode *)malloc(sizeof(listNode));
    if (temp != NULL)
    {
        temp->nodeData = data;
        if (*headNode == NULL)
        {
            temp->nodeNext = NULL;
            temp->nodePrevious = NULL;
            *headNode = temp;
        }
        else
        {
            count = *headNode;
            while (count->nodeNext != NULL)
            {
                count = count->nodeNext;
            }
            count->nodeNext = temp;
            temp->nodePrevious = count;
            temp->nodeNext = NULL;
        }
    }
    else
    {
        printf("Error! Memory Allocation.\n");
    }
}
void Insert_After(listNode *headNode, uint32 data)
{
    listNode *temp = NULL;
    listNode *count1 = NULL;
    listNode *count2 = NULL;
    uint32 position = 0;
    uint32 countNum = 1;
    uint32 length = 0;
    length = List_Length(headNode);
    temp = (listNode *)malloc(sizeof(listNode));
    if (temp != NULL)
    {
        printf("Enter position you want to insert after: ");
        scanf("%i", &position);
        if ((position > length) || (position == 0))
        {
            printf("Invalid Position!\n");
        }
        else
        {
            count1 = headNode;
            temp->nodeData = data;
            while (countNum < position)
            {
                countNum++;
                count1 = count1->nodeNext;
            }
            if(count1->nodeNext == NULL){
                count1->nodeNext = temp;
                temp->nodePrevious = count1;
                temp->nodeNext = NULL;
            }
            else{
                count2 = count1->nodeNext;
                temp->nodeNext = count2;
                count2->nodePrevious = temp;
                temp->nodePrevious = count1;
                count1->nodeNext = temp;
            }
        }
    }
    else
    {
        printf("Error! Memory Allocation.\n");
    }
}
void Insert_Before(listNode **headNode, uint32 data){
    listNode *temp = NULL;
    listNode *count1 = NULL;
    listNode *count2 = NULL;
    uint32 position = 0;
    uint32 countNum = 1;
    uint32 length = 0;
    length = List_Length(*headNode);
    temp = (listNode *)malloc(sizeof(listNode));
    if (temp != NULL)
    {
        printf("Enter position you want to insert before: ");
        scanf("%i", &position);
        if ((position > length) || (position == 0))
        {
            printf("Invalid Position!\n");
        }
        else
        {
            count1 = *headNode;
            temp->nodeData = data;
            while (countNum < position)
            {
                countNum++;
                count1 = count1->nodeNext;
            }
            if(count1->nodePrevious == NULL){
                temp->nodeNext = count1;
                temp->nodePrevious = NULL;
                count1->nodePrevious = temp;
                *headNode = temp;
            }
            else{
                count2 = count1->nodePrevious;
                count1->nodePrevious=temp;
                count2->nodeNext = temp;
                temp->nodePrevious = count2;
                temp->nodeNext = count1;
            }
        }
    }
    else
    {
        printf("Error! Memory Allocation.\n");
    }   
}

void Delete_AtBegining(listNode **headNode)
{
    listNode *temp = NULL;
    listNode *count = *headNode;
    if (*headNode == NULL)
    {
        printf("Empty List!\n");
    }
    else
    {
        *headNode = count->nodeNext;
        temp = *headNode;
        temp->nodePrevious = NULL;
        free(count);
    }
}
void Delete_Node(listNode *headNode)
{
    listNode *temp = NULL;
    listNode *temp2 = NULL;

    listNode *count = headNode;
    uint32 position = 0;
    uint32 countNum = 1;
    uint32 length = 0;
    length = List_Length(headNode);
    if (headNode == NULL)
    {
        printf("Empty List!\n");
    }
    else
    {
        printf("Enter position you want to delete: ");
        scanf("%i", &position);
        if ((position > length) || (position == 0))
        {
            printf("Invalid Position!\n");
        }
        else
        {
            if (position == length)
            {
                while (countNum < (position - 1))
                {
                    countNum++;
                    count = count->nodeNext;
                }
                temp = count->nodeNext;
                count->nodeNext = NULL;
                temp->nodePrevious = NULL;
                free(temp);
            }
            else
            {
                while (countNum < (position - 1))
                {
                    countNum++;
                    count = count->nodeNext;
                }
                temp = count->nodeNext;
                count->nodeNext = temp->nodeNext;
                temp2 = count->nodeNext;
                temp2->nodePrevious = count;
                free(temp);
            }
        }
    }
}
void Inverse_List(listNode **headNode)
{
    listNode *prev = NULL;
    listNode *current = *headNode;
    listNode *next = NULL;
    if (headNode == NULL)
    {
        printf("Empty List!\n");
    }
    else
    {
        while (current != NULL)
        {
            next = current->nodeNext;
            current->nodeNext = prev;
            prev = current;
            current = next;
        }
        *headNode = prev;
    }
}