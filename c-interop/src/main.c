#include <stdio.h>
#include <stdint.h>

extern uint32_t add_one(uint32_t value);

int c_main(void) {
    uint32_t value = add_one(42);
    printf("Value: %d\n", value);
}

