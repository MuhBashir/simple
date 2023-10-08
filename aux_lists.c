#include "main.h"

/**
 * add_sep_node -  adds a separator found at the end
 * of a sep_list.
 * @head: head of the linked list.
 * @sep: separator found (; | &).
 * Return: address of the head
 */
sep_list *add_sep_node(sep_list **head, char sep)
{
	sep_list *new, *temp;

	new = malloc(sizeof(sep_list));
	if (new == NULL)
		return (NULL);

	new->separator = sep;
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
 * free_sep - frees a sep_list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_sep(sep_list **head)
{
	sep_list *temp;
	sep_list *curr;

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

/**
 * add_line_node - adds a command line at the end
 * of a list_line.
 * @head: head of the linked list.
 * @line: command line.
 * Return: address of the head.
 */
list_line *add_line_node(list_line **head, char *line)
{
	list_line *new, *temp;

	new = malloc(sizeof(list_line));
	if (new == NULL)
		return (NULL);

	new->line = line;
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
 * free_line - frees a list_line
 * @head: head of the linked list.
 * Return: no return.
 */
void free_line(list_line **head)
{
	list_line *temp;
	list_line *curr;

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
