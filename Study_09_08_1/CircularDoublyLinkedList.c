#include "CircularDoublyLinkedList.h"

/*노드 생성*/
Node* CDLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));						//동적할당

	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

/*노드 소멸*/
void CDLL_DestroyNode(Node* Node)
{
	free(Node);												//동적할당해제
}

/*노드 추가*/
void CDLL_AppendNode(Node** Head, Node* NewNode)
{
	/*헤드노드가 NULL 이라면 새로운 노드를 헤드로*/
	if ((*Head) == NULL)
	{
		*Head = NewNode;
		(*Head)->NextNode = *Head;
		(*Head)->PrevNode = *Head;
	}
	else
	{
		/*테일과 헤드사이에 NewNode를 삽입*/
		Node* Tail = (*Head)->PrevNode;						//꼬리를 헤드의 앞노드값(꼬리)으로 초기화

		Tail->NextNode->PrevNode = NewNode;					// 헤드의 앞노드값을 NewNode로 초기화
		Tail->NextNode = NewNode;							// 기존꼬리의 다음노드값을 newNode로 초기화

		NewNode->NextNode = (*Head);						//새 노드의 다음노드값을 헤드로 초기화
		NewNode->PrevNode = Tail;							//새 노드의 앞노드값을 기존꼬리로 초기화
	}
}

/*노드 삽입*/
void CDLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;					//NewNode의 다음노드값을  Current의 다음노드값으로 초기화
	NewNode->PrevNode = Current;							//NewNode의 앞 노드값을 Current로 초기화

	Current->NextNode->PrevNode = NewNode;					//Current의 다음노드의 앞노드값을 NewNode로 초기화
	Current->NextNode = NewNode;							//Current의 다음노드를 NewNode로 초기화
}

/*노드 제거*/
void CDLL_RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)									//헤드가 제거대상이라면
	{
		(*Head)->PrevNode->NextNode = Remove->NextNode;		//헤드의 앞노드의 다음노드값을 헤드의 다음노드값으로 초기화
		(*Head)->NextNode->PrevNode = Remove->PrevNode;		//헤드의 다음노드의 앞노드값을 헤드의 앞노드값으로 초기화

		*Head = Remove->NextNode;							//헤드를 다음노드로 지정

		Remove->PrevNode = NULL;							//헤드의 앞노드와 다음노드를 NULL로 초기화(완전분리)
		Remove->NextNode = NULL;
	}
	else
	{
		Node* Temp = Remove;

		Remove->PrevNode->NextNode = Temp->NextNode;		//제거대상의 앞노드의 다음노드값을 제거대상의 다음노드값으로 초기화
		Remove->NextNode->PrevNode = Temp->PrevNode;		//제거대상의 다음노드의 앞노드갚을 제거대상의 앞노드값으로 초기화

		Remove->PrevNode = NULL;							//제거대상의 앞노드와 다음노드 NULL초기화(완전분리)
		Remove->NextNode = NULL;
	}
}

/*노드 탐색*/
Node* CDLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}
	return Current;
}

int CDLL_GetNodeCount(Node* Head)
{
	unsigned int Count = 0;
	Node* Current = Head;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;

		/*다돌아서 다시 헤드로 돌아올경우 정지*/
		if (Current == Head)
		{
			break;
		}
	}
	return Count;
}

void PrintNode(Node* _Node)
{
	if (_Node->PrevNode == NULL)
	{
		printf("Prev : NULL");
	}
	else
	{
		printf("Prev : %d", _Node->PrevNode->Data);
	}

	printf(" Current : %d ", _Node->Data);

	if (_Node->NextNode == NULL)
	{
		printf("Next : NULL\n");
	}
	else
	{
		printf("Next : %d\n", _Node->NextNode->Data);
	}
}