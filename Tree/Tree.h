#pragma once
#include <vector>

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

	void addNode(T data, TreeNode<T>* parent) {
		TreeNode t* = new TreeNode(data)
		parent.children.push_back(t);
		size++;
	}
};