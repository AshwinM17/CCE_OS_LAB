#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    // Execute the 'ls' command with the '-l' flag
    execl("/bin/ls", "ls",NULL);
    return 0;
}
