#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
typedef unsigned int uint32;
typedef signed int sint32;
typedef unsigned char uint8;
typedef signed char sint8;
typedef struct listNode
{
    uint32 nodeData;
    struct listNode *nodeNext;
    struct listNode *nodePrevious;
} listNode;

uint8 List_Length(listNode *headNode);
void Display_List(listNode *headNode);
void Insert_AtBegining(listNode **headNode, uint32 data);
void Insert_AtTail(listNode **headNode, uint32 data);
void Insert_After(listNode *headNode, uint32 data);
void Delete_AtBegining(listNode **headNode);
void Delete_Node(listNode *headNode);
void Inverse_List(listNode **headNode);

#endif