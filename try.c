# include <stdio.h>
# include <unistd.h>
// # include <time.h>
# include <pthread.h>
# include <sys/time.h>
# include "philosopher.h"

// int mails = 0;
// pthread_mutex_t mutex;

// void* routine() {
//     for (int i = 0; i < 10000000; i++) {
//         pthread_mutex_lock(&mutex);
//         mails++;
//         pthread_mutex_unlock(&mutex);
//     }
// 	return (void*)0;
// }

// int main(int argc, char* argv[]) {
//     pthread_t th[8];
//     int i;
//     pthread_mutex_init(&mutex, NULL);
//     for (i = 0; i < 8; i++) {
//         if (pthread_create(th + i, NULL, &routine, NULL) != 0) {
//             perror("Failed to create thread");
//             return 1;
//         }
//         printf("Thread %d has started\n", i);
//     }
//     for (i = 0; i < 8; i++) {
//         if (pthread_join(th[i], NULL) != 0) {
//             return 2;
//         }
//         printf("Thread %d has finished execution\n", i);
//     }
//     pthread_mutex_destroy(&mutex);
//     printf("Number of mails: %d\n", mails);
//     return 0;
// }

// uint64_t    get_time(void)
// {
//     struct timeval    tv;

//     gettimeofday(&tv, NULL);
//     return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
// }

uint64_t    atime(void)
{
    struct timeval    tv;

    gettimeofday(&tv, NULL);
    return ((tv.tv_sec) * 1000);
}
uint64_t    get(void)
{
    struct timeval    tv;

    gettimeofday(&tv, NULL);
    return ((tv.tv_usec)    );
}



// int main() {

// printf("\nget_time %llu\n",get_time());
// printf("\natime %llu\n",atime());
// printf("\nget %llu\n",get());
//   return 0;
// }

void *bbbb(void * arg)
{
    t_phil *philo;

	philo = (t_phil *) arg;
    philo->status.time=get_time();
    if( ft_modulus(philo->status.time, philo->input.whattimeisit)< 400)
        printf("eating");


}

int main()
{
        uint64_t a;
        t_phil *philo;
        philo->input.n_ph = 3;
        philo->who_am_i = 0;
	philo->am_i_alive = 1;
	philo->status.status = 0;
	philo->stick.right = 0;
	philo->stick.left = 0;
	philo->what_i_am_doing.eating = 0;
	philo->what_i_am_doing.sleeping = 0;
	philo->what_i_am_doing.thinking = 0;
        printf("a0");
    while (1)
    {
        
        philo->input.whattimeisit=get_time();
        ft_init_thread(philo);
        ft_join(philo);
        return (0);
    }
}
