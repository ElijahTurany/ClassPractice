#pragma once
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
public:
	T data;
	vector<TreeNode<T>*> children;

	TreeNode(T dataIn) {
		data = dataIn;
	}
};

template <typename T>
class Tree {
private:
	TreeNode<T>* root{ nullptr };
	int size{ 0 };
public:
	Tree() {}

	int getSize() {
		return size;
	}

	void addNode(T data, TreeNode<T>* parentNode) {
		TreeNode* t = new TreeNode(data);
		parentNode->children.push_back(t);
		size++;
	}

	int heightHelper(TreeNode<T>* nodeIn) {
		int largest = 0;
		int current;
		if (nodeIn->children.size() == 0) {
			return 1;
		}

		for (int i = 0; i < nodeIn->children.size(); i++) {
			current = heightHelper(nodeIn->children[i]);
			if (current > largest) {
				largest = current;
			}
		}

		return 1 + largest;
	}

	int getHeight() {
		if (root == nullptr) {
			return 0;
		}
		else {
			return heightHelper(root);
		}
	}
};