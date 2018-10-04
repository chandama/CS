#ifndef DNODE_H_
#define DNODE_H_

/** A DNode is the building block for a double-linked list. */
struct DNode {
  /** A copy of the data */
  Item_Type data;
  /** A pointer to the next DNode */
  DNode* next;
  /** A pointer to the previous DNode */
  DNode* prev;
  DNode(const Item_Type& the_data, 
        DNode* prev_val = NULL, DNode* next_val = NULL) :
    data(the_data), next(next_val), prev(prev_val) {}
};
#endif
