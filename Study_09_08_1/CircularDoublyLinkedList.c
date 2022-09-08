#include "CircularDoublyLinkedList.h"

/*��� ����*/
Node* CDLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));						//�����Ҵ�

	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

/*��� �Ҹ�*/
void CDLL_DestroyNode(Node* Node)
{
	free(Node);												//�����Ҵ�����
}

/*��� �߰�*/
void CDLL_AppendNode(Node** Head, Node* NewNode)
{
	/*����尡 NULL �̶�� ���ο� ��带 ����*/
	if ((*Head) == NULL)
	{
		*Head = NewNode;
		(*Head)->NextNode = *Head;
		(*Head)->PrevNode = *Head;
	}
	else
	{
		/*���ϰ� �����̿� NewNode�� ����*/
		Node* Tail = (*Head)->PrevNode;						//������ ����� �ճ�尪(����)���� �ʱ�ȭ

		Tail->NextNode->PrevNode = NewNode;					// ����� �ճ�尪�� NewNode�� �ʱ�ȭ
		Tail->NextNode = NewNode;							// ���������� ������尪�� newNode�� �ʱ�ȭ

		NewNode->NextNode = (*Head);						//�� ����� ������尪�� ���� �ʱ�ȭ
		NewNode->PrevNode = Tail;							//�� ����� �ճ�尪�� ���������� �ʱ�ȭ
	}
}

/*��� ����*/
void CDLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;					//NewNode�� ������尪��  Current�� ������尪���� �ʱ�ȭ
	NewNode->PrevNode = Current;							//NewNode�� �� ��尪�� Current�� �ʱ�ȭ

	Current->NextNode->PrevNode = NewNode;					//Current�� ��������� �ճ�尪�� NewNode�� �ʱ�ȭ
	Current->NextNode = NewNode;							//Current�� ������带 NewNode�� �ʱ�ȭ
}

/*��� ����*/
void CDLL_RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)									//��尡 ���Ŵ���̶��
	{
		(*Head)->PrevNode->NextNode = Remove->NextNode;		//����� �ճ���� ������尪�� ����� ������尪���� �ʱ�ȭ
		(*Head)->NextNode->PrevNode = Remove->PrevNode;		//����� ��������� �ճ�尪�� ����� �ճ�尪���� �ʱ�ȭ

		*Head = Remove->NextNode;							//��带 �������� ����

		Remove->PrevNode = NULL;							//����� �ճ��� ������带 NULL�� �ʱ�ȭ(�����и�)
		Remove->NextNode = NULL;
	}
	else
	{
		Node* Temp = Remove;

		Remove->PrevNode->NextNode = Temp->NextNode;		//���Ŵ���� �ճ���� ������尪�� ���Ŵ���� ������尪���� �ʱ�ȭ
		Remove->NextNode->PrevNode = Temp->PrevNode;		//���Ŵ���� ��������� �ճ�就�� ���Ŵ���� �ճ�尪���� �ʱ�ȭ

		Remove->PrevNode = NULL;							//���Ŵ���� �ճ��� ������� NULL�ʱ�ȭ(�����и�)
		Remove->NextNode = NULL;
	}
}

/*��� Ž��*/
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

		/*�ٵ��Ƽ� �ٽ� ���� ���ƿð�� ����*/
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