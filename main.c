#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int key;
    int prior;
    struct node* Left;
    struct node* Right;
} node_t;
typedef node_t treap_rand;

//void PrintTree(treap_rand *t, int n) {
//    int i;
//    if (t != NULL) {
//        PrintTree(t->Right, n + 1);
//        for (i = 0; i < n; i++) putchar(' ');
//        printf("%d\n", t->key);
//        PrintTree(t->Left, n + 1);
//    }
//}


treap_rand* Merge(treap_rand *L, treap_rand *R) {
    if (!L)
        return R;
    if (!R)
        return L;
    if (L->prior > R->prior) {
        L->Right = Merge(L->Right, R);
        return L;
    } else {
        R->Left = Merge(L, R->Left);
        return R;
    }
}

void Split(treap_rand *T, int key, treap_rand **L, treap_rand **R) {
    if (!T) {
        *L = NULL;
        *R = NULL;
        return;
    }
    treap_rand* tmp = NULL;
    if (T->key <= key) {
        Split(T->Right, key, &tmp, R);
        T->Right = tmp;
        *L = T;
    } else {
        Split(T->Left, key, L, &tmp);
        T->Left = tmp;
        *R = T;
    }
}

treap_rand* Insert(treap_rand *T, int key) {
    treap_rand *L = NULL, *R = NULL;
    if (T) {
        Split(T, key, &L, &R);
    }
    node_t* node = malloc(sizeof(node_t));
    if (node) {
        node->key = key;
       //srand(time(NULL));
        node->prior = rand();
        node->Left = NULL;
        node->Right = NULL;
    };
    return Merge(Merge(L, node), R);
}
void deleteTreap(treap_rand* T) {
    if (T) {
        deleteTreap(T->Left);
        deleteTreap(T->Right);
        free(T);
    }
}
treap_rand* treapRemove(treap_rand* T, int key) {
    treap_rand *L, *M, *R;
    Split(T, key - 1, &L, &R);
    Split(R, key, &M, &T);
    deleteTreap(M);
    return Merge(L, T);
}



node_t* treapFind(treap_rand* T, int key) {
    treap_rand* res = NULL;
    while (T) {
        if (T->key == key) {
            res = T;
            break;
        }
        if (T->key > key) {
            T = T->Left;
        } else {
            T = T->Right;
        }
    }
    return res;
}

int main() {
    treap_rand* T = NULL;
    char var;
    int key;
    while (scanf("%c %d\n", &var, &key) > 0) {
        switch (var) {
            case 'a': {
                T = Insert(T, key);
                //PrintTree(T,key);
                break;
            }
            case 'r': {
                T = treapRemove(T, key);
                //PrintTree(T,key);
                break;
            }
            case 'f': {
                if (treapFind(T,key)){
                    printf("%s\n", "yes"); break;
                }
                else {printf("%s\n", "no");break;}
            }
        }
    }
}


