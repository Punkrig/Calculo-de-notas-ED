#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *leitura;
    FILE *saida;
    char linha[200]; // Declaração de uma variável para armazenar cada linha do arquivo.
    leitura = fopen("C:\\Users\\USER\\Desktop\\estrutura de dados\\primeira lista\\DadosEntrada.csv", "r"); // Abre o arquivo de entrada para leitura.

    if (leitura == NULL) { // Verifica se houve algum erro ao abrir o arquivo de leitura.
        printf("Erro ao abrir o arquivo de leitura.\n");
        return 1; // Encerra o programa com código de erro 1.
    }

    saida = fopen("SituacaoFinal.csv", "w"); // Abre o arquivo de saída para escrita.

    if (saida == NULL) { // Verifica se houve algum erro ao abrir o arquivo de saída.
        printf("Erro ao abrir o arquivo de saída.\n");
        fclose(leitura); // Fecha o arquivo de leitura antes de encerrar o programa.
        return 1; // Encerra o programa com código de erro 1.
    }

    while (fgets(linha, sizeof(linha), leitura) != NULL) {
        // Lê uma linha do arquivo de entrada e armazena em 'linha'.

        char *token = strtok(linha, ","); // Divide a linha em partes usando ',' como delimitador.
        int coluna = 1; // Inicia a contagem das colunas na primeira.

        char nome[100], sit[10] = ""; // Declara variáveis para armazenar o nome, a situação e as notas.
        float nota1, nota2, media;   // Variáveis para armazenar as notas e a média.

        while (token != NULL) {
            if (coluna == 1) {
                strcpy(nome, token); // Armazena o primeiro token como o nome.
            } else if (coluna == 4) {
                nota1 = atof(token); // Converte e armazena o quarto token como nota1.
            } else if (coluna == 5) {
                nota2 = atof(token); // Converte e armazena o quinto token como nota2.
            }

            media = (nota1 + nota2) / 2; // Calcula a média das notas.

            if (media >= 7) {
                strcpy(sit, "APROVADO"); // Define a situação como "APROVADO" se a média for maior ou igual a 7.
            } else {
                strcpy(sit, "REPROVADO"); // Define a situação como "REPROVADO" se a média for menor que 7.
            }

            token = strtok(NULL, ","); // Obtém o próximo token.
            coluna++;
        }

        // Escreve os dados formatados no arquivo de saída no formato CSV.
        fprintf(saida, "%s,%.2f,%s\n", nome, media, sit);
    }

    fclose(leitura); // Fecha o arquivo de leitura.
    fclose(saida);   // Fecha o arquivo de saída.

    return 0; // Encerra o programa com código de sucesso.
}
