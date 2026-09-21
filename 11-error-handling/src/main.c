#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int read_positive_integer(void) {
    int rc = 0;
    int buf_size = 16;
    char *buf = malloc(buf_size);

    printf("Enter a number: ");

    if (fgets(buf, buf_size, stdin) == NULL) {
	printf("No input!\n");
	rc = -EINVAL;
	goto clean;
    }

    buf[strcspn(buf, "\n")] = '\0';

    errno = 0;
    rc = strtol(buf, NULL, 10);

    if (errno != 0) {
	rc = -EINVAL;
	goto clean;
    }
    
 clean:
    free(buf);

    return rc;
}

int main(void) {
    int number = read_positive_integer();

    if (number < 0) {
	printf("Error: %i\n", number);
    } else {
	printf("Read: '%i'\n", number);
    }
}
