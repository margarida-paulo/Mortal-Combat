#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define DEBUG 0

#define COMBO 0
#define ATAQUES 1
#define FICHEIRO 0
#define INPUT 1
#define TARZANTABORDA 4

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
int    	    prep_jogada(Jogador *jogador, FILE *file, int input_or_file);
void        check_wins(Jogador **j_1, Jogador **j_2, char **ataqueJ1, char **ataqueJ2, int file_or_input, FILE *file);
Jogador    *init_jogador(int id);
void    	exit_game(Jogador **j_1, Jogador **j_2, const char *mensagem, int file_or_input, FILE *file);

//
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
            break;
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
            break;
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
            break;
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
            break;
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
            break;
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
            break;
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
            break;
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
            break;
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
            break;
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
            break;
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
            break;
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

int    ataque_invalido(char ataque[], Jogador *jogador){
    if (strlen(ataque) > 4)
    {
        if (!strncmp(ataque, "TARZANTABORDA", 13))
        {
            if (!ataque[13])
                return (1);
            for(int i = 13; ataque[i]; i++)
            {
                if (!isdigit(ataque[i]))
                    return (TARZANTABORDA);
            }
            if (jogador->estamina <= 500 || jogador->estamina >= 900)
                return (2);
            return (TARZANTABORDA);
        }
        if (strcmp(ataque, "ARROZAO") != 0 && strcmp(ataque, "DADBAD") != 0 && strcmp(ataque, "STTEACC") != 0 && strcmp(ataque, "TATAPAAA") != 0)
            return (1);
        if (jogador->estamina <= 750)
            return (2);
        return (0);
    }
    for (int i = 0; i < 4 && ataque[i]; i++)
    {
        if (strchr( "ZPAETRCBOMD", ataque[i]) == NULL)
            return (1);
    }
    return (0);
}

char    *charstrjoin_frees(char c, char *str)
{
    char    *new_str;
    size_t     i;

    if (str == NULL)
    {
        new_str = strdup("a");
        new_str[0] = c;
        return (new_str);
    }
    new_str = malloc(sizeof(char) * strlen(str) + 2);
    new_str[0] = c;
    for (i = 0; i < strlen(str); i++)
        new_str[i + 1] = str[i];
    new_str[i + 1] = '\0';
    free (str);
    return (new_str);
}

void    print_history(Jogador *jogador)
{
    Jogador *temp;
    char *history = NULL;

    temp = jogador->prev;
    for (int i = 0; i < 20 && temp != NULL;)
    {
        if (temp->ataque != NULL && temp->tipo_de_ataque == COMBO)
        {
            for(int a = strlen(temp->ataque) - 1; a >= 0; a--)
            {
                history = charstrjoin_frees(temp->ataque[a], history);
            }
            i++;
            if (i >= 20)
                break;           
        }
        else if (temp->ataque != NULL)
        {
            for(int a = strlen(temp->ataque) - 1; a >= 0; a--)
            {
                history = charstrjoin_frees(temp->ataque[a], history);
                i++;
                if (i >= 20)
                    break;
            }
        }
        temp = temp->prev;
    }
    if (history == NULL)
        printf("H: \n");
    else
    {
        printf("H: %s\n", history);
        free(history);
    }
}

// Returns 0 if everything ran smoothly, 1 if the file is over or if the attack is invalid,
// and 2 if TARZANTABORDA was activated.
int    prep_jogada(Jogador *jogador, FILE *file, int input_or_file)
{
    char ataque[200];
    jogador->multi_estamina = multi_estamina(jogador);
    if (DEBUG == 1)
        printf("Jogada: %d P#%d [%d|%d] (x%d)\n", jogador->id_ataque, jogador->id, jogador->vida, jogador->estamina, jogador->multi_estamina);
    else
        printf("P#%d [%d|%d] (x%d)\n", jogador->id, jogador->vida, jogador->estamina, jogador->multi_estamina);
    print_history(jogador);
    if (input_or_file == INPUT)
    {
        printf("I: ");
        scanf(" %s", ataque);
    }
    else
    {
        if (fgets(ataque, 200, file) == NULL)
            return (1);
        if (strlen(ataque) != 0 && ataque[strlen(ataque) - 1] == '\n')
            ataque[strlen(ataque) - 1] = '\0';
        printf("I: %s\n", ataque);
    }
    while (ataque_invalido(ataque, jogador) == 2)
    {
        printf("Estamina insuficiente\n");
        printf("P#%d [%d|%d] (x%d)\n", jogador->id, jogador->vida, jogador->estamina, jogador->multi_estamina);
        print_history(jogador);
        if (input_or_file == FICHEIRO)
        {
            if (fgets(ataque, 200, file) == NULL)
                return (1);
            if (strlen(ataque) != 0 && ataque[strlen(ataque) - 1] == '\n')
                ataque[strlen(ataque) - 1] = '\0';
            printf("I: %s\n", ataque);
        }
        else
        {
            printf("I: ");           
            scanf(" %s", ataque);
        }

    }
    if(ataque_invalido(ataque, jogador) && ataque_invalido(ataque, jogador) != TARZANTABORDA)
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
    if (ataque_invalido(ataque, jogador) == TARZANTABORDA)
        return(TARZANTABORDA);
    return (0);
}

