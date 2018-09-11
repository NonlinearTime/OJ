#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char val;
    node *left, *right;
};

node* root = nullptr;
char A[30], B[30];
int L;

int find_root_idx(char root, int start, int len) {
    for (int i = start; i < start + len; ++i) {
        if (B[i] == root) return i;
    }
    return -1;
}

node* construct_btree(int ia, int ib, int len) {
    if (len == 0)
        return nullptr;
    node* r = new node();
    r->val = A[ia];
    int rb = find_root_idx(r->val, ib, len);
    r->left = construct_btree(ia + 1, ib, rb - ib);
    r->right = construct_btree(ia + rb - ib + 1, rb + 1, len - rb + ib - 1);
    return r;
}

void Post_order_traversal(node* r) {
    if (r == NULL) return;
    Post_order_traversal(r->left);
    Post_order_traversal(r->right);
    printf("%c", r->val);
    return;

}

int main() {
    scanf("%s%s", A, B);
    L = 0;
    while (A[++L] != '\0');

    root = construct_btree(0, 0, L);

    Post_order_traversal(root);

    return 0;
}