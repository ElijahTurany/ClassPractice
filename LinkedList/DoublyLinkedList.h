#pragma once

template <typename T>
class ListNode {
	//fields
private:
	T data;
	ListNode<T>* next;
	ListNode<T>* prev;
	//methods
public:
	//constructor
	ListNode(T data) {
		this->data = data;
		next = nullptr;
		prev = nullptr;
	}
	ListNode(T data, ListNode<T>* next) {
		this->data = data;
		this->next = next;
		prev = nullptr;
	}
	ListNode(T data, ListNode<T>* prev, ListNode<T>* next) {
		this->data = data;
		this->prev = prev;
		this->next = next;
	}
	//getters, setters
	T getData() { return data; }
	ListNode<T>* getNext() { return next; }
	ListNode<T>* getPrev() { return prev; }
	void setData(T d) { data = d; }
	void setNext(ListNode<T>* n) { next = n; }
	void setPrev(ListNode<T>* n) { prev = n; }
};

template <typename T>
class DoublyLinkedList {
	//fields
private:
	ListNode<T>* head{ nullptr };
	int size{ 0 };
	//constructor
public:
	DoublyLinkedList() {
		head = new ListNode<T>{ T{} };
	}
	//TODO Copy Constructor
	//TODO destructor
	~DoublyLinkedList() { //O(N)
		ListNode<T>* previous = nullptr;
		ListNode<T>* n = head;
		while (n != nullptr) {
			previous = n;
			n = n->getNext();
			delete previous;
		}
		delete n;
	}
	//TODO copy assignment operator overload
	//methods
	void append(T item) { //O(N)
		//(1) Create the new node to hold the item
		
		//(2) Traverse to the end of the chain
		ListNode<T>* current{ head };
		while (current->getNext() != nullptr) {
			current = current->getNext();
		}
		//(3) Attach the node we created onto the end of the chain
		ListNode<T>* temp = new ListNode<T>(item, current, nullptr);
		current->setNext(temp);
		//(4) Increase the size
		size++;
	}

	//void prepend(T item) {
	//	ListNode<T>* n = new ListNode<T>*{ item, head };
	//	head = n;
	//	size++;

	//	tail->setNext(n);
	//}

	void insert(T item, int index) { //O(N)
		if (index < 0 || index > size) {
			return;
		}

		ListNode<T>* current{ head };

		for (int i = 0; i < index; i++) {
			current = current->getNext();
		}

		ListNode<T>* newNode = new ListNode<T>(item, current, current->getNext());
		if (index > size) {
			current->getNext()->setPrev(newNode);
		}
		current->setNext(newNode);
		size++;
	}

	T get(int index) { //O(N)
		if (index < 0 || index >= size) {
			throw "Invalid index";
		}

		ListNode<T>* current{ head->getNext() };
		for (int i = 0; i < index; i++) {
			current = current->getNext();
		}

		return current->getData();
	}

	//must do: get rid of the item
	//often want to: also get the item back
	T remove(int index) { //O(N)
		ListNode<T>* current{ head };
		ListNode<T>* toDelete;
		T toReturn;

		if (index < 0 || index >= size) {
			throw "Invalid index";
		}

		for (int i = 0; i < index, i++) {
			current = current->getNext();
		}

		toReturn = current->getNext()->getData();
		toDelete{ current->getNext() };
		current->setNext(current->getNext()->getNext());
		current->getNext()->getNext()->setPrev(current);
		delete toDelete;
		size--;
		return toReturn;
	}
	int getSize() { //O(1)
		return size;
	}

	void recursiveTraverse(ListNode<T>* current) {
		if (current == nullptr) {
			return;
		}

		recursiveTraverse(current->getNext());
	}

	void reverse() {
		reverseNode(head, head->getNext());
		head->setNext(nullptr);
	}
	void reverseNode(ListNode<T>* prev, ListNode<T>* current) {
		if (current->getNext() == nullptr) {
			return;
		}
		ListNode<T>* next{ current->getNext() };
		current->setNext(prev);
		reverseNode(current, next);
	}
};
