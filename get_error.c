#include "main.h"

/**
 * get_error -  calls the error according the builtin, syntax or permission
 * @datash: data structure that contains arguments
 * @eval: error value
 * Return: error
 */
int get_error(shell_data *datash, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = error_env_r(datash);
		break;
	case 126:
		error = error_path_126_r(datash);
		break;
	case 127:
		error = error_not_found_r(datash);
		break;
	case 2:
		if (_strcmp("exit", datash->args[0]) == 0)
			error = error_exit_shell(datash);
		else if (_strcmp("cd", datash->args[0]) == 0)
			error = error_get_cd_r(datash);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	datash->status = eval;
	return (eval);
}
