#include <stdio.h>
#include <stdint.h>
#include <errno.h>

typedef struct {
    uint16_t *items;
    int len;
} iterator_t;

int iterator_next(iterator_t *iter, uint16_t **item) {
    if (iter->len <= 0) {
	return -ENOENT;
    }

    *item = iter->items;
    iter->items += 1;
    iter->len -= 1;

    return 0;
}

int main(void) {
    uint16_t array[16] = {5, 2, 3, 6, 7, 2, 3, 4, 1, 5, 3, 5, 2, 4, 2, 7};

    iterator_t iter = {
	.items = array,
	.len = 16,
    };

    uint16_t *item;
    uint16_t sum = 0;
    int i = 0;
    while (iterator_next(&iter, &item) != -ENOENT) {
	int value = (*item) * (*item);
	printf("%i: %i\n", i, value);
	sum += value;
	i++;
    }

    printf("Sum is %i\n", sum);
}
