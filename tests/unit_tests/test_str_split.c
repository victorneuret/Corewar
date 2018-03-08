/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** test_str_split
*/

#include <criterion/criterion.h>

#include "common/str_split.h"

Test(str_split, str_split_sentence)
{
	char str[] = "Hello world, my name is Jeff from the Overwatch team.";
	char **array = str_split(str, ' ');

	if (!array)
		return;
	cr_assert_str_eq(array[0], "Hello");
	cr_assert_str_eq(array[5], "Jeff");
	cr_assert_str_eq(array[9], "team.");
	free_str_array(array);
}

Test(str_split, str_split_path)
{
	char str[] = "/home/dev/urandom";
	char **array = str_split(str, '/');

	if (!array)
		return;
	cr_assert_str_eq(array[0], "home");
	cr_assert_str_eq(array[1], "dev");
	cr_assert_str_eq(array[2], "urandom");
	free_str_array(array);
}

Test(str_split, str_split_word)
{
	char str[] = "hello";
	char **array = str_split(str, '/');

	if (!array)
		return;
	cr_assert_str_eq(array[0], "hello");
	free_str_array(array);
}

Test(str_split, str_split_error1)
{
	char str[] = "";
	char **array = str_split(str, '/');

	cr_assert_null(array);
}

Test(str_split, str_split_error2)
{
	char *str = NULL;
	char **array = str_split(str, '/');

	cr_assert_null(array);
}
