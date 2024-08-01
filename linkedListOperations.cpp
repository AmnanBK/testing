#include <stdlib.h>
#include <iostream>

using namespace std;

// Create a Node
struct Node {
	int data;
	struct Node* next;
};

void insertAtBeginning(struct Node** headRef, int newData) {
	// Allocate memory to a node
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	// Insert the data
	newNode->data = newData;
	newNode->next = (*headRef);

	// Move head to new node
	(*headRef) = newNode;
}

void insertAfter(struct Node* prevNode, int newData) {
	if (prevNode == NULL) {
		cout << "The given previous node cannot be NULL \n";
		return;
	}

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = newData;
	newNode->next = prevNode->next;
	prevNode->next = newNode;
}

void insertAtEnd(struct Node** headRef, int newData) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	struct Node* last = *headRef;

	newNode->data = newData;
	newNode->next = NULL;

	if (*headRef == NULL) {
		*headRef = newNode;
		return;
	}

	while (last->next != NULL) {
		last = last->next;
	}

	last->next = newNode;
	return;
}

void deleteNode(struct Node** headRef, int key) {
	struct Node *temp = *headRef, *prev;

	if (temp != NULL && temp->data == key) {
		*headRef = temp->next;
		free(temp);
		return;
	}
	
	// Find the key to be deleted
	while (temp != NULL && temp->data != key) {
		prev = temp;
		temp = temp->next;
	}

	// If the key is not present
	if (temp == NULL) {
		return;
	}

	// Remove the node
	prev->next = temp->next;

	free(temp);
}

bool searchNode(struct Node** headRef, int key) {
	struct Node* current = *headRef;

	while (current != NULL) {
		if (current->data == key) {
			return true;
		}
		current = current->next;
	}
	return false;
}

void sortLinkedList(struct Node** headRef) {
	struct Node *current = *headRef, *index = NULL;
	int temp;

	if (headRef == NULL) {
		return;
	} else {
		while (current != NULL) {
			// Index points to the node next to current
			index = current->next;

			while (index != NULL) {
				if (current->data > index->data) {
					temp = current->data;
					current->data = index->data;
					index->data = temp;
				}
				index = index->next;
			}
			current = current->next;
		}
	}
}

void printList(struct Node* node) {
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
	cout << "\n";
}

int main() {
	struct Node* head = NULL;

	insertAtEnd(&head, 1);
	insertAtBeginning(&head, 2);
	insertAtBeginning(&head, 3);
	insertAtEnd(&head, 4);
	insertAfter(head->next, 5);

	cout << "Linked list: ";
	printList(head);

	cout << "After deleting an element: ";
	deleteNode(&head, 3);
	printList(head);

	int itemToFind = 3;
	if (searchNode(&head, itemToFind)) {
		cout << itemToFind << " is found \n";
	} else {
		cout << itemToFind << " is not found \n";
	}

	sortLinkedList(&head);
	cout << "Sorted List: ";
	printList(head);
}