/*
	환형 연결리스트(Circular Doubly Linked List)
	각 노드는 이전노드와 다음노드를 가리키는 포인터를 가진다.
	헤드와 테일은 서로 연결되어있다.
*/

#pragma once
#ifndef CIRCULAR_DOUBLY_LINKEDLIST_H
#define CIRCULAR_DOUBLY_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
	struct tagNode* PrevNode;
	struct tagNode* NextNode;
} Node;

/*함수 원형 선언*/
Node* CDLL_CreateNode(ElementType NewData);
void CDLL_DestroyNode(Node* Node);
void CDLL_AppendNode(Node** Head, Node* NewData);
void CDLL_InsertAfter(Node* Current, Node* NewData);
void CDLL_RemoveNode(Node** Head, Node* Remove);
Node* CDLL_GetNodeAt(Node* Head, int Location);
int CDLL_GetNodeCount(Node* Head);
void PrintNode(Node* _Node);

#endif