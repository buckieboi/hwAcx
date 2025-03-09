#ifndef AUTOCOMPLETER_H
#define AUTOCOMPLETER_H

#include <vector>
#include <string>
using namespace std;
#include "Autocompleter.h" // need for recognizing h file.

// public: notes to remember integer height and left right nodes = nullptr and e is entry point

// Entry e;
// int height;
// Node* left;
// Node* right;

// For the mandatory running times below:
// n is the number of strings in the dictionary.
// Assume that the length of every string is O(1).


// Creates a new Autocompleter with an empty dictionary.
//
// Must run in O(1) time.
Autocompleter::Autocompleter(){
	root = nullptr;
}

// Adds a string x to the dictionary.
// If x is already in the dictionary, does nothing.
//
// Must run in O(log(n)) time.
void Autocompleter::insert(string x, int freq){
	//put the burdern of work insert on insert_recurse
	insert_recurse(Entry(x, freq), root);

}
// Inserts an Entry into an AVL tree rooted at p.
//
// Should run in O(log(n)) time.
void Autocompleter::insert_recurse(Entry e, Node* &p);
//idea: so  insert() calls on insert_recurse take care of job
// and this will insert entry e into evl tree rooted at p
//use avl rules ot find where it is like if... will  pick left or right
if(e < p){
	p->left = e;
}
else{
	p->right = e;
}






// Returns the number of strings in the dictionary
// of possible completions.
//
// Must run in O(n) time.
int Autocompleter::size();
	//dump work onto size recursion by calling it
	size_recurse(root); // needs root for formula: size(root)=1+size(root.left)+size(root.right)

// Returns the size of the binary tree rooted at p.
//
// Should run in O(n) time.
int Autocompleter::size_recurse(Node* p);
	//check of work2.txt dictionary is empty base case.
	if(p==nullptr) return 0;

	//go thru the size of txt dictionary n is its size and update a counter;
	//the total size is all the nodes added together( 1head + left node + right node)
	return 1 + size_recurse(p->left) + size_recurse(p->right)




// Fills the vector T with the three most-frequent completions of x.
// If x has less than three completions, then
// T is filled with all completions of x.
// The completions appear in T from most to least frequent.
//
// Must run fast.  In particular, you should not search all nodes in the
// tree for possible completions.
// Instead, only search regions of the tree for which a completion could
// be present, which will yield a run time bound of O(k log n ) time,
// where k is the number of completions in the tree.
void Autocompleter::completions(string x, vector<string> &T);



// Fills C with the completions of x in the BST rooted at p.
void Autocompleter::completions_recurse(string x, Node* p, vector<Entry> &C);



// Rebalances the AVL tree rooted at p.
// Helpful for insert().
// Should be called on every node visited during
// the search in reverse search order.
//
// Should run in O(1) time.
void Autocompleter::rebalance(Node* &p){
	//to know if it needs rebalnce. now which rotation?
	//difference being positive means the left is greater so right rotation
	if(height(p->left) - height(p->right) > 1){
		if(height(p->left->left) < height(p->left->right)){
			left_rotate(p->left);
		}
		right_rotate(p);
	}
	else if(height(p->right) - height(p->left) > 1){
		if(height(p->right->right) < height(p->right->left)){
			right_rotate(p->right);
		}
		left_rotate(p);
	}


}

// Perform left and right rotations
// of an AVL tree rooted at p (helpful for implementing rebalance).
//
// Should run in O(1) time.
void Autocompleter::right_rotate(Node* &p){
	//
	Node* A = p;
	Node* B = p->left;
	Node* Br = B->right;


	B->right = A;
	A->left = Br;

	update_height(A);
	update_height(B);

}
void Autocompleter::left_rotate(Node* &p){
	//opposite of right rotation
	p->right = p;
	p = p->left;
}


//A useful method to update
//the height of a node,
//assuming subtrees already have
//the correct height.
void Autocompleter::update_height(Node*& p)
{
	if (p != nullptr)
		p->height = 1 + max(height(p->left), height(p->right));
}


#endif