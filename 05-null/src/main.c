#include <stdio.h>
#include <stdbool.h>

const char *get_string(bool flag) {
    if (flag) {
	return "all your base are belong to us";
    } else {
	return NULL;
    }
}

void print_string(const char *s) {
    if (s == NULL) {
	printf("Error: string is NULL!\n");
    } else {
	printf("%s\n", s);
    }
}

int main(void) {
    print_string(get_string(false));
    print_string(get_string(true));

    return 0;
}
