/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:39:13 by mmariani          #+#    #+#             */
/*   Updated: 2023/02/14 00:11:07 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_takechopstick(t_phil *philo)
{
	int l;
	int r;

	l = philo->who_am_i - 1;
	r = philo->who_am_i + 1;
	if (l < 0 )
		l = philo->input.n_ph;
	if (r > philo->input.n_ph - 1)
		r = 0;
	pthread_mutex_lock(&philo[r].right.staybeef);
	if (philo->right.chopstick == 0)
		philo->right.chopstick = 1;
	pthread_mutex_unlock(&philo[r].right.staybeef);

	pthread_mutex_lock(&philo->input.writing);
	ft_printmsg(philo, get_time(),RIGHT);
	pthread_mutex_unlock(&philo->input.writing);

	pthread_mutex_lock(&philo[l].left.staybeef);
	if (philo->left.chopstick == 0)
		philo->left.chopstick = 1;
	pthread_mutex_unlock(&philo[l].left.staybeef);

	pthread_mutex_lock(&philo->input.writing);
	ft_printmsg(philo, get_time(), LEFT);
	pthread_mutex_unlock(&philo->input.writing);
	return (NULL);
}

void	ft_putbackchopstick(t_phil *philo)
{
	int l;
	int r;

	l = philo->who_am_i - 1;
	r = philo->who_am_i + 1;
	if (l < 0 )
		l = philo->input.n_ph;
	if (r > philo->input.n_ph)
		r = 0;
	pthread_mutex_lock(&philo[r].right.staybeef);
	if (philo->right.chopstick == 1)
		philo->right.chopstick = 0;
	pthread_mutex_unlock(&philo[r].right.staybeef);

	pthread_mutex_lock(&philo[l].left.staybeef);
	if (philo->left.chopstick == 1)
		philo->left.chopstick = 0;
	pthread_mutex_unlock(&philo[l].left.staybeef);
}

// ft_printmsg(philo->who_i_am, philo->what_i_am_doing.eating);
void	ft_printmsg(t_phil *philo, int tempo ,int a)
{
	if (philo->input.stillrunning != 0)
	{
		if (a == EATING)
			printf("\n%d    philo = %d is eating\n", tempo, philo->who_am_i);
		if (a == SLEEPING)
			printf("\n%d    philo = %d is eating\n", tempo, philo->who_am_i);
		if (a == THINKING)
			printf("\n%d    philo = %d is eating\n", tempo, philo->who_am_i);
		if (a == LEFT)
			printf("\n%d    philo = %d take left chopstick\n", tempo, philo->who_am_i);
		if (a == RIGHT)
			printf("\n%d    philo = %d take right chopstick\n", tempo, philo->who_am_i);
		philo->status.status = 0;
	}
	// else
	// 	return (0);
}

// uint64_t	get_time(t_phil *philo, int flag)
// {
// 	struct timeval	tv;

// 	gettimeofday(&tv, NULL);
// 	if (flag)
// 		philo->last_meal = ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000) - philo->context->start_time;
// 	return (((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000));
// }

uint64_t	get_time()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	// return ((tv.tv_usec));
	return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);

}

uint64_t	get_ttdead(t_phil *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	// return ((tv.tv_usec));
	philo->input.whattimeisit  = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);

}