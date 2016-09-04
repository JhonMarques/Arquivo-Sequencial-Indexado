#include <iostream>
#include <conio2.h>
#include <iomanip>
#define  N  10


using namespace std;

struct Indexado{
                 int cod;
                 string nome;
                 string cidade;
                 bool status;
               };

struct manipula{
                 int pos;
                 int cod;
                };

Indexado Registro[N] = {{1, "Gustavo", "Assis", true}, {2, "Pedro", "Candido Mota", false}, {3, "Jhonatas", "New York", true}};
manipula busca[N];
int total = 3;


void Busca();
void Incluir();
void Deletar();
void Imprimir();
void Imprimi_Indices();
void Exaustiva();
void Reorganizar();


int main(){
   //Menu de Entrada
    setlocale(LC_ALL,"PTB");
    textbackground(BLACK);

    int fim = -1;
    int op = -1;
    int i = 0;

    for(i = 0; i<total; i++)
    {
        busca[i].cod = Registro[i].cod;
        busca[i].pos = i;
    }

    textbackground(CYAN);

    while (op != 0){
        clrscr();

        textcolor (WHITE);
        gotoxy(27,1);
        cout<<"Arquivo Sequencial Indexado";
        gotoxy(27, 2);
        cout<<"---------------------------";
        gotoxy(27,4);
        cout<<"Opções:";
        gotoxy(27,6);
        cout<<" 1 - Busca ";
        gotoxy(27,8);
        cout<<" 2 - Inclusão de Registros";
        gotoxy(27,10);
        cout<<" 3 - Exclusão de Registros ";
        gotoxy(27,12);
        cout<<" 4 - Imprimir Registros";
        gotoxy(27,14);
        cout<<" 5 - Imprimir Posições";
        gotoxy(27,16);
        cout<<" 6 - Leitura Exaustiva";
        gotoxy(27,18);
        cout<<" 7 - Reorganizar";
        gotoxy(27,20);
        cout<<" 0 - Sair";
        gotoxy(27,22);
        cout<<"Escolha uma Opção: ";
        cin>>op;
        switch (op){

            case 0: { clrscr();
                        gotoxy(32,6);
                        cout << "Bom Descanso...\n\n";
                        getch();
                        break;
                      }
            case 1:  Busca(); break;
            case 2:  Incluir(); break;
            case 3:  Deletar(); break;
            case 4:  Imprimir();break;
            case 5:  Imprimi_Indices();break;
            case 6:  Exaustiva();break;
            case 7:  Reorganizar();break;

            default: { cout << "\n\n\t\t\t    Opcao Invalida...\n";
                       getch();
                       break;}
       }

    }

}
void Busca(){


    int id;
    int inicio = 0;
    int fim = total;
    int meio = (inicio + fim) / 2;

    clrscr();
    gotoxy(32 , 2);
    cout<<"BUSCA DE REGISTROS";
    gotoxy(32 , 3);
    cout<<"------------------";

    gotoxy(31 , 6);
    cout<<"Código Procurado: ";
    cin >> id;

    while ( inicio <= fim && id != busca[meio].cod )
    {
        if(busca[meio].cod > id)
        {
            fim = meio - 1;
        }
        else
        {
            inicio = meio + 1;
        }

        meio = (fim + inicio)/2;
    }


        if (busca[meio].cod == id && Registro[meio].status == true)
        {
            gotoxy(31, 8);
            cout<<"Cliente: "<< Registro[meio].nome;
            gotoxy(31, 10);
            cout<<"Cidade: "<< Registro[meio].cidade;
        }
        else
        {
             gotoxy(31, 9);
             cout<<"Não Encontrado!";

        }

    getch();
}
void Incluir(){

    char continuar = 'S';
    char confirma;
    int qtd = 0;
    int i = total;

    Indexado aux[N];
    manipula aux2[N];
    int organiza;

   if (total <= N ){
        while (continuar == 'S')
            {
                clrscr();
                gotoxy(30 , 2);
                cout << "Inclusão de Registros";

                gotoxy(30 , 3);
                cout << "---------------------";

                gotoxy(30 , 5);
                cout << "Cod: ";
                cin >> aux[i].cod;


                for(int j = 0; j < total; j++)
                {
                    while (aux[i].cod == Registro[j].cod && Registro[j].status == true)
                    {
                        clrscr();
                        gotoxy(30 , 8);
                        cout<<"Código Já Existente!!!";
                        getch();

                        clrscr();
                        gotoxy(30 , 2);
                        cout<<"Inclusão de Registros";
                        gotoxy(30 , 3);
                        cout<<"---------------------";

                        gotoxy(30 , 5);
                        cout<<"Código: ";
                        cin>>aux[i].cod;

                    }
                }


                gotoxy(30 , 7);
                cout << "Nome: ";
                cin >> aux[i].nome;

                gotoxy(30 , 9);
                cout << "Cidade: ";
                cin >> aux[i].cidade;

                aux[i].status = true;
                aux2[i].cod = aux[i].cod;
                aux2[i].pos = i;

                qtd ++;
                i++;

                gotoxy(23 , 11);
                cout << "Incluir Mais Registros S/N: ";
                cin >> continuar;
                continuar = toupper(continuar);
        }

        clrscr();
        gotoxy(30 , 2);
        cout << "Inclusão de Registros";

        gotoxy(30 , 3);
        cout << "---------------------";

        gotoxy(26 , 6);
        cout << "Salvar Registros Informados S/N: ";
        cin >> confirma;
        confirma = toupper(confirma);

        if (confirma == 'S')
        {
            for(i = total; i < qtd + total; i++)
            {
                Registro[i] = aux[i];
                busca[i] = aux2[i];

            }
            total = total + qtd;
            for (int j = 0; j < total; j++)
            {
                for (int i = j+1; i < total; i++)
                {
                    if (busca[i].cod < busca[j].cod)
                    {
                        organiza = busca[i].cod;
                        busca[i].cod = busca[j].cod;
                        busca[j].cod = organiza;

                        organiza = busca[i].pos;
                        busca[i].pos = busca[j].pos;
                        busca[j].pos = organiza;

                    }
                 }
            }
            gotoxy(28 , 12);
            cout << "Registros Salvos!!!";
            getch();
        }else
        {
            gotoxy(28 , 12);
            cout << "Salvar Não Confirmado!!!";
            getch();
        }
   }else
   {
       cout << "Lista Cheia!!!";
       getch();
   }
}
void Deletar(){
    clrscr();
    int del = 0;
    char confirma = 'N';

    int id;
    int inicio = 0;
    int fim = total;
    int meio = (inicio + fim) / 2;

    gotoxy(31 , 2);
    cout<<"Deletar Registros";
    gotoxy(31 , 3);
    cout<<"-----------------";

    gotoxy(27 , 5);
    cout<<"Informe o Código a Deletar: ";
    cin>> del;

    while ( inicio <= fim && del != busca[meio].cod )
    {
        if(busca[meio].cod > del)
        {
            fim = meio - 1;
        }
        else
        {
            inicio = meio + 1;
        }

        meio = (fim + inicio)/2;
    }


        if (busca[meio].cod == del && Registro[meio].status == true)
        {
            gotoxy(31, 7);
            cout<<"Cliente: "<< Registro[meio].nome;
            gotoxy(31, 8);
            cout<<"Cidade: "<< Registro[meio].cidade;

            gotoxy(30 , 12);
            cout<<"Deseja excluir S/N: ";
            cin >> confirma;
            confirma = toupper(confirma);

            if (confirma == 'S')
            {
                Registro[meio].status = false;
                gotoxy(30 , 15);
                cout<<"Exclusão Realizada";
                getch();
            }
            else
            {
              gotoxy(30 , 15);
              cout<<"Exclusão Cancelada";
              getch();
            }
        }
        else
        {
             gotoxy(30, 9);
             cout<<"Não Encontrado!";
             getch();

        }
};
void Imprimir(){
 clrscr();
 int L = 5;

 gotoxy(36, 2);
 cout << "Registros";

 gotoxy(36, 3);
 cout << "---------";

 for (int i = 0; i < total; i++)
 {   if(Registro[i].status == true)
     {
        gotoxy(23 , L);
        cout<<"Cod: "<< Registro[i].cod << "  Nome: "<< Registro[i].nome <<"  Cidade: "<< Registro[i].cidade;
        L+=2;

     }

 }

getch();

};
void Imprimi_Indices(){
     clrscr();
 int L = 5;

 gotoxy(36, 2);
 cout << "Posições";

 gotoxy(36, 3);
 cout << "--------";

 for (int i = 0; i < total; i++)
 {  if (Registro[i].status == true)
    {
        gotoxy(32 , L);
        cout<<"Cod: "<< busca[i].cod << "  Indice: "<< busca[i].pos;
        L+=2;
    }
 }
 getch();
}
void Exaustiva(){
  clrscr();
  int i = total;
  char salvar;
  Indexado leitura[N];

  gotoxy(30 , 2);
  cout<<"Leitura Exaustiva";
  gotoxy(30 , 3);
  cout<<"-----------------";

  if (i < N)
  {
      gotoxy(30 , 5);
      cout<<"Código: ";
      cin>>leitura[i].cod;

      for(int j = 0; j < total; j++)
      {
        while (leitura[i].cod == Registro[j].cod && Registro[j].status == true )
        {
            clrscr();
            gotoxy(30 , 8);
            cout<<"Código Já Existente!!!";
            getch();

            clrscr();
            gotoxy(30 , 2);
            cout<<"Leitura Exaustiva";
            gotoxy(30 , 3);
            cout<<"-----------------";

            gotoxy(30 , 5);
            cout<<"Código: ";
            cin>>leitura[i].cod;
         }
      }
      gotoxy(30 , 7);
      cout<<"Cliente: ";
      cin>>leitura[i].nome;

      gotoxy(30 , 9);
      cout<<"Cidade: ";
      cin>>leitura[i].cidade;

      leitura[i].status = true;

      gotoxy(28 , 11);
      cout<<"Deseja Salvar Registro S/N: ";
      cin>>salvar;
      salvar = toupper(salvar);

      if (salvar == 'S')
      {
          Registro[i] = leitura[i];
          gotoxy(30 , 14);
          cout<<"Registro Salvo!";
          total += 1;
          getch();
      }

  }


  }
