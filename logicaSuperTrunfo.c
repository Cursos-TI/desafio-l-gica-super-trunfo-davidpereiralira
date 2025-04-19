#include <stdio.h>

// Desafio Super Trunfo - Países - Tema 2 - Comparação das Cartas
#define MAX_ESTADOS 8 // Número máximo de estados
#define MAX_CIDADES_POR_ESTADO 4 // Número máximo de cidades por estado

typedef struct { // Definição das variáveis para armazenar as propriedades das cidades
    char codigo[4]; // Código da cidade com três dígitos
    char nomeCidade[50]; // Nome da cidade
    unsigned long int populacao; // População da cidade
    float area; // Área em km²
    float pib; // PIB
    int pontosTuristicos; // Número de pontos turísticos
    float densidadePopulacional; // Densidade populacional (população/área)
    float PIBPerCapita; // PIB per capita (PIB/população)
    float superPoder; // Super Poder
}Carta;

int main() {
    Carta cartas[MAX_ESTADOS * MAX_CIDADES_POR_ESTADO]; // Armazena todas as cartas
    int totalCartas = 0; // Contador de cartas cadastradas
    
    // Cadastro da Carta A01:
    printf("Cadastro da Carta A01\n");
    printf("Digite o nome da cidade: ");
    scanf("%s", cartas[totalCartas].nomeCidade);
    printf("Digite a população: ");
    scanf("%lu", &cartas[totalCartas].populacao);
    printf("Digite a área: ");
    scanf("%f", &cartas[totalCartas].area);
    printf("Digite o PIB: ");
    scanf("%f", &cartas[totalCartas].pib);
    printf("Digite a quantidade de pontos turísticos: ");
    scanf("%d", &cartas[totalCartas].pontosTuristicos);
   
    // Cálculo da densidade populacional e PIB per capita para carta A01:
    cartas[totalCartas].densidadePopulacional = (float)cartas[totalCartas].populacao / cartas[totalCartas].area;
    cartas[totalCartas].PIBPerCapita = cartas[totalCartas].pib / cartas[totalCartas].populacao;

    // Cálculo Super Poder:
    cartas[totalCartas].superPoder = (float)cartas[totalCartas].populacao + cartas[totalCartas].area + cartas[totalCartas].pib + cartas[totalCartas].pontosTuristicos + cartas[totalCartas].pib + cartas[totalCartas].PIBPerCapita + (1 / cartas[totalCartas].densidadePopulacional);

    // Armazenar o código da carta A01 e incrementar o contador de cartas:
    snprintf(cartas[totalCartas].codigo, sizeof(cartas[totalCartas].codigo), "A01");
    totalCartas++;

    // Cadastro da Carta A02:
    printf("Cadastro da Carta A02\n");
    printf("Digite o nome da cidade: ");
    scanf("%s", cartas[totalCartas].nomeCidade);
    printf("Digite a população: ");
    scanf("%lu", &cartas[totalCartas].populacao);
    printf("Digite a área: ");
    scanf("%f", &cartas[totalCartas].area);
    printf("Digite o PIB: ");
    scanf("%f", &cartas[totalCartas].pib);
    printf("Digite a quantidade de pontos turísticos: ");
    scanf("%d", &cartas[totalCartas].pontosTuristicos);

    // Cálculo da densidade populacional e PIB per capita para carta A02:
    cartas[totalCartas].densidadePopulacional = (float)cartas[totalCartas].populacao / cartas[totalCartas].area;
    cartas[totalCartas].PIBPerCapita = cartas[totalCartas].pib / cartas[totalCartas].populacao;

    // Cálculo Super Poder:
    cartas[totalCartas].superPoder = (float)cartas[totalCartas].populacao + cartas[totalCartas].area + cartas[totalCartas].pib + cartas[totalCartas].pontosTuristicos + cartas[totalCartas].pib + cartas[totalCartas].PIBPerCapita + (1 / cartas[totalCartas].densidadePopulacional);

    // Armazenar o código da carta A02 e incrementar o contador de cartas:
    snprintf(cartas[totalCartas].codigo, sizeof(cartas[totalCartas].codigo), "A02");
    totalCartas++;

    //Exibição dos dados das cartas:
    printf("\nExibição dos Dados das Cartas\n");
    for (int i = 0; i < totalCartas; i++) {
        printf("Carta %s:\n", cartas[i].codigo);
        printf("Nome da Cidade: %s\n", cartas[i].nomeCidade);
        printf("População: %lu\n", cartas[i].populacao);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2f \n", cartas[i].pib);
        printf("Pontos Turísticos: %d\n", cartas[i].pontosTuristicos);
        printf("Densidade Populacional: %.2f\n", cartas[i].densidadePopulacional);
        printf("PIB Per Capita: %.2f\n", cartas[i].PIBPerCapita);
        printf("Super Poder: %.2f\n", cartas[i].superPoder);
    }

    // contador de pontos para decidir qual cidade vence:
    int pontosCidade1 = 0; 
    int pontosCidade2 = 0;
    
    // Comparação de atributos entre as duas cartas:
    if (cartas[0].populacao > cartas[1].populacao) {
        printf("A cidade 1 tem maior população.\n"); pontosCidade1++;
    } else {
        printf("A cidade 2 tem maior população.\n"); pontosCidade2++;
    }
    if (cartas[0].area > cartas[1].area) {
        printf("A cidade 1 tem maior área.\n"); pontosCidade1++;
    } else {
        printf("A cidade 2 tem maior área.\n"); pontosCidade2++;
    }
    if (cartas[0].pib > cartas[1].pib) {
        printf("A cidade 1 tem maior PIB.\n"); pontosCidade1++;
    } else {
        printf("A cidade 2 tem maior PIB.\n"); pontosCidade2++;
    }
    if (cartas[0].pontosTuristicos > cartas[1].pontosTuristicos) {
        printf("A cidade 1 tem mais pontos turísticos.\n"); pontosCidade1++;
    } else {
        printf("A cidade 2 tem mais pontos turísticos.\n"); pontosCidade2++;
    }
    if (cartas[0].densidadePopulacional < cartas[1].densidadePopulacional) { //Menor densidade populacional é melhor
        printf("A cidade 1 tem menor densidade populacional.\n"); pontosCidade1++;
    } else {
        printf("A cidade 2 tem menor densidade populacional.\n"); pontosCidade2++;
    }
    if (cartas[0].PIBPerCapita > cartas[1].PIBPerCapita) {
        printf("A cidade 1 tem maior PIB per capita.\n"); pontosCidade1++;
    } else {
        printf("A cidade 2 tem maior PIB per capita.\n"); pontosCidade2++;
    }
    if (cartas[0].superPoder > cartas[1].superPoder) {
        printf("A cidade 1 tem maior Super Poder.\n"); pontosCidade1++;
    } else {
        printf("A cidade 2 tem maior Super Poder.\n"); pontosCidade2++;
    }

    // Exibição do Resultado Final: A cidade que acumulu mais pontos em todos os atributos vence:
    if (pontosCidade1 > pontosCidade2) {
        printf("***A cidade vencedora é: %s***\n", cartas[0].nomeCidade);
    } else {
        printf("***A cidade vencedora é: %s***\n", cartas[1].nomeCidade);
    }
    
    return 0;
}
