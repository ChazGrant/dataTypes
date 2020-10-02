#include <stdio.h>

typedef struct Node
{
	int value;
	struct Node *next;
} Node;

Node* getLast(Node *head)
{
	if (head == NULL) // �������� ������� ������
	{
		return NULL;
	}
	while (head->next) // ���� � �������� ���� ������ �� ���������...
	{
		head = head->next;
	}
	return head; // ���������� ��������� �������, � �������� next = NULL 
}

Node* getNth(Node *head, int n)
{
	int counter = 0;
	while (counter < n && head) // ���� �� ������� ������ � ��������� �� ������ ������ ��������
	{
		head = head->next; // ��������� �������, ��� �������� ���� ������ �� ���������
		counter++;
	}
	return head;
}

Node* getLastButOne(Node *head)
{
	if (!head) // ���� ������ �� ����������
	{
		exit(-2);
	}
	if (head->next == NULL) // ���� ������ �� ������ ��������
	{
		return NULL;
	}
	while (head->next->next) // ���� ���������� ������� ����� 2 �������
	{
		head = head->next; // ��������� ������� 
	}
	return head;
}

void push(Node **head, int data)
{
	Node *tmp = (Node*)malloc(sizeof(Node)); // ������ ������, � ������� ����� �������� ���� ������
	tmp->value = data;
	tmp->next = *head;
	*head = tmp; // ������������ ��������� ������� � tmp
}

int pop(Node **head)
{
	Node* prev = NULL; // ������ ������, ����� ����� �������� ��� ��������
	int val;
	if (head == NULL) // ���� ������ ����
	{
		exit(-1);
	} 
	prev = (*head); // ���������� ������ ���������� ��������
	val = (*head)->value; // ���������� �������� ���������� ��������
	(*head) = (*head)->next; // ������������ ��������� ������� � NULL
	free(prev); // ������� ������ ���������� �������������� ��������
	return val;
}

void pushBack(Node *head, int value)
{
	Node *last = getLast(head); // �������� ��������� �������
	Node *tmp = (Node *)malloc(sizeof(Node)); // ������ �������
	tmp->value = value;
	tmp->next = NULL;
	last->next = tmp; // ������ ������ ���������� �������� �� ���������
}

int popBack(Node **head)
{
	Node *lastbtn = NULL;
	if (!head) // �������� NULL
	{
		return NULL;
	}
	if (!*head) // ������ ����
	{
		return NULL;
	}
	lastbtn = getLastButOne(*head); // �������� ������������� �������
	if (!lastbtn) // ���� � ������ ���� �������
	{
		free(*head);
		*head = NULL;
	}
	else {
		free(lastbtn->next); // ������ ��������� �������
		lastbtn->next = NULL; // � ��� ��� ������ NULL
	}
	return lastbtn->value;
}

void insert(Node *head, unsigned n, int val)
{
	Node *tmp = NULL;
	unsigned i = 0;
	while (i < n && head->next) // ���� ���� ��������� �������
	{
		head = head->next;
		i++;
	}

	tmp = (Node*)malloc(sizeof(Node)); 
	tmp->value = val;

	if (head->next) // ���� �� ��������� �� � �����
	{
		tmp->next = head->next; // ����������� ������ �� ��������� �������
	}
	else {
		tmp->next = NULL;
	}
	head->next = tmp;
}

int deleteNth(Node **head, int n)
{
	if (n == 0) // �������� pop, ���� ������� 0 ������ �������
	{
		return pop(head);
	}
	else {
		Node *prev = getNth(head, n - 1); // �������, �������������� �����������
		Node *elm = prev->next; // ������ �� ��������� �������, ����� ���������� ����� ���� ��������� �����
		int val = elm->value;

		prev->next = elm->next; // ������ �� ������� ����� ����������
		free(elm);
		return val;
	}
}

void deleteList(Node **head)
{
	Node* prev = NULL;
	while ((*head)->next) // ���� ���� ��������
	{
		prev = (*head); // ��������� ������� � ��������� ����������
		(*head) = (*head)->next;
		free(prev);
	}
	free(*head);
}

void fromArray(Node **head, int *arr, int size)
{
	size_t i = size - 1;
	if (arr == NULL || size == 0) // ���� ������� ������ ������
	{
		return;
	}
	do {
		push(head, arr[i]); // ������� ������� ������� � ������
	} while (i-- != 0);
}

int length(Node *head)
{
	return sizeof(head) / sizeof(int);
}

int *toArray(const Node *head)
{
	int len = length(&head);
	int *values = (int*)malloc(len * sizeof(int)); // �������� ������ �� ������� ������
	while (head) // ���� ������� �� NULL
	{
		values[--len] = head->value; // ������� ������� � ������
		head = head->next;
	}
	return *values;
}

void printLinkedList(const Node *head)
{
	while (head)
	{
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
}

int main()
{
	Node *head = NULL;
//	int arr[] = { 2,4,76,7,12,3,4 };
	//fromArray(&head, arr, 7);
	push(&head, 25);
	push(&head, 36);
	printf("%d\n",pop(&head));
	printLinkedList(head);

	/*printLinkedList(head);


	insert(head, 4, 333);
	printLinkedList(head);

	pushBack(head, 11);
	pushBack(head, 12);
	pushBack(head, 13);
	pushBack(head, 14);
	printLinkedList(head);

	printf("%d\n", pop(&head));
	printf("%d\n", popBack(&head));
	printLinkedList(head);

	//deleteNth(&head, 4);
	//printLinkedList(head);

	deleteList(&head);*/

	getch();
	return 0;
}