#pragma once
/*
	���� ���Ḯ��Ʈ(Doubly Linked List)
	�� ���� �������� ������带 ����Ű�� �����͸� ������.
*/


#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H

#include <stdio.h>
#include<stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
	struct tagNode* PrevNode;	//�ճ�� �ּ�����
	struct tagNode* NextNode;	//�޳�� �ּ�����
} Node;

/*�Լ� ���� ����*/
Node* DLL_CreateNode(ElementType NewData);
void DLL_DestroyNode(Node* Node);
void DLL_AppendNode(Node** Head, Node* NewNode);
void DLL_InsertAfter(Node* Current, Node* NewNode);
void DLL_RemoveNode(Node** Head, Node* Remove);
Node* DLL_GetNodeAt(Node* Head, int Location);
int DLL_GetNodeCount(Node* Head);

#endif