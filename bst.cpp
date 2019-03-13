/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			bst.cpp
 * Author(s):		Peter Bauer
 * Due Date:		May 31, 2017
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include <stdlib.h>
#include "bst.h"
#include "general.h"

struct Node{
  int value;
  struct Node* right;
  struct Node* left;
};


Bst new_bst(){
  return 0;
}

void delete_bst(Bst bst){
  if(bst == 0){
    return;
  }
  delete_bst(bst->left);
  delete_bst(bst->right);
  sfree(bst);
}

int get_depth(Bst bst){
  if(bst == 0){
    return 0;
  }
  int leftDepth = get_depth(bst->left);
  int rightDepth = get_depth(bst->right);

  if(leftDepth > rightDepth){
    return leftDepth+1;
  } else {
    return rightDepth+1;
  }
}

Node* createNewNode (int value);

void add(Bst* bst, int value){
  if((*bst) == 0){
    Node* newNode = createNewNode(value);
    (*bst) = newNode;
    return;
  }
  if(value <= (*bst)->value){
    if((*bst)->left == 0){
      Node* newNode = createNewNode(value);
      (*bst)->left = newNode;
    } else {
      Node* next = (*bst)->left;
      add(&next, value);
    }
  } else {
    if((*bst)->right == 0){
      Node* newNode = createNewNode(value);
      (*bst)->right = newNode;
    } else {
      Node* next = (*bst)->right;
      add(&next, value);
    }
  }
}

Node* createNewNode (int value){
  Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->value = value;
  newNode->left = 0;
  newNode->right = 0;
  return newNode;
}

int root_value(Bst bst){
  if(bst == 0){
      return 0;
  }
  return bst->value;
}

Bst left_subtree(Bst root){
  if(root == 0){
      return 0;
  }
  return root->left;
}

Bst right_subtree(Bst root){
  if(root == 0){
      return 0;
  }
  return root->right;
}

int traverse_pre_order(Bst bst, int *elements, int start){
  if(bst == 0){
    return start;
  }
  elements[start] = bst->value;
  start++;
  start = traverse_pre_order(bst->left, elements, start);
  start = traverse_pre_order(bst->right, elements, start);
  return start;
}

int traverse_in_order(Bst bst, int *elements, int start){
  if(bst == 0){
    return start;
  }
  start = traverse_in_order(bst->left, elements, start);
  elements[start] = bst->value;
  start++;
  start = traverse_in_order(bst->right, elements, start);
  return start;
}

int traverse_post_order(Bst bst, int *elements, int start){
  if(bst == 0){
    return start;
  }
  start = traverse_post_order(bst->left, elements, start);
  start = traverse_post_order(bst->right, elements, start);
  elements[start] = bst->value;
  start++;
  return start;
}

bool are_equal(Bst bst1, Bst bst2){
  if(bst1 == 0 && bst2 == 0){
    return true;
  }
  if(get_depth(bst1) == get_depth(bst2)){
    int *elements = new int[get_depth(bst1)];
    traverse_in_order(bst1, elements, 0);
    int *elements1 = new int[get_depth(bst2)];
    traverse_in_order(bst2, elements1, 0);
    for (int i = 0; i < get_depth(bst1)+1; i++) {
      if(elements[i] != elements1[i]){
        return false;
      }
    }
    if(bst1->value == bst2->value){
      return true;
    }
  }
  return false;
}

void most_left_longest_branch(Bst bst, Bst* branch){
  if(bst == 0){
    return;
  }
  if(get_depth(bst->right) > get_depth(bst->left)){
    add(branch, bst->value);
    most_left_longest_branch(&(*bst->right), branch);
  } else if (get_depth(bst->right) <= get_depth(bst->left)){
    add(branch, bst->value);
    most_left_longest_branch(&(*bst->left), branch);
  }
}

int get_number_of_subtrees(Bst bst){
  if(bst == 0){
    return -1;
  }
  int *elements = new int[get_depth(bst)];
  int solution = traverse_in_order(bst, elements, 0);
  return solution-1;
}
