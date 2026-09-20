#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint32_t factor;
} args_t;

uint32_t transform(uint32_t value,
		   uint32_t (*f)(uint32_t value, void *arg),
		   void *arg) {
    return f(value, arg);
}

uint32_t multiply(uint32_t value, void *arg) {
    args_t *args = arg;

    return value * args->factor;
}

int main(void) {
    args_t args = {
	.factor = 3,
    };

    uint32_t value = transform(5, multiply, &args);

    printf("Value: %d\n", value);

    return 0;
}
