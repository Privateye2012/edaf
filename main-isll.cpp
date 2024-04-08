/*
** file: main-isll.cpp
**
** Integer Single Linked List
** UC: 21046 - EDAF @ UAb
** e-fólio A 2022-23
**
** Aluno: 2100900 - Carlos Sampaio
*/

// Defina neste ficheiro:
//   A entrada/saída de dados
//   As instâncias da classe da estrutura de dados
//   A implementação dos comandos através dos métodos da classe
//   Código auxiliar
//   Não utilize variáveis globais

#include <iostream>
#include <sstream>
#include "isll.h"
using namespace std;

//inicialmente foi criado um ficheiro interface.h para a classe Interface
//mas depois percebi que não era possível, e como tal, coloquei o conteúdo da classe no ficheiro main-isll.cpp
//deixando apenas o que dizia respeito às operações da lista ligada no ficheiro isll.h e isll.cpp

//conteúdo do interface.h entretanto eliminado
class Interface {
private:
    string cmd;
    //a classe foi pensada para guardar o comando na string cmd e os argumentos
    //dos comandos num vetor de ints args. Na dúvida se seria permitido utilizar
    //a biblioteca <vector> optei por não usar, mas deixei a estrutura da interface
    //montada na mesma, ainda que a mesma pudesse assim ser facilmente dispensada.
public:
    Interface();
    ~Interface();
    string setcmd(string cmd);
    string getcmd();
    void run();
};


//conteúdo do interface.cpp entreretanto eliminado
Interface::Interface() { //construtor vazio 
}

Interface::~Interface() { //destrutor
}

void Interface::run() {
   //Declaração de variáveis e criação de instâncias
   ISll list; //cria uma instância da classe ISll criando uma lista vazia
   
   int sair=0, arg, pos1, pos2; //variáveis auxiliares
   //sair é uma variável que controla o ciclo do programa
   //arg é uma variável que guarda o argumento do comando
   //pos1 e pos2 são variáveis que guardam as posições dos elementos a serem procurados,
   //devolvidos ou invertidos, conforme a opção.
   
   string input, token; 
   //input é a string que guarda o input do utilizador e token é
   //a string que guarda cada token do input. Inicialmente o input era guardado através
   //de ciclos de getline, quando se verificou era recomendado no enunciado a utilização
   //do operador de extração

   //ciclo do-while, controlado por uma variável de controlo sair, utilizada para os testes
   //realizados localmente. Aquando da utilização de ficheiro, o ciclo é controlado pelo EOF
   do {
      //verificar se atingiu o EOF e terminar o programa
      if (cin.eof()) {
         exit(0);
      }
      
      //limpar memória antes de utilizar getline
      cin.clear();
      getline(cin, input);

      //se o input começar por # ou se for uma linha vazia, ignora
      if (input[0] == '#' || input == "") {
         continue;
      }

      stringstream ss(input); //inicia o stringstream com o input
      ss >> input; //utilização do operador de extração
      setcmd(input); //guarda o comando

      int opt = 0; //reinicia a variavel opt
      //reinicia as variáveis pos1 e pos2
      pos1 = -1;
      pos2 = -1;
      
      //compara o comando recebido, e atribui um valor int à variável opt
      //para utilizar no switch-case implementado de seguida
      if (getcmd() == "insert_0") { opt = 0;}
      else if (getcmd() == "insert_end") { opt = 1;}
      else if (getcmd() == "print_0") { opt = 2;}
      else if (getcmd() == "print") { opt = 3;}
      else if (getcmd() == "delete_0") { opt = 4;}
      else if (getcmd() == "delete_end") { opt = 5;}
      else if (getcmd() == "dim") { opt = 6;}
      else if (getcmd() == "clear") { opt = 7;}
      else if (getcmd() == "find") { opt = 8;}
      else if (getcmd() == "find_max") { opt = 9;}
      else if (getcmd() == "delete_pos") { opt = 10;}
      else if (getcmd() == "invert_range") { opt = 11;}
      else if (getcmd() == "print_end") { opt = 12;}
      else if (getcmd() == "q") {opt = 99;}
      else {
         cout << "Comando invalido." << endl;
         continue;
      } 

      switch (opt) {
      case 0:
         //inserir no inicio da lista
         //lê os argumentos e carrega para a lista ligada
         while (ss >> arg) {
            list.add_head(arg);
            }
         break;
      case 1:
         //inserir no fim da lista
         //lê os argumentos e carrega para a lista ligada
         while (ss >> arg) {
            list.add_tail(arg);
            }
         break;
      case 2:
         //imprime o primeiro elemento da lista
         list.print_0();
         break;
      case 3:
         //verifica se a lista está vazia
         if (list.size() == 0) {
               cout << "Comando print: Lista vazia!" << endl;
         }
         //imprime a lista caso não esteja vazia
         else {
               list.print();
         }
         break;
      case 4:
         //remove o primeiro elemento da lista
         list.remove_head();
         break;
      case 5:
         //remove o último elemento da lista
         list.remove_tail();
         break;
      case 6:
         //imprime o tamanho da lista
         cout << "Lista tem " << list.size() << " itens" << endl;
         break;
      case 7:
         //verifica se a lista está vazia antes de tentar limpar
         if (list.size() == 0) {
               cout << "Comando clear: Lista vazia!" << endl;
         }
         else {
         list.clear(); //limpa a lista
         }
         break;
      case 8:
         //procura um elemento na lista e devolve a sua posição na lista
         ss >> arg; //lê o argumento/elemento a procurar e guarda na variável arg
         pos1 = list.find(arg); //guarda a posição do elemento na variável pos1
         
         if (list.find(arg) == -1) {
               cout << "Elemento nao encontrado" << endl;
         }
         else {
               cout << "Item " << arg << " na posicao " << pos1 << endl;
         }
         break;
      case 9:
         //procura o maior elemento da lista e devolve a sua posição na lista
         if (list.find_max() == -1) {
               cout << "Lista vazia" << endl;
         }
         else {
               cout << "Max Item ";
               list.print_val_max();
               cout << " na posicao " << list.find_max() << endl;
         }
         break;
      case 10:
         //remove um elemento da lista na posição indicada
         ss >> pos1; //lê a posição do elemento a remover
         list.remove_pos(pos1);
         break;
      case 11:
         //inverte os elementos da lista entre as posições indicadas
         ss >> pos1 >> pos2;
         list.invert_range(pos1, pos2);
         break;
      case 12:
         //imprime o último elemento da lista
         list.print_end();
         break;
      case 99:
         sair = 1;
         break;
      default:
         cout << "Comando invalido." << endl; //q sai do programa
      }
   } while (sair != 1);
}

string Interface::setcmd(string cmd) { //setter para o comando
    this->cmd = cmd;
    return cmd;
}


string Interface::getcmd() { //getter para o comando
    return cmd;
}


int main()
{
   //a função main apenas cria um objeto da classe Interface e chama a função run()
   //que controla todo o interface do programa (inputs, outputs, chamadas de funções, etc.)
   Interface interface;
   interface.run();
   return 0;
}

// EOF