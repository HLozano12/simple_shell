#include "tom_shelleck.h"

/**
 * _unsetenv - deletes a variable name from the environment
 * @name: name of env variable
 * Return: 3 on success, -1 for error
 */
int _unsetenv(const char *name)
{
	int i, size;

	size = sizeof(char *);
	for (i = 0; name[i]; i++)
		if (name[i] == '=')
			return (-1);
	i = env_index(name);
	if (i < 0)
		return (3);
	free(environ[i]);
	environ[i] = environ[i + 1];
	for (i++; environ[i]; i++)
		environ[i] = environ[i + 1];
	environ = _reallocf(environ, size * (i + 2), size * (i + 1));
	if (!environ)
		return (-1);
	return (3);
}
