#include "deck.h"
/**
 * num_fun - turn into integer card value
 * @head_t1: pointer to the list
 * Return: integer rep
 **/
int num_fun(deck_node_t *head_t1)
{
	int a_num, j;
	int num[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
	char val[13] = {'A', '2', '3', '4', '5', '6', '7',
		'8', '9', '1', 'J', 'Q', 'K'};

	for (j = 0; j < 13; j++)
	{
		if (head_t1->card->value[0] == val[j])
			a_num = num[j];
	}

	return (a_num);
}
/**
 * num_sort - sorts a doubly linked list of integers, 4 stages
 * @list: pointer to the list head
 * Return: no return
 **/
void num_sort(deck_node_t **list)
{
	deck_node_t *head_t1, *head_t2, *a1, *a2;
	int flag = 0, i, a_num1, a_num2;
	unsigned int k;

	head_t1 = *list;
	head_t2 = *list;
	for (i = 0; i < 4; i++)
	{ k =  head_t1->card->kind;
		while (head_t1->next && head_t1->next->card->kind == k)
		{
			a_num1 = num_fun(head_t1);
			a_num2 = num_fun(head_t1->next);
			flag = 0;
			head_t2 = head_t1;
			while (head_t2 && head_t2->card->kind == k && a_num1 > a_num2)
			{
				a1 = head_t2;
				a2 = head_t2->next;
				a1->next = a2->next;
				if (a2->next)
					a2->next->prev = a1;
				a2->prev = a1->prev;
				a2->next = a1;
				a1->prev = a2;
				if (a2->prev)
					a2->prev->next = a2;
				head_t2 = a2->prev;
				if (!a2->prev)
					*list = a2;
				flag = 1;
				if (!head_t2)
					break;
				a_num1 = num_fun(head_t2);
				a_num2 = num_fun(head_t2->next);
			}
			if (flag == 0)
				head_t1 = head_t1->next;
		}
		head_t1 = head_t1->next;
	}
}
/**
 * kind_sort - sorts a doubly linked list of integers
 *             in ascending order using the Insertion sort ailgorithm
 * @list: pointer to the list head
 * Return: no return
 **/
void kind_sort(deck_node_t **list)
{
	deck_node_t *head_t1, *head_t2, *a1, *a2;
	int flag;

	if (list)
	{
		head_t1 = *list;
		head_t2 = *list;
		while (list && head_t1->next)
		{
			if (head_t1->next)
			{
				flag = 0;
				head_t2 = head_t1;
				while (head_t2 && head_t2->card->kind > head_t2->next->card->kind)
				{
					a1 = head_t2;
					a2 = head_t2->next;
					a1->next = a2->next;
					if (a2->next)
						a2->next->prev = a1;
					if (a2)
					{
						a2->prev = a1->prev;
						a2->next = a1;
					}
					if (a1)
						a1->prev = a2;
					if (a2->prev)
						a2->prev->next = a2;
					head_t2 = a2->prev;
					if (!a2->prev)
						*list = a2;
					flag = 1;
				}
			}
			if (flag == 0)
				head_t1 = head_t1->next;
		}
	}
}
/**
 * sort_deck - sorts a deck of cards
 * @deck: ponter to the deck
 * Return: no return
 *
 **/
void sort_deck(deck_node_t **deck)
{
	if (deck)
	{
		kind_sort(deck);
		num_sort(deck);
	}
}
