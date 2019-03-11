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

}

int get_depth(Bst bst){
  return 0;
}

void Insert(int value, Node* start_node);

void add(Bst* bst, int value){
  Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->value = value;
  newNode->left = 0;
  newNode->right = 0;
  if(bst == 0){
    (*bst) = newNode;
    return;
  }
  Insert(value, newNode);
}

void Insert(int value, Node* start_node){
  if(value <= start_node->value){
    if(start_node->left == 0){
      start_node->left = (struct Node*) malloc(sizeof(struct Node));
      start_node->value = value;
      start_node->left = 0;
      start_node->right = 0;
    } else {
      Insert(value, start_node->left);
    }
  } else {
    if(start_node->right == 0){
      start_node->right = (struct Node*) malloc(sizeof(struct Node));
      start_node->value = value;
      start_node->left = 0;
      start_node->right = 0;
    } else {
      Insert(value, start_node->right);
    }
  }
}


int root_value(Bst bst){
  return 0;
}

Bst left_subtree(Bst root){
  return 0;
}

Bst right_subtree(Bst root){
  return 0;
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
