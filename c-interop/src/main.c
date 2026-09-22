#include <stdio.h>
#include <stdint.h>
#include "main.h"
#include "bindings.h"

int c_main(void) {
    uint32_t value = add_one(42);
    printf("Value: %d\n", value);

    struct Test test = get_test();

    printf("String: %s\n", test.s);
}

