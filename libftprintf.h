#ifndef LIBFTPRINTF_H
#define LIBFTPRINTF_H

#define ftcoucou ft_putstr("coucou");

#include <unistd.h>
#include <stdlib.h>
#include <wchar.h>
#include <stdio.h>
#include <stdarg.h>
# include <limits.h>
#include <locale.h>
#include "libft/libft.h"

typedef struct s_conv
{
	char			indicateur;
	char			*data;
	int				attributs[5];
	int				longueur[6];
	int				precision;
	int				largeur;
	int 			leng;
	struct s_conv	*next;
}				t_conv;

int				parseur_printf(char *format, t_conv **conversions);
int				add_attributs(t_conv **new, char *arg);
int				add_largeur_precision(t_conv **new, char *arg, int i);
int				add_longueur(t_conv **new, char *arg, int i);
int				add_indicateur(t_conv **new, char *arg, int i);
void			add_data(t_conv **tamp, void *data);
void			is_string(t_conv **tamp, char *argument);
void			is_string_S(t_conv **tamp, wchar_t *argument);
void			is_char(t_conv **tamp, int argument);
void			is_char_extended(t_conv **tamp, wint_t argument);
void			flag_d_i(t_conv **tamp, long long int argument);
void 			longueur_de_champ(t_conv **tamp);
void			precision_str(t_conv **tamp, char *arg, int i);
void 			precision_int(t_conv **tamp, char *arg, int i);
long int		ft_nbrlonglong(long long int n, int base);
int				ft_nbrlongue(long n, int base);
char			*ft_itoabaselong(long long int n, int base);
short int		ft_nbrunsigned(unsigned long long int n, int base);
char			*ft_itoabaseunsigned(unsigned long long int n, int base);
void			flag_o_O(t_conv **tamp, unsigned long long int argument);
void			flag_u_U(t_conv **tamp, unsigned long long int argument);
void			flag_x_X(t_conv **tamp, unsigned long long int argument);
char			*ft_itoabaseXlong(unsigned long long int n, int base);
char			*ft_itoa_baseX(unsigned int n, int base);
void 			precision_char(t_conv **tamp, char arg, int i);
void			flag_p(t_conv **tamp, void *argument);
void			flag_pourcent(t_conv **tamp);
char			*ft_strjoincharrev(char *str, char c);
void			ajouter_p(t_conv **tamp, int i);
void			ajout_attributs_gauche(t_conv **tamp, char *arg, int *i, int *j);
void			ajout_attributs_droite(t_conv **tamp, char *arg, int *i, int *j);
void			print_str(char **finalstr, t_conv **tamp, char *format, int i);
char 			*conversion_C(t_conv **tamp, wchar_t argument);
int				ft_printf(const char * restrict format, ...); 

#endif