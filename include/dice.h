#ifndef CH_DICE_H
#define CH_DICE_H

#include <delegate.h>

struct ch_dice;

struct ch_dice*		dice_create(struct ch_dice_delegate *delegate);
void				dice_go(struct ch_dice *dice);
struct ch_dice*		dice_destroy(struct ch_dice *dice);

#endif
