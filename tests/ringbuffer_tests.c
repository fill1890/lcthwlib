#include "minunit.h"
#include <ringbuffer.h>

char* test_create() {
    return NULL;
}

char* test_read_write() {
    return NULL;
}

char* test_destroy() {
    return NULL;
}

char* all_tests() {
    mu_suite_start();

    mu_run_test(test_create);
    mu_run_test(test_read_write);
    mu_run_test(test_destroy);

    return NULL;
}

RUN_TESTS(all_tests);
