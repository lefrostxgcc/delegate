#include <stdlib.h>
#include <delegate.h>

struct ch_dice_delegate
{
	void (*show)(int, int);
	struct ch_dice_delegate *next;
};

struct ch_dice_delegate *
dice_delegate_create(void (*show)(int, int))
{
	struct ch_dice_delegate	*head;

	head = NULL;
	dice_delegate_add(&head, show);
	return head;
}

void
dice_delegate_add(struct ch_dice_delegate **delegate, void (*show)(int, int))
{
	struct ch_dice_delegate	*node;
	struct ch_dice_delegate	*p;

	node = (struct ch_dice_delegate *) malloc(sizeof(struct ch_dice_delegate));
	node->show = show;
	node->next = NULL;

	if(!*delegate)
		*delegate = node;
	else
	{
		for (p = *delegate; p->next != NULL; p = p->next)
			;
		p->next = node;
	}
}

void
dice_delegate_remove(struct ch_dice_delegate **delegate, void (*show)(int, int))
{
	struct ch_dice_delegate	*p;
	struct ch_dice_delegate	*p_prev;
	struct ch_dice_delegate	*p_next;

	p = *delegate;

	if (!p)
		return;

	if (p->show == show)
	{
		p_next = p->next;
		*delegate = p_next;
		free(p);
		p = p_next;
	}

	p_prev = p;
	while (p != NULL)
	{
		p_next = p->next;
		if (p->show == show)
		{
			p_prev->next = p_next;
			free(p);
		}
		else
		{
			p_prev = p;
		}
		p = p_next;
	}
}

void
dice_delegate_go(struct ch_dice_delegate *delegate, int a, int b)
{
	for (; delegate; delegate = delegate->next)
		delegate->show(a, b);
}

void
dice_delegate_destroy(struct ch_dice_delegate **delegate)
{
	struct ch_dice_delegate	*p;
	struct ch_dice_delegate	*p_next;

	p = *delegate;

	if (!p)
		return;

	while (p != NULL)
	{
		p_next = p->next;
		free(p);
		p = p_next;
		if (p_next)
			p_next = p_next->next;
	}

	*delegate = NULL;
}



















