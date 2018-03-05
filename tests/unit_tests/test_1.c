/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** Unit test 1
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "tests.h"

#include "common/my_printf.h"

#include "common/utils/nbr/getnbr.h"
#include "common/utils/nbr/nbr_base.h"
#include "common/utils/io/io_utils.h"
#include "common/utils/str/str_utils.h"

Test(str_utils, putstr, .init = redirect)
{
	putstr("Hello");
	cr_assert_stdout_eq_str("Hello");
}

Test(nbr_base, nbr_base)
{
	char *ptr;

	ptr = conv_nb_base(42, BASE_DEC);
	cr_assert_str_eq("42", ptr);
	free(ptr);
	ptr = conv_nb_base(42, BASE_BIN);
	cr_assert_str_eq("101010", ptr);
	free(ptr);
	ptr = conv_nb_base(42, BASE_OCT);
	cr_assert_str_eq("52", ptr);
	free(ptr);
}

Test(str_utils, substring)
{
	char test[] = "Hello world, my name is Elon Musk.";
	char *result = substring(test, 24, 32);

	cr_assert_str_eq(result, "Elon Musk");
	free(result);
}

Test(str_utils, ends_with)
{
	cr_assert_eq(ends_with("corewar.c", ".c"), true);
	cr_assert_eq(ends_with("corewar.c", ".h"), false);
	cr_assert_eq(ends_with("corewar.c", ""), true);
	cr_assert_eq(ends_with("corewar.c", "corewar"), false);
	cr_assert_eq(ends_with("", ""), true);
	cr_assert_eq(ends_with("corewar.c", "corewar.c"), true);
	cr_assert_eq(ends_with("corewar.c", "_corewar.c"), false);
	cr_assert_eq(ends_with("corewar.c", NULL), true);
	cr_assert_eq(ends_with(NULL, ".c"), false);
}

Test(getnbr, getnbr)
{
	cr_assert_eq(getnbr("42"), 42);
	cr_assert_eq(getnbr("-42"), -42);
	cr_assert_eq(getnbr("4"), 4);
	cr_assert_eq(getnbr("-1"), -1);
	cr_assert_eq(getnbr("8765422"), 8765422);
	cr_assert_eq(getnbr("hello40"), 0);
	cr_assert_eq(getnbr("40hello"), 40);
	cr_assert_eq(getnbr(""), 0);
	cr_assert_eq(getnbr(NULL), 0);
}
