typedef struct node
{
    int value;
    struct node* next;
} node;
typedef node* list;

void push(list* L, int x);
void print(list* L);
void push_b4(list* L, int n, int x);
void push_after(list* L, int n, int x);
void push_end(list* L, int x);
int pop(list* L);
int pop_end(list* L);
int pop_num(list* L, int n);
void upor(list* L);
void menu();
