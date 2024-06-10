#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define COMBO 0
#define ATAQUES 1
//
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

//nbn
// Returns the points taken by an attack. Positive points
//take life from Jogador 2. Negative points take life from
//Jogador 1.
// If the attacks are not valid, returns -50.
int efeito_ataque_simples(char j_1, char j_2)
{
    if (j_1 == j_2)
        return (0);
    if (j_1 == 'D' || j_2 == 'D')
        return (0);
    switch (j_1){
        case 'Z' : {
            switch(j_2){
                case 'P' : {
                    return (4);
                }
                 case 'A' : {
                    return (8);
                }
                case 'E' : {
                    return (12);
                }
                case 'T' : {
                    return (16);
                }
                case 'R' : {
                    return (-20);
                }
                case 'C' : {
                    return (-16);
                }
                case 'B' : {
                    return (12);
                }
                case 'O' : {
                    return (-8);
                }
                case 'M' : {
                    return (-4);
                }   
                case ' ' : {
                    return (20);
                }        
            }
        }
        case 'P' : {
            switch(j_2){
                case 'Z' : {
                    return (-4);
                }
                 case 'A' : {
                    return (4);
                }
                case 'E' : {
                    return (8);
                }
                case 'T' : {
                    return (12);
                }
                case 'R' : {
                    return (16);
                }
                case 'C' : {
                    return (-20);
                }
                case 'B' : {
                    return (-16);
                }
                case 'O' : {
                    return (-12);
                }
                case 'M' : {
                    return (16);
                } 
                case ' ' : {
                    return (20);
                }         
            }
        }

        case 'A' : {
            switch(j_2){
                case 'Z' : {
                    return (-8);
                }
                 case 'P' : {
                    return (-4);
                }
                case 'E' : {
                    return (4);
                }
                case 'T' : {
                    return (8);
                }
                case 'R' : {
                    return (12);
                }
                case 'C' : {
                    return (16);
                }
                case 'B' : {
                    return (-20);
                }
                case 'O' : {
                    return (-16);
                }
                case 'M' : {
                    return (12);
                }
                case ' ' : {
                    return (-20);
                }         
            }
        }

       case 'E' : {
            switch(j_2){
                case 'Z' : {
                    return (-12);
                }
                 case 'P' : {
                    return (-8);
                }
                case 'A' : {
                    return (-4);
                }
                case 'T' : {
                    return (4);
                }
                case 'R' : {
                    return (-8);
                }
                case 'C' : {
                    return (12);
                }
                case 'B' : {
                    return (16);
                }
                case 'O' : {
                    return (20);
                }
                case 'M' : {
                    return (-16);
                }
                case ' ' : {
                    return (20);
                }         
            }
        }

      case 'T' : {
            switch(j_2){
                case 'Z' : {
                    return (-16);
                }
                 case 'P' : {
                    return (-12);
                }
                case 'A' : {
                    return (-8);
                }
                case 'E' : {
                    return (-4);
                }
                case 'R' : {
                    return (4);
                }
                case 'C' : {
                    return (-8);
                }
                case 'B' : {
                    return (12);
                }
                case 'O' : {
                    return (16);
                }
                case 'M' : {
                    return (20);
                }
                case ' ' : {
                    return (20);
                }         
            }
        }

      case 'R' : {
            switch(j_2){
                case 'Z' : {
                    return (20);
                }
                 case 'P' : {
                    return (-16);
                }
                case 'A' : {
                    return (-12);
                }
                case 'E' : {
                    return (8);
                }
                case 'T' : {
                    return (-4);
                }
                case 'C' : {
                    return (4);
                }
                case 'B' : {
                    return (8);
                }
                case 'O' : {
                    return (12);
                }
                case 'M' : {
                    return (-16);
                }
                case ' ' : {
                    return (20);
                }         
            }
        }

      case 'C' : {
            switch(j_2){
                case 'Z' : {
                    return (16);
                }
                case 'P' : {
                    return (20);
                }
                case 'A' : {
                    return (-16);
                }
                case 'E' : {
                    return (-12);
                }
                case 'T' : {
                    return (8);
                }
                case 'R' : {
                    return (-4);
                }
                case 'B' : {
                    return (-8);
                }
                case 'O' : {
                    return (-4);
                }
                case 'M' : {
                    return (-8);
                }
                case ' ' : {
                    return (20);
                }         
            }
        }

      case 'B' : {
            switch(j_2){
                case 'Z' : {
                    return (-12);
                }
                 case 'P' : {
                    return (16);
                }
                case 'A' : {
                    return (20);
                }
                case 'E' : {
                    return (-16);
                }
                case 'T' : {
                    return (-12);
                }
                case 'R' : {
                    return (-8);
                }
                case 'C' : {
                    return (8);
                }
                case 'O' : {
                    return (16);
                }
                case 'M' : {
                    return (-20);
                }
                case ' ' : {
                    return (20);
                }         
            }
        }

      case 'O' : {
            switch(j_2){
                case 'Z' : {
                    return (8);
                }
                 case 'P' : {
                    return (12);
                }
                case 'A' : {
                    return (16);
                }
                case 'E' : {
                    return (-20);
                }
                case 'T' : {
                    return (-16);
                }
                case 'R' : {
                    return (-12);
                }
                case 'C' : {
                    return (4);
                }
                case 'B' : {
                    return (-16);
                }
                case 'M' : {
                    return (20);
                }
                case ' ' : {
                    return (20);
                }         
            }
        }

      case 'M' : {
            switch(j_2){
                case 'Z' : {
                    return (4);
                }
                 case 'P' : {
                    return (-16);
                }
                case 'A' : {
                    return (-12);
                }
                case 'E' : {
                    return (16);
                }
                case 'T' : {
                    return (-20);
                }
                case 'R' : {
                    return (16);
                }
                case 'C' : {
                    return (8);
                }
                case 'B' : {
                    return (20);
                }
                case 'O' : {
                    return (-20);
                }
                case ' ' : {
                    return (20);
                }         
            }
        }

      case ' ' : {
            switch(j_2){
               case 'Z' : {
                    return (-20);
                }
                 case 'P' : {
                    return (-20);
                }
                case 'A' : {
                    return (-20);
                }
                case 'E' : {
                    return (-20);
                }
                case 'T' : {
                    return (-20);
                }
                case 'R' : {
                    return (-20);
                }
                case 'C' : {
                    return (-20);
                }
                case 'B' : {
                    return (-20);
                }
                case 'O' : {
                    return (-20);
                }
                case 'M' : {
                    return (-20);
                }     
                case ' ' : {
                    return (0);
                } 
                case 'D' : {
                    return (0);
                }           
            }
        }
    }
    return (-50);
}