void        check_wins(Jogador **j_1, Jogador **j_2, char **ataqueJ1, char **ataqueJ2, int file_or_input, FILE *file)
{

    if ((*j_1)->vida <= 0 && (*j_2)->vida <= 0)
    {
        if (*ataqueJ1 != NULL)
            free(*ataqueJ1);
        if (*ataqueJ2 != NULL)
            free(*ataqueJ2);
        exit_game((j_1), (j_2), "Empate! O jogo termina!", file_or_input, file);
    }
    else if ((*j_1)->vida <= 0)
    {
        if (*ataqueJ1 != NULL)
            free(*ataqueJ1);
        if (*ataqueJ2 != NULL)
            free(*ataqueJ2);
        exit_game((j_1), (j_2), "Jogador 2 venceu o jogo!", file_or_input, file);
    }
    else if ((*j_2)->vida <= 0)
    {
        if (*ataqueJ1 != NULL)
            free(*ataqueJ1);
        if (*ataqueJ2 != NULL)
            free(*ataqueJ2);
        exit_game((j_1), (j_2), "Jogador 1 venceu o jogo!", file_or_input, file);
    }
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
    j->ataque = NULL;

    return (j);
}

void    exit_game(Jogador **j_1, Jogador **j_2, const char *mensagem, int file_or_input, FILE *file)
{
    Jogador *temp;
    
    while(*j_1)
    {
        temp = (*j_1)->prev;
        if ((*j_1)->ataque != NULL)
            free((*j_1)->ataque);
        free(*j_1);
        (*j_1) = temp;
    }

    while(*j_2)
    {
        temp = (*j_2)->prev;
        if ((*j_2)->ataque != NULL)
            free((*j_2)->ataque);
        free(*j_2);
        (*j_2) = temp;
    }
    if (file_or_input == FICHEIRO)
    {
        if (fclose(file) != 0)
        {
            printf("Failed to close file");
            exit(0);
        }
    }

    printf("%s", mensagem);
    exit(0);
}

void    tarzantaborda(Jogador **j_1, Jogador **j_2, int retrocessos)
{
    Jogador *novo_atualJ1 = *j_1;
    Jogador *novo_atualJ2 = *j_2;   
    
    printf(">>> Voltou %d ataques\n", retrocessos);

    while (retrocessos > 0 && (*j_1)->id_ataque > 0)
    {
        novo_atualJ1 = (*j_1)->prev;
        novo_atualJ2 = (*j_2)->prev;
        if ((*j_1)->ataque != NULL)
            free((*j_1)->ataque);
        if ((*j_2)->ataque != NULL)
            free((*j_2)->ataque);
        free(*j_1);
        free(*j_2);
        *j_1 = novo_atualJ1;
        *j_2 = novo_atualJ2;
        retrocessos--;
    }
}

Jogador *dup_jogador_seguinte(Jogador *jogador)
{
    Jogador *novo_jogador = malloc(sizeof(Jogador));
    novo_jogador->ataque = NULL;
    novo_jogador->estamina = jogador->estamina;
    novo_jogador->id = jogador->id;
    novo_jogador->id_ataque = jogador->id_ataque + 1;
    novo_jogador->multi_estamina = jogador->multi_estamina;
    novo_jogador->vida = jogador->vida;
    jogador->next = novo_jogador;
    novo_jogador->prev = jogador;
    novo_jogador->next = NULL;
    novo_jogador->tipo_de_ataque = jogador->tipo_de_ataque;
    return (novo_jogador);
}

