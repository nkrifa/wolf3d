/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 23:32:31 by oukrifa           #+#    #+#             */
/*   Updated: 2017/10/29 17:30:20 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**      PRINT ERRNO 
*/

int                 ft_puterror(char *s)
{
    ft_putendl_fd(s, 2);
    return (EXIT_FAILURE);
}

/*
**       OPEN THE FD CORRECTLY
*/

int                 ft_open(const char *file_name)
{
    int             fd;

    fd = open(file_name, O_RDONLY);
    if (fd == -1)
        exit(ft_puterror(OPEN_ERROR));
    return (fd);
}

/*
**      GET THE NB OF COL AND LINES OF THE FILE AND CHECK INPUTS ERRORS TOO
*/

void                get_and_check(int fd, t_map *map)
{
    int             ret;
    char            *line;
    unsigned int    count;

    count = 1;
    line = NULL;
    if ((ret = get_next_line(fd, &line)) <= 0)
        exit(ft_puterror(READ_ERROR));
    map->col = ft_strlen(line);
    free(line);
    while ((ret = get_next_line(fd, &line)) >= 0 && count++ > 0)
    {
        if (!ret)
            break;
        if (map->col != ft_strlen(line))
            exit(ft_puterror(LINE_ERROR));
        free(line);
    }
    if (ret == FAILURE)
        exit(ft_puterror(READ_ERROR));
    map->line = count - 1;
}

/*
**      STORE ALL THE X, Y, Z 
*/

int             **get_points(int fd, t_map *map)
{
    int             ret;
    int             count;
    char            *line;
    int             **tab;

    count = 0;
    line = NULL;
    if (!(tab = (int **)ft_memalloc(sizeof(int *) * map->line))))
        exit(ft_puterror(MALLOC_ERROR));
        while ((ret = get_next_line((const int)fd, &line)) >= 0)
        {
            while (*line)
            {
            if (!(tab[count / map->col] = (int *)ft_memalloc(sizeof(int ) * map->col))))
                exit(ft_puterror(MALLOC_ERROR));
            tab[count / map->col][count % map->line] = (int)(*line - '0');
            //tab[count].y = count / map.col;
            //tab[count].color = 0;
            //tab[count++] = ft_atoi(line);
            //while (*line && *line != ' ')
            //    line++;
            count++;
            line = *line ? line + 1 : line;
        }
        if (!ret)
            break;
    }
    {
        int i = 0; //
        int j = 0; //
        while (i < map->line)
        {
            j = 0;
            while(j < map->col)
                printf("%d ", , tab[i][j]);
            i++;
        }
    }
    return (tab);
}

/*
**      MANAGE THE CHECK/PARSE PART
*/

t_point             *ft_parsing(char *av, t_file *file)
{
    int             fd;
    t_map         *map;

    fd = ft_open(av);
    get_and_check(fd, file);
    close(fd);
    fd = ft_open(av);
    point = get_points(fd, *file);
    close(fd);
    return (point);
}
/*
int main(int ac, char **av)
{
    t_file file;
    if (ac == 2)
    {
        ft_parsing(av[1], &file);
    }
}
*/