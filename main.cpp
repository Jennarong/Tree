#include <iostream>
#include <ctime>
#include <cstdlib>
#include "tree.h"
using namespace std;

template<class T>
void delete_node(Tree<T> &myTreeBalance, int num) {
	for (int i = 0; i < num; i++)
	{
		int randn = (rand() % 100 - 1) + 1;
		Node<T>* p = search(myTreeBalance, randn);
		if (p->key == randn && !myTreeBalance.isEmpty()) {
			myTreeBalance.deleteNode(p);
		}
	}
}

template<class T>
Node<T>* search(Tree<T> &myTreeBalance, int num) {
	Node<T>*s = myTreeBalance.search(num);
	if (s->key == num) {
		cout << num << " have in tree." << endl;
		return s;
	}
	else {
		cout << num << " not have in tree." << endl;
	}
}

template<class T>
void insert(Tree<T> &myTree, int size)
{
	for (int i = 0; i <= size; i++)
	{
		myTree.insert(rand() % 100 + 1);
	}
}

void main()
{
	Tree<int> myTree, myTreeBalance;
	int size, num, num_delete;
	srand(time(NULL));

	cout << "How many number :";
	cin >> size;
	myTree.data = new int[size];
	insert(myTree, size);


	myTree.inorder();
	cout << "Number in tree :";
	for (int i = 0; i <= size; i++)
	{
		cout << myTree.data[i] << " ";
	}
	cout << endl;
	cout << "Height of tree :" << myTree.height();
	cout << endl;
	myTreeBalance.balance(myTree.data, 0, size - 1);
	cout << "New height of tree :" << myTreeBalance.height() << endl;

	cout << "What number want to search  :";
	cin >> num;
	search(myTreeBalance, num);


	cout << "How many a number you want to delete :";
	cin >> num_delete;
	delete_node(myTreeBalance, num_delete);
	cout << endl;
	cout << "New height of tree after delete :" << myTreeBalance.height() << endl;

}
