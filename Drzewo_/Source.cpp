#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node {

	Node* left;
	Node* right;
	Node* parent;
	int val;
};


class Tree {
private:
	int sumUp_(Node* root_);
	void in_order_(Node* root_);
	double findMedian_(Node* root_);
public:
	
	Node* root;
	int size;

    Tree() : root(nullptr),size(0) {}
	void insert(int val);
	int sumUp()			{ return sumUp_(root); }
	int sumUpLeft()		{ return sumUp_(root->left); }
	int sumUpRight()	{ return sumUp_(root->right); }
	void in_order()		{ in_order_(root); }
	double findMedian() { return findMedian_(root); }
};


 void Tree::insert(int val) {
	Node* pom;
	Node* newNode = new Node;
	newNode->val = val;
	newNode->left = nullptr;
	newNode->right = nullptr;
	newNode->parent = nullptr;

	if (root == nullptr) {
		root = newNode;
		
	}
	else
	{
		pom = root;
		while (pom) {
			if (newNode->val < pom->val)
				if (pom->left == nullptr) {
					pom->left = newNode;
					break;
				}
				else
					pom = pom->left;

			else if (newNode->val >= pom->val) {
				if (pom->right == nullptr) {
					pom->right = newNode;
					break;
				}
				else
					pom = pom->right;

			}



		}

		newNode->parent = pom;
	}
	size++;
}


 void Tree::in_order_(Node* root_) {
	if (root_) {

		in_order_(root_->left);
		cout << root_->val << endl;
		in_order_(root_->right);

	}
}


 double Tree::findMedian_(Node *root_)
{
	if (root == nullptr)
		return 0;

	int counter = size;
	int currentCount = 0;
	Node* current = root;
	Node* prev = nullptr;
	Node* previous = nullptr;

	while (current != nullptr)
	{
		if (current->left == nullptr)
		{
			currentCount++;

			if (counter % 2 == 0 && currentCount == (counter / 2) + 1)
				return (previous->val + current->val) / 2.0;
			else if (counter % 2 != 0 && currentCount == (counter + 1) / 2)
				return current->val;

			previous = current;
			current = current->right;
		}
		else
		{
			prev = current->left;
			while (prev->right != nullptr && prev->right != current)
				prev = prev->right;

			if (prev->right == nullptr)
			{
				prev->right = current;
				current = current->left;
			}

			else
			{
				prev->right = nullptr;

				previous = prev;

				currentCount++;

				if (counter % 2 != 0 && currentCount == (counter + 1) / 2)
					return current->val;

				else if (counter % 2 == 0 && currentCount == (counter / 2) + 1)
					return (previous->val + current->val) / 2.0;

				previous = current;
				current = current->right;

			}
		} 
	} 
}


 int Tree::sumUp_(Node* root_)
{
	if (root_ == nullptr)
		return 0;
	return (root_->val + sumUp_(root_->left) + sumUp_(root_->right));
}

int main() {
	srand(time(nullptr));

	Tree tree;
	int amount = 0;
	int sum = 0;
	double average = 0;
	int leftSubtreeSum = 0;
	int rightSubtreeSum = 0;
	
	cout << "Podaj liczbe wezlow w drzewie: ";
	cin >> amount;

	for (int j = 0; j < amount; j++) {
		tree.insert(rand() % 100 + 1);
	}
	cout << "Wezly drzewa wypisane w kolejnosci:" << endl;
	tree.in_order();

	sum = tree.sumUp();
	average = sum / tree.size;
	leftSubtreeSum = tree.sumUpLeft();
	rightSubtreeSum = tree.sumUpRight();
	cout << "Wartosc korzenia: " << tree.root->val << endl;
	cout << "Mediana jest rowna:" << tree.findMedian() << endl;
	cout << "Suma lewego poddrzewa jest rowna:" << leftSubtreeSum << endl;
	cout << "Suma prawego poddrzewa jest rowna:" << rightSubtreeSum << endl;
	cout << "Suma calosci jest rowna:" << sum << endl;
	cout << "Srednia arytmetyczna jest rowna:" << average << endl;

}
