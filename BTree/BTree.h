#pragma once
#include <vector>
using namespace std;

class LeafNode {
private:
	vector<int> data;
	InternalNode* parent;
public:
	LeafNode(vector<int> dataIn, InternalNode* parentIn) {
		data = dataIn;
		parent = parentIn;
	}
	void insert(int dataIn) {
		data.push_back(dataIn);
		//Sort
		if (data.size() >= 4) {
			vector<int> right = { data[2], data[3] };
			LeafNode rightNode{ right, parent };
			data.pop_back();
			data.pop_back();
			parent->addChild(&rightNode);
			parent->addVal(data[2]);
		}
	}
};

class InternalNode {
private:
	vector<int> data;
	vector<LeafNode*> children;
	InternalNode* parent;
public:
	InternalNode(vector<int> dataIn, vector<LeafNode*> childrenIn, InternalNode* parentIn) {
		data = dataIn;
		children = childrenIn;
		parent = parentIn;
	}

	InternalNode() {
		parent = nullptr;
	}

	void addChild(LeafNode* nodeIn) {
		children.push_back(nodeIn);
	}

	void addVal(int valIn) {
		data.push_back(valIn);
	}

	int getChildren() {
		return children.size();
	}

	void insert(int val) {
		if (data.size() == 0) {
			children[0]->insert(val);
		}
		else {
			for (int i = 0; i < data.size(); i++) {
				if (val < data[i]) {
					children[i]->insert(val);
				}
			}
			if (val >= data[data.size() - 1]) {
				children[children.size() - 1]->insert(val);
			}
		}

		if (children.size() > 4) {
			this->splitNode();
		}
	}

	void splitNode() {

	}
};

class Tree {
private:
	InternalNode* root{ nullptr };
public:
	Tree() {
		root = new InternalNode();
	}

	void insert(int val) {
		if (root->getChildren() == 0) {
			vector<int> vec{ val };
			LeafNode l{ vec, root };
			root->addChild(&l);
		}
		else {
			root->insert(val);
		}
	}
};