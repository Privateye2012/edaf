/*
** file: isll.cpp
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

#include "isll.h"

using namespace std;

ISll::ISll() {
    //cria lista vazia com 0 itens e a head a apontar para a tail=NULL
    n = 0;
    head = NULL;
}

ISll::~ISll() {
    //destrutor chama o m?todo clear
    clear();
}

bool ISll::isEmpty() {
    //verifica se a lista est? vazia (true/false)
    return n == 0;
}

int ISll::size() {
    //retorna o n?mero de elementos da lista
    return n;
}

void ISll::add_head(int item) {
    //adiciona um elemento no início da lista
    //cria um novo n? com o valor indicado e o aponta para a head que existia antes da cria??o do novo n?
    //a head passa a apontar para o novo n?, e a head anterior passa a ser o segundo n? da lista
    //aumenta o n?mero de elementos da lista
    INode *newNode = new INode;
    newNode->item = item;
    newNode->next = head;
    head = newNode;
    n++;
}

void ISll::add_tail(int item) {
    //adiciona um elemento no final da lista
    //cria um novo n? com o valor indicado e o aponta para NULL, passando a ser a nova tail
    //verifica se a head era simultaneamente tail, se sim, aponta a head para o novo n?
    //caso a head n?o fosse simultaneamente tail, percorre a lista at? a encontrar e aponta a tail anterior 
    //para o novo n?, que como j? vimos ? a nova tail
    INode *newNode = new INode;
    newNode->item = item;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    }
    else {
        INode *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    n++;
}

void ISll::add_pos(int item, int pos) {
    //adiciona um elemento na posição indicada
    //verifica se a posi??o indicada ? v?lida
    if (pos < 0 || pos > n) {
        cout << "Posicao invalida" << endl;
        return;
    }
    if (pos == 0) { //se a posi??o for 0, adiciona no in?cio
        add_head(item);
        return;
    }
    //caso n?o seja 0, cria um novo n? com o valor indicado e o aponta para o n? que estava na posi??o indicada
    //o n? anterior passa a apontar para este novo n?
    INode *newNode = new INode;
    newNode->item = item;
    INode *current = head;
    for (int i = 0; i < pos - 1; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    n++;
}



void ISll::remove_head() {
    //remove o primeiro elemento da lista
    //verifica se a lista est? vazia
    if (head == NULL) {
        cout << "Comando delete_0: Lista vazia!" << endl;
        return;
    }
    //caso n?o esteja, cria um n? tempor?rio, aponta-o para a head e aponta a head para o segundo n? da lista
    //apaga o n? tempor?rio e diminui o n?mero de elementos da lista
    INode *temp = head;
    head = head->next;
    delete temp;
    n--;
}

void ISll::remove_tail() {
    //remove o último elemento da lista
    //verifica se a lista est? vazia
    if (head == NULL) {
        cout << "Comando remove_tail: Lista vazia!" << endl;
        return;
    }
    if (head->next == NULL) { //se a lista tiver apenas um elemento, apaga a head e fica lista vazia
        delete head;
        head = NULL;
        n--;
        return;
    }
    //caso n?o se verifique nenhuma das hip?teses acima, percorre a lista at? encontrar a tail
    //apaga a tail e aponta o n? anterior para NULL, passando a ser a nova tail
    INode *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    delete current->next;
    current->next = NULL;
    n--;
}

void ISll::clear() {
    //limpa a lista
    //percorre a lista e apaga cada n?
    while (head != NULL) {
        INode *temp = head;
        head = head->next;
        delete temp;
    }
    n = 0;
}

int ISll::find(int elem) {
    //retorna a posição do elemento indicado ou -1 se não existir
    if (head == NULL) {
        return -1;
    }
    //percorre a lista at? encontrar o elemento ou at? chegar ao fim da lista
    INode *current = head;
    int pos = 0;
    while (current != NULL) {
        if (current->item == elem) {
            return pos;
        }
        current = current->next;
        pos++;
    }
    return -1;
}

int ISll::find_max() {
    //retorna a posição do elemento máximo ou -1 se a lista estiver vazia
    if (head == NULL) {
        return -1;
    }
    //percorre a lista at? encontrar o elemento máximo ou at? chegar ao fim da lista
    //guarda o primeiro elemento como sendo o m?ximo, e vai verificando os seguintes
    //se encontrar um elemento maior, guarda-o como sendo o m?ximo nas vari?veis pos e pos_max
    INode *current = head;
    int max = current->item;
    int pos = 0;
    int pos_max = 0;
    while (current != NULL) {
        if (current->item > max) {
            max = current->item;
            pos_max = pos;
        }
        current = current->next;
        pos++;
    }
    return pos_max;
}

void ISll::remove_pos(int pos) {
    //remove um elemento da lista
    if (pos < 0 || pos >= n) {
        cout << "Comando delete_pos: Posicao invalida!" << endl;
        return;
    }
    if (pos == 0) {
        INode *temp = head;
        head = head->next;
        delete temp;
        n--;
        return;
    }
    INode *current = head;
    for (int i = 0; i < pos - 1; i++) {
        current = current->next;
    }
    INode *temp = current->next;
    current->next = current->next->next;
    delete temp;
    n--;
}

void ISll::invert_range(int pos1, int pos2) {
    //inverte todos os elementos entre as posições indicadas
    if (pos1 < 0 || pos1 >= n || pos2 < 0 || pos2 >= n) {
        cout << "Posicao invalida" << endl;
        return;
    }

    //criar lista auxiliar
    ISll templist;
    INode *temp = head;
    //guarda na lista auxiliar as posições indicadas de forma invertida
    for (int i = 0; i <= pos2; i++) {
        if (i >= pos1) {
            templist.add_head(temp->item);
        }
        temp = temp->next;
    }
    //guarda na lista original as posições indicadas de forma invertida
    temp = head;
    //INode *temp2 = templist.head;
    for (int i = 0; i <= pos2; i++) {
        if (i >= pos1) {
            temp->item = templist.head->item;
            templist.remove_head();
        }
        temp = temp->next;
    }
}

void ISll::print_0() {
    //imprime o primeiro elemento da lista
    if (head == NULL) {
        cout << "Lista vazia" << endl;
        return;
    }
    cout << "Lista(0)=" << " " << head->item << endl;
} 

void ISll::print() {
    //percorre a lista e vai imprimindo n? a n?
    INode *current = head;
    cout << "Lista=";
    while (current != NULL) {
        cout << " " << current->item;
        current = current->next;
    }
    cout << endl;
}

void ISll::print_end() {
    //imprime o último elemento da lista
    //verifica se a lista est? vazia
    if (head == NULL) {
        cout << "Lista vazia" << endl;
        return;
    }
    //percorre a lista at? encontrar a tail
    INode *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    cout << "Lista(end)=" << " " << current->item << endl;
}

void ISll::print_val_max() {
    //imprime o valor máximo da lista
    if (head == NULL) {
        cout << "Lista vazia" << endl;
        return;
    }
    INode *current = head;
    int max = current->item;
    while (current != NULL) {
        if (current->item > max) {
            max = current->item;
        }
        current = current->next;
    }
    cout << max;
}

// EOF