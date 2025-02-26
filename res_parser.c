#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cjson/cJSON.h>
#include "res_parser.h"

int parse_and_print_response(void *response, int size, int n) {
    int total_size = size * n;

    char *json = (char *)malloc(total_size + 1);
    if (!json) {
        fprintf(stderr, "[!]: Memory allocation failure\n");
        return total_size;
    }
    strncpy(json, (char *)response, total_size);
    json[total_size] = '\0';

    cJSON *root = cJSON_Parse(json);
    if (root == NULL) {
        fprintf(stderr, "[!]: JSON parsing error\n");
        free(json);
        return total_size;
    }

    cJSON *choices = cJSON_GetObjectItem(root, "choices");
    if (choices && cJSON_IsArray(choices)) {
        cJSON *first_choice = cJSON_GetArrayItem(choices, 0);
        if (first_choice) {
            cJSON *text = cJSON_GetObjectItem(first_choice, "text");
            if (text && cJSON_IsString(text)) {
                printf("Chatbot: %s\n", text->valuestring);
            } else {
                fprintf(stderr, "[!] No matching text in JSON response. Try again!\n");
            }
        }
    }
    cJSON_Delete(root);
    free(json);

    return total_size;
}
