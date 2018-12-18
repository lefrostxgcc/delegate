#include <stdlib.h>
#include <time.h>
#include <dice.h>

enum {DICE_MIN = 1, DICE_MAX = 6, DICE_RANGE = DICE_MAX - DICE_MIN};

struct ch_dice
{
	struct ch_dice_delegate		*delegate;
	int							a;
	int							b;
};

static int			random_dice(void);

struct ch_dice*		dice_create(struct ch_dice_delegate *delegate)
{
	struct ch_dice	*dice;

	srand(time(NULL));
	dice = (struct ch_dice *) malloc(sizeof(struct ch_dice));
	dice->delegate = delegate;
	return dice;
}

void				dice_go(struct ch_dice *dice)
{
	dice->a = random_dice();
	dice->b = random_dice();
	dice_delegate_go(dice->delegate, dice->a, dice->b);
}

struct ch_dice*		dice_destroy(struct ch_dice *dice)
{
	free(dice);
}

static int			random_dice(void)
{
	return DICE_MIN + rand() % DICE_RANGE;
}
