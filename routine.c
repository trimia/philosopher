/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:39:13 by mmariani          #+#    #+#             */
/*   Updated: 2023/02/10 18:44:27 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_takechopstick(t_phil *philo)
{
	// rand 1 -> nb_phil

	if (philo->stick.right == 0 && philo->stick.left == 0)
	{
		philo->stick.right = 1;
		philo->stick.left = 1;
		// philo->status = EATING
	}
}

void		ft_putbackchopstick(t_phil *philo)
{
	
}

// ft_printmsg(philo->who_i_am, philo->what_i_am_doing.eating);
void	ft_printmsg(t_phil *philo, int tempo)
{
	if (philo->status == EATING)
		printf("\n%d ms = %d is eating", philo->who_am_i,  tempo);
	if (philo->status == SLEEPING)
		printf("\n%d ms = %d is sleeping", philo->who_am_i, tempo);
	if (philo->status == THINKING)
		printf("\n%d ms = %d is thinking", philo->who_am_i, tempo);
	philo->status = 0;
}

// uint64_t	get_time(t_phil *philo, int flag)
// {
// 	struct timeval	tv;

// 	gettimeofday(&tv, NULL);
// 	if (flag)
// 		philo->last_meal = ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000) - philo->context->start_time;
// 	return (((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000));
// }

uint64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_usec) * 1000);
}