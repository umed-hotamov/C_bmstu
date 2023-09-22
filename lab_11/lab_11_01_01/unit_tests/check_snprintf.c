#include <stdlib.h>
#include <check.h>

#include "my_snprintf.h"

START_TEST(test_print_func)
{
	ck_assert_int_eq(1, 1);
}
END_TEST

Suite* test_print_suite(void)
{
	Suite *s;
	TCase *tc_neg;

	s = suite_create("key");

	tc_neg = tcase_create("negatives");

	tcase_add_test(tc_neg, test_print_func);

	suite_add_tcase(s, tc_neg);

	return s;
}

int main(void)
{
	int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = test_print_suite();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
