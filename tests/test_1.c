/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** Unit test 1
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "common/utils/io_utils.h"
#include "common/utils/str_utils.h"

void redirect(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(str_utils, putstr, .init = redirect)
{
	putstr("Hello");
	cr_assert_stdout_eq_str("Hello");
}
