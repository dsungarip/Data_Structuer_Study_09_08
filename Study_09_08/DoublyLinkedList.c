#include "DoublyLinkedList.h"

/*노드 생성*/
Node* DLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));	

	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;	// 앞노드 주소
	NewNode->NextNode = NULL;	// 다음노드 주소

	return NewNode;
}

/*노드 소멸*/
void DLL_DestroyNode(Node* Node)
{
	free(Node);
}

/*노드 추가*/
void DLL_AppendNode(Node** Head, Node* NewNode)
{
	/*헤드노드가 NULL 이라면 새로운노드가 헤드*/
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		/*테일을 찾아 NewNode를 연결*/
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewNode;	//기존 테일의 NextNode에 NewNode 주소대입
		NewNode->PrevNode = Tail;	//NewNode의 앞노드를 기존 Tail의 주소를 대입
	}
}

/*노드 삽입*/
void DLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	if (Current->NextNode != NULL)		//Current가 꼬리노드가 아닐경우
	{
		Current->NextNode->PrevNode = NewNode;		//Current의 다음노드의 PrevNode의 값을 NewNode의 주소값으로 변경
	}

	Current->NextNode = NewNode;
}

/*노드 제거*/
void DLL_RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)									//헤드가 제거대상이라면
	{
		*Head = Remove->NextNode;							//헤드에 다음노드주소 넣기
		if ((*Head) != NULL)								//다음노드가 NULL이 아니라면
		{
			(*Head)->PrevNode = NULL;						//다음노드의 PrevNode를 NULL로 초기화.(연결끊기)
		}

		Remove->PrevNode = NULL;							//제거대상이 가진 앞뒤노드의 주소 초기화
		Remove->NextNode = NULL;
	}
	else													// 헤드가 제거대상 아니면
	{
		Node* Temp = Remove;								// 일단 제거대상의 주소를 Temp에 넣는다.

		if (Remove->PrevNode != NULL)						// 제거대상이 헤드노드가 아니라면
		{
			Remove->PrevNode->NextNode = Temp->NextNode;	// 제거대상의 앞노드의 다음노드값을 제거대상의 다음노드값으로 변경
		}
		if (Remove->NextNode != NULL)						// 제거대상이 꼬리노드가 아니라면
		{
			Remove->NextNode->PrevNode = Temp->PrevNode;	// 제거대상의 뒷노드의 앞노드값을 제거대상의 앞노드값으로 변경
		}

		Remove->PrevNode = NULL;							//제거대상의 앞뒤노드값 NULL초기화
		Remove->NextNode = NULL;
	}
}

/*노드 탐색*/
Node* DLL_GetNodeAt(Node* Head, int Location)				//헤드주소와 찾을 노드의 번호
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

/*노드 수 세기*/
int DLL_GetNodeCount(Node* Head)
{
	unsigned int Count = 0;
	Node* Current = Head;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}

	return Count;
}