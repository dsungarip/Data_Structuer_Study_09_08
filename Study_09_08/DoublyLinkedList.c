#include "DoublyLinkedList.h"

/*��� ����*/
Node* DLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));	

	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;	// �ճ�� �ּ�
	NewNode->NextNode = NULL;	// ������� �ּ�

	return NewNode;
}

/*��� �Ҹ�*/
void DLL_DestroyNode(Node* Node)
{
	free(Node);
}

/*��� �߰�*/
void DLL_AppendNode(Node** Head, Node* NewNode)
{
	/*����尡 NULL �̶�� ���ο��尡 ���*/
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		/*������ ã�� NewNode�� ����*/
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewNode;	//���� ������ NextNode�� NewNode �ּҴ���
		NewNode->PrevNode = Tail;	//NewNode�� �ճ�带 ���� Tail�� �ּҸ� ����
	}
}

/*��� ����*/
void DLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	if (Current->NextNode != NULL)		//Current�� ������尡 �ƴҰ��
	{
		Current->NextNode->PrevNode = NewNode;		//Current�� ��������� PrevNode�� ���� NewNode�� �ּҰ����� ����
	}

	Current->NextNode = NewNode;
}

/*��� ����*/
void DLL_RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)									//��尡 ���Ŵ���̶��
	{
		*Head = Remove->NextNode;							//��忡 ��������ּ� �ֱ�
		if ((*Head) != NULL)								//������尡 NULL�� �ƴ϶��
		{
			(*Head)->PrevNode = NULL;						//��������� PrevNode�� NULL�� �ʱ�ȭ.(�������)
		}

		Remove->PrevNode = NULL;							//���Ŵ���� ���� �յڳ���� �ּ� �ʱ�ȭ
		Remove->NextNode = NULL;
	}
	else													// ��尡 ���Ŵ�� �ƴϸ�
	{
		Node* Temp = Remove;								// �ϴ� ���Ŵ���� �ּҸ� Temp�� �ִ´�.

		if (Remove->PrevNode != NULL)						// ���Ŵ���� ����尡 �ƴ϶��
		{
			Remove->PrevNode->NextNode = Temp->NextNode;	// ���Ŵ���� �ճ���� ������尪�� ���Ŵ���� ������尪���� ����
		}
		if (Remove->NextNode != NULL)						// ���Ŵ���� ������尡 �ƴ϶��
		{
			Remove->NextNode->PrevNode = Temp->PrevNode;	// ���Ŵ���� �޳���� �ճ�尪�� ���Ŵ���� �ճ�尪���� ����
		}

		Remove->PrevNode = NULL;							//���Ŵ���� �յڳ�尪 NULL�ʱ�ȭ
		Remove->NextNode = NULL;
	}
}

/*��� Ž��*/
Node* DLL_GetNodeAt(Node* Head, int Location)				//����ּҿ� ã�� ����� ��ȣ
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

/*��� �� ����*/
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