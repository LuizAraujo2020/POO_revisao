//
//  main.c
//  BasicC_002
//
//  Created by Luiz Araujo on 25/03/22.
//

/*:
 ## Exercício 002
 Elabore um programa que receba um número inteiro e imprima de 1 até o número informado.
    - Nos múltiplos de  5 substitua por somente `M05`
    - Nos múltiplos de 10 substitua por somente `M10`
    - Nos múltiplos de 15 substitua por somente `M15`
 
    - Na mesma linha apresente incremento e decremento do valor
 */
#include <stdio.h>
#include <string.h>

void verificarInteiro(int, char[]);
void printarLista(int, int);

int main(int argc, const char * argv[]) {
    int inteiro = 15;
    
    do {
        printf("Informe um número inteiro: ");
        scanf("%d", &inteiro);
        
        for (int i = 1; i <= inteiro ; i++) {
            printarLista(inteiro, i);
        }
        
        printf("\n\n");
    } while(inteiro > 0);
    
    return 0;
}


/// Cria uma lista com duas colunas, substituindo os múltiplos de 5, 10 ou 15 separadamente.
///
///  ColunaA: lista crescente.
///  ColunaB: lista decrescente.
///
///  Parameters:
///         - inteiro: o número recebido na main, input do usuário;
///         - cont: o número gerado pelo loop for na main.
void printarLista(int inteiro, int cont) {
    //MARK: COLUNA A
    char colunaA[4];
    char colunaB[4];
    
    verificarInteiro(cont, colunaA);
    
    
    //MARK: COLUNA B
    /// Pega o inteiro inserido pelo usuário, adiciona 1 para não ir até 0,
    /// depois diminui o valor gerado pelo loop for na main, para ficar na ordem decrescente.
    int intAux = ((inteiro + 1) - cont);
    
    verificarInteiro(intAux, colunaB);
    
    
    printf("%s\t%s\n", colunaA, colunaB);
}


void verificarInteiro(int inteiro, char coluna[]) {
    
    if (inteiro % 15 == 0) {
        strcpy(coluna, "M15");
        
    } else {
        if (inteiro % 10 == 0) {
            strcpy(coluna, "M10");
            
        } else {
            if (inteiro % 5 == 0) {
                strcpy(coluna, "M05");
                
            } else {
                /// Se não for nenhum dos mútiplos, transforma a constante `inteiro` em *string*.
                sprintf(coluna, "%3d", inteiro);
            }
        }
    }
}
