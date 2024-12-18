    #include <stdio.h>
    #include <stdlib.h>
    #include <locale.h>
    #include <string.h> //para usar strcpy

    // alt + shift + f = arruma o codigo automaticamente

    typedef struct
    { // typedef combina com estrutura para um tipo de dado usando typedef, isso permite agrupar diferentes tipos de dados sob o mesmo nome.
        char nome[30];
        int quantidade;
        float valorTotal;
    } Pedido; // estrutura pra armazenar pedido

    void exibirMenu(); // void = tipo de retorno vazio
    void processarPedido(Pedido Pedido[], int *contadorPedidos, float precos[]);
    void exibirPedido(Pedido pedidos[], int contadoPedidos, float totalGeral);
    void limparTela();
    float calcularTotalGeral(Pedido pedido[], int contadorPedidos);

    void adicionarNovoProduto(char ***produtos, float **precos, int *numProdutos)
    {
        char novoProduto[30];
        float novoPreco;

        printf("Digite o nome do novo produto: ");
        scanf(" %[^\n]", novoProduto); // l� uma linha inteiro, incluindo espa�os

        printf("Digite o pre�o do novo produto: ");
        scanf("%f", &novoPreco);

        // Realoca mem�ria para adicionar um novo produto
        char **tempProdutos = realloc(*produtos, (*numProdutos + 1) * sizeof(char *));
        float *tempPrecos = realloc(*precos, (*numProdutos + 1) * sizeof(float));

        if (tempProdutos == NULL || tempPrecos == NULL)
        {
            printf("Erro ao alocar mem�ria.\n");
            return;
        }

        *produtos = tempProdutos;
        *precos = tempPrecos;

        // aloca memoria para o novo produto
        (*produtos)[*numProdutos] = malloc(strlen(novoProduto) + 1);
        if ((*produtos)[*numProdutos] == NULL)
        {
            printf("Erro ao alocar mem�ria para o novo produto.\n");
            free(tempProdutos); // Libera a mem�ria alocada se realloc falhar
            free(tempPrecos);   // Libera a mem�ria alocada se realloc falhar
            return;
        }

        // Copia o nome do novo produto
        strcpy((*produtos)[*numProdutos], novoProduto);
        (*precos)[*numProdutos] = novoPreco;
        (*numProdutos)++; // incrementa o numero de produtos

        printf("Produto adicionado com sucesso!\n");
    }

    void exibirMenu(char **produtos, float *precos, int numProdutos)
    {
        system("cls");
        printf("\n\n\n=================================================================\n");
        printf("==========** Digite o codigo do produto **=======================\n");
        printf("=================================================================\n");
        for (int i = 0; i < numProdutos; i++)
        {
            printf("%s\t|Pre�o: %.2f R$\t|C�digo:%d\n", produtos[i], precos[i], i + 1);
        }
    }

    int main()
    {

        setlocale(LC_ALL, "Portuguese"); // setlocale(LC_ALL) = acentua��o
        system("color 00");              // cor("color f0") = branco

        int qtd;                           // int = inteiro
        float totalCompra, totalGeral = 0; // totalCompra = soma dos lanches //float = numero real //o geral � utilizado para armazenar
        totalGeral = 0.0;                  // inicia com a compra atual
        int op;
        // op = op��o
        // do-while quando � pra menu, � um la�o de repeti��o( 1 - While, +_2 - Do While, 3 - for)
        // adicionar vetores (Array de strings) para armazenar o produtos e seus pre�os:

        // Declare produtos e precos como ponteiros
        char **produtos = malloc(100 * sizeof(char *));
        float *precos = malloc(100 * sizeof(float));

        // Inicializando os produtos e pre�os
        produtos[0] = malloc(30);
        strcpy(produtos[0], "Cachorro Quente");
        produtos[1] = malloc(30);
        strcpy(produtos[1], "Sanduiche");
        produtos[2] = malloc(30);
        strcpy(produtos[2], "Coxinha");
        produtos[3] = malloc(30);
        strcpy(produtos[3], "Bomba");
        produtos[4] = malloc(30);
        strcpy(produtos[4], "Refrigerante");

        precos[0] = 6.0;
        precos[1] = 5.50;
        precos[2] = 5.0;
        precos[3] = 6.0;
        precos[4] = 3.50;

        int numProdutos = 5; // n�mero de produtos iniciais

        // char *produtos[100] = {"Cachorro Quente", "Sandu�che", "Coxinha", "Bomba", "Refrigerante"};
        // // char = caractere em igles
        // //* = um ponteiro, uma variavel que armazena o endere�o de outra vari�vel na mem�ria.

        // float precos[100] = {6.0, 5.50, 5.0, 6.0, 3.50};
        // float = numero real
        // no c sempre use . para separar numeros reais
        int quantidades[100] = {0, 0, 0, 0, 0};
        // int = numeros inteiros
        // inicializando as quantidades

        Pedido pedidos[100];     // suponha que o maximos de pedidos seja 100
        int contadorPedidos = 0; // contador para os pedidos
        do
        {
            // do = fa�a

            int sair = 0;
            printf("\n\n\n=================================================================\n");
            printf("==========** Digite o codigo do produto **=======================\n");
            printf("=================================================================\n");
            printf("Cachorro Quente\t|Preco: 6.00 R$\t|Codigo:1\n");
            printf("Sanduche\t|Preco: 5.50 R$\t|Codigo:2\n");
            printf("Coxinha\t\t|Preco: 5.00 R$\t|Codigo:3\n");
            printf("Bomba\t\t|Preco: 6.00 R$\t|Codigo:4\n");
            printf("Refrigerante\t|Preco: 3.50 R$\t|Codigo:5\n");
            printf("==================================================================\n");
            printf("==========** Digite [0] Para Finalizar a compra **================\n");
            printf("==================================================================\n");
            printf("==================================================================\n");
            printf("=>");
            scanf("%d", &op);
            // sacnf = ler o valor da variavel
            //%d = pra ler numero inteiro
            //&op = op variavel, & define aonde vai armazenar
            // exemplo:

            system("cls");
            // limpa tela apos o enter

            switch (op)
            {
                system("cls");
                // limpa tela apos o enter

            case 1:
                printf("[Cachorro Quente]\nDigite a quantidade:");
                scanf("%d", &qtd);
                system("cls");

                totalCompra = qtd * precos[0];
                // printf("Valor da compra:%.2f\n", totalCompra);
                totalGeral += totalCompra; // acumulando o total
                //%f = float
                //%.2 antes do f = 2 casa decimais

                strcpy(pedidos[contadorPedidos].nome, produtos[0]);
                pedidos[contadorPedidos].quantidade = qtd;
                pedidos[contadorPedidos].valorTotal = totalCompra;
                contadorPedidos++;

                // break = para o bloco de execu��o
                break;

            case 2:
                printf("[Sanduche]\nDigite a quantidade:");
                scanf("%d", &qtd);
                system("cls");

                totalCompra = qtd * precos[1];
                // printf("Valor da compra:%.2f\n", totalCompra);
                totalGeral += totalCompra; // acumulando o total

                strcpy(pedidos[contadorPedidos].nome, produtos[1]);
                pedidos[contadorPedidos].quantidade = qtd;
                pedidos[contadorPedidos].valorTotal = totalCompra;
                contadorPedidos++;

                // break = para o bloco de execu��o
                break;

            case 3:
                printf("[Coxinha]\nDigite a quantidade:");
                scanf("%d", &qtd);
                system("cls");

                totalCompra = qtd * precos[2];
                // printf("Valor da compra:%.2f\n", totalCompra);
                totalGeral += totalCompra; // acumulando o total

                strcpy(pedidos[contadorPedidos].nome, produtos[2]);
                pedidos[contadorPedidos].quantidade = qtd;
                pedidos[contadorPedidos].valorTotal = totalCompra;
                contadorPedidos++;

                // break = para o bloco de execu��o
                break;

            case 4:
                printf("[Bomba]\nDigite a quantidade:");
                scanf("%d", &qtd);
                system("cls");

                totalCompra = qtd * precos[3];
                // printf("Valor da compra:%.2f\n", totalCompra);
                totalGeral += totalCompra; // acumulando o total

                strcpy(pedidos[contadorPedidos].nome, produtos[3]);
                pedidos[contadorPedidos].quantidade = qtd;
                pedidos[contadorPedidos].valorTotal = totalCompra;
                contadorPedidos++;

                // break = para o bloco de execu��o
                break;

            case 5:
                printf("[Refrigerante]\nDigite a quantidade:");
                scanf("%d", &qtd);

                totalCompra = qtd * precos[4];
                // printf("Valor da compra:%.2f\n", totalCompra);
                totalGeral += totalCompra; // acumulando o total

                strcpy(pedidos[contadorPedidos].nome, produtos[4]);
                pedidos[contadorPedidos].quantidade = qtd;
                pedidos[contadorPedidos].valorTotal = totalCompra;
                contadorPedidos++;

                // break = para o bloco de execu��o
                break;

            case 0:
                printf("[Compra finalizada.]");
                sair = 1;
                // break = para o bloco de execu��o
                break;

            default:
                printf("[Opcao Invalida]\n");
                break;
            }

            // se o int sair = 0, ira continuar e printar oq estar no if. se o sair = 1 voc� sai sem printar oq ta dentro do if

            if (sair == 0)
            {
                for (int i = 0; i < contadorPedidos; i++)
                {
                    printf("%-20s %dx Unidades\t\t\t%.2f R$\n", pedidos[i].nome, pedidos[i].quantidade, pedidos[i].valorTotal); // estava certo, mas estava passando apenas um string (%s), faltando o string (%d) = faltando quantidade (intero) e o valor (real).
                    //%-20s = indica que o texto deve ser alinhado � esquerda, e 20 define a largura do campo como 20 caracteres.
                    //
                }
            }
            // while = enquanto ! = 0
            //!= : diferente
            //! : nega��o
            // diferente de 0 por causa do case 0, se for mudar pra finalizar com 1, ira mudar o case 0 para case 1 e o op != (diferente) 1

        } while (op != 0);

        printf("\n\nPedidos realizados:\n");
        // exibir as quantidades compradas e o total geral
        for (int i = 0; i < contadorPedidos; i++)
        {
            printf("%-20s %dx Unidades\t\t\t%.2f R$\n", pedidos[i].nome, pedidos[i].quantidade, pedidos[i].valorTotal); // estava certo, mas estava passando apenas um string (%s), faltando o string (%d) = faltando quantidade (intero) e o valor (real).
            //%-20s = ndica que o texto deve ser alinhado � esquerda, e 20 define a largura do campo como 20 caracteres.
            //
        }

        // int (inteiro) = 0
        // i <= 5; atribui��o e come�a do 1, ent fica 1,2,3,4,
        // i++ como come�a do i � atribuida a 5 e come�a do 1, soma mais 1, por isso ++

        //%s um string que substitui o valor correspondente que � passsado como argumento produtos [i]
        //%d usado para imprimir um numero inteiro, sera substituido pelo valor correspondete q � passado quantidades [i]
        //: caractere q separa um string (%s) e um numero (%d).
        //\n saltar uma linha

        // for � uma estrutura de repeti��o; i = 0; i < 5 percorre 0 a 4 pq ja come�a do 1; i++ = 4 + 1 (i = i + 1)
        printf("\nTotal geral: %.2f R$\n", totalGeral);

        for (int i = 0; i < numProdutos; i++)
        {
            free(produtos[i]); // Libera cada string alocada
        }
        free(produtos); // Libera o array de ponteiros
        free(precos);   // Libera o array de pre�os

        return 0;
    }
