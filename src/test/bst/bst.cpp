#include <stdlib.h>
#include <stdio.h>

template<typename T>
struct bst_node {
	T data;
	bst_node *parent;
	bst_node *left;
	bst_node *right;
};

template<typename T>
bst_node<T> *
bst_insert(bst_node<T> *bst, T val, bst_node<T> *parent)
{
	if (bst == NULL) {
		bst_node<T> *n = new bst_node<T>;
		n->data = val;
		n->parent = parent;
		n->left = NULL;
		n->right = NULL;
		return n;
	}
	if (val < bst->data) {
		bst->left = bst_insert(bst->left, val, bst);
		return bst;
	} else if (val > bst->data) {
		bst->right = bst_insert(bst->right, val, bst);
		return bst;
	}
	printf("dupe\n");
	exit(1);
	return NULL;
}

template<typename T>
bst_node<T> *
bst_find(bst_node<T> *bst, T val)
{
	if (bst == NULL) {
		printf("could not find\n");
		return NULL;
	}
	if (bst->data == val) {
		return bst;
	}
	if (val > bst->data) {
		return bst_find(bst->right, val);
	}
	if (val < bst->data) {
		return bst_find(bst->left, val);
	}
	return NULL;
}

template<typename T>
void
bst_replace(bst_node<T> *n1, bst_node<T> *n2, bst_node<T> **bst)
{
	if (n1 == (*bst)) {
		(*bst) = n2;
	}
	if (n2) {
		n2->parent = n1->parent;
	}
	if (n1->parent == NULL) {
		return;
	}
	if (n1->parent->left == n1) {
		n1->parent->left = n2;
	} else {
		n1->parent->right = n2;
	}
}

template<typename T>
bst_node<T> *
bst_delete(bst_node<T> *bst, T val)
{
	bst_node<T> *n = bst_find(bst, val);
	bst_node<T> *null = NULL;
	if (!n) {
		return bst;
	}
	//no children
	if (n->left == NULL && n->right == NULL) {
		bst_replace(n, null, &bst);
		delete n;
		return bst;
	}
	//one child
	if (n->left == NULL) {
		bst_replace(n, n->right, &bst);
		delete n;
		return bst;
	}
	if (n->right == NULL) {
		bst_replace(n, n->left, &bst);
		delete n;
		return bst;
	}
	//two children
	bst_node<T> *succ = n->right;
	while (succ->left) {
		succ = succ->left;
	}
	bst_replace(succ, null, &bst);
	succ->left = n->left;
	succ->right = n->right;
	delete n;
	return bst;
}

template<typename T>
bst_node<T> *
make_bst(T arr[], size_t arrlen)
{
	bst_node<T> *bst = NULL;
	for (int i = 0; i < arrlen; i++)
		bst = bst_insert(bst, arr[i], bst);
	return bst;
}

template<typename T>
void
print_bst(bst_node<T> *bst)
{
	if (bst == NULL) {
		return;
	}
	printf("%d\n", bst->data);	
	printf("left: ");
	print_bst(bst->left);
	printf("right: ");
	print_bst(bst->right);
	return;
}

int
main(int argc, char *argv[])
{
	int arr[] = { 1, 4, 32, 12, 56, 11, 31, 8 };
	bst_node<int> *bst = make_bst(arr, sizeof(arr)/sizeof(arr[0]));
	//print_bst(bst);
	bst_node<int> *search = bst_find(bst, 1);
	if (search)
		printf("%d %p\n", search->data, (void *)search);
	else
		printf("no match\n");
	bst = bst_delete(bst, 56);
	search = bst_find(bst, 1);
	if (search)
		printf("%d %p\n", search->data, (void *)search);
	else
		printf("no match\n");
	search = bst_find(bst, 4);
	if (search)
		printf("%d %p\n", search->data, (void *)search);
	else
		printf("no match\n");
	search = bst_find(bst, 8);
	if (search)
		printf("%d %p\n", search->data, (void *)search);
	else
		printf("no match\n");
	search = bst_find(bst, 1);
	if (search)
		printf("%d %p\n", search->data, (void *)search);
	else
		printf("no match\n");
	search = bst_find(bst, 99);
	if (search)
		printf("%d %p\n", search->data, (void *)search);
	else
		printf("no match\n");
	return 0;
}

