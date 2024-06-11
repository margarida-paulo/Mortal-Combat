#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define COMBO 0
#define ATAQUES 1

//Combos are not affected by multi_estamina.
//Life recovering when deffending is affected by multi_estamina.
typedef struct historico_jogadas{
	int		id;
	int		id_ataque;
	char	*ataque;
	int		vida;
	int		estamina;
	int		multi_estamina;
	int		tipo_de_ataque;
	struct historico_jogadas	*next;
	struct historico_jogadas	*prev;
} Jogador;

int 		efeito_ataque_simples(char j_1, char j_2);
int 		multi_estamina(Jogador *jogador);
int    	prep_jogada(Jogador *jogador);
void        check_wins(Jogador **j_1, Jogador **j_2);
Jogador    *init_jogador(int id);
void    	exit_game(Jogador **j_1, Jogador **j_2, const char *mensagem, int free_ataque);
