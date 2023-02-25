/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:33:31 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/25 18:53:02 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void ft_free_stack(t_deque *a)
{
	t_node *temp;
	t_node *t;
	temp = a->head;
	while (temp)
	{
		t = temp->next;
		free(temp);
		temp = t;
	}
	free(a);
}

void ft_free_everything(t_infos *data)
{
	ft_free_stack(data->a);
	ft_free_stack(data->b);
	free(data->numbers);
}

t_node *ft_new_node(int number)
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->number = number;
	new_node->next = NULL;
	new_node->previous = NULL;
	new_node->index = -1;
	return (new_node);
}

void	ft_push_front(t_deque *deck, int number)
{
	t_node *new_node;

	new_node = ft_new_node(number);
	if (!new_node)
		return;
	if (deck->head == NULL)
	{
		deck->head = new_node;
		deck->tail = new_node;
	}
	else
	{
		new_node->next = deck->head;
		deck->head->previous = new_node;
		deck->head = new_node;
	}
	deck->size++;
}

void ft_push_rear(t_deque *deck, int number)
{
	t_node *new_node;

	new_node = ft_new_node(number);
	if (!new_node)
		return;
	if (deck->tail == NULL)
	{
		deck->head = new_node;
		deck->tail = new_node;
	}
	else
	{
		deck->tail->next = new_node;
		new_node->previous = deck->tail;
		deck->tail = new_node;
	}
	deck->size++;
}

int ft_pop_front(t_deque *deck)
{
	t_node *temp;
	int number;

	if (deck->head == NULL)
		return (UINT_MAX);
	temp = deck->head;
	number = temp->number;
	deck->head = deck->head->next;
	if (deck->head == NULL)
		deck->tail = NULL;
	else
		deck->head->previous = NULL;
	free(temp);
	deck->size--;
	return (number);
}

int ft_pop_rear(t_deque *deck)
{
	t_node *temp;
	int number;

	if (deck->tail == NULL)
		return (INT_MAX);
	temp = deck->tail;
	number = temp->number;
	deck->tail = deck->tail->previous;
	if (deck->tail == NULL)
		deck->head = NULL;
	else
		deck->tail->next = NULL;
	free(temp);
	deck->size--;
	return (number);
}