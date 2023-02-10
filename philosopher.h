/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:20:05 by mmariani          #+#    #+#             */
/*   Updated: 2023/02/10 20:48:27 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <stdio.h>
# include <unistd.h>
# include <time.h>
# include <pthread.h>
# include <sys/time.h>

typedef enum s_status
{
	EATING 		= '1',
	THINKING 	= '2',
	SLEEPING 	= '3',
	DIE 		= '42',
} 			t_statut;

typedef struct s_time
{
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	n_ph;
	uint64_t whattimeisit;
	//int n_ph_musteat
}		t_time;

typedef struct s_routine
{
	int eating;
	int thinking;
	int sleeping;
}		t_routine;

typedef struct s_chopstick
{
	int	how_many;
	int right;
	int left;
	//mutex
	
} t_chopstick;

typedef struct s_phil
{
	int			who_am_i;
	pthread_t	phill;
	t_routine	what_i_am_doing;
	int			am_i_alive;
	t_chopstick	stick;
	int			status;
	t_time		input;
}		t_phil;

typedef struct s_status
{
	int statu
}				t_tiempo

int			ft_isdigit(int n);
int			ft_isspace(char str);
int			ft_atoi(const char *str);
void		ft_init_thread(t_phil *philo, t_routine *routine);
void		ft_join(t_phil *philo);
int			ft_check(char **argv, t_phil *philo);
void		*ft_routine(void * arg);
void		ft_makingthingsready(t_phil *philo, char **argv);
void		ft_printmsg(t_phil *philo, int tempo);
void		ft_takechopstick(t_phil * philo);
uint64_t	get_time(void);




#endif