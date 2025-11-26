// ...existing code...
#include <stdio.h>
#include <ctype.h>  // para usar toupper()

#define QTD_QUESTOES 10
#define QTD_ALUNOS 50

// ---------- STRUCT ----------
typedef struct {
    int id;
    char respostas[QTD_QUESTOES];
    int acertos;
} Aluno;

// ---------- PROTÓTIPOS ----------
void cadastrarGabarito(char gabarito[]);
Aluno cadastrarAluno();
void corrigirProvas(Aluno alunos[], int qtd, char gabarito[]);
void exibirResultados(Aluno alunos[], int qtd);
void menu();

// ---------- FUNÇÃO PRINCIPAL ----------
int main() {
    menu();
    return 0;
}

// ---------- MENU PRINCIPAL ----------
void menu() {
    char gabarito[QTD_QUESTOES];
    Aluno alunos[QTD_ALUNOS];
    int opcao;
    int qtdAlunos = 0;
    int gabaritoCadastrado = 0;

    do {
        printf("\n=============================\n");
        printf("       SISTEMA DE PROVAS     \n");
        printf("=============================\n");
        printf("1. Cadastrar Gabarito\n");
        printf("2. Cadastrar Aluno\n");
        printf("3. Corrigir Provas\n");
        printf("4. Exibir Resultados\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) { // validação simples
            while (getchar() != '\n'); // limpa entrada
            opcao = 0;
        }

        switch (opcao) {
            case 1:
                cadastrarGabarito(gabarito);
                gabaritoCadastrado = 1;
                break;

            case 2:
                if (!gabaritoCadastrado) {
                    printf("\nCadastre o gabarito primeiro!\n");
                } else if (qtdAlunos < QTD_ALUNOS) {
                    alunos[qtdAlunos] = cadastrarAluno();
                    qtdAlunos++;
                } else {
                    printf("\nLimite de alunos atingido!\n");
                }
                break;

            case 3:
                if (qtdAlunos == 0) {
                    printf("\nNenhum aluno cadastrado!\n");
                } else {
                    corrigirProvas(alunos, qtdAlunos, gabarito);
                }
                break;

            case 4:
                if (qtdAlunos == 0) {
                    printf("\nNenhum resultado para exibir!\n");
                } else {
                    exibirResultados(alunos, qtdAlunos);
                }
                break;

            case 5:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 5);
}

// ---------- FUNÇÃO PARA CADASTRAR GABARITO ----------
void cadastrarGabarito(char gabarito[]) {
    printf("\n--- Cadastro do Gabarito ---\n");
    for (int i = 0; i < QTD_QUESTOES; i++) {
        printf("Questao %d (A-E): ", i + 1);
        scanf(" %c", &gabarito[i]);
        gabarito[i] = toupper((unsigned char)gabarito[i]); // deixa em maiúscula
    }
    printf("\nGabarito cadastrado com sucesso!\n");
}

// ---------- FUNÇÃO PARA CADASTRAR ALUNO ----------
Aluno cadastrarAluno() {
    Aluno a;
    printf("\n--- Cadastro de Aluno ---\n");
    printf("ID do aluno: ");
    while (scanf("%d", &a.id) != 1) {
        while (getchar() != '\n');
        printf("ID invalido. Digite novamente: ");
    }

    for (int i = 0; i < QTD_QUESTOES; i++) {
        printf("Resposta da questao %d (A-E): ", i + 1);
        scanf(" %c", &a.respostas[i]);
        a.respostas[i] = toupper((unsigned char)a.respostas[i]);
    }

    a.acertos = 0;
    return a;
}

// ---------- FUNÇÃO PARA CORRIGIR AS PROVAS ----------
void corrigirProvas(Aluno alunos[], int qtd, char gabarito[]) {
    for (int i = 0; i < qtd; i++) {
        alunos[i].acertos = 0;
        for (int j = 0; j < QTD_QUESTOES; j++) {
            if (alunos[i].respostas[j] == gabarito[j]) {
                alunos[i].acertos++;
            }
        }
    }
    printf("\nTodas as provas foram corrigidas!\n");
}

// ---------- FUNÇÃO PARA EXIBIR RESULTADOS ----------
void exibirResultados(Aluno alunos[], int qtd) {
    printf("\n--- RESULTADOS ---\n");
    for (int i = 0; i < qtd; i++) {
        printf("Aluno %d: %d acertos\n", alunos[i].id, alunos[i].acertos);
    }
}
