#include <iostream>
#include <queue>
using namespace std;

class Tree {
private:
	char data;
	Tree* left;
	Tree* right;
public:
	Tree(char data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
	void setLeft(Tree* left) {
		this->left = left;
	}
	void setRight(Tree* right) {
		this->right = right;
	}
	char getData() {
		return data;
	}
	Tree* getLeft() {
		return left;
	}
	Tree* getRight() {
		return right;
	}
	Tree* search(Tree* node, char c) {
		if (node == NULL) {
			return NULL;
		}
		if (node->getData() == c) {
			return node;
		}
		Tree* temp = search(node->getLeft(), c);
		if (temp == NULL) {
			return search(node->getRight(), c);
		}
		else {
			return temp;
		}
		
	}
	void prePrint(Tree* leaf) {
		if (leaf == NULL) {
			return;
		}
		cout << leaf->getData();
		prePrint(leaf->getLeft());
		prePrint(leaf->getRight());
	}
	void inPrint(Tree* leaf) {
		if (leaf == NULL) {
			return;
		}
		inPrint(leaf->getLeft());
		cout << leaf->getData();
		inPrint(leaf->getRight());
	}
	void postPrint(Tree* leaf) {
		if (leaf == NULL) {
			return;
		}
		postPrint(leaf->getLeft());
		postPrint(leaf->getRight());
		cout << leaf->getData();
	}
};
int main() {
	queue<Tree*> tq;
	int n;
	cin >> n;
	char a, b, c;
	Tree root('A');

	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		Tree* temp = root.search(&root, a);
		if (temp == NULL) {
			Tree* node = new Tree(a);
			if (b != '.') {
				node->setLeft(new Tree(b));
			}
			if (c != '.') {
				node->setRight(new Tree(c));
			}
			tq.push(node);
		}
		else {
			if (b != '.') {
				temp->setLeft(new Tree(b));
			}
			if (c != '.') {
				temp->setRight(new Tree(c));
			}
		}
	}
	while (!tq.empty()) {
		Tree* t = tq.back();
		tq.pop();
		Tree* temp = root.search(&root, t->getData());
		if (temp == NULL) {
			tq.push(t);
		}
		else {
			if (t->getLeft() != NULL) {
				temp->setLeft(t->getLeft());
			}
			if (t->getRight() != NULL) {
				temp->setRight(t->getRight());
			}
		}
	}
	root.prePrint(&root);
	cout << "\n";
	root.inPrint(&root);
	cout << "\n";
	root.postPrint(&root);
}