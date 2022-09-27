#pragma once
#include <iostream>
#include "Node.h"
#include "colormod.h"
using namespace std;


Color::Modifier rojo(Color::FG_RED);
Color::Modifier verde(Color::FG_GREEN);
Color::Modifier gris(Color::FG_DEFAULT);
Color::Modifier amarillo(Color::FG_YELLOW);


class LinkedList{
  public:
  Node* head = NULL;
  void add_at_head(string value) {
    Node* new_node = new Node(value);
    if(this->head == NULL)
    {
      this->head = new_node;
    }
    else
    {
      Node* aux_node = this->head;
      new_node->next = aux_node;
      this->head = new_node;
    }
  }

  
  void printList(){
    Node *aux=head;
    while(aux){
      if(aux->color=="verde"){
        cout<<verde<<aux->value;
        
      }
      else if(aux->color=="amarillo"){
        cout<<amarillo<<aux->value;
      }
      else{
         cout<<gris<<aux->value;
      }
    aux=aux->next;
    }
    cout<<gris<<endl;
    
  }

 void perdiste(){
   while(this->head){
     cout<<rojo<<this->head->value;
     head=head->next;
   }
   cout<<endl;
   cout<<rojo<<"has exedido el limite de intentos y no lograste adivinar la palabra"<<endl;
   exit(1);
  }

int size(Node* l1)
{
  
  if(this->head->next==NULL)
    {
        return 0;
    }
    else
    {
        return 1 + size(l1);
    }
}

void comparar(LinkedList l1,int a){
  Node *aux=this->head;
  Node *aux2=l1.head;
  int contador=0;
  while(aux){
    if(aux->value==aux2->value){
      aux->color="verde";
      contador+=1;
    }
    aux=aux->next;
    aux2=aux2->next;
    
  }
  if(contador==a){
    printList();
    cout<<endl;
   cout<<verde<<"Has logrado adivinar la palbra felicidades"<<endl;
   exit(1);
  }
  aux=this->head;
  aux2=l1.head;
  while(aux){
    if(aux->color=="gris"){
      while(aux2){
        if(aux->value==aux2->value){
          aux->color="amarillo";
        }
        aux2=aux2->next;
      }
      aux2=l1.head;
    }
    aux=aux->next;
  }
  }
};
