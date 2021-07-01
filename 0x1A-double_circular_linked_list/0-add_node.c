#include "list.h"

/**
 * create_node - creates a new List node
 * @str: string to copy into the new node
 * Return: node of List type
 */
List *create_List_node(char *str)
{
	List *node = malloc(sizeof(List));

	/* Check input, malloc, strdup */
	if (!str || !node)
		return (NULL);

	node->next = node->prev = NULL;
	node->str = strdup(str);

	return (node);
}

/**
 * add_node_end - adds a node to the end
 * of a doubly circular linked list
 * @list: head of the linked list
 * @str: string to copy into the new node
 * Return: Address of the newly added node
 */
List *add_node_end(List **list, char *str)
{
	List *node = create_List_node(str);
	List *head_node, *last_node = NULL;

	if (!node)
		return (NULL);

	if (!(*list))
		node->prev = node->next = *list = node;
	else
	{
		head_node = *list;
		last_node = (*list)->prev;

		last_node->next = node;

		node->prev = last_node;
		node->next = head_node;

		head_node->prev = node;
	}

	return (node);
}

/**
 * add_node_begin - adds a node at the beginning
 * of a doubly circular linked list
 * @list: head of the linked list
 * @str: string to copy into the new node
 * Return: Address of the newly added node
 */
List *add_node_begin(List **list, char *str)
{
	List *node = create_List_node(str);
	List *head_node, *last_node = NULL;

	if (!node)
		return (NULL);

	if (!(*list))
		node->prev = node->next = node;
	else
	{
		head_node = *list;
		last_node = (*list)->prev;

		last_node->next = node;

		node->prev = last_node;
		node->next = head_node;

		head_node->prev = node;
	}

	*list = node; /* Reset Head in both cases */
	return (node);
}
