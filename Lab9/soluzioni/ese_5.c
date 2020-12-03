include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct node_s {
    char v;
    struct node_s  left,  right;
} node_t;
typedef node_t * tree;
int palindrome(char [], int);
int palindrome_paths(tree, char [], int);
tree create_tree();
tree createVal(char);
void print(tree);

int main() {
    tree t = create_tree();
    char s[N];
    print(t);
    printf("\n%d", palindrome_paths(t,s,0));

    return 0;
}
void print(tree t){
    if(t==NULL)
        return;
    printf(" (");
    print(t->left);
    printf(" %c ", t->v);
    print(t->right);
    printf(") ");
}

tree create_tree() {
    tree tmp = createVal('a');
    tmp->left = createVal('b');
    tmp->left->left = createVal('a');
    tmp->left->right = createVal('b');
    tmp->right = createVal('a');
    tmp->right->left = createVal('a');
    tmp->right->right = createVal('b');
    tmp->right->right->left = createVal('b');
    tmp->right->right->right = createVal('a');

    return tmp;
}

tree createVal(char val) {
    tree tmp = malloc(sizeof(node_t));
    tmp->v = val;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

int palindrome_paths(tree t, char s[], int h){
    int paths=0;
    if(t->left==NULL && t->right==NULL) {
        s[h] = t->v;
        h++;
        s[h] = '\0';
        return palindrome(s, h);
    }
    s[h]=t->v;
    h++;
    if(t->left!=NULL)
        paths+=palindrome_paths(t->left, s, h);
    if(t->right!=NULL)
        paths+=palindrome_paths(t->right, s, h);

    return paths;

}
int palindrome(char s[], int size){
    int i, flag=1;
    for(i=0; i<size && flag; i++)
        if(s[i]!=s[size-i-1])
            flag=0;
    if(flag)
        return 1;
    else
        return 0;

}

