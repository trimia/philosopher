/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:18:28 by mmariani          #+#    #+#             */
/*   Updated: 2023/02/14 19:21:54 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_etaing(t_phil *philo)
{
	philo->lastmeal = get_time();
	philo->status.status = EATING;
	philo->what_i_am_doing.eating = 1;
	pthread_mutex_lock(&philo->input->writing);
	ft_printmsg(philo, philo->lastmeal, EATING);
	pthread_mutex_unlock(&philo->input->writing);
	usleep(philo->input->tt_eat - philo->input->tt_eat/10);
	ft_putbackchopstick(philo);
}

void	ft_sleeping(t_phil *philo)
{
	philo->status.time = get_time();
	philo->what_i_am_doing.eating = 0;
	philo->status.status = SLEEPING;
	philo->what_i_am_doing.sleeping = 1;
	pthread_mutex_lock(&philo->input->writing);
	ft_printmsg(philo, get_time(), SLEEPING);
	pthread_mutex_unlock(&philo->input->writing);
	usleep(philo->input->tt_sleep - philo->input->tt_sleep / 10);
		// philo->what_i_am_doing.sleeping = 0;
}


void	ft_thinking(t_phil *philo)
{
	philo->status.time = get_time();
	philo->what_i_am_doing.sleeping = 0;
	philo->status.status = THINKING;
	philo->what_i_am_doing.thinking = 1;
	// philo->what_i_am_doing.eating = 0;
	// usleep(50);
	pthread_mutex_lock(&philo->input->writing);
	ft_printmsg(philo, get_time(), THINKING);
	pthread_mutex_unlock(&philo->input->writing);
	philo->what_i_am_doing.thinking = 0;
}


// // if(philo->status.status == 0 && philo->what_i_am_doing.eating == 1)
// 	// philo->status.time=get_time();
// 	// printf("\npresleep philo %d whattimeisit 0 = %llu\n",philo->who_am_i, philo->input.whattimeisit);
// 	// printf("\npresleep philo %d statustime 0 %llu\n",philo->who_am_i, philo->status.time);
// 	// printf("\npresleep philo %d difftempo = %llu\n",philo->who_am_i, ft_modulus(philo->status.time, philo->input.whattimeisit ));
// 	{
// 		philo->status.time = get_time();
// 		philo->status.status = SLEEPING;
// 		philo->what_i_am_doing.eating = 0;
// 		philo->what_i_am_doing.sleeping = 1;
// 		usleep(philo->input.tt_sleep - philo->input.tt_sleep/10);
// 		while (1)
// 		{
// 			if(ft_modulus(get_time(),philo->status.time)> philo->input.tt_sleep)
// 			{
// 				pthread_mutex_lock(&philo->input.writing);
// 				ft_printmsg(philo, get_time(), SLEEPING);
// 				pthread_mutex_unlock(&philo->input.writing);
// 				philo->what_i_am_doing.sleeping = 0;
// 				break;
// 			}
// 		}
// 	}
// 	if (philo->what_i_am_doing.sleeping != 0)
// 	{
// 			philo->status.time = get_time();
// 			philo->status.status = THINKING;
// 			philo->what_i_am_doing.thinking = 1;
// 			pthread_mutex_lock(&philo->input.writing);
// 			ft_printmsg(philo, get_time(), THINKING);
// 			pthread_mutex_unlock(&philo->input.writing);
// 			philo->what_i_am_doing.thinking=0;
// 	}
