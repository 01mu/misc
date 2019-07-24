/*
 * binary search tree
 * github.com/01mu
 */

#ifndef BST_H_
#define BST_H_

template <class T>
class BST
{
    protected:
    struct Node
    {
        T data;
        Node * left;
        Node * right;
    };

    private:
    Node * root;

    Node * new_node(T data);
    Node * get_min(Node * node);

    Node * insert_a(T data, Node * node);
    Node * remove_a(T data, Node * node);
    void inorder_a(Node * node);
    void postorder_a(Node * node);
    void destructor_a(Node * node);

    public:
    BST(T data);
    BST(T * arr, int size);
    ~BST();

    void insert(T data);
    void remove(T data);
    void inorder();
    void postorder();
};

#endif
