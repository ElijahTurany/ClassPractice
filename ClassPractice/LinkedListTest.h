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
			Node* currentNode = head;
			int currentIndex = 1;

			if (index == 0) {
					Node* temp = new Node;
					temp->data=input;
					temp->next=currentNode;
					head = temp;
			}

			while (currentIndex <= index) {
				if (currentIndex == index) {
					Node* temp = new Node;
					temp->data=input;
					temp->next=currentNode->next;
					currentNode->next=temp;
					break;
				}
				if (currentNode->next == NULL) {
					break;
				}
				currentNode = currentNode->next;
				currentIndex++;
			}
		}
		int getNode(int index) {
			Node* currentNode = head;
			int currentIndex = 0;
			int value = 0;

			while (currentIndex <= index) {
				if (currentIndex == index) {
					value = currentNode->data;
					break;
				}
				if (currentNode->next == NULL) {
					break;
				}
				currentNode = currentNode->next;
				currentIndex++;
			}
			return value;

		}
		void deleteNode(int index) {
			Node* currentNode = head;
			Node* prevNode;
			int currentIndex = 0;

			while (currentIndex <= index) {
				if (index == 0) {
					head = head->next;
					delete currentNode;
					break;
				}
				if (currentIndex == index) {
					prevNode->next=currentNode->next;;
					delete currentNode;
					break;
				}
				if (currentNode->next == NULL) {
					break;
				}
				prevNode=currentNode;
				currentNode = currentNode->next;
				currentIndex++;
			}
		}
		int getLength() {
			Node* n = head;
			int count = 0;
			while (n != NULL) {
				count++;
				n = n->next;
			}
			return count;
		}
	private:
		Node* head;
		Node* tail;
};

