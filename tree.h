#include <queue>
#include <stack>
using namespace std;

#ifndef Binary_Search_Tree
#define Binary_Search_Tree

template<class T> class Tree;

template<class T>
class Node
{
public:
	Node() { left = right = NULL; }
	Node(const T& el, Node *l = 0, Node *r = 0)
	{
		key = el; left = l; right = r;
	}

	T key;
	Node *left, *right;
};

template<class T>
class Tree {
public:
	Tree() { root = 0; count = 0; }
	~Tree() { clear(); }
	void clear() { clear(root); root = 0; }
	bool isEmpty() { return root == 0; }
	void inorder() { inorder(root); }
	int height(){ return height(root); }
	void insert(const T& el);
	Node<T>* search(const T& el){ return search(root, el); }
	void deleteNode(Node<T> *& node);
	void deleteEl(const T& el);
	void balance(T data[], int first, int last);
	T size;
	T *data;



protected:
	Node<T> *root,*parent;
	void clear(Node<T> *p);
	void inorder(Node<T> *p);
	void visit(Node<T> *p);
	int height(Node<T> *p);
	Node<T>* search(Node<T> *p, const T&);
	int count;


};

template<class T>
void Tree<T>::clear(Node<T> *p)
{
	if (p != 0) {

		clear(p->left);
		clear(p->right);
		delete p;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void Tree<T>::inorder(Node<T> *p)
{
	if (p != 0)
	{
		inorder(p->left);
		data[count++] = p->key;
		inorder(p->right);
	}

}

template<class T>
int Tree<T>::height(Node<T> *p)
{
	int left, right;
	if (p == NULL)
		return 0;
	left = height(p->left);
	right = height(p->right);
	if (left > right)
		return left + 1;
	else
		return right + 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void Tree<T>::insert(const T &el)
{
	Node<T> *p = root, *prev = 0;
	while (p != 0)
	{
		prev = p;
		if (p->key < el)
			p = p->right;
		else
			p = p->left;
	}
	if (root == 0)
		root = new Node<T>(el);
	else if (prev->key<el)
		prev->right = new Node<T>(el);
	else
		prev->left = new Node<T>(el);

}
template<class T>
Node<T>* Tree<T>::search(Node<T> *p, const T &el)
{
	while (p != NULL)
	{
		if (el == p->key)
			return p;
		else if (el < p->key)
			p = p->left;
		else
			p = p->right;
	}
}
template <class T>
void Tree<T>::deleteEl(const T &el)
{
	Node<T> *p = root, *prev = 0;
	while (p != NULL)
	{
		if (p->key == el){
		}
		prev = p;
		if (p != NULL && p->key == el)
			p = p->right;
		else
			p = p->left;
	}
	if (p != NULL && p->key == el)
	{
		if (p == root) {
			deleteNode(root);
		}
		else if (prev->left == p) {
			deleteNode(prev->left);
		}
		else{
			deleteNode(prev->right);
		}
		
	}
	else if (root != 0)
		cout << el << "  is't in the tree " << endl;
	else
		cout << "The tree not have eliment" << endl;
}


template<class T>
void Tree<T>::deleteNode(Node<T> *&node) {
	Node<T> *prev, *curr = node;
	if (curr->left == NULL && curr->right == NULL) 
	{
		if (parent->left == curr) {
			parent->left = NULL;
		}
		else{
			parent->right = NULL;
		}
		delete curr;
		return;
	}


	// Node with single child
	if ((curr->left == NULL && curr->right != NULL) || (curr->left != NULL && curr->right == NULL)) {
		if (curr->left == NULL && curr->right != NULL) {
			if (parent->left == curr) {
				parent->left = curr->right;
			}
			else {
				parent->right = curr->right;
			}
		}
		else { // left child present, no right child
			if (parent->left == curr) {
				parent->left = curr->left;
			}
			else {
				parent->right = curr->left;
			}
		}
		delete curr;
		return;
	}

	// Node with 2 children
	if (node->left != NULL && node->right != NULL) {
		curr = node->left;
		prev = node;
		while (curr->right != 0) {
			prev = curr;
			curr = curr->right;
		}
		node->key = curr->key;
		if (prev == node) {
			prev->left = curr->left;
		}
		else{
			prev->right = curr->left;
		}
		delete curr;
		return;
	}
}


template<class T>
void Tree<T>::balance(T data[], int first, int last)
{
	if (first <= last) {
		int middle = (first + last) / 2;
		insert(data[middle]);
		balance(data, first, middle - 1);
		balance(data, middle + 1, last);
	}
}

#endif // Binary_Search_Tree
