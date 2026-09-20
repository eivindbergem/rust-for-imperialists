#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct {
    uint8_t *data;
    int len;
} buffer_t;

buffer_t alloc_buffer(int len) {
    buffer_t buffer = {
	.data = malloc(len),
	.len = len,
    };

    assert(buffer.data != NULL);

    return buffer;
}

void print_buffer(buffer_t *buffer) {
    printf("Buffer: ");
    for (int i = 0; i < buffer->len; i++) {
	printf("%02X ", buffer->data[i]);
    }

    printf("\n");
}

void free_buffer(buffer_t buffer) {
    free(buffer.data);
}

int main(void) {
    buffer_t buffer = alloc_buffer(16);

    for (int i = 0; i < buffer.len; i++) {
	buffer.data[i] = i;
    }

    print_buffer(&buffer);

    free_buffer(buffer);

    // buffer.data has been freed and is a dangling pointer

    print_buffer(&buffer);
}
