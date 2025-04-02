#include "../so_long.h"

void	fill_path(char **map, int x, int y);
void	find_cord(char **map, int *start_x, int *start_y);

int	check_shape(char **map)
{
	int	y;
	int	len;

	len = ft_strlen(map[0]);
	y = 1;
	while (map[y])
	{
		if (ft_strlen(map[y]) != len)
			return (0);
		y ++;
	}
	return (1);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** copiaMatrice(char** matrice) {
    // Alloca una matrice dinamica
    int i = 0;
    char** nuovaMatrice = (char**)malloc(sizeof(char*) * 10); // Dimensione arbitraria per iniziare
    if (nuovaMatrice == NULL) {
        printf("Memoria insufficiente\n");
        return NULL;
    }

    // Cicla sulla matrice di stringhe, usando `while` finché non trova NULL
    while (matrice[i] != NULL) {
        // Calcola la lunghezza della stringa escludendo l'ultimo carattere
        int len = strlen(matrice[i]) - 1;

        // Alloca memoria per la nuova stringa
        nuovaMatrice[i] = (char*)malloc((len + 1) * sizeof(char));
        if (nuovaMatrice[i] == NULL) {
            printf("Memoria insufficiente per la stringa %d\n", i);
            return NULL;
        }

        // Copia i caratteri escluso l'ultimo
        strncpy(nuovaMatrice[i], matrice[i], len);
        nuovaMatrice[i][len] = '\0';  // Assicurati che la stringa sia terminata

        i++;

        // Ridimensiona la matrice se necessario
        // In un caso reale sarebbe necessario una logica per ridimensionare dinamicamente la memoria
    }

    // Aggiungi NULL alla fine della matrice
    nuovaMatrice[i] = NULL;

    return nuovaMatrice;
}





int	check_path(char **map)
{
	char	**dupmap;
	int	x;
	int	y;
	int	i;

	i = 0;
	dupmap = copiaMatrice(map);
	if (dupmap == NULL)
		return (0);
	find_cord(dupmap, &x, &y);
	fill_path(dupmap, x, y);
	while (dupmap[i])
	{
		if (ft_strchr(dupmap[i], 'E') != NULL)
		{
			ft_free_strs(dupmap);
			return (0);
		}
		if (ft_strchr(dupmap[i], 'C') != NULL)
		{
			ft_printf("Error: il player non puo' raggiungere l'uscita\n");
			ft_free_strs(dupmap);
			return (0);
		}
		i ++;
	}
	ft_free_strs(dupmap);
	return (1);
}

void	fill_path(char **map, int x, int y)
{
	map[y][x] = '1';
	if (map[y - 1][x] != '1')
		fill_path(map, x, y - 1);
	if (map[y + 1][x] != '1')
		fill_path(map, x, y + 1);
	if (map[y][x - 1] != '1')
		fill_path(map, x - 1, y);
	if (map[y][x + 1] != '1')
		fill_path(map, x + 1, y);
}

void	find_cord(char **map, int *start_x, int *start_y)
{
	int	x;
	int	y;
	int	len;

	len = ft_strlen(map[0]);
	y = 1;
	while (map[y])
	{
		x = 1;
		while (x < len-1)
		{
			if (map[y][x] == 'P')
			{
				*start_x = x;
				*start_y = y;
				return;
			}
			x ++;
		}
		y ++;
	}
}
