#include "LinkedList.h"
#include "Node.h"
#include "colormod.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;

string aleatoria();
void presentacion();
bool BancoPalabra(string);

int main() {

  string a;
  int b;
  int temp = 0;
  presentacion();
  a = aleatoria();
  b = a.length();

  LinkedList l1 = LinkedList();
  while (temp < a.length()) {
    l1.add_at_head(a.substr(a.length() - 1 - temp, 1));
    temp += 1;
  }

  temp = 0;
  int temp2 = 0;
  LinkedList l2 = LinkedList();

  while (temp < 6) {

    cout << "Ingrese una palabra de " << b << " letras" << endl;
    cin >> a;
    for (int letra = 0; letra < a.size(); letra++) {
      a[letra] = toupper(a[letra]);
    }
    if (BancoPalabra(a) == false) {
      cout << "intento invalido" << endl;
      continue;
    }
    if (l2.CompararPalabra(l1) == false) {
      cout << "La palabra ingresada contiene diferente tamaño de letras"
           << endl;
      continue;
    }
    while (temp2 < b) {
      l2.add_at_head(a.substr(b - 1 - temp2, 1));
      temp2 += 1;
    }

    l2.comparar(l1, b);
    l2.printList();
    temp += 1;
    temp2 = 0;
    if (temp == 6) {
      l2.perdiste();
    }
    l2.head = NULL;
  }
}

void presentacion() {

  cout << "Bienvenido a wordle" << endl;
  cout << "creado por: Santiago Henao y Juan David Zapata Moncada" << endl;
  cout << "Escriba si para comezar el juego" << endl;
  string a;
  cin >> a;
  if (a == "si") {
    cout << "iniciando juego" << endl;
  } else {
    exit(1);
  }
}

string aleatoria() {
  srand(time(NULL));
  int a;
  a = 1 + rand() % 1791;
  cout << "numero aleatorio: " << a << endl;
  int temp = 1;

  string nombreArchivo = "data.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  while (getline(archivo, linea)) {
    if (temp == a) {
      return linea;
    }
    temp += 1;
  }
  return 0;
}
bool BancoPalabra(string palabra) {
  cout << "comprobando que la palabra ingresada esté en el banco... " << endl;
  string nombreArchivo = "data.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  while (getline(archivo, linea)) {
    if (linea == palabra) {
      cout << "efectivamente si pertenece al banco " << linea << endl;
      return true;
    }
  }
  return false;
}
