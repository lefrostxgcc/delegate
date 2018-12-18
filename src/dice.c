#include <stdlib.h>
#include <time.h>
#include <dice.h>

enum {DICE_MIN = 1, DICE_MAX = 6, DICE_RANGE = DICE_MAX - DICE_MIN};

struct ch_dice
{
	void (*show)(int, int);
	int a;
	int b;
};

static int			random_dice(void);

struct ch_dice*		dice_create(void (*show_delegate)(int, int))
{
	struct ch_dice	*dice;

	srand(time(NULL));
	dice = (struct ch_dice *) malloc(sizeof(struct ch_dice));
	dice->show = show_delegate;
	return dice;
}

void				dice_go(struct ch_dice *dice)
{
	dice->a = random_dice();
	dice->b = random_dice();
	dice->show(dice->a, dice->b);
}

struct ch_dice*		dice_destroy(struct ch_dice *dice)
{
	free(dice);
}

static int			random_dice(void)
{
	return DICE_MIN + rand() % DICE_RANGE;
}
