//
//  main_es6.c
//  lab9
//
//  Created by ing.conti on 11/12/2018.
//  Copyright © 2018 ing.conti. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct ET {
    char dato;
    struct ET * left, * right;
} treeNode;


// per comodita:
typedef enum  {
    FALSE = 0,
    TRUE = 1
} BOOL;

typedef treeNode * tree;
// copiamo f. di supporto da altri es:
tree creaAlbero(void);
tree createVal(char val);
void print(tree t);

//int contains (tree t, char word[]);
// oppure...
BOOL contains (tree t, char *word);

int main(){
    tree alb = creaAlbero();
    print(alb);
    
    char s1[] = "mio";
    BOOL ok1 = contains(alb, s1);
    printf("\n%d\n", ok1);

    char s2[] = "ciao";
    BOOL ok2 = contains(alb, s2);
    printf("\n%d\n", ok2);

    char s3[] = "ciaz";
    BOOL ok3 = contains(alb, s3);
    printf("\n%d\n", ok3);
}


//////

tree creaAlbero() {
    tree tmp = createVal('o');
    tmp->left = createVal('i');
    tmp->left->left = createVal('m');
    tmp->left->right = createVal('z');
    tmp->right = createVal('a');
    tmp->right->left = createVal('m');
    tmp->right->right = createVal('i');
    tmp->right->right->left = createVal('c');
    tmp->right->right->right = createVal('m');
    
    return tmp;
}



//                            o
//                           / \
//                          /   \
//                         /     \
//                        /       \
//                       /         \
//                      /           \
//                     i             a
//                    / \           / \
//                   /   \         /   \
//                  /     \       /     \
//                 m       z     t       i
//                                      /  \
//                                     c    m

tree createVal(char val) {
    tree tmp = malloc(sizeof(treeNode));
    tmp->dato = val;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

// modificata x stampare nuovo tipo:
void print(tree t){
    if(t==NULL)
        return;
    printf(" (");
    print(t->left);
    printf("%c", t->dato);
    print(t->right);
    printf(") ");
}



BOOL contains (tree t, char *word){
    if(t==NULL && *word == 0)
        return TRUE;

    size_t len = strlen(word);
    // guardo ultimo: se diverso false..
    // se uguale ricorro ...
    char *lastchar = word+len-1;
    if (*lastchar != t->dato)
        return FALSE;

    char buff[128];
    // il nuovo buffer deve essere pu corta di 1
    strncpy(buff, word, len-1);
    //termino stringa
    buff[len-1] = 0;
    
    BOOL L_contains = contains(t->left, buff);
    BOOL R_contains = contains(t->right, buff);
    return L_contains || R_contains;
}
