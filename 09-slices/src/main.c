#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint8_t *data;
    int len;
} slice_t;

void print_slice(slice_t slice) {
    printf("Slice: ");

    for (int i = 0; i < slice.len; i++) {
	printf("%02X ", slice.data[i]);
    }

    printf("\n");
}

int main(void) {
    uint8_t array[16];
    int len = sizeof(array) / sizeof(*array);

    for (int i = 0; i < len; i++) {
	array[i] = i;
    }
    
    slice_t slice = {
	.data = array,
	.len = len,
    };

    print_slice(slice);
}
