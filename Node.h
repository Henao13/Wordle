#ifndef NODE
#define NODE
#include "colormod.h"
#include <iostream>
using namespace std;
class Node {
public:
  string value;
  Node *next;
  string color;
  Node(string value) {
    this->value = value;
    this->next = NULL;
    this->color="gris";
  }
};
#endif
