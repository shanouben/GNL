#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(const char *str)
{
    int a;

    a = 0;
    while (str[a])
        a++;
    return (a);
}

char	*ft_strcpy(char *dest, char *src)
{
    int a; 

    a = 0;
    while (src[a])
    {
        dest[a] = src[a];
        a++;
    }
    dest[a] = '\0';
    return(dest);
}

char	*ft_strdup(char *str)
{
    int a;
    char *str2;

    a = 0;
    if (!(str2 = malloc(sizeof(char)* (ft_strlen(str) + 1))))
        return NULL;
    return (ft_strcpy(str2, str));
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
    unsigned int i;
    int a;
    char *str2;

    i = len + 1;
    a = 0;
    if (!( str2 = malloc( sizeof(char) * (i + 1))))
        return NULL;
    while(start <= i)  
    {
        str2[a] = str[start];
        a++;
        start++;
    }  
    str2[a] = '\0';
    return (str2);
}

char	*ft_strchr(const char *str, int c)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return ((char*)str + i);
        i++;
    }
    return NULL;
}

void	*ft_memset(void *str, int c, size_t n)
{
    size_t i;
    char *str2;
    unsigned char c2;

    str2 = (char*)str;
    c2 = (unsigned char)c;
    i = 0;
    while (i <= n)
    {
       str2[i] = c2;
        i++;
    }
    return (str);
}

void	ft_bzero(void *str, size_t n)
{
    if (n == 0)
        return;
    ft_memset(str, '\0', n);
}

void	*ft_calloc(size_t count, size_t size)
{
    void *str;

    if (size == 0 || count == 0 )
    {
        size = 1;
        count = 1;
    }
    if (! (str = malloc( size * count)))
        return (NULL);
    ft_bzero(str, count * size);
    return (str);
}

char	*ft_strjoinfree(char *s1, char *s2)
{
    char *join;

    if (!(join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
        return (NULL);
    ft_strcpy(join, s1);
    ft_strcpy(join + ft_strlen(s1), s2);
    free(s2);
    free(s1);
    return (join);
}

int main(int ac, char **av)
{
    (void)ac;
    
     
    printf("%s\n", ft_strjoinfree(ft_strdup(av[1]), ft_strdup(av[2])));
  

    return 0;
    }