int multi_estamina(Jogador *jogador)
{
    if (jogador->estamina > 750)
        return (1);
    else if (jogador->estamina > 500)
        return (2);
    else if (jogador->estamina > 250)
        return (3);
    else
        return (4);
}

int    ataque_invalido(char ataque[]){
    if (strlen(ataque) > 4)
    {
        if (strcmp(ataque, "ARROZAO") != 0 && strcmp(ataque, "DADBAD") != 0 && strcmp(ataque, "STTEACC") != 0 && strcmp(ataque, "TATAPAAA") != 0)
            return (1);
    }
    for (int i = 0; i < 4 && ataque[i]; i++)
    {
        if (strchr( "ZPAETRCBOMD", ataque[i]) == NULL)
            return (1);
    }
    return (0);
}

int    prep_jogada(Jogador *jogador)
{
    jogador->multi_estamina = multi_estamina(jogador);
    printf("P#%d[%d|%d] (x%d)\n", jogador->id, jogador->vida, jogador->estamina, jogador->multi_estamina);
//    printf("H: ", HISTORY);
    char ataque[200];
    printf("I: ");
    scanf(" %s", ataque);
    if (ataque_invalido(ataque))
        return (1);
    if (strlen(ataque) > 4)
        jogador->tipo_de_ataque = COMBO;
    else   
        jogador->tipo_de_ataque = ATAQUES;
    if (jogador->tipo_de_ataque == ATAQUES){
        jogador->ataque = strdup("    ");
        for (int i = 0; ataque[i]; i++)
            (jogador->ataque)[i] = ataque[i];
    }
    else
        jogador->ataque = strdup(ataque);
    return (0);
}

void        check_wins(Jogador **j_1, Jogador **j_2)
{
    if ((*j_1)->vida <= 0 && (*j_2)->vida <= 0)
        exit_game((j_1), (j_2), "Empate! O jogo termina!\n", 0);
    else if ((*j_1)->vida <= 0)
        exit_game((j_1), (j_2), "O jogador 2 ganhou!\n", 0);
    else if ((*j_2)->vida <= 0)
        exit_game((j_1), (j_2), "O jogador 1 ganhou!\n", 0);
}

Jogador    *init_jogador(int id)
{
    Jogador *j = malloc(sizeof(Jogador));
    j->id = id;
    j->estamina = 1000;
    j->vida = 1000;
    j->id_ataque = 0;
    j->prev = NULL;
    j->next = NULL;

    return (j);
}

void    exit_game(Jogador **j_1, Jogador **j_2, const char *mensagem, int free_ataque)
{
    Jogador *temp;
    
    while(*j_1)
    {
        temp = (*j_1)->prev;
        if (free_ataque)
            free((*j_1)->ataque);
        free(*j_1);
        (*j_1) = temp;
    }

    while(*j_2)
    {
        temp = (*j_2)->prev;
        if (free_ataque)
            free((*j_2)->ataque);
        free(*j_2);
        (*j_2) = temp;
    }

    printf("%s", mensagem);
    exit(0);
}

