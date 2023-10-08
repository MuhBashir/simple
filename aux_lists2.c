#include "main.h"

/**
 * add_rvar - adds a variable at the end
 * of a re_var list.
 * @head:  head of the linked list.
 * @lvar: length of the variable.
 * @val: value of the variable.
 * @lval: length of the value.
 * Return: address of the head
 */
re_var *add_rvar(re_var **head, int lvar, char *val, int lval)
{
	re_var *new, *temp;

	new = malloc(sizeof(re_var));
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;
	new->val = val;
	new->len_val = lval;

	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * free_rvar - frees a re_var list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_rvar(re_var **head)
{
	re_var *temp;
	re_var *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}
