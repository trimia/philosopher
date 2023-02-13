/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:18:28 by mmariani          #+#    #+#             */
/*   Updated: 2023/02/13 23:47:03 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_etaing(t_phil *philo)
{
	philo->lastmeal = get_time();
	philo->status.status = EATING;
	philo->what_i_am_doing.eating = 1;
	usleep(philo->input.tt_eat - philo->input.tt_eat/10);
	if(ft_modulus(get_time(), philo->lastmeal) > philo->input.tt_eat)
	{
		pthread_mutex_lock(&philo->input.writing);
		ft_printmsg(philo, philo->lastmeal, EATING);
		pthread_mutex_unlock(&philo->input.writing);
		ft_putbackchopstick(philo);
	}
}

void	ft_sleeping(t_phil *philo)
{
	philo->status.time = get_time();
	philo->what_i_am_doing.eating = 0;
	philo->status.status = SLEEPING;
	philo->what_i_am_doing.sleeping = 1;
	usleep(philo->input.tt_sleep - philo->input.tt_sleep / 10);
	if(ft_modulus(get_time(), philo->status.time) > philo->input.tt_sleep)
	{
		pthread_mutex_lock(&philo->input.writing);
		ft_printmsg(philo, get_time(), SLEEPING);
		pthread_mutex_unlock(&philo->input.writing);
		philo->what_i_am_doing.sleeping = 0;
	}
}

void	ft_thinking(t_phil *philo)
{
	philo->status.time = get_time();
	philo->status.status = SLEEPING;
	philo->what_i_am_doing.eating = 0;
	philo->what_i_am_doing.sleeping = 1;
	usleep(philo->input.tt_sleep - philo->input.tt_sleep / 10);
	if(ft_modulus(get_time(), philo->status.time) > philo->input.tt_sleep)
	{
		pthread_mutex_lock(&philo->input.writing);
		ft_printmsg(philo, get_time(), SLEEPING);
		pthread_mutex_unlock(&philo->input.writing);
		philo->what_i_am_doing.sleeping = 0;
	}
}
