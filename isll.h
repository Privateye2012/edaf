/*
** file: isll.h
**
** Integer Single Linked List
** UC: 21046 - EDAF @ UAb
** e-fólio A 2022-23
**
** Aluno: 2100900 - Carlos Sampaio
*/

// Defina:
// em file.h as classes da estrutura de dados
// em file.cpp a implementação dos métodos das classes da estrutura de dados

#include <iostream>

using namespace std;


// definir nó
struct INode {
   // atributos obrigatórios
   int item;             // informação em cada nó
   INode *next;			 // Single Linked List, aponta apenas para o pr?ximo n?
   // outros atributos e métodos (protótipos) livres

};

// definir lista simplesmente ligada
class ISll {
private:
   // atributos obrigatórios
   int n;                // dimensão atual da lista
   INode *head;          // Single Linked List, aponta apenas para a cabeça da lista, não precisa de apontador para a cauda
   // outros atributos e métodos (protótipos) livres
public:
   // métodos obrigatórios
   ISll();               // construtor
   ~ISll();              // destrutor
   bool isEmpty();       // verifica se a lista está vazia
   int size();           // retorna o número de elementos da lista
   void add_head(int);        // adiciona um elemento no início da lista
   void add_tail(int);        // adiciona um elemento no final da lista
   void add_pos(int, int);   // adiciona um elemento na posição indicada
   void remove_head();     // remove o primeiro elemento da lista
   void remove_tail();     // remove o último elemento da lista
   void remove_pos(int);   // remove um elemento da posição indicada
   int find(int);         // a posição do elemento indicado
   int find_max();        // retorna a posição do maior elemento da lista
   void invert_range(int, int); // inverte a ordem dos elementos entre as posições indicadas
   void clear();         // limpa a lista
   void print_0();         // imprime o primeiro elemento da lista
   void print();         // imprime a lista
   void print_end();         // imprime o último elemento da lista
   void print_val_max();    // imprime o maior elemento da lista
   // outros métodos (protótipos) livres
};

// EOF

