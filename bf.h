
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 100
#define	BUFF_SIZE 30000

/* GNL */
int		ft_find_line(char *s);
char	*ft_strmerge(char *buff, char *tmp_buff);
char	*ft_return_line(char *buff);
char	*ft_prepare_next(char *buff);
char	*get_next_line(int fd);
char	*ft_recover(int fd, char *buff);

/* UTILS */
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_replace(const char *s, char *stack);
int		ft_isinstr(const char *stack, char c);
void	*ft_bzero(void *b, size_t len);
void	*ft_calloc(size_t count, size_t size);
