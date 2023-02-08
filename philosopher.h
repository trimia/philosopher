/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:20:05 by mmariani          #+#    #+#             */
/*   Updated: 2023/02/08 18:02:24 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

typedef struct s_time
{
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	n_ph;
	//int n_ph_musteat
}		t_time;

typedef struct s_routine
{
	int eating;
	int thinking;
	int sleeping;
}		t_routine;

typedef struct s_phil
{
	pthread_t	who_i_am;
	t_routine	what_i_am_doing;
	int			am_i_alive;
	t_chopstick	stick;

}		t_phil;

typedef struct s_chopstick
{
	int	how_many;
	int right;
	int left;
	//mutex
	
} t_chopstick;

int		ft_isdigit(int n);
int		ft_isspace(char str);
int		ft_atoi(const char *str);
int		ft_check(char **argv, t_time *input);
void	ft_makingthingsready(t_phil *philo, int nb, char **argv);
void	ft_init_thread(t_phil *philo, t_routine *routine, int nb);


#endif