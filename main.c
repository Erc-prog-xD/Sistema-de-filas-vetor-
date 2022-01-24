#include <stdlib.h>
#include <stdio.h>
#include "fila.h"


/* funções que vão servir para mostrar o menu e retornar um valor*/
int menuInicial()
{
    int n;
    printf("\n1 - Menu caixa\n2 - Menu cliente\n3 - Encerrar\nEscolha:");
    scanf("%d", &n);
     if(n < 1 || n > 3)
    {
        printf("\n|Valor inexistente|\n");
        return 0;
    }
    else
    {
        return n;
        printf("\n");
    }
    
}
int opCaixa()
{
    int ca;
    printf("\n1 - Chamar o proximo\n2 - Visualizar as filas\n3 - Listar quantidade de atendimentos\n4 - Voltar ao menu anterior\nEscolha:");
    scanf("%d", &ca);
    if(ca < 1 || ca>4)
    {
        printf("\n|Valor inexistente|\n");
        return 0;
    }
    else
    {
        return ca;
        printf("\n");
    }
    
}
int opCliente()
{
    int cl;
    printf("\nRETIRA SENHA\n1 - Normal\n2 - Prioritaria\n3 - voltar ao menu anterior\nEscolha:");
    scanf("%d", &cl);
     if(cl < 1 || cl>3)
    {
        printf("\n|Valor inexistente|\n");
        return 0;
    }
    else
    {
        return cl;
        printf("\n");
    }
    
  
}

int main()  
{
     Fila * normal = criaFila();
     Fila * prioritaria = criaFila();
     int filNomal = 1;
     int filPriori = 1;
     int cont = -1;
     int contRemover = 0;
     int qntAtendimentosNormais = 0;
     int qntAtendimentosPrioritaria = 0;

/* o while serve para o programa se manter ativo e o cont = -1 só pode ser mudado quando a opção encerrar
for escolhida, assim mudado esse valor de cont e liberando a memoria das duas filas parando o loop de todo o programa*/ 
    while (cont == -1)
    {
        // função que retorna o valor que é escolhido no menu e guarda dentro da variavel guardaMenuInicial
        int guardarMenuInicial = menuInicial();
        
        // Opção 1 que leva ao caixa, esse opção só pode voltar ao menu inicial com o valor escolhido corretamente
        while(guardarMenuInicial == 1)
        {
            // função que retorna uma opção e guarda em guardaCaixa
            int guardaCaixa = opCaixa();

            //verificação do valor escolhido, se caso for 1 então chama o primeiro da fila
            if(guardaCaixa == 1)
            {
                /* sempre que o contRemove sobrar resto 0 verifica se a fila prioriatia não está vazia
                e assim remove o primeiro elemento da fila prioritaria */
                /* tirei a ideia de modulo para que a cada 1 prioritario e 2 normais a fila retornasse 
                repetindo assim até as duas filas NORMAL E PRIORITARIA estarem vazias. o contRemover ajuda
                no incremento para essa verificação por isso ele está incrementador a cada remoção tanto da fla
                prioritaria quanto da normal*/
                if((0 + contRemover) % 3 == 0)
                {
                    if(!filaVazia(prioritaria))
                    {
                        printf("\nO %d da fila prioritaria foi atendido\n",remova(prioritaria));
                        contRemover++;
                        qntAtendimentosPrioritaria++;
                    }
                // se caso a primeira estiver vazia então verifica se apenas a fila normal contem clientes
                    else if(!filaVazia(normal))
                    {
                        printf("\nO %d da fila normal foi atendido\n",remova(normal));
                        qntAtendimentosNormais++;
                    }
                // se nenhuma conter clientes mostra a mensagem e reseta os contadores filPriori e filNormal
                    else
                    {
                        printf("A fila esta vazia");
                        filPriori = 1;
                        filNomal = 1;
                    }
                }
                else
                {
                    if(!filaVazia(normal))
                    {
                        printf("\nO %d da fila normal foi removido\n",remova(normal));
                        contRemover++;
                        qntAtendimentosNormais++;
                    }
                    else if(!filaVazia(prioritaria))
                    {
                        printf("\nO %d da fila prioritaria foi removido\n",remova(prioritaria));
                        qntAtendimentosPrioritaria++;
                    }
                    else
                    {
                        printf("\n|A fila esta vazia|\n");
                        filPriori = 1;
                        filNomal = 1;
                    }
                }
                
            }
            //verifica se foi escolhido o 2 
            //funçãoq que imprime o que há nas filas 
            else if(guardaCaixa == 2)
            {
                printf("\n|FILA NORMAL|\n");
                imprimirFila(normal);
                printf("\n|FILA PRIORITARIA|\n");
                imprimirFila(prioritaria);
                printf("\n");
            }
            //verifica se foi escolhida a opção 3
            /* mostra a quantidade de atendimentos totais e sepadados entra a fila normal e prioritaria
            com ajuda de contadores colocados na aba de remover*/
            else if(guardaCaixa == 3)
            {
                printf("\nQuantidade de atendimentos: %d\n", (qntAtendimentosPrioritaria + qntAtendimentosNormais));
                printf("\n|Quantidade de atendimentos Normais: %d|\n|Quantidade de atendimentos Prioritarios: %d|\n",
                qntAtendimentosNormais,qntAtendimentosPrioritaria);
            }

            /* verifica se foi escolhido a opção 4 e se caso foi o guardaMenuInicial modifica seu valor saindo 
            saindo assim da repetição e entrando novamente no primeiro loop que é o do menu inicial.*/
            else if(guardaCaixa == 4)
            {
                guardarMenuInicial -= 1;
            }
        }              
        //opção que o cliente escolhe uma senha
        //enquanto guardaMenuInicial for == 2 essa aba continuara
        while(guardarMenuInicial == 2)
        {
            int guardaCliente = opCliente();
            /* escolhe a retirada de uma senha normal*/
            if(guardaCliente == 1)
            {
                /* verifica se a fila está cheia*/
                if(filaCheia(normal))
                {
                    printf("\n|FILA NORMAL ESTA CHEIA|\n");
                    
                }
                // se não estive insere o valor dentro da fila normal
                else
                {
                printf("\n|O %d lugar entrou na fila NORMAL|\n", filNomal);
                insere(normal, filNomal);
                filNomal++;  
                }
                
            }
            //escolhe a retirada de uma senha prioritaria
            else if(guardaCliente == 2)
            {
                /*se a fila prioritaria estiver cheia manda a mensagem e sai do menu do cliente e volta para 
                o inicial*/
                if(filaCheia(prioritaria))
                {
                    printf("\n|FILA PRIORITARIA ESTA CHEIA|\n");
                    
                }
                /* se não insere um cliente na fila*/
                else
                {
                    printf("\n|O %d lugar entrou na fila PRIORITARIA|\n", filPriori); 
                    insere(prioritaria, filPriori);
                    filPriori++;  
                }
            }
        
             /* se caso a opção 3 for escolhida decrementa o valor do guardaMenuInicial para sair do loop
            e entra no menu inical*/
            else if(guardaCliente == 3)
            {
                guardarMenuInicial -= 2;
            } 
        }
        //encerra o programa saindo do primeiro loop do menu inicial
        //liberando a memória das filas
        if(guardarMenuInicial == 3)
        {
            printf("|PROGRAMA ENCERRADO|");
            libera(normal);
            libera(prioritaria);
            cont++;
        }
    }
}