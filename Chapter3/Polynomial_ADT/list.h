//list for polynomial with operation add and times

struct node
{
    int Coefficient;
    int Exponent;
    struct node * next;
};
typedef struct node Node;
typedef Node * List;

void Initialization(List * plist);
void add_node(List * plist, Node * pnode);
void List_add(const List * plist1, const List * plist2, List * plist_sum);
void List_product(const List * plist1, const List * plist2, List * plist_prod);
void EmptytheList(List * plist);
void NodeCopy(const Node * pnode_from, Node * pnode_to);