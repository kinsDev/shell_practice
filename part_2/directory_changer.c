#include <unistd.h>
#include <stdlib.h>
#include "kkshell.h"
#include "main.h"

/**
 * _cd - Change the current working directory
 * @params: Shell parameters
 *
 * Return: void
 */
void _cd(param_t *params)
{
	char *target = NULL, cwd[1024];
	char **tmpArgs = NULL, **originArgs = NULL;
	int i;

	if (params->tokCount == 1)
	{
		/* If only 'cd' is provided, change to HOME directory */
		target = _getenv("HOME", params);
		if (!target)
		{
			params->status = 0;
			return;
		}
	}
	else if (params->args[1][0] == '-')
	{
		/* Handle options starting with '-' */
		if (!_strcmp(params->args[1], "-"))
		{
			/* Change to the previous working directory */
			target = _getenv("OLDPWD", params);
			if (!target)
			{
				params->status = 0;
				target = _getenv("PWD", params);
				_printf("%s\n", target);
				free(target);
				return;
			}
			_printf("%s\n", target);
		}
		else
		{
			params->status = 2;
			_printf("%s: %d: cd: Illegal option %c%c\n",
				params->argv[0], params->lineCount,
				'-', params->args[1][1]);
			return;
		}
	}
	else
	{
		/* Change to the provided directory */
		target = _strdup(params->args[1]);
		if (!target)
		{
			write(STDERR_FILENO, "cd target malloc error\n", 22);
			exit(EXIT_FAILURE);
		}
	}

	/* Attempt to change the current working directory */
	i = chdir(target);
	if (i)
	{
		/* Failed to change the directory */
		write_error(params, "can't cd to ");
		write(STDERR_FILENO, target, _strlen(target));
		write(STDERR_FILENO, "\n", 1);
		params->status = 0;
		free(target);
		return;
	}
	free(target);

	/* Update OLDPWD to the previous PWD */
	tmpArgs = malloc(sizeof(char *) * 3);
	if (!tmpArgs)
		exit(EXIT_FAILURE);
	originArgs = params->args;
	params->args = tmpArgs;
	params->tokCount = 3;

	tmpArgs[0] = _strdup("setenv");
	tmpArgs[1] = _strdup("OLDPWD");
	if (!tmpArgs[0] || !tmpArgs[1])
	{
		write(STDERR_FILENO, "cd old PWD malloc error\n", 23);
		free_params(params);
		exit(EXIT_FAILURE);
	}
	tmpArgs[2] = _getenv("PWD", params);
	_setenv(params);
	for (i = 0; i < 3; i++)
		free(tmpArgs[i]);

	/* Update PWD to the new working directory */
	tmpArgs[0] = _strdup("setenv");
	tmpArgs[1] = _strdup("PWD");
	tmpArgs[2] = _strdup(getcwd(cwd, 1024));
	if (!tmpArgs[0] || !tmpArgs[1] || !tmpArgs[2])
	{
		write(STDERR_FILENO, "cd new PWD malloc error\n", 23);
		free_params(params);
		exit(EXIT_FAILURE);
	}
	_setenv(params);
	for (i = 0; i < 3; i++)
		free(tmpArgs[i]);
	free(tmpArgs);

	/* Reset params */
	params->args = originArgs;
}

