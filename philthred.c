/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philthred.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:06:34 by mmariani          #+#    #+#             */
/*   Updated: 2023/02/13 19:20:22 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_init_thread(t_phil *philo)
{
	int	i;

	// philo->who_i_am[philo->input.n_ph];
	i = 0;
	// printf("\nnumber of philo = %d\n",philo->input.n_ph);
	while (i < philo->input.n_ph)
	{
		philo[i].who_am_i = i;
		pthread_create(&(philo[i].phill), NULL, &ft_routine, &(philo[i]));
		philo->input.whattimeisit = get_time(philo); // time 0

		i++;
	}
}

void	*ft_monitor(void *philos)
{
	int		i;
	t_phil	*philo;

	i = 0;
	philo = (t_phil *)philos;
	while(philo->am_i_alive != 0)
	{
		while (i < philo->input.n_ph)
		{
			pthread_mutex_lock(&philo->stick.staybeef);
			if(ft_modulus(philo->lastmeal,get_time(philo)) > philo->input.tt_die)
			{
				pthread_mutex_lock(&philo->input.writing);
				philo->am_i_alive = 0;
				ft_printmsg(philo,philo->input.whattimeisit);
				pthread_mutex_unlock(&philo->input.writing);

			}
			pthread_mutex_unlock(&philo->stick.staybeef);
			i++;
		}
	}

}

void	*ft_routine(void *arg)
{
	t_phil *philo;

	philo = (t_phil *) arg;
	
	// philo->status.time = get_time();
	// printf("\npreeat philo %d whattimeisit 0 = %llu\n",philo->who_am_i, philo->input.whattimeisit);
	// printf("\npreeat philo %d statustime 0 %llu\n",philo->who_am_i, philo->status.time);
	// printf("\npreeat philo %d difftempo = %llu\n",philo->who_am_i, ft_modulus(philo->status.time, philo->input.whattimeisit ));
	// printf("\npreeat philo %d created\n",philo->who_am_i);
	// printf("philo name %d",philo->who_am_i);
	ft_takechopstick(philo);
	if ((philo->stick.left && philo->stick.right) && philo->status.status == 0)
	{
		philo->lastmeal = get_time(philo);
		philo->status.status = EATING;
		philo->what_i_am_doing.eating = 1;
		usleep(philo->input.tt_eat - philo->input.tt_eat/10);
		while (1)
		{
			if(ft_modulus(get_time(philo),philo->lastmeal) > philo->input.tt_eat)
			{
				pthread_mutex_lock(&philo->input.writing);
				ft_printmsg(philo, philo->lastmeal);
				pthread_mutex_unlock(&philo->input.writing);
				ft_putbackchopstick(philo);
				break;
		 	}
		}
	}
	// if(philo->status.status == 0 && philo->what_i_am_doing.eating == 1)
	// philo->status.time=get_time();
	// printf("\npresleep philo %d whattimeisit 0 = %llu\n",philo->who_am_i, philo->input.whattimeisit);
	// printf("\npresleep philo %d statustime 0 %llu\n",philo->who_am_i, philo->status.time);
	// printf("\npresleep philo %d difftempo = %llu\n",philo->who_am_i, ft_modulus(philo->status.time, philo->input.whattimeisit ));
	if (philo->what_i_am_doing.eating == 1 && philo->status.status == 0)
	{
		philo->status.time = get_time(philo);
		philo->what_i_am_doing.eating = 0;
		philo->status.status = SLEEPING;
		philo->what_i_am_doing.sleeping = 1;
		usleep(philo->input.tt_sleep - philo->input.tt_sleep/10);
		while (1)
		{
			if(ft_modulus(get_time(philo),philo->status.time)> philo->input.tt_sleep)
			{
				pthread_mutex_lock(&philo->input.writing);
				ft_printmsg(philo, philo->input.whattimeisit);
				pthread_mutex_unlock(&philo->input.writing);
				philo->what_i_am_doing.sleeping = 0;
				break;
			}
		}
	}
	if (philo->what_i_am_doing.sleeping != 1 && philo->what_i_am_doing.eating != 1)
	{
			philo->status.status = THINKING;
			philo->status.time = get_time(philo);
			philo->what_i_am_doing.thinking=1;
			pthread_mutex_lock(&philo->input.writing);
			ft_printmsg(philo, philo->input.whattimeisit);
			pthread_mutex_unlock(&philo->input.writing);
			philo->what_i_am_doing.thinking=0;
	}
	// if (philo->what_i_am_doing.sleeping == 1 && philo->status.status == 0 && ft_modulus(philo->status.time, philo->input.whattimeisit )< philo->input.tt_)
	// {
	// 	philo->status.status = THINKING;
		// while (philo->status.status == THINKING)
		// 	philo->status.time =get_time();
	// 	philo->what_i_am_doing.thinking = 1;
	// 	ft_printmsg(philo, philo->input.whattimeisit);
	// }

}

void	ft_join(t_phil *philo)
{
	int	i;

	i = 0;
	while (i < philo->input.n_ph)
	{
		pthread_join(philo[i].phill, NULL);
		// printf("\nphilo %d has finished\n", i);
		i++;
	}
}
