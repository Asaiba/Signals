#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

// This function runs when SIGTSTP (Ctrl+Z) is received
void handle_SIGTSTP(int sig) {
    printf("\nGot Ctrl+Z! Exiting safely...\n");
    exit(0); // End the program
}

int main() {
    // Connect the signal to our handler
    signal(SIGTSTP, handle_SIGTSTP);

    printf("Running... Press Ctrl+Z to stop it.\n");

    // Keep printing until stopped
    while (1) {
        printf("Still Running...\n");
        sleep(1);
    }

    return 0;
}