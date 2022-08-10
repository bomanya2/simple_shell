#ifndef _MAIN_H_
#define  _MAIN_H_

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

/* Mallocs */
#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

extern char **environ;

/**
 * struct data - Struct with all the relevant runtime data
 * @av: Argument Vector
 * @input: Cmd line
 * @args: Tokens of the cmd line
 * @status: Last status of the shell
 * @counter: Count of lines
 * @_environ: Env variable
 * @pid: PID of the shell
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
} data_shell;

/**
 * struct sep_list_s - Singly linked list
 * @separator: ; | &
 * @next: Next node
 * Description: Singly linked list for separators
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - Single linked list
 * @line: Cmd line
 * @next: Next node
 * Description: Singly linked list for cmd lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - Singly linked list
 * @len_var: Variable length
 * @val: Value of variable
 * @len_val: Value length
 * @next: Next node
 * Description: Singly linked list for variables
 */
typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;

/**
 * struct builtin_s - Builtin struct for args
 * @name: Name of the cmd builtin
 * @f: Data type pointer function
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t;

sep_list *add_sep_node_end(sep_list **head, char sep);
void free_sep_list(sep_list **head);
line_list *add_line_node_end(line_list **head, char *line);
void free_line_list(line_list **head);
r_var *add_rvar_node(r_var **head, int lvar, char *var, int lval);
void free_rvar_list(r_var **head);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);
void rev_string(char *s);

int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
int first_char(char *input, int *i);
void print_syntax_error(data_shell *datash, char *input, int i, int boolean);
int check_syntax_error(data_shell *datash, char *input);

char *without_comment(char *in);
void shell_loop(data_shell *datash);
char *read_line(int *i_eof);

char *swap_char(char *input, int boolean);
void add_nodes(sep_list **head_s, line_list **head_l, char *input);
void go_next(sep_list **list_s, line_list **list_l, data_shell *datash);
int split_commands(data_shell *datash, char *input);
char **split_line(char *input);

void check_env(r_var **h, char *in, data_shell *data);
int check_vars(r_var **h, char *in, char *st, data_shell *data);
char *replaced_input(r_var **head, char *input, char *new_input, int nlen);
char *rep_var(char *input, data_shell *datash);

void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
int exec_line(data_shell *datash);
int is_cdir(char *path, int *i);
char *_which(char *cmd, char **_environ);
int is_executable(data_shell *datash);
int check_error_cmd(char *dir, data_shell *datash);
int cmd_exec(data_shell *datash);


char *_getenv(const char *name, char **_environ);
int _env(data_shell *datash);
char *copy_info(char *name, char *value);
void set_env(char *name, char *value, data_shell *datash);
int _setenv(data_shell *datash);
int _unsetenv(data_shell *datash);
void cd_dot(data_shell *datash);
void cd_to(data_shell *datash);
void cd_previous(data_shell *datash);
void cd_to_home(data_shell *datash);
int cd_shell(data_shell *datash);
int (*get_builtin(char *cmd))(data_shell *datash);
int exit_shell(data_shell *datash);

int get_len(int n);
char *aux_itoa(int n);
int _atoi(char *s);
char *strcat_cd(data_shell *, char *, char *, char *);
char *error_get_cd(data_shell *datash);
char *error_not_found(data_shell *datash);
char *error_exit_shell(data_shell *datash);
char *error_get_alias(char **args);
char *error_env(data_shell *datash);
char *error_syntax(char **args);
char *error_permission(char **args);
char *error_path_126(data_shell *datash);

int get_error(data_shell *datash, int eval);
void get_sigint(int sig);
void aux_help_env(void);
void aux_help_setenv(void);
void aux_help_unsetenv(void);
void aux_help_general(void);
void aux_help_exit(void);
void aux_help(void);
void aux_help_alias(void);
void aux_help_cd(void);

int get_help(data_shell *datash);

#endif
