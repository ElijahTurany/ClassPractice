//#pragma once
//
//template <typename T>
//class ListNode {
//	//fields
//private:
//	T data;
//	ListNode<T>* next;
//	//methods
//public:
//	//constructor
//	ListNode(T data) {
//		this->data = data;
//		next = nullptr;
//	}
//	ListNode(T data, ListNode<T>* next) {
//		this->data = data;
//		this->next = next;
//	}
//	//getters, setters
//	T getData() { return data; }
//	ListNode<T>* getNext() { return next; }
//	void setData(T d) { data = d; }
//	void setNext(ListNode<T>* n) { next = n; }
//};
//
//template <typename T>
//class CustomLinkedList {
//	//fields
//private:
//	ListNode<T>* head{ nullptr };
//	int size{ 0 };
//	//constructor
//public:
//	CustomLinkedList() {
//		head = new ListNode<T>{ T{} };
//	}
//	//TODO Copy Constructor
//	//TODO destructor
//	~CustomLinkedList() { //O(N)
//		ListNode<T>* prev = nullptr;
//		ListNode<T>* n = head;
//		while (n != nullptr) {
//			prev = n;
//			n = n->getNext();
//			delete prev;
//		}
//		delete n;
//	}
//	//TODO copy assignment operator overload
//	//methods
//	void append(T item) { //O(N)
//		//(1) Create the new node to hold the item
//		ListNode<T>* temp = new ListNode<T>(item);
//		//(2) Traverse to the end of the chain
//		ListNode<T>* current{ head };
//		while (current->getNext() != nullptr) {
//			current = current->getNext();
//		}
//		//(3) Attach the node we created onto the end of the chain
//		current->setNext(temp);
//		//(4) Increase the size
//		size++;
//	}
//
//	//void prepend(T item) {
//	//	ListNode<T>* n = new ListNode<T>*{ item, head };
//	//	head = n;
//	//	size++;
//
//	//	tail->setNext(n);
//	//}
//
//	void insert(T item, int index) { //O(N)
//		if (index < 0 || index > size) {
//			return;
//		}
//
//		ListNode<T>* newNode = new ListNode<T>(item);
//		ListNode<T>* current{ head };
//
//		for (int i = 0; i < index; i++) {
//			current = current->getNext();
//		}
//
//		newNode->setNext(current->getNext());
//		current->setNext(newNode);
//		size++;
//	}
//
//	T get(int index) { //O(N)
//		if (index < 0 || index >= size) {
//			throw "Invalid index";
//		}
//
//		ListNode<T>* current{ head->getNext()};
//		for (int i = 0; i < index; i++) {
//			current = current->getNext();
//		}
//
//		return current->getData();
//	}
//
//	//must do: get rid of the item
//	//often want to: also get the item back
//	T remove(int index) { //O(N)
//		ListNode<T>* current{ head };
//		ListNode<T>* toDelete;
//		T toReturn;
//
//		if (index < 0 || index >= size) {
//			throw "Invalid index";
//		}
//
//		for (int i = 0; i < index; i++) {
//			current = current->getNext();
//		}
//
//		toReturn = current->getNext()->getData();
//		toDelete{ current->getNext() };
//		current->setNext(current->getNext()->getNext());
//		delete toDelete;
//		size--;
//		return toReturn;
//	}
//	int getSize() { //O(1)
//		return size;
//	}
//};