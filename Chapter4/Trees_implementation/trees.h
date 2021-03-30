
typedef int ElementType;
typedef struct TreeNode * ptrToNode;

struct TreeNode
{
    ElementType element;
    ptrToNode FirstChild;
    ptrToNode NextSibling;
};