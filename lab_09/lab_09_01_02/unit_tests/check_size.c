#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "types_defs.h"
#include "read_file.h"

START_TEST(test_size_is_valid)
{
	int return_code = size_is_valid(25);

	ck_assert_int_eq(return_code, OVERFLOW);
}
END_TEST

Suite* test_size_is_valid_suite(void)
{
	Suite *s;
	TCase *tc_neg;

	s = suite_create("size_is_valid");

	tc_neg = tcase_create("negatives");

	tcase_add_test(tc_neg, test_size_is_valid);

	suite_add_tcase(s, tc_neg);

	return s;
}

int main(void)
{
	int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = test_size_is_valid_suite();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
