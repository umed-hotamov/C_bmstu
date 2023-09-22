#include <stdlib.h>
#include <check.h>

#include "../inc/mysort.h"

#define ERR_EMPTY_ARRAY 104

START_TEST(test_key_func)
{
	size_t size = 0;
	int *array = (int*)malloc(size * sizeof(int));
	int *start = size + array;
	int *end = array;
	int return_code = 0;

	return_code = key(start, end, NULL, NULL);
    free(array);
	ck_assert_int_eq(return_code, ERR_EMPTY_ARRAY);
}
END_TEST

Suite* test_key_suite(void)
{
	Suite *s;
	TCase *tc_neg;

	s = suite_create("key");

	tc_neg = tcase_create("negatives");

	tcase_add_test(tc_neg, test_key_func);

	suite_add_tcase(s, tc_neg);

	return s;
}

int main(void)
{
	int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = test_key_suite();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
