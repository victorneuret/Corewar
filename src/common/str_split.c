/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** Splits a String
*/

#include <stdlib.h>

#include "common/utils/str/str_utils.h"

static size_t count_words(char const *str, char separator)
{
	size_t word_count = 1;

	for (size_t i = 0; i + 1 < my_strlen(str); i++)
		if (str[i] == separator && str[i + 1] != separator)
			word_count++;
	if (str[0] == separator)
		word_count--;
	return word_count;
}

static void fill_array(char **array, size_t word_count,
			char const *str, char separator)
{
	size_t str_index = 0;
	size_t start = 0;
	size_t end = 0;

	for (size_t i = 0; i < word_count; i++) {
		while (str[str_index] == separator)
			str_index++;
		start = str_index;
		for (end = start;
		str[str_index] && str[str_index] != separator; end++)
			str_index++;
		array[i] = substring(str, start, end - 1);
	}
}

char **str_split(char const *str, char separator)
{
	size_t word_count = str ? count_words(str, separator) : 0;
	char **array = str ? malloc((word_count + 1) * (sizeof(char*))) : NULL;

	if (!array)
		return NULL;
	if (my_strlen(str) == 0) {
		free(array);
		return NULL;
	}
	if (word_count == 1)
		array[0] = my_strdup(str);
	else
		fill_array(array, word_count, str, separator);
	array[word_count] = 0;
	for (int i = 0; array[0][i] != '\0'; i++)
		if (array[0][i] == separator)
			array[0][i] = '\0';
	return array;
}

void free_str_array(char **array)
{
	if (!array)
		return;
	for (size_t i = 0; array[i]; i++)
		free(array[i]);
	free(array);
}
