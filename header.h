#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

struct No
{
    int key;
    No *left;
    No *right;
    int FatBal;
};

class ABP
{
private:
    No *raiz;

public:
    ABP() { raiz = NULL; }
    void insert(No **raiz, int value);
    void printOut(No *raiz);
    int printMenu();
    int alturaArv(No *raiz);
    void fatorBalanceamento(No *raiz);
};

void ABP::insert(No **raiz, int value)
{
  No *aux = *raiz;

  while (aux)
  {
    if (value == aux->key)
    {
      return;
    }
    if (value < aux->key)
    {
      raiz = &aux->left;
    }
    else
    {
        raiz = &aux->right;
    }
    aux = *raiz; 
  }

  aux = new No();
  aux->key = value;
  aux->left = NULL;
  aux->right = NULL;
  *raiz = aux;
}

int ABP::alturaArv(No *raiz)
{
  if (raiz == NULL)
  {
    return -1;
  }
  else
  {
    int esq = alturaArv(raiz->left);
    int dir = alturaArv(raiz->right);

    if (esq > dir)
    {
      return esq + 1;
    }
    else
    {
      return dir + 1;
    }
  }
  
}

void ABP::fatorBalanceamento(No *raiz)
{
  if (raiz)
  {
    raiz->FatBal = abs(alturaArv(raiz->left) - alturaArv(raiz->right));
    fatorBalanceamento(raiz->right);
    fatorBalanceamento(raiz->left);
  }
}

void ABP::printOut(No *raiz)
{
    if (raiz)
    {
        printOut(raiz->left);
        std::cout << "   " << raiz->FatBal << "      |      " << raiz->key << std::endl;
        printOut(raiz->right);
    }
}
