/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:39:13 by mmariani          #+#    #+#             */
/*   Updated: 2023/02/13 19:17:37 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_takechopstick(t_phil *philo)
{
	if (philo[philo->who_am_i + 1].stick.right == 0 && philo[philo->who_am_i].stick.left == 0)
	{
		philo->stick.right = 1;
		philo->stick.left = 1;
		pthread_mutex_lock(&philo->input.writing);
		printf("\n%d le ha preseeeeeee\n", philo->who_am_i);
		pthread_mutex_unlock(&philo->input.writing);
		// philo->status = EATING
	}
}

void	ft_putbackchopstick(t_phil *philo)
{
	if (philo->stick.right == 1 && philo->stick.left == 1)
	{
		philo->stick.right = 0;
		philo->stick.left = 0;
		pthread_mutex_lock(&philo->input.writing);
		printf("\n%d le ha rimesse in tavola\n", philo->who_am_i);
		pthread_mutex_unlock(&philo->input.writing);
	}
}

// ft_printmsg(philo->who_i_am, philo->what_i_am_doing.eating);
void	ft_printmsg(t_phil *philo, int tempo)
{
	if (philo->status.status == EATING)
		printf("\nphilo %d ms = %d is eating\n", philo->who_am_i,  tempo);
	if (philo->status.status == SLEEPING)
		printf("\n%d ms = %d is sleeping\n", philo->who_am_i, tempo);
	if (philo->status.status == THINKING)
		printf("\n%d ms = %d is thinking\n", philo->who_am_i, tempo);
	philo->status.status = 0;
	// philo->input.whattimeisit = get_time();
}

// uint64_t	get_time(t_phil *philo, int flag)
// {
// 	struct timeval	tv;

// 	gettimeofday(&tv, NULL);
// 	if (flag)
// 		philo->last_meal = ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000) - philo->context->start_time;
// 	return (((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000));
// }

uint64_t	get_time(t_phil *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	// return ((tv.tv_usec));
	philo->input.whattimeisit  = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);

}