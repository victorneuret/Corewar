/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** label_list
*/

#include "common/op.h"
#include "common/my_printf.h"
#include "common/str_split.h"
#include "common/utils/str/str_utils.h"
#include "common/utils/char/char_utils.h"

static void count_labels_in_line(char const *line, size_t *count)
{
	for (size_t j = 0; j < my_strlen(line); j++) {
		if (line[j] == COMMENT_CHAR)
			return;
		if (line[j] == DIRECT_CHAR)
			j += 2;
		if (line[j] == LABEL_CHAR) {
			*count += 1;
			return;
		}
	}
}

static size_t get_label_count(char **lines)
{
	size_t count = 0;

	if (!lines)
		return 0;
	for (size_t i = 0; lines[i]; i++) {
		if (lines[i][0] == COMMENT_CHAR)
			continue;
		count_labels_in_line(lines[i], &count);
	}
	return count;
}

static void fill_label(char **labels, char const *line, size_t *index)
{
	for (size_t j = 0; j < my_strlen(line); j++) {
		if (line[j] == COMMENT_CHAR)
			return;
		if (line[j] == DIRECT_CHAR)
			j += 2;
		if (line[j] == LABEL_CHAR) {
			labels[*index] = substring(line, 0,
					last_index_of(line, LABEL_CHAR) - 1);
			*index += 1;
			return;
		}
	}
}

static void fill_labels(char **lines, char **labels)
{
	size_t index = 0;

	for (size_t i = 0; lines[i]; i++) {
		if (lines[i][0] == COMMENT_CHAR)
			continue;
		fill_label(labels, lines[i], &index);
	}
}

char **get_label_list(char **lines)
{
	size_t label_count = get_label_count(lines);
	char **labels = malloc((label_count + 1) * sizeof(char *));

	if (!labels)
		return NULL;
	for (size_t i = 0; i <= label_count; i++)
		labels[i] = NULL;
	fill_labels(lines, labels);
	return labels;
}
