#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "abb.h"

struct _s_abb {
    abb_elem elem;
    struct _s_abb *left;
    struct _s_abb *right;
};

static bool elem_eq(abb_elem a, abb_elem b) {
    return a == b;
}

static bool elem_less(abb_elem a, abb_elem b) {
    return a < b;
}

static bool invrep(abb tree) {
    /*
     * Needs implementation
    */
    if(tree == NULL) return true;
    return true;
}

abb abb_empty(void) {
    abb tree;
    /*
     * Needs implementation
    */
    tree = NULL;
    assert(invrep(tree) && abb_is_empty(tree));
    return tree;
}

abb abb_add(abb tree, abb_elem e) {
    assert(invrep(tree));
    /*
     * Needs implementation
    */
    if(abb_is_empty(tree)){
        abb new_node = calloc(1, sizeof(struct _s_abb));
        new_node->elem = e;
        new_node->left = abb_empty();
        new_node->right = abb_empty();
        tree = new_node;
    }else{
        if(elem_less(e, tree->elem)){
            tree->left = abb_add(tree->left, e);
        }else if(elem_less(tree->elem, e)){
            tree->right = abb_add(tree->right, e);
        }
    }

    assert(invrep(tree) && abb_exists(tree, e));
    return tree;
}

bool abb_is_empty(abb tree) {
    assert(invrep(tree));
    /*
     * Needs implementation
    */
    return tree == NULL;
}

bool abb_exists(abb tree, abb_elem e) {
    bool exists;
    assert(invrep(tree));
    /*
     * Needs implementation
    */
    if(abb_is_empty(tree)){
        exists =  false;
    }else if(elem_eq(tree->elem, e)){
        exists = true;
    }else if(elem_less(e, tree->elem)){
        exists = abb_exists(tree->left, e);
    }else if(elem_less(tree->elem, e)){
        exists = abb_exists(tree->right, e);
    }

    return exists;
}

unsigned int abb_length(abb tree) {
    unsigned int length=0;
    assert(invrep(tree));
    /*
     * Needs implementation
    */
    abb aux = tree;
    if(!abb_is_empty(aux)){
        length = abb_length(aux->left) + abb_length(aux->right) + 1;
    }
    assert(invrep(tree) && (abb_is_empty(tree) ||  length > 0));
    return length;
}

abb abb_remove(abb tree, abb_elem e) {
    assert(invrep(tree));
    /*
     * Needs implementation
    */
    if(abb_is_empty(tree)){
        return tree;
    }else if(elem_less(e, tree->elem)){
        tree->left = abb_remove(tree->left, e);
    }else if(elem_less(tree->elem, e)){
        tree->right = abb_remove(tree->right, e);
    }else if(abb_is_empty(tree->left) && abb_is_empty(tree->right)){
        free(tree);
        tree = NULL;
    }else if(abb_is_empty(tree->left)){
        abb aux = tree->right;
        free(tree);
        tree = aux;
    }else if(abb_is_empty(tree->right)){
        abb aux = tree->left;
        free(tree);
        tree = aux;
    }else{
        tree->elem = abb_min(tree->right);
        tree->right = abb_remove(tree->right, tree->elem);
    }
    assert(invrep(tree) && !abb_exists(tree, e));
    return tree;
}

abb_elem abb_root(abb tree) {
    abb_elem root;
    assert(invrep(tree) && !abb_is_empty(tree));
    /*
     * Needs implementation
    */
    root = tree->elem;
    assert(abb_exists(tree, root));
    return root;
}

abb_elem abb_max(abb tree) {
    abb_elem max_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    /*
     * Needs implementation
    */
    abb aux = tree;
    while(aux->right != NULL){
        aux = aux->right;
    }
    max_e = aux->elem;
    assert(invrep(tree) && abb_exists(tree, max_e));
    return max_e;
}

abb_elem abb_min(abb tree) {
    abb_elem min_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    /*
     * Needs implementation
    */
    abb aux = tree;
    while(aux->left != NULL){
        aux = aux->left;
    }
    min_e = aux->elem;
    assert(invrep(tree) && abb_exists(tree, min_e));
    return min_e;
}

void abb_dump(abb tree) {
    assert(invrep(tree));
    
    if (tree != NULL) {
        printf("%d ", tree->elem);
        abb_dump(tree->left);
        //printf("%d ", tree->elem);
        abb_dump(tree->right);
        /*No importa el orden del subarbol que se se imprime primero, puede imprimirse
         *primero el de la derecha y luego el de la izquierda, al imprimirse tendra otro orden,
         *pero al rearmar el arbol sera exactamente igual
         */   
    }

}

abb abb_destroy(abb tree) {
    assert(invrep(tree));
    /*
     * Needs implementation
    */
    if(!abb_is_empty(tree->left)){
        tree->left = abb_destroy(tree->left);
    }
    if(!abb_is_empty(tree->right)){
        tree->right = abb_destroy(tree->right);
    }
    free(tree);
    tree = NULL;
    assert(tree == NULL);
    return tree;
}

