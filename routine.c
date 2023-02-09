/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:39:13 by mmariani          #+#    #+#             */
/*   Updated: 2023/02/09 13:14:15 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_takechopstick(t_phil * philo)
{
	
}

// ft_printmsg(philo->who_i_am, philo->what_i_am_doing.eating);
void	ft_printmsg(t_phil *philo, int tempo)
{
	if (philo->status == 1 )
		printf("\n%d ms = %d is eating", philo->who_i_am,tempo);
	if (philo->status == 2 )
		printf("\n%d ms = %d is sleeping", philo->who_i_am,tempo);
	if (philo->status == 3 )
		printf("\n%d ms = %d is thinking", philo->who_i_am,tempo);
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
	return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}