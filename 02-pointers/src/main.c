#include <stdio.h>

typedef struct {
    int value1;
    int value2;
} item_t;

void print_item(item_t *item) {
    printf("value1: %i, value2: %i\n", item->value1, item->value2);
}

void add_one(item_t *item) {
    item->value1 += 1;
    item->value2 += 1;
}

item_t add_one_copy(item_t item) {
    item.value1 += 1;
    item.value2 += 1;

    return item;
}

int main(void) {
    item_t item = {
	.value1 = 42,
	.value2 = 43
    };

    print_item(&item);
    add_one(&item);
    print_item(&item);

    item_t item_copy = add_one_copy(item);
    print_item(&item);
    print_item(&item_copy);
}
