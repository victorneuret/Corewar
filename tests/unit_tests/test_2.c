/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** test_2
*/

#include <criterion/criterion.h>

#include "common/bit_manipulations.h"

#include "common/utils/str/str_utils.h"
#include "common/utils/char/char_utils.h"

Test(reverse_bits, reverse_bits)
{
	cr_assert_eq(reverse_bits(0), 0);
	cr_assert_eq(reverse_bits(0x00000042), 0x42000000);
	cr_assert_eq(reverse_bits(0xff000000), 0xff);
	cr_assert_eq(reverse_bits((int) 0xabcdef00), 0x00efcdab);
	cr_assert_eq(reverse_bits((int) 0xffffffff), (int) 0xffffffff);
}

Test(reverse16_bits, reverse16_bits)
{
	cr_assert_eq(reverse16_bits(0), 0);
	cr_assert_eq(reverse16_bits(0x0042), 0x4200);
	cr_assert_eq(reverse16_bits(0xff00), 0xff);
	cr_assert_eq(reverse16_bits((int) 0xabcd), 0xcdab);
	cr_assert_eq(reverse16_bits((int) 0xffff), (int) 0xffff);
}

Test(char_utils, first_index_of)
{
	cr_assert_eq(first_index_of("0123456789", '4'), 4);
	cr_assert_eq(first_index_of("0123456789", '0'), 0);
	cr_assert_eq(first_index_of("0123456789", '9'), 9);
	cr_assert_eq(first_index_of("0123456789", 'a'), -1);
	cr_assert_eq(first_index_of("0000000000", '0'), 0);
	cr_assert_eq(first_index_of("aaaa000000", '0'), 4);
	cr_assert_eq(first_index_of("", '0'), -1);
	cr_assert_eq(first_index_of(NULL, '0'), -1);
}

Test(char_utils, last_index_of)
{
	cr_assert_eq(last_index_of("0123456789", '4'), 4);
	cr_assert_eq(last_index_of("0123456789", '0'), 0);
	cr_assert_eq(last_index_of("0123456789", '9'), 9);
	cr_assert_eq(last_index_of("0123456789", 'a'), -1);
	cr_assert_eq(last_index_of("0000000000", '0'), 9);
	cr_assert_eq(last_index_of("aaaa000000", '0'), 9);
	cr_assert_eq(last_index_of("", '0'), -1);
	cr_assert_eq(last_index_of(NULL, '0'), -1);
}

Test(str_utils, int_to_str)
{
	char *str;

	str = int_to_str(42);
	cr_assert_str_eq(str, "42");
	free(str);
	str = int_to_str(-42);
	cr_assert_str_eq(str, "-42");
	free(str);
	str = int_to_str(87654);
	cr_assert_str_eq(str, "87654");
	free(str);
	str = int_to_str(0);
	cr_assert_str_eq(str, "0");
	free(str);
}
