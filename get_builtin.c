#include "main.h"

/**
 * get_builtin_r -  builtin that pais the command in the arg
 * @cmd: command
 * Return: function pointer of the builtin command.
 */
int (*get_builtin_r(char *cmd))(shell_data *)
{
	builtin_type builtin[] = {
		{ "env", _env_r },
		{ "exit", exit_shell },
		{ "setenv", _setenv_r },
		{ "unsetenv", _unsetenv_r },
		{ "cd", cd_shell_r },
		{ "help", get_help },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; builtin[i].name; i++)
	{
		if (_strcmp(builtin[i].name, cmd) == 0)
			break;
	}

	return (builtin[i].f);
}
