#include <stdio.h>
#include <string.h>

#define MAX_CARDS 30
#define MAX_NAME_LENGTH 50

typedef struct {
  char name[MAX_NAME_LENGTH];
  int attribute1;
  int attribute2;
  int attribute3;
} Card;

void printCard(Card card) {
  printf("Nome: %s\n", card.name);
  printf("Atributo 1: %d\n", card.attribute1);
  printf("Atributo 2: %d\n", card.attribute2);
  printf("Atributo 3: %d\n", card.attribute3);
}

int compareCards(Card card1, Card card2, int attribute) {
  switch (attribute) {
    case 1: return card1.attribute1 - card2.attribute1;
    case 2: return card1.attribute2 - card2.attribute2;
    case 3: return card1.attribute3 - card2.attribute3;
    default: return 0;
  }
}

int main() {
  Card deck[MAX_CARDS];
  int numCards, choice, player1Card, player2Card;

  printf("Quantas cartas deseja criar? (max %d): ", MAX_CARDS);
  scanf("%d", &numCards);

  for (int i = 0; i < numCards; i++) {
    printf("Digite o nome da carta %d: ", i + 1);
    scanf(" %[^\n]", deck[i].name);
    printf("Digite o atributo 1: ");
    scanf("%d", &deck[i].attribute1);
    printf("Digite o atributo 2: ");
    scanf("%d", &deck[i].attribute2);
    printf("Digite o atributo 3: ");
    scanf("%d", &deck[i].attribute3);
  }

  printf("\nJogador 1, escolha sua carta (0 a %d): ", numCards - 1);
  scanf("%d", &player1Card);
  printf("Jogador 2, escolha sua carta (0 a %d): ", numCards - 1);
  scanf("%d", &player2Card);

  printf("\nJogador 1 escolheu:\n");
  printCard(deck[player1Card]);
  printf("\nJogador 2 escolheu:\n");
  printCard(deck[player2Card]);

  printf("\nEscolha o atributo para comparar (1, 2 ou 3): ");
  scanf("%d", &choice);

  int result = compareCards(deck[player1Card], deck[player2Card], choice);
  if (result > 0) {
    printf("\nJogador 1 venceu!\n");
  } else if (result < 0) {
    printf("\nJogador 2 venceu!\n");
  } else {
    printf("\nEmpate!\n");
  }

  return 0;
}