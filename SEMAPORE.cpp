#include <iostream>
#include <unistd.h>
#include <semaphore.h>
#include <sys/wait.h>

using namespace std;

sem_t mutex;

void print_lines() {
    pid_t pid = getpid();

    sem_wait(&mutex);

    cout << "Hello I am process no " << pid << endl;
    cout << "Hello I am process no " << pid << endl;

    sem_post(&mutex);
}

int main() {

    // initialize semaphore (shared between processes, initial value = 1)
    sem_init(&mutex, 1, 1);

    // create processes
    fork();
    fork();

    // all processes run this
    print_lines();

    // wait for all child processes
    while (wait(NULL) > 0);

    // destroy semaphore
    sem_destroy(&mutex);

    return 0;
}