void Reorganizar(){
    clrscr();
    int i = 0;
    char confirma;
    int L = 4;

    gotoxy(29 , 1);
    cout<<"Reorganizar Registros";
    gotoxy(29 , 2);
    cout<<"---------------------";


    for (int i = 0; i < total; i++)
     {
            gotoxy(18 , L);
            cout<<"Cod: "<< Registro[i].cod << "  Nome: "<< Registro[i].nome <<"  Cidade: "<< Registro[i].cidade<< "  Status: "<< Registro[i].status;
            L+=2;
     }

    gotoxy(24 , L+=2);
    cout<<"Deseja Reorganizar o Arquivo S/N: ";
    cin>>confirma;
    confirma = toupper(confirma);

    if (confirma == 'S')
    {
        for ( i = 0; i < total; i++)
        {
            if (Registro[i].status == false)
                {
                    if (i == total)
                    {
                        total--;
                    }
                    else
                    {
                        while (i <= total)
                        {
                            Registro[i] = Registro[i+1];
                            i++;
                        }
                        total--;
                    }
                }
        }
    }
    L = 4;
    clrscr();

    gotoxy(29 , 1);
    cout<<"Reorganizar Registros";
    gotoxy(29 , 2);
    cout<<"---------------------";

    for (int i = 0; i < total; i++)
     {
            gotoxy(18 , L);
            cout<<"Cod: "<< Registro[i].cod << "  Nome: "<< Registro[i].nome <<"  Cidade: "<< Registro[i].cidade<< "  Status: "<< Registro[i].status;
            L+=2;
     }
  gotoxy(26  , L+3);
  cout<< "Registros Reorganizados!!!";
  getch();
}







