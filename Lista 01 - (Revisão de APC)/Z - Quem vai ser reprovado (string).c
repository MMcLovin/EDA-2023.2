 #include <stdio.h>

struct Aluno
{
    char nome[20];
    int nota;
};

//função que encontra o maior nome entre os candidatos a reprovação
int achaMaiorNome(struct Aluno alunos[], int vetCandidatos[], int numCandidatos)
{
    int maiorNome = 0;
    for (int i = 0; i < numCandidatos; i++)
    {
        int len = 0;

        for (int j = 0; alunos[vetCandidatos[i]].nome[j] != '\0'; j++)
        {
            len++;
        }
        if (len > maiorNome)
        {
            maiorNome = len;
        }
    }
    return maiorNome;
}

//resolve casos de desmpate
int desempate(struct Aluno alunos[], int nAlunos, int menorNota)
{
    int numCandidatos = 0;
    int vetCandidatos[nAlunos];//apenas será feito o desempate entre 2 candidatos
    int j = 0;//indexCandidato
    
    for (int i = 0; i < nAlunos; i++)
    {
        if (alunos[i].nota == menorNota)
        {
            numCandidatos++;
            vetCandidatos[j] = i;
            j++;
        }
    }

    int reprovado = vetCandidatos[0];
    int maiorNome = achaMaiorNome(alunos, vetCandidatos, numCandidatos);

    //pega quem estiver por ultimo em ordem alfabetica
    if (numCandidatos > 1)
    {
        //for para comparação de elementos
        for (int k = 0; k < numCandidatos; k++)
        {
            //for para comparação de letras
            for (int i = 0; i < maiorNome; i++)
            {
                //verifica apenas os caracteres diferentes
                //char comparando1 = alunos[reprovado].nome[i];
                //char comparando2 = alunos[vetCandidatos[k]].nome[i];
                if (alunos[reprovado].nome[i] != alunos[vetCandidatos[k]].nome[i])
                {
                    //eh diferente e eh maior, reprova o de indice 0
                    if(alunos[vetCandidatos[k]].nome[i] > alunos[reprovado].nome[i])
                    {
                        reprovado = vetCandidatos[k];
                    }
                    //podemos sair do loop independentemente do resultado do if acima
                    break;
                }
            }
        }
    }
    else
    {
        reprovado = vetCandidatos[0];
    }
    return reprovado;
}

//acha a menor nota e chama a função para apurar o reprovado
int achaReprovado(struct Aluno alunos[], int nAlunos)
{
    int menor = alunos[0].nota;

    //acha a menor nota para podermos checar e resolver um caso de desempate
    for (int i = 0; i < nAlunos; i++)
    {
        if (alunos[i].nota <= menor)
        {
            menor = alunos[i].nota;
        }
    }
    //devolve o aluno reprovado e resolve um caso de empate, se existir
    int reprovado = desempate(alunos, nAlunos, menor);

    return reprovado;
}

int main() {
     
    int nAlunos;
    int instancia = 1;

    while (scanf("%d", &nAlunos) != EOF)
    {
        if (nAlunos >= 1 && nAlunos <= 100)
        {
            struct Aluno alunos[nAlunos];

            //le a string do nome ate achar um espaco em branco
            //e tmb le a nota do aluno
            for (int i = 0; i < nAlunos; i++)
            {
                scanf("%s", &(alunos[i].nome));
                scanf("%d", &alunos[i].nota);                
            }

            //indice do aluno reprovado
            int reprovado = achaReprovado(alunos, nAlunos);

            printf("Instancia %d\n", instancia);
            printf("%s\n", alunos[reprovado].nome);
            printf("\n");

            instancia++;
        }
    }
    
    return 0;
}