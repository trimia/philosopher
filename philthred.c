/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philthred.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:06:34 by mmariani          #+#    #+#             */
/*   Updated: 2023/02/14 19:30:52 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_init_thread(t_phil *philo, t_chopstick *stick, t_time *input)
{
	int	i;
	int l;
	int r;

	i = 0;
	// printf("\ninit thread\n");

	// philo->who_i_am[philo->input.n_ph];
	// printf("\nnumber of philo = %d\n",philo->input.n_ph);
		// printf("\ntest --> %d\n", input->n_ph);
	while (i < input->n_ph)
	{

		philo[i].who_am_i = i;
		l= i - 1;
		r = i;
		if(i == 0)
			l = input->n_ph -1;
		philo[i].left = &stick[l];
		philo[i].right = &stick[r];
		philo[i].right->chopstick = 0;
		philo[i].left->chopstick = 0;
		philo[i].what_i_am_doing.eating = 0;
		philo[i].what_i_am_doing.sleeping = 0;
		philo[i].what_i_am_doing.thinking = 0;
		philo[i].status.status = 0;
		
		philo[i].am_i_alive = 1;
		// philo[i].input.stillrunning = 1;

		i++;
	}
	ft_initmutex(philo, stick, input);
	i = 0;
	while (i < input->n_ph)
	{
		pthread_create(&(philo[i].phill), NULL, &ft_routine, &(philo[i]));
		i++;
	}
		input->whattimeisit = get_time(); // time 0
}

void	*ft_monitor(void *philos)
{
	t_phil	*philo;
	int		i;

	philo = (t_phil *)philos;
	printf("\nsiamo nel monitor\n");
	
	while(1)
	{
		i = 0;
		printf("\nn_ph-->  %d\n",philo[0].input->n_ph);
		while (i < philo[0].input->n_ph)
		{
			pthread_mutex_lock(&philo[i].stop);
			// printf("se via piu giu cé1 una  valle");
			if (ft_modulus(philo[i].lastmeal, get_ttdead(philo)) > philo[0].input->tt_die)
			{
				// printf("perche non ci entra?");
				philo[0].input->stillrunning = 0;
				philo[i].am_i_alive = 0;
				pthread_mutex_lock(&philo[0].input->writing);
				// printf("\n%llu    philo = %d is died\n", philo[0].input->whattimeisit, philo[i].who_am_i);
				pthread_mutex_unlock(&philo[0].input->writing);
				return (NULL);
			}
			pthread_mutex_unlock(&philo[i].stop);
			i++;
		}
	}
}

void	*ft_routine(void *arg)
{
	t_phil *philo;

	philo = (t_phil *) arg;
	printf("\nbenvenuti nella routine\n");
	philo->lastmeal = get_time();




	
	while (1)
	{
		
		ft_takechopstick(philo);
		if ((philo->left->chopstick && philo->right->chopstick) && philo->status.status == 0)
			ft_etaing(philo);
		if (philo->what_i_am_doing.eating == 1 && philo->status.status == 0)
			ft_sleeping(philo);
		if (philo->what_i_am_doing.sleeping != 0)
			ft_thinking(philo);
		if (!(philo->input->stillrunning))
			break;
	}
	return NULL;
}

void	ft_join(t_phil *philo, t_time *input)
{
	int	i;

	i = 0;
	pthread_join(input->newsies, NULL);
	while (i < input->n_ph)
	{
		pthread_join(philo[i].phill, NULL);
		// printf("\nphilo %d has finished\n", i);
		i++;
	}
}

	// {
	// 	philo->lastmeal = get_time();
	// 	philo->status.status = EATING;
	// 	philo->what_i_am_doing.eating = 1;
	// 	usleep(philo->input.tt_eat - philo->input.tt_eat/10);
	// 	while (1)
	// 	{
	// 		if(ft_modulus(get_time(),philo->lastmeal) > philo->input.tt_eat)
	// 		{
	// 			pthread_mutex_lock(&philo->input.writing);
	// 			ft_printmsg(philo, philo->lastmeal, EATING);
	// 			pthread_mutex_unlock(&philo->input.writing);
	// 			ft_putbackchopstick(philo);
	// 			break;
	// 	 	}
	// 	}
	// }
	// // if(philo->status.status == 0 && philo->what_i_am_doing.eating == 1)
	// // philo->status.time=get_time();
	// // printf("\npresleep philo %d whattimeisit 0 = %llu\n",philo->who_am_i, philo->input.whattimeisit);
	// // printf("\npresleep philo %d statustime 0 %llu\n",philo->who_am_i, philo->status.time);
	// // printf("\npresleep philo %d difftempo = %llu\n",philo->who_am_i, ft_modulus(philo->status.time, philo->input.whattimeisit ));
	// {
	// 	philo->status.time = get_time();
	// 	philo->status.status = SLEEPING;
	// 	philo->what_i_am_doing.eating = 0;
	// 	philo->what_i_am_doing.sleeping = 1;
	// 	usleep(philo->input.tt_sleep - philo->input.tt_sleep/10);
	// 	while (1)
	// 	{
	// 		if(ft_modulus(get_time(),philo->status.time)> philo->input.tt_sleep)
	// 		{
	// 			pthread_mutex_lock(&philo->input.writing);
	// 			ft_printmsg(philo, get_time(), SLEEPING);
	// 			pthread_mutex_unlock(&philo->input.writing);
	// 			philo->what_i_am_doing.sleeping = 0;
	// 			break;
	// 		}
	// 	}
	// }
	// if (philo->what_i_am_doing.sleeping != 1 && philo->what_i_am_doing.eating != 1)
	// {
	// 		philo->status.time = get_time();
	// 		philo->status.status = THINKING;
	// 		philo->what_i_am_doing.thinking = 1;
	// 		pthread_mutex_lock(&philo->input.writing);
	// 		ft_printmsg(philo, get_time(), THINKING);
	// 		pthread_mutex_unlock(&philo->input.writing);
	// 		philo->what_i_am_doing.thinking=0;
	// }
	// // if (philo->what_i_am_doing.sleeping == 1 && philo->status.status == 0 && ft_modulus(philo->status.time, philo->input.whattimeisit )< philo->input.tt_)
	// // {
	// // 	philo->status.status = THINKING;
	// 	// while (philo->status.status == THINKING)
	// 	// 	philo->status.time =get_time();
	// // 	philo->what_i_am_doing.thinking = 1;
	// // 	ft_printmsg(philo, philo->input.whattimeisit);
	// // }

