/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:20:05 by mmariani          #+#    #+#             */
/*   Updated: 2023/02/14 17:10:21 by mmariani         ###   ########.fr       */
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
	DIE 		= '4',
	LEFT		= '5',
	RIGHT		= '6',
} 			t_status;

typedef struct s_time
{
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	n_ph;
	int stillrunning;
	uint64_t whattimeisit;
	pthread_t newsies;
	pthread_mutex_t writing;
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
	int id;
	int chopstick;
	pthread_mutex_t staybeef;
	//mutex
	
} t_chopstick;

typedef struct s_stats
{
	int			status;
	uint64_t	time;

}				t_stats;

typedef struct s_phil
{
	int				who_am_i;
	pthread_t		phill;
	pthread_mutex_t stop;
	t_routine		what_i_am_doing;
	int				am_i_alive;
	t_chopstick		*left;
	t_chopstick		*right;
	t_stats			status;
	t_time			*input;
	uint64_t		lastmeal;
}		t_phil;

int			ft_isdigit(int n);
int			ft_isspace(char str);
int			ft_atoi(const char *str);
void		ft_init_thread(t_phil *philo, t_chopstick *stick, t_time *input);
void		ft_join(t_phil *philo, t_time *input);
int			ft_check(char **argv, t_phil *philo);
void		ft_etaing(t_phil *philo);
void		ft_sleeping(t_phil *philo);
void		ft_thinking(t_phil *philo);
void		ft_initmutex(t_phil *philo ,t_chopstick *stick, t_time  *input);
void		ft_killmutex(t_phil *philo, t_chopstick *stick, t_time *input);

void		*ft_routine(void * arg);
void		*ft_monitor(void *philos);
void		ft_makingthingsready(char **argv, t_time *input);
void		ft_philostart(t_phil *philo, t_chopstick *stick, t_time *input);

void		ft_printmsg(t_phil *philo, int tempo, int a);
void		ft_takechopstick(t_phil * philo);
void		ft_putbackchopstick(t_phil *philo);
uint64_t	get_time(void);
uint64_t	get_ttdead(t_phil *philo);
uint64_t	ft_modulus(uint64_t a, uint64_t b);

void *bbbb(void * arg);




#endif