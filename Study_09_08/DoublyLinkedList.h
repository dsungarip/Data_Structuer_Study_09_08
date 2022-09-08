#pragma once
/*
	이중 연결리스트(Doubly Linked List)
	각 노드는 이전노드와 다음노드를 가리키는 포인터를 가진다.
*/


#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H

#include <stdio.h>
#include<stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
	struct tagNode* PrevNode;	//앞노드 주소저장
	struct tagNode* NextNode;	//뒷노드 주소저장
} Node;

/*함수 원형 선언*/
Node* DLL_CreateNode(ElementType NewData);
void DLL_DestroyNode(Node* Node);
void DLL_AppendNode(Node** Head, Node* NewNode);
void DLL_InsertAfter(Node* Current, Node* NewNode);
void DLL_RemoveNode(Node** Head, Node* Remove);
Node* DLL_GetNodeAt(Node* Head, int Location);
int DLL_GetNodeCount(Node* Head);

#endif