/*
 * binary search tree
 * github.com/01mu
 */

#include "bst.h"

#ifndef BST_CPP_
#define BST_CPP_

template <class T>
BST<T>::BST(T data)
{
    root = new_node(data);
}

template <class T>
BST<T>::BST(T * arr, int size)
{
    int i;

    root = new_node(arr[0]);

    for(i = 1; i < size; i++)
    {
        insert(arr[i]);
    }
}

template <class T>
BST<T>::~BST()
{
    destructor_a(root);
}

template <class T>
void BST<T>::destructor_a(Node * node)
{
    Node * right = NULL;

    if(node != NULL)
    {
        right = node->right;

        destructor_a(node->left);
        delete node;
        destructor_a(right);
    }
}

template <class T>
typename BST<T>::Node * BST<T>::get_min(Node * node)
{
    Node * min = NULL;

    while(node->left != NULL)
    {
        min = node->left;
    }

    return min;
}

template <class T>
void BST<T>::remove(T data)
{
    remove_a(data, root);
}

template <class T>
typename BST<T>::Node * BST<T>::remove_a(T data, Node * node)
{
    Node * temp = NULL;

    if(node == NULL)
    {
        return node;
    }

    if(data < node->data)
    {
        node->left = remove_a(data, node->left);
    }
    else if(data > node->data)
    {
        node->right = remove_a(data, node->right);
    }
    else
    {
        if(node->left == NULL)
        {
            temp = node->right;

            delete node;
            return temp;
        }
        else if(node->right == NULL)
        {
            temp = node->left;

            delete node;
            return temp;
        }

        temp = get_min(node->right);

        node->data = temp->data;
        node->right = remove_a(temp->data, node->right);
    }

    return node;
}

template <class T>
typename BST<T>::Node * BST<T>::new_node(T data)
{
    Node * node = new Node;

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

template <class T>
void BST<T>::insert(T data)
{
    insert_a(data, root);
}

template <class T>
typename BST<T>::Node * BST<T>::insert_a(T data, Node * node)
{
    if(node == NULL)
    {
        return new_node(data);
    }

    if(data < node->data)
    {
        node->left = insert_a(data, node->left);
    }
    else if(data > node->data)
    {
        node->right = insert_a(data, node->right);
    }
}

template <class T>
void BST<T>::inorder()
{
    inorder_a(root);
}

template <class T>
void BST<T>::inorder_a(Node * node)
{
    if(node != NULL)
    {
        inorder_a(node->left);
        printf("%d \n", node->data);
        inorder_a(node->right);
    }
}

template <class T>
void BST<T>::postorder()
{
    postorder_a(root);
}

template <class T>
void BST<T>::postorder_a(Node * node)
{
    if(node != NULL)
    {
        postorder_a(node->right);
        printf("%d \n", node->data);
        postorder_a(node->left);
    }
}

#endif
