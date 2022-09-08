/*
	ȯ�� ���Ḯ��Ʈ(Circular Doubly Linked List)
	�� ���� �������� ������带 ����Ű�� �����͸� ������.
	���� ������ ���� ����Ǿ��ִ�.
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

/*�Լ� ���� ����*/
Node* CDLL_CreateNode(ElementType NewData);
void CDLL_DestroyNode(Node* Node);
void CDLL_AppendNode(Node** Head, Node* NewData);
void CDLL_InsertAfter(Node* Current, Node* NewData);
void CDLL_RemoveNode(Node** Head, Node* Remove);
Node* CDLL_GetNodeAt(Node* Head, int Location);
int CDLL_GetNodeCount(Node* Head);
void PrintNode(Node* _Node);

#endif