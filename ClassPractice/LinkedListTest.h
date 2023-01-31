#pragma once

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
			while (n != NULL) {
				cout << n->data << " ";
				n = n->next;
			}
		}
		void insertNode(int input, int index) {
			Node* prev;
			Node* current;
			int currentIndex = 0;

			while (currentIndex <= index) {
				
			}
		}
	private:
		Node* head;
		Node* tail;
};

