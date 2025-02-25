#include <stdio.h>
#include <string.h>
#include "api.h"

int main() {
    char user_input[256];

    printf("Enter the message to the chatbot: (press q or type exit to quit):\n");
    while (1) {
        printf(">> ");
        fgets(user_input, sizeof(user_input), stdin);

        user_input[strcspn(user_input, "\n")] = 0;

        if (strcmp(user_input, "exit") == 0 || strcmp(user_input, "q") == 0) {
            break;
        }

        send_query(user_input);
    }

    return 0;
}