void    jogada(Jogador **j_1, Jogador **j_2, int file_or_input, FILE *file)
{
    char    *ataqueJ1 = NULL;
    char    *ataqueJ2 = NULL;
    int vida_perdidaJ1 = 0;
    int vida_perdidaJ2 = 0;
    int estamina_gastaJ1 = 0;
    int estamina_gastaJ2 = 0;
    int pontos_ataque;
    Jogador *j_1_seguinte;
    Jogador *j_2_seguinte;
    if (!strncmp((*j_1)->ataque, "TARZANTABORDA", 13))
    {
        tarzantaborda(j_1, j_2, atoi(&(*j_1)->ataque[13]));
        return;
    }
    if ((*j_1)->tipo_de_ataque == ATAQUES && (*j_2)->tipo_de_ataque == ATAQUES)
    {
        ataqueJ1 = (*j_1)->ataque;
        ataqueJ2 = (*j_2)->ataque;
        for (int i = 0; i < 4 && !((*j_1)->ataque[i] == ' ' && (*j_2)->ataque[i] == ' '); i++)
            printf("[%c,%c]", (*j_1)->ataque[i], (*j_2)->ataque[i]);
        printf("\n");
        for (int i = 0; i < 4; i++)
        {
            int vida_perdidaJ1 = 0;
            int vida_perdidaJ2 = 0;
            int estamina_gastaJ1 = 0;
            int estamina_gastaJ2 = 0;
            (*j_1)->ataque = strdup("A");
            (*j_1)->ataque[0] = ataqueJ1[i];
            (*j_2)->ataque = strdup("A");
            (*j_2)->ataque[0] = ataqueJ2[i];
            if (ataqueJ1[i] == ' ' && ataqueJ2[i] == ' ')
                break;
            if (ataqueJ1[i] == 'D')
            {
                estamina_gastaJ1 += 10;
                vida_perdidaJ1 -= (10 * (*j_1)->multi_estamina);
            }
            if (ataqueJ2[i] == 'D')
            {
                estamina_gastaJ2 += 10;
                vida_perdidaJ2 -= (10 * (*j_2)->multi_estamina);
            }
            if (ataqueJ1[i] == ' ')
                estamina_gastaJ1 -= 25;
            if (ataqueJ2[i] == ' ')
                estamina_gastaJ2 -= 25;
            if (ataqueJ1[i] != 'D' && ataqueJ1[i] != ' ')
                estamina_gastaJ1 += 25;
            if (ataqueJ2[i] != 'D' && ataqueJ2[i] != ' ')
                estamina_gastaJ2 += 25;
            pontos_ataque = efeito_ataque_simples(ataqueJ1[i], ataqueJ2[i]);
            if (pontos_ataque > 0)
                vida_perdidaJ2 += (pontos_ataque * (*j_2)->multi_estamina);
            else if (pontos_ataque < 0)
                vida_perdidaJ1 += (-pontos_ataque * (*j_1)->multi_estamina);
            j_1_seguinte = dup_jogador_seguinte(*j_1);
            j_2_seguinte = dup_jogador_seguinte(*j_2);
            j_1_seguinte->vida -= vida_perdidaJ1;
            j_2_seguinte->vida -= vida_perdidaJ2;
            j_1_seguinte->estamina -= estamina_gastaJ1;
            j_2_seguinte->estamina -= estamina_gastaJ2;
            j_1_seguinte->ataque = NULL;
            j_2_seguinte->ataque = NULL;
            if (j_1_seguinte->estamina < 0)
                j_1_seguinte->estamina = 0;
            if (j_2_seguinte->estamina < 0)
                j_2_seguinte->estamina = 0;
            check_wins(&j_1_seguinte, &j_2_seguinte, &ataqueJ1, &ataqueJ2, file_or_input, file);
            *j_1 = j_1_seguinte;
            *j_2 = j_2_seguinte;
        }
        free(ataqueJ1);
        free(ataqueJ2);
        return;
    }
    else if ((*j_1)->tipo_de_ataque == COMBO && (*j_2)->tipo_de_ataque == COMBO)
    {
        printf("[%s,%s]\n", (*j_1)->ataque, (*j_2)->ataque);
        if(strcmp((*j_1)->ataque, "ARROZAO") == 0)
        {
            vida_perdidaJ2 += 500;
            estamina_gastaJ1 += 500;
        }

        else if(strcmp((*j_1)->ataque, "DADBAD") == 0)
        {
            vida_perdidaJ2 += 400;
            estamina_gastaJ1 += 400;
        }

        else if(strcmp((*j_1)->ataque, "STTEACC") == 0)
        {
            vida_perdidaJ2 += 300;
            estamina_gastaJ1 += 300;
        }

        else if(strcmp((*j_1)->ataque, "TATAPAAA") == 0)
        {
            vida_perdidaJ2 += 200;
            estamina_gastaJ1 += 200;
        }


       if(strcmp((*j_2)->ataque, "ARROZAO") == 0)
        {
            vida_perdidaJ1 += 500;
            estamina_gastaJ2 += 500;
        }

        else if(strcmp((*j_2)->ataque, "DADBAD") == 0)
        {
            vida_perdidaJ1 += 400;
            estamina_gastaJ2 += 400;
        }

        else if(strcmp((*j_2)->ataque, "STTEACC") == 0)
        {
            vida_perdidaJ1 += 300;
            estamina_gastaJ2 += 300;
        }

        else if(strcmp((*j_2)->ataque, "TATAPAAA") == 0)
        {
            vida_perdidaJ1 += 200;
            estamina_gastaJ2 += 200;
        }
    }
    else if ((*j_2)->tipo_de_ataque == COMBO)
    {
        printf("[ ,%s]\n", (*j_2)->ataque);
        if(strcmp((*j_2)->ataque, "ARROZAO") == 0)
        {
            vida_perdidaJ1 += 500;
            estamina_gastaJ2 += 500;
        }

        else if(strcmp((*j_2)->ataque, "DADBAD") == 0)
        {
            vida_perdidaJ1 += 400;
            estamina_gastaJ2 += 400;
        }

        else if(strcmp((*j_2)->ataque, "STTEACC") == 0)
        {
            vida_perdidaJ1 += 300;
            estamina_gastaJ2 += 300;
        }

        else if(strcmp((*j_2)->ataque, "TATAPAAA") == 0)
        {
            vida_perdidaJ1 += 200;
            estamina_gastaJ2 += 200;
        }
        estamina_gastaJ1 -= 25;
        free((*j_1)->ataque);
        (*j_1)->ataque = strdup(" ");

    }
    else if ((*j_1)->tipo_de_ataque == COMBO)
    {
        printf("[%s, ]\n", (*j_1)->ataque);
        if(strcmp((*j_1)->ataque, "ARROZAO") == 0)
        {
            vida_perdidaJ2 += 500;
            estamina_gastaJ1 += 500;
        }

        else if(strcmp((*j_1)->ataque, "DADBAD") == 0)
        {
            vida_perdidaJ2 += 400;
            estamina_gastaJ1 += 400;
        }

        else if(strcmp((*j_1)->ataque, "STTEACC") == 0)
        {
            vida_perdidaJ2 += 300;
            estamina_gastaJ1 += 300;
        }

        else if(strcmp((*j_1)->ataque, "TATAPAAA") == 0)
        {
            vida_perdidaJ2 += 200;
            estamina_gastaJ1 += 200;
        }
        estamina_gastaJ2 -= 25;
        free((*j_2)->ataque);
        (*j_2)->ataque = strdup(" ");

    }
    j_1_seguinte = dup_jogador_seguinte(*j_1);
    j_2_seguinte = dup_jogador_seguinte(*j_2);
    j_1_seguinte->vida = (*j_1)->vida - vida_perdidaJ1;
    j_2_seguinte->vida = (*j_2)->vida - vida_perdidaJ2;
    j_1_seguinte->estamina = (*j_1)->estamina - estamina_gastaJ1;
    j_2_seguinte->estamina = (*j_2)->estamina - estamina_gastaJ2;
    if (j_1_seguinte->estamina > 1000)
        j_1_seguinte->estamina = 1000;
    if (j_2_seguinte->estamina > 1000)
        j_2_seguinte->estamina = 1000;    
    *j_1 = j_1_seguinte;
    *j_2 = j_2_seguinte;
    check_wins(j_1, j_2, &ataqueJ1, &ataqueJ2, file_or_input, file);
}

