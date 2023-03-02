#pragma once
#include <iostream>

struct Node {
	int data;
	struct Node* next;
};

class LinkedList {
public:
	LinkedList() {
		head = nullptr;
		tail = nullptr;
	}

	~LinkedList() {
		Node* prev = head;
		Node* n = head->next;
		while (n != nullptr) {
			n = prev->next;
			delete prev;
		}
		delete n;
	}

	void createNode(int input) {
		Node* temp = new Node;
		temp->data = input;
		temp->next = nullptr;
		if (head == nullptr) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
	}

	void printList() {
		Node* n = head;
		while (n != nullptr) {
			cout << n->data << " ";
			n = n->next;
		}
	}

	void insertNode(int input, int index) {
		Node* currentNode = head;

		if (index == 0) {
			Node* temp = new Node;
			temp->data = input;
			temp->next = currentNode;
			head = temp;
		}
		else {
			for (int i = 1; i <= index; i++) {
				if (currentNode->next == nullptr) {
					return;
				}
				currentNode = currentNode->next;
			}
			Node* temp = new Node;
			temp->data = input;
			temp->next = currentNode->next;
			currentNode->next = temp;
		}
	}

	int getNode(int index) {
		if (index < 0) {
			throw "Invalid index";
		}

		Node* currentNode = head;

		for (int i = 0; i <= index; i++) {
			if (currentNode->next == nullptr) {
				throw "Out of bounds";
			}
			currentNode = currentNode->next;
		}
		return currentNode->data;

	}

	void deleteNode(int index) {
		Node* currentNode = head;
		Node* prevNode = head;

		if (index == 0) {
			head = head->next;
			delete currentNode;
		}

		for (int i = 0; i < index; i++) {
			if (currentNode->next == nullptr) {
				return;
			}
			prevNode = currentNode;
			currentNode = currentNode->next;
		}

		prevNode->next = currentNode->next;
		delete currentNode;
	}

	int getLength() {
		Node* n = head;
		int count = 0;
		while (n != nullptr) {
			count++;
			n = n->next;
		}
		return count;
	}

private:
	Node* head;
	Node* tail;
};