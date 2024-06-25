#include "LinkedList.h"

Node* create(char* name, int id)
{
	Node* new_node = (Node*)malloc(sizeof(Node));

	if (new_node == NULL) {
		fpirntf(stderr, "node could not created\n");
		exit(EXIT_FAILURE);
	}

	new_node->name = name;
	new_node->id = id;
	new_node->prev = NULL;
	new_node->next = NULL;

	return new_node;
}

void destroy(Node* node) 
{
	free(node);
}

void append(Node** head, Node* new_node)
{
	if ((*head) == NULL) {
		*head = new_node;
		(*head)->next = *head;
		(*head)->prev = *head;
	}
	else {
		Node* tail = (*head)->prev;

		tail->next->prev = new_node;
		tail->next = new_node;

		new_node->next = (*head);
		new_node->prev = tail;
	}
}

void insert(Node* cur, Node* new_node)
{
	new_node->next = cur->next;
	new_node->prev = cur;

	if (cur->next != NULL) {
		cur->next->prev = new_node;
		cur->next = new_node;
	}
}

void remove_node(Node** head, Node* remove)
{
	if (*head == remove) {
		(*head)->prev->next = remove->next;
		(*head)->next->prev = remove->prev;

		*head = remove->next;

		remove->prev = NULL;
		remove->next = NULL;
	}
	else {
		remove->prev->next = remove->next;
		remove->next->prev = remove->prev;

		remove->prev = NULL;
		remove->next = NULL;
	}
}

Node* getNodeAt(Node* head, int location)
{
	Node* cur = head;

	while (cur != NULL && (--location) >= 0) {
		cur = cur->next;
	}

	return cur;
}

int getNodeCount(Node* head)
{
	unsigned int count = 0;
	Node* cur = head;

	while (cur != NULL) {
		cur = cur->next;
		count++;
		if (cur == head)
			break;
	}

	return count;
}

void printNode(Node* _Node)
{
	if (_Node->prev == NULL)
		printf("Prev: NULL\n");
	else
		printf("Prev: %s, %d", _Node->prev->name, _Node->prev->id);

	printf("Cur: %s, %d\n", _Node->name, _Node->id);

	if (_Node->next == NULL)
		printf("Next: NULL\n");
	else
		printf("Next: %s, %d\n", _Node->next->name, _Node->next->id);
}

Node* getNodeAfterDay(Node* head, char* name, int day)
{
	Node* cur = head;

	while (cur != NULL && (cur->name) != name)
		cur = cur->next;
	
	while (cur != NULL && (--day) >= 0) {
		cur = cur->next;
	}

	return cur;
}