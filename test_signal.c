// File: test_signal.c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Handler for SIGTSTP (Ctrl+Z)
void handle_sigint(int sig) {
    printf("\nReceived SIGTINT (Ctrl+C). Exited...\n");
    exit(0);
}

int main() {
    // Register the handler
    if (signal(SIGINT, handle_sigint) == SIG_ERR) {
        perror("Error registering signal handler");
        return 1;
    }

    printf("Running... Press Ctrl+C to terminate.\n");

    // Loop to simulate continuous processing
    while (1) {
        printf("Working...\n");
        sleep(2);
    }

    return 0;
}
