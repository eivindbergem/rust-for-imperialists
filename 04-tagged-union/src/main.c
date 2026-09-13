#include <stdio.h>
#include <math.h>

typedef enum {
    SHAPE_CIRCLE,
    SHAPE_RECTANGLE,
    SHAPE_TRIANGLE,
} shape_variant_t;

typedef struct {
    float radius;
} circle_t;

typedef struct {
    float width;
    float height;
} rectangle_t;

typedef struct {
    float base;
    float height;
} triangle_t;

typedef struct {
    shape_variant_t variant;
    union {
	circle_t circle;
	rectangle_t rectangle;
	triangle_t triangle;
    };
} shape_t;

float area(shape_t *shape) {
    switch (shape->variant) {
    case SHAPE_CIRCLE:
	return M_PI * shape->circle.radius * shape->circle.radius;
    case SHAPE_RECTANGLE:
	return shape->rectangle.width * shape->rectangle.height;
    case SHAPE_TRIANGLE:
	return (shape->triangle.base * shape->triangle.height) / 2.0;
    default:
	return NAN;
    }
}

const char* name(shape_t *shape) {
    switch (shape->variant) {
    case SHAPE_CIRCLE:
	return "circle";
    case SHAPE_RECTANGLE:
	return "rectangle";
    case SHAPE_TRIANGLE:
	return "triangle";
    default:
	return "unknown";
    }
}

void print_shape(shape_t *shape) {
    printf("Shape is a %s with an area of %f\n",
	   name(shape), area(shape));
}

int main(void) {
    shape_t circle = {
	.variant = SHAPE_CIRCLE,
	.circle = {
	    .radius = 4.5,
	}
    };

    shape_t rectangle = {
	.variant = SHAPE_RECTANGLE,
	.rectangle = {
	    .width = 3.6,
	    .height = 6.8,
	}
    };

    shape_t triangle = {
	.variant = SHAPE_TRIANGLE,
	.triangle = {
	    .base = 5.3,
	    .height = 2.3,
	}
    };

    print_shape(&circle);
    print_shape(&rectangle);
    print_shape(&triangle);

    return 0;
}
