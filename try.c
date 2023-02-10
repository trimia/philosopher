# include <stdio.h>
# include <unistd.h>
// # include <time.h>
# include <pthread.h>
# include <sys/time.h>


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

uint64_t    get_time(void)
{
    struct timeval    tv;

    gettimeofday(&tv, NULL);
    return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}

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
    return ((tv.tv_usec) * 1000);
}



int main() {

printf("\nget_time %llu\n",get_time());
printf("\natime %llu\n",atime());
printf("\nget %llu\n",get());
  return 0;
}