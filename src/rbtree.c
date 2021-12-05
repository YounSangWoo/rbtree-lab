
/* ----------------- */
#include <stdio.h>
/* ----------------- */
#include "rbtree.h"
#include <stdlib.h>

rbtree *new_rbtree(void)
{
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));
  // TODO: initialize struct if needed
  return p;
}

void delete_rbtree(rbtree *t)
{
  // TODO: reclaim the tree nodes's memory
  free(t);
}

node_t *rbtree_insert(rbtree *t, const key_t key)
{

  // TODO: implement insert
  node_t *y = t->nil;
  node_t *x = t->root;
  node_t *z = calloc(1, sizeof(node_t));
  z->key = key;

  while (x != t->nil)
  {
    y = x;
    if (key < x->key)
      x = x->left;
    else
      x = x->right;
  }

  z->parent = y;
  if (y == t->nil)
  {
    t->root = z;
  }
  else if (z->key < y->key)
  {
    y->left = z;
  }
  else
    y->right == z;

  z->left = t->nil;
  z->right = t->nil;
  z->color = RBTREE_RED;

  /*   //삽입이후 부모의 색상 비교
  while (z->parent->color == RBTREE_RED)
  {
    if(z->parent == z->parent->parent->left)
    {
      y = z->parent->parent->right;
      if (y->color == RBTREE_RED){
        z->parent->color = RBTREE_BLACK;
        y->color = RBTREE_BLACK;
        z->parent->parent->color = RBTREE_RED;
        z = z->parent->parent;
      }
      else if(z==z->parent->right)
      {
        z = z->parent;
        
      }
    }

  }
 */

  t->root->color == RBTREE_BLACK;

  return t->root;
}

node_t *rbtree_find(const rbtree *t, const key_t key)
{
  // TODO: implement find
  return t->root;
}

node_t *rbtree_min(const rbtree *t)
{
  // TODO: implement find
  node_t *x = t->root;
  while (x->left != t->nil)
  {
    x = x->left;
  }

  return x;
}

node_t *rbtree_max(const rbtree *t)
{
  // TODO: implement find
  node_t *x = t->root;
  while (x->right != t->nil)
  {
    x = x->right;
  }

  return x;
}

int rbtree_erase(rbtree *t, node_t *p)
{
  // TODO: implement erase
  return 0;
}

int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n)
{
  // TODO: implement to_array
  return 0;
}

/* ------------------------------------------------------------- */

node_t *left_rotate(rbtree *t, node_t *x)
{

  return t->root;
}

void main()
{
  int key = 100;
  rbtree *t = new_rbtree();
  node_t *p = rbtree_insert(t, key);

  printf("%d", key);
}