#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 256
# define MAX_FD 65536
# define FAILURE -1
# define SUCCESS 1
# define EOFF 0

# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct		s_gnl
{
	int				i;
	char			buff[BUFF_SIZE + 1];
	int				size;
}					t_gnl;

int					get_next_line(const int fd, char **line);
int					get_next_offset(int const fd, char **line, char offset);

#endif
