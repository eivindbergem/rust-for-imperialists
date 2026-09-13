#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int uid;
    int gid;
} user_t;

void init_user(user_t *user, int uid) {
    int gid;

    if (uid % 2 == 0) {
	gid = uid;
    } else {
	gid = 1;
    }
    
    user->uid = uid;
    user->gid = gid;
}

void print_user(user_t *user) {
    printf("User, uid: %i, gid: %i\n", user->uid, user->gid);
}

int main(void) {    
    user_t user;

    print_user(&user);
    init_user(&user, 42);
    print_user(&user);
}
