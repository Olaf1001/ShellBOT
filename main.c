#include <stdio.h>
#include <string.h>
#include "api.h"

int main() {
    char userInput[256];

    printf("Enter the message to the chatbot: (press q or type exit to quit):\n");
    while (1) {
        printf("> ");
        fgets(userInput, sizeof(userInput), stdin);

        userInput[strcspn(userInput, "\n")] = 0;

        if (strcmp(userInput, "exit") == 0 || strcmp(userInput, "q") == 0) {
            break;
        }

        send_query(userInput);
    }

    return 0;
}
