#include <stdio.h>

typedef struct Node
{
	int value;
	struct Node *next;
} Node;

Node* getLast(Node *head)
{
	if (head == NULL) // Передача пустого списка
	{
		return NULL;
	}
	while (head->next) // Пока у элемента есть ссылка на следующий...
	{
		head = head->next;
	}
	return head; // Возвращаем последний элемент, у которого next = NULL 
}

Node* getNth(Node *head, int n)
{
	int counter = 0;
	while (counter < n && head) // Цикл до нужного номера с проверкой на наичие такого элемента
	{
		head = head->next; // Обновляем элемент, для которого ищем ссылку на следующий
		counter++;
	}
	return head;
}

Node* getLastButOne(Node *head)
{
	if (!head) // Если списка не существует
	{
		exit(-2);
	}
	if (head->next == NULL) // Если список из одного элемента
	{
		return NULL;
	}
	while (head->next->next) // Пока существует элемент через 2 позиции
	{
		head = head->next; // Обновляем элемент 
	}
	return head;
}

void push(Node **head, int data)
{
	Node *tmp = (Node*)malloc(sizeof(Node)); // Создаём объект, в который будем заносить наши данные
	tmp->value = data;
	tmp->next = *head;
	*head = tmp; // Приравниваем последний элемент к tmp
}

int pop(Node **head)
{
	Node* prev = NULL; // Создаём объект, чтобы потом получить его значение
	int val;
	if (head == NULL) // Если список пуст
	{
		exit(-1);
	} 
	prev = (*head); // Запоминаем ссылку последнего элемента
	val = (*head)->value; // Запоминаем значение последнего элемента
	(*head) = (*head)->next; // Приравниваем последний элемент к NULL
	free(prev); // Очищаем память последнего запомнившегося элемента
	return val;
}

void pushBack(Node *head, int value)
{
	Node *last = getLast(head); // Получаем последний элемент
	Node *tmp = (Node *)malloc(sizeof(Node)); // Создаём элемент
	tmp->value = value;
	tmp->next = NULL;
	last->next = tmp; // Делаем ссылку последнего элемента на созданный
}

int popBack(Node **head)
{
	Node *lastbtn = NULL;
	if (!head) // Получили NULL
	{
		return NULL;
	}
	if (!*head) // Список пуст
	{
		return NULL;
	}
	lastbtn = getLastButOne(*head); // Получаем предпоследний элемент
	if (!lastbtn) // Если в списке один элемент
	{
		free(*head);
		*head = NULL;
	}
	else {
		free(lastbtn->next); // Чистим последний элемент
		lastbtn->next = NULL; // И даём ему ссылку NULL
	}
	return lastbtn->value;
}

void insert(Node *head, unsigned n, int val)
{
	Node *tmp = NULL;
	unsigned i = 0;
	while (i < n && head->next) // Пока есть следующий элемент
	{
		head = head->next;
		i++;
	}

	tmp = (Node*)malloc(sizeof(Node)); 
	tmp->value = val;

	if (head->next) // Если мы вставляем не в конец
	{
		tmp->next = head->next; // Присваиваем ссылку на следуюищй элемент
	}
	else {
		tmp->next = NULL;
	}
	head->next = tmp;
}

int deleteNth(Node **head, int n)
{
	if (n == 0) // Вызываем pop, если передан 0 индекс массива
	{
		return pop(head);
	}
	else {
		Node *prev = getNth(head, n - 1); // Элемент, предшествующий переданному
		Node *elm = prev->next; // Ссылка на следующий элемент, чтобы произвести сдвиг всех элементов влево
		int val = elm->value;

		prev->next = elm->next; // Ссылка на элемент после удаляемого
		free(elm);
		return val;
	}
}

void deleteList(Node **head)
{
	Node* prev = NULL;
	while ((*head)->next) // Пока есть элементы
	{
		prev = (*head); // Сохраняем элемент в отдельной переменной
		(*head) = (*head)->next;
		free(prev);
	}
	free(*head);
}

void fromArray(Node **head, int *arr, int size)
{
	size_t i = size - 1;
	if (arr == NULL || size == 0) // Если передан пустой массив
	{
		return;
	}
	do {
		push(head, arr[i]); // Заносим элемент массива в список
	} while (i-- != 0);
}

int length(Node *head)
{
	return sizeof(head) / sizeof(int);
}

int *toArray(const Node *head)
{
	int len = length(&head);
	int *values = (int*)malloc(len * sizeof(int)); // Выделяем память по размеру списка
	while (head) // Пока элемент не NULL
	{
		values[--len] = head->value; // Заносим элемент в массив
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