int main(int argc, char **argv)
{
    Jogador *j_1;
    Jogador *j_2;
    int64_t file_or_input;
    FILE     *file;
    int     prep;

    if (argc > 2)
    {
        printf("Número inválido de argumentos!");
        return (1);
    }
    if (argc == 2)
    {
        file = fopen(argv[1], "r");
        if (file == NULL)
        {
            printf("Ficheiro inválido!\n");
            return (2);
        }
        file_or_input = FICHEIRO;
    }
    else
        file_or_input = INPUT;
    j_1 = init_jogador(1);
    j_2 = init_jogador(2);
    while (1)
    {
        prep = prep_jogada(j_1, file, file_or_input);
        if (prep == 1)
            exit_game(&j_1, &j_2, "Entrada invalida\n", file_or_input, file);
        else if (prep == TARZANTABORDA)
        {
            tarzantaborda(&j_1, &j_2, atoi(&(j_1->ataque[13])));
            continue;
        }
        prep = prep_jogada(j_2, file, file_or_input);
        if (prep == 1)
            exit_game(&j_1, &j_2, "Entrada invalida\n", file_or_input, file);
        else if (prep == TARZANTABORDA)
        {
            tarzantaborda(&j_1, &j_2, atoi(&(j_2->ataque[13])));
            continue;
        }
        jogada(&j_1, &j_2, file_or_input, file);
    }

}
