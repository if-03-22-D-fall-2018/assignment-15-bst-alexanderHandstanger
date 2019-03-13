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
  return 0;
}

int traverse_in_order(Bst bst, int *elements, int start){
  return 0;
}

int traverse_post_order(Bst bst, int *elements, int start){
  return 0;
}

bool are_equal(Bst bst1, Bst bst2){
  return false;
}

void most_left_longest_branch(Bst bst, Bst* branch){

}

int get_number_of_subtrees(Bst bst){
  return 0;
}
