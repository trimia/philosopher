/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philthred.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:06:34 by mmariani          #+#    #+#             */
/*   Updated: 2023/02/10 20:48:25 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_init_thread(t_phil *philo, t_routine *routine)
{
	int	i;

	// philo->who_i_am[philo->input.n_ph];
	i = 0;
	// printf("\nnumber of philo = %d\n",philo->input.n_ph);
	while (i < philo->input.n_ph)
	{
		pthread_create(&(philo[i].phill), NULL, &ft_routine, (void *)&(philo[i]));
		philo[i].who_am_i = i;
		printf("\nphilo %d created\n",philo->who_am_i);
		i++;
	}
}

void	*ft_routine(void *arg)
{
	t_phil *philo;

	philo = (t_phil *) arg;
	philo->input.whattimeisit = get_time(); // time 0
	// ft_takechopstick();
	if ((philo->stick.left && philo->stick.right) && philo->status == 0)
	{
		if(philo->input.whattimeisit  < philo->input.)
		philo->status = EATING;
		philo->what_i_am_doing.eating = 1;
		ft_printmsg(philo, philo->input.whattimeisit);
	}
	// ft_putbackchopstick();
	if (philo->what_i_am_doing.eating == 1 && philo->status == 0)
	{
		philo->status = SLEEPING;
		philo->what_i_am_doing.sleeping = 1;
		ft_printmsg(philo, philo->input.whattimeisit);
	}
	if (philo->what_i_am_doing.sleeping == 1 && philo->status == 0)
	{
		philo->status = THINKING;
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
		printf("\nphilo %d has finished\n", i);
		i++;
	}
}
