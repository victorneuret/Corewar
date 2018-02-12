/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** Unit test 1
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "common/my_printf.h"

#include "common/utils/nbr_base.h"
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

// int main(void)
// {
// 	char *ptr;

// 	ptr = conv_nb_base(42, BASE_DEC);
// 	my_printf("%s\n", ptr);
// 	free(ptr);
// 	ptr = conv_nb_base(42, BASE_BIN);
// 	my_printf("%s\n", ptr);
// 	free(ptr);
// 	ptr = conv_nb_base(42, BASE_OCT);
// 	my_printf("%s\n", ptr);
// 	free(ptr);
// 	ptr = conv_nb_base(3940219, BASE_HEX);
// 	my_printf("%s\n", ptr);
// 	free(ptr);
// 	ptr = conv_nb_base(3940219, BASE_HEX_CAPS);
// 	my_printf("%s\n", ptr);
// 	free(ptr);
// 	return 0;
// }
