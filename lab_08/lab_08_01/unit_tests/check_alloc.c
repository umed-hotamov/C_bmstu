#include <stdlib.h>
#include <check.h>

#include "../inc/matrix.h"

#define ERR_EMPTY_ARRAY 104

START_TEST(test_alloc_func)
{
    size_t size = 2;
    int **matrix = alloc_matrix(size, size);
    int return_code = -1;
	
    ck_assert_int_eq(return_code, -1);

    free_matrix(matrix, size);
}
END_TEST

Suite* test_alloc_suite(void)
{
	Suite *s;
	TCase *tc_neg;

	s = suite_create("alloc_matrix");

	tc_neg = tcase_create("negatives");

	tcase_add_test(tc_neg, test_alloc_func);

	suite_add_tcase(s, tc_neg);

	return s;
}

int main(void)
{
	int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = test_alloc_suite();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
