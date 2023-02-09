/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philthred.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:06:34 by mmariani          #+#    #+#             */
/*   Updated: 2023/02/09 18:06:55 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_init_thread(t_phil *philo, t_routine *routine)
{
	int	i;

	// philo->who_i_am[philo->input.n_ph];
	i = 0;
	while (i < philo->input.n_ph)
	{
		pthread_create(&philo[i].who_i_am , NULL, &ft_routine, (void *)philo);
		printf("philo %d created",i);
	}
}

void	*ft_routine(void *arg)
{
	t_phil *philo;

	philo = (t_phil *) arg;
	philo->input.whattimeisit = get_time();
	// ft_takechopstick();
	if ((philo->stick.left && philo->stick.right) && philo->status == 0)
	{
		philo->status = 1;
		philo->what_i_am_doing.eating = 1;
		ft_printmsg(philo, philo->input.whattimeisit);
	}
	// ft_putbackchopstick();
	if (philo->what_i_am_doing.eating == 1 && philo->status == 0)
	{
		philo->status = 1;
		philo->what_i_am_doing.sleeping = 1;
		ft_printmsg(philo, philo->input.whattimeisit);
	}
	if (philo->what_i_am_doing.sleeping == 1 && philo->status == 0)
	{
		philo->status = 1;
		philo->what_i_am_doing.thinking = 1;
		ft_printmsg(philo, philo->input.whattimeisit);
	}

}

void	ft_join(t_phil *philo)
{
	int	i;

	i = 0;
	while (i < philo->input.n_ph)
	{
		pthread_join(philo->who_i_am + i , NULL);
		printf("philo %d has finished", i);
	}
}
