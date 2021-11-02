#include <iostream>
#include <cstdlib>
#include "header.h"

int main()
{
    ABP arvore;


    char fileName[11];
    No *raiz = NULL;
    int option;

    std::cout << "Digite o nome do arquivo" << std::endl;
    std::cin >> fileName;
    std::cout << std::endl;

    do
    {
      std::cout << "Escolha uma opção: " << std::endl;
      std::cout << "1) Gerar ABP" << std::endl;
      std::cout << "2) Calcular Fator de Balanceamento" << std::endl;
      std::cout << "3) Imprimir ABP" << std::endl;
      std::cout << "4) Sair" << std::endl;
      std::cin >> option;

      switch (option)
      {
        case 1: {
          std::system("clear");
          FILE *fp;
          char ch, valor[5];
          int count = 0, val;
          fp = fopen(fileName, "r");
          for (int i = 0; i < 5; i++){
              valor[i] = '\0';
          }
          while (!feof(fp))
          {
              ch = fgetc(fp);
              if (ch == ',' || ch == EOF)
              {
                  val = atol(valor);
                  arvore.insert(&raiz, val);
                  printf("Valor lido: %s\n", valor);
                  for (int i = 0; i < 5; i++)
                  {
                      valor[i] = '\0';
                  }
                  count = 0;
              }
              else
              {
                  valor[count] = ch;
                  count++;
              }
          }
          fclose(fp);
          std::cout << "ABP gerada com sucesso!" << std::endl;
          std::cout << std::endl;
        }
           break;

        case 2: 
          std::system("clear");
          arvore.fatorBalanceamento(raiz);
          std::cout << "Fator de balanceamento calculado com sucesso!" << std::endl;
          std::cout << std::endl;
          break;

        case 3: 
          std::system("clear");
          std::cout << "FatBal" << "    |     " << "Chave" << std::endl;
          arvore.printOut(raiz);
          std::cout << std::endl;
          break;

        case 4: 
          std::system("clear");
          std::exit(0);
          break;

        default:
          std::cout << "Por favor, digite uma opção válida" << std::endl;
          break;
      }

    } while (option != 4);
}