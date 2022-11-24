typedef struct {
    char name[30];
} item_t;

typedef struct node_t {
    item_t item;
    struct node_t* next;
} node_t;

typedef struct {
    node_t* head;
} tree_t;

void add_item(tree_t* list, char* name);
void print_items(tree_t* list);
void deallocate_list(tree_t* list);
