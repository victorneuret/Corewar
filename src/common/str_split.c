/*
** EPITECH PROJECT, 2017
** Corewar
** File description:
** Splits a String
*/

#include <stdlib.h>

#include "common/utils/str/str_utils.h"

static char *substring(char const *src, int begin, int end)
{
	char *result = malloc(end - begin + 2);

	if (!result)
		return 0;
	for (int i = 0; i < end - begin + 1; i++)
		result[i] = src[begin + i];
	result[end - begin + 1] = 0;
	return result;
}

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
	size_t word_count = count_words(str, separator);
	char **array = malloc((word_count + 1) * (sizeof(char*)));

	if (!array)
		return 0;
	if (word_count == 1)
		array[0] = my_strdup(str);
	else
		fill_array(array, word_count, str, separator);
	array[word_count] = 0;
	for (int i = 0; array[0][i] != '\0'; i++) {
	 	if (array[0][i] == separator)
			array[0][i] = '\0';
	}
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
