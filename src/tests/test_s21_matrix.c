#include "test_s21_matrix.h"

int main(void) {
  int failed = 0;
  int success = 0;
  Suite *s21_matrix_test[] = {
      test_s21_calc_complements(), test_s21_create_matrix(),
      test_s21_determinant(),      test_s21_eq_matrix(),
      test_s21_inverse_matrix(),   test_s21_mult_matrix(),
      test_s21_mult_number(),      test_s21_remove_matrix(),
      test_s21_sub_matrix(),       test_s21_sum_matrix(),
      test_s21_transpose(),        NULL};

  for (int i = 0; s21_matrix_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_matrix_test[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    failed += srunner_ntests_failed(sr);
    success += srunner_ntests_run(sr);
    srunner_free(sr);
  }
  printf("\033[41m========= FAILED : %-3d =========\033[0m\n", failed);
  printf("\033[42m\033[30m========= SUCCESS: %-3d =========\033[0m\n", success);
  return failed == 0 ? 0 : 1;
}