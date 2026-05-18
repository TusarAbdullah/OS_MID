#include <bits/stdc++.h>
#include <sys/types.h>
#include <unistd.h>   // needed for fork() and getpid()

using namespace std;

int main()
{

    // PID of main process
    pid_t main_id = getpid();
    cout << "The PID of main process: " << main_id << endl;

    // Create child process
    pid_t res = fork();

    if (res == 0)
        {
            // Child process
            cout << "Child Process:\t[Child PID]: " << getpid()
                 << "\t[Parent PID]: " << main_id << endl;
        }
    else if (res < 0)
        {
            // Fork failed
            cout << "Fork failed" << endl;
        }
    else
        {
            // Parent process
            cout << "Parent Process:\t[Parent PID]: " << getpid() << endl;
        }

    return 0;
}

