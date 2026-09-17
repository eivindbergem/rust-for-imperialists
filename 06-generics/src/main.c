#include <stdio.h>
#include <math.h>

typedef struct {
    void *arg;
    float (*area)(void*);
    const char* (*name)(void);
} shape_t;

typedef struct {
    float radius;
} circle_t;

float circle_area(void *arg) {
    circle_t *circle = arg;

    return M_PI * circle->radius * circle->radius;
}

const char *circle_name() {
    return "circle";
}

typedef struct {
    float width;
    float height;
} rectangle_t;

float rectangle_area(void *arg) {
    rectangle_t *rectangle = arg;

    return rectangle->width * rectangle->height;
}

const char *rectangle_name() {
    return "rectangle";
}

typedef struct {
    float base;
    float height;
} triangle_t;

float triangle_area(void *arg) {
    triangle_t *triangle = arg;

    return (triangle->base * triangle->height) / 2.0;
}

const char *triangle_name() {
    return "triangle";
}

void print_shape(shape_t *shape) {
    printf("Shape is a %s with an area of %f\n",
	   shape->name(), shape->area(shape->arg));

}

int main(void) {
    circle_t circle = {
	.radius = 4.5,
    };
    shape_t circle_shape = {
	.arg = &circle,
	.area = circle_area,
	.name = circle_name,
    };

    rectangle_t rectangle = {
	.width = 3.6,
	.height = 6.8,
    };
    shape_t rectangle_shape = {
	.arg = &rectangle,
	.area = rectangle_area,
	.name = rectangle_name,
    };

    triangle_t triangle = {
	.base = 5.3,
	.height = 2.3,
    };
    shape_t triangle_shape = {
	.arg = &triangle,
	.area = triangle_area,
	.name = triangle_name,
    };

    print_shape(&circle_shape);
    print_shape(&rectangle_shape);
    print_shape(&triangle_shape);

    return 0;
}
