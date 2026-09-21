#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

void print_string(const char *s) {
    printf("String: '%s'\n", s);
}

int count_bytes(const char *s) {
    int n = 0;

    while (*s != 0) {
	n++;
	s++;
    }

    return n;
}

int count_chars(const char *s) {
    int n = 0;

    while (*s != 0) {
	int len = 1;
	char first_byte = *(s++);

	if ((first_byte & 0x80) == 0x00) {
            len = 1;
	} else if ((first_byte & 0xe0) == 0xc0) {
            len = 2;
	} else if ((first_byte & 0xf0) == 0xe0) {
            len = 3;
	} else if ((first_byte & 0xf5) == 0xf0) {
            len = 4;
	} else {
	    assert(false);
	}

	for (int i = 1; i < len; i++) {
            int next_byte = *(s++);
	    assert((next_byte & 0xc0) == 0x80);
	}

	n++;
    }

    return n;
}

int main() {
    const char *literal = "string literal";
    char stack[32];
    strncpy(stack, "static allocation", sizeof(stack));

    char *heap = malloc(32);
    strncpy(heap, "heap allocation", 32);

    print_string(literal);
    print_string(stack);
    print_string(heap);

    const char *s = "æøå";

    printf("Bytes in '%s': %i\n", s, count_bytes(s));
    printf("Chars in '%s': %i\n", s, count_chars(s));

    return 0;
}
