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

	p = *delegate;

	if (!p)
		return;

	if (p->show == show)
	{
		*delegate = p->next;
		free(p);
	}

	p_prev = p;
	while (p != NULL)
	{
		if (p->show == show)
		{
			p_prev->next = p->next;
			p = p->next;
			free(p);
		}
		else
		{
			p_prev = p;
			p = p->next;
		}
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

	for (p_next = p->next; p != NULL; p = p_next, p_next = p_next->next)
		free(p);

	*delegate = NULL;
}
