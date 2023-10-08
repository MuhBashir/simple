#ifndef _MAIN_
#define _MAIN_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFFER_SIZE 1024
#define TOKKEN_BUFSIZE 128
#define TOKEN_DELIM " \t\r\n\a"
/*
#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"
*/

/* Points to an array of pointers to strings called the "environment" */
extern char **env;
/*
extern char **environ;

*/

/**
 * struct data - struct that contains all relevant data on runtime
 * @av: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell.
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} shell_data;

/**
 * struct sep_list_s - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} list_line;
/*
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} list_line;
*/

/**
 * struct r_var_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} re_var;
/*
	{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var; 
*/

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(shell_data *datash);
} builtin_type;

/* aux_lists.c */
sep_list *add_sep_node(sep_list **head, char sep);
void free_sep(sep_list **head);
list_line *add_line_node(list_line **head, char *line);
void free_line(list_line **head);

/* aux_lists2.c */
re_var *add_rvar(re_var **head, int lvar, char *var, int lval);
void free_rvar(re_var **head);

/* aux_str functions */
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);

/* aux_mem.c */
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

/* aux_str2.c */
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_characters(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);

/* aux_str3.c */
void reverse_string(char *s);

/* check_syntax_error.c */
int repeated_characters(char *input, int i);
int error_sep(char *input, int i, char last);
int first_character(char *input, int *i);
void print_syntax_err(shell_data *datash, char *input, int i, int bool);
int check_syntax_err(shell_data *datash, char *input);

/* shell_loop.c */
char *without_comments(char *in);
void loop_shell(shell_data *datash);

/* read_line.c */
char *line_read(int *i_eof);

/* split.c */
char *swap_character(char *input, int bool);
void add_nodes_r(sep_list **head_s, list_line **head_l, char *input);
void go_next_r(sep_list **list_s, list_line **list_l, shell_data *datash);
int split_commands_r(shell_data *datash, char *input);
char **split_line_r(char *input);

/* rep_var.c */
void check_env_r(re_var **h, char *in, shell_data *data);
int check_vars_r(re_var **h, char *in, char *st, shell_data *data);
char *replaced_input_r(re_var **head, char *input, char *new_input, int nlen);
char *rep_var_r(char *input, shell_data *datash);

/* get_line.c */
void bring_line_r(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line_r(char **lineptr, size_t *n, FILE *stream);

/* exec_line */
int exec_line_r(shell_data *datash);

/* cmd_exec.c */
int is_cdir_r(char *path, int *i);
char *_which_r(char *cmd, char **_environ);
int is_executable_r(shell_data *datash);
int check_error_cmd_r(char *dir, shell_data *datash);
int cmd_exec_r(shell_data *datash);

/* env1.c */
char *_getenv_r(const char *name, char **_environ);
int _env_r(shell_data *datash);

/* env2.c */
char *copy_info_r(char *name, char *value);
void set_env_r(char *name, char *value, shell_data *datash);
int _setenv_r(shell_data *datash);
int _unsetenv_r(shell_data *datash);

/* cd.c */
void cd_dot(shell_data *datash);
void cd_to(shell_data *datash);
void cd_previous(shell_data *datash);
void cd_to_home(shell_data *datash);

/* cd_shell.c */
int cd_shell_r(shell_data *datash);

/* get_builtin */
int (*get_builtin_r(char *cmd))(shell_data *datash);

/* _exit.c */
int exit_shell_r(shell_data *datash);

/* aux_stdlib.c */
int get_len_r(int n);
char *aux_itoa_r(int n);
int _atoi(char *s);

/* aux_error1.c */
char *strcat_cd_r(shell_data *, char *, char *, char *);
char *error_get_cd_r(shell_data *datash);
char *error_not_found_r(shell_data *datash);
char *error_exit_shell_r(shell_data *datash);

/* aux_error2.c */
char *error_get_alias_r(char **args);
char *error_env_r(shell_data *datash);
char *error_syntax_r(char **args);
char *error_permission_r(char **args);
char *error_path_126_r(shell_data *datash);


/* get_error.c */
int get_error(shell_data *datash, int eval);

/* get_sigint.c */
void get_sigint_r(int sig);

/* aux_help.c */
void aux_help_env_r(void);
void aux_help_setenv_r(void);
void aux_help_unsetenv_r(void);
void aux_help_general_r(void);
void aux_help_exit_r(void);

/* aux_help2.c */
void aux_help_r(void);
void aux_help_alias_r(void);
void aux_help_cd_r(void);

/* get_help.c */
int get_help(shell_data *datash);

#endif
