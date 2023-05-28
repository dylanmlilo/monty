#include "monty.h"

/**
 * _rrealloc - function that reallocates a memory block using malloc and free
 *
 * @ptr: pointer to the memory previously allocated
 * @old_size: size in bytes of the allocated space for ptr
 * @new_size: size in bytes for the new memory block
 *
 * Return: If new_size == old_size - ptr
 *         If new_size == 0 and ptr is not NULL - NULL
 *         Else - a pointer to the reallocated memory block
 */

void *_rrealloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *memory;
	char *ptr_copy, *filler;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		memory = malloc(new_size);
		if (memory == NULL)
			return (NULL);

		return (memory);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	ptr_copy = ptr;
	memory = malloc(sizeof(*ptr_copy) * new_size);

	if (memory == NULL)
	{
		free(ptr);
		return (NULL);
	}

	filler = memory;

	for (i = 0; i < old_size && i < new_size; i++)
		filler[i] = *ptr_copy++;

	free(ptr);
	return (memory);
}

/**
 * _strcpy - function that Copies the string pointed to by src
 *
 * @dest: the pointer to the destination of copied string
 * @src: the pointer to the src of the source string
 *
 * Return: a pointer to dest
 */

char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * assign_lineptr - function that reassigns the lineptr variable for _getline
 *
 * @lineptr: a buffer to store an input string
 * @n: size of lineptr
 * @buffer: string to assign to lineptr
 * @b:the size of buffer
 *
 * Return: Nothing
 */

void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b)
{
	if (*lineptr == NULL)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else if (*n < b)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}

/**
 * _getline - function that reads input from a stream
 *
 * @lineptr: a buffer to store the input
 * @n: the size of lineptr
 * @stream: the stream to read from
 *
 * Return: the number of bytes read
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t input;
	ssize_t ret;
	int red;
	char c = 'x', *buffer;

	if (input == 0)
	{
		fflush(stream);
	}
	else
	{
		return (-1);
	}
	input = 0;
	buffer = malloc(sizeof(char) * 120);

	if (!buffer)
	{
		return (-1);
	}

	while (c != '\n')
	{
		red = read(STDIN_FILENO, &c, 1);
		if (red == -1 || (red == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (red == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= 120)
		{
			buffer = _rrealloc(buffer, input, input + 1);
		}

		buffer[input] = c;
		input++;
	}
	buffer[input] = '\0';

	assign_lineptr(lineptr, n, buffer, input);

	ret = input;
	if (red != 0)
		input = 0;
	return (ret);
}