void    jogada(Jogador **j_1, Jogador **j_2)
{
    int vida_perdidaJ1 = 0;
    int vida_perdidaJ2 = 0;
    int estamina_gastaJ1 = 0;
    int estamina_gastaJ2 = 0;
    Jogador *j_1_seguinte = malloc(sizeof(Jogador));
    Jogador *j_2_seguinte = malloc(sizeof(Jogador));
    j_1_seguinte->vida = (*j_1)->vida;
    j_1_seguinte->estamina = (*j_1)->estamina;
    j_2_seguinte->vida = (*j_2)->vida;
    j_2_seguinte->estamina = (*j_2)->estamina;
    j_1_seguinte->ataque = (*j_1)->ataque + 1;
    j_2_seguinte->ataque = (*j_2)->ataque + 1;
    (*j_1)->next = j_1_seguinte;
    (*j_2)->next = j_2_seguinte;
    j_1_seguinte->prev = *j_1;
    j_2_seguinte->prev = *j_2;
    j_1_seguinte->id = (*j_1)->id;
    j_2_seguinte->id = (*j_2)->id;
    printf("[%c,%c][%c,%c][%c,%c][%c,%c]\n", (*j_1)->ataque[0], (*j_2)->ataque[0], (*j_1)->ataque[1], (*j_2)->ataque[1], (*j_1)->ataque[2], (*j_2)->ataque[2], (*j_1)->ataque[3], (*j_2)->ataque[3]);
    if ((*j_1)->tipo_de_ataque == ATAQUES && (*j_2)->tipo_de_ataque == ATAQUES)
    {
        for (int i = 0; i < 4; i++)
        {
            if ((*j_1)->ataque[i] == 'D')
            {
                estamina_gastaJ1 += 10;
                vida_perdidaJ1 -= (10 * (*j_1)->multi_estamina);
            }
            if ((*j_2)->ataque[i] == 'D')
            {
                estamina_gastaJ2 += 10;
                vida_perdidaJ2 -= (10 * (*j_2)->multi_estamina);
            }
            if ((*j_1)->ataque[i] == ' ')
                estamina_gastaJ1 -= 25;
            if ((*j_2)->ataque[i] == ' ')
                estamina_gastaJ2 -= 25;
            if ((*j_1)->ataque[i] != 'D' && (*j_1)->ataque[i] != ' ')
                estamina_gastaJ1 += 25;
            if ((*j_2)->ataque[i] != 'D' && (*j_2)->ataque[i] != ' ')
                estamina_gastaJ2 += 25;
            int pontos_ataque = efeito_ataque_simples((*j_1)->ataque[i], (*j_2)->ataque[i]);
            if (pontos_ataque > 0)
                vida_perdidaJ2 += (pontos_ataque * (*j_1)->multi_estamina);
            else if (pontos_ataque < 0)
                vida_perdidaJ1 += (-pontos_ataque * (*j_2)->multi_estamina);
        }
    }
    else if ((*j_1)->tipo_de_ataque == COMBO && (*j_2)->tipo_de_ataque == COMBO)
    {
        if(strcmp((*j_1)->ataque, "ARROZAO") == 0)
            vida_perdidaJ2 += 500;
        estamina_gastaJ1 += 500;
        if(strcmp((*j_1)->ataque, "DADBAD") == 0)
            vida_perdidaJ2 += 400;
        estamina_gastaJ1 += 400;
        if(strcmp((*j_1)->ataque, "STTEACC") == 0)
            vida_perdidaJ2 += 300;
        estamina_gastaJ1 += 300;
        if(strcmp((*j_1)->ataque, "TATAPAAA") == 0)
            vida_perdidaJ2 += 200;
        estamina_gastaJ1 += 200;
    }
    else if ((*j_2)->tipo_de_ataque == COMBO)
    {
        if(strcmp((*j_2)->ataque, "ARROZAO") == 0)
            vida_perdidaJ1 += 500;
        estamina_gastaJ2 += 500;
        if(strcmp((*j_2)->ataque, "DADBAD") == 0)
            vida_perdidaJ1 += 400;
        estamina_gastaJ2 += 400;
        if(strcmp((*j_2)->ataque, "STTEACC") == 0)
            vida_perdidaJ1 += 300;
        estamina_gastaJ2 += 300;
        if(strcmp((*j_2)->ataque, "TATAPAAA") == 0)
            vida_perdidaJ1 += 200;
        estamina_gastaJ2 += 200;
    }
    if((*j_1)->tipo_de_ataque == ATAQUES && (*j_2)->tipo_de_ataque == COMBO)
        estamina_gastaJ1 -= 25;
    if((*j_2)->tipo_de_ataque == ATAQUES && (*j_1)->tipo_de_ataque == COMBO)
        estamina_gastaJ2 -= 25;
    j_1_seguinte->vida = (*j_1)->vida - vida_perdidaJ1;
    j_2_seguinte->vida = (*j_2)->vida - vida_perdidaJ2;
    j_1_seguinte->estamina = (*j_1)->estamina - estamina_gastaJ1;
    j_2_seguinte->estamina = (*j_2)->estamina - estamina_gastaJ2;
    *j_1 = j_1_seguinte;
    *j_2 = j_2_seguinte;
}

int main(void)
{
    Jogador *j_1 = init_jogador(1);
    Jogador *j_2 = init_jogador(2);
    while (1)
    {
        if (prep_jogada(j_1) || prep_jogada(j_2))
            exit_game(&j_1, &j_2, "Entrada invalida\n", 0);
        jogada(&j_1, &j_2);
        check_wins(&j_1, &j_2);
    }

}
