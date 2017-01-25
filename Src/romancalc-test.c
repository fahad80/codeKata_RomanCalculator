/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "./Src/romancalc-test.check" instead.
 */

#include <check.h>

#line 1 "./Src/romancalc-test.check"
#include "romancalc.h"

START_TEST(romancalcTest)
{
#line 4
	fail_unless(roman2decimalSingleChar('1') == 1, "function is not working");
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, romancalcTest);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}