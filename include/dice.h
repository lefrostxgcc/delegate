#ifndef CH_DICE_H
#define CH_DICE_H

struct ch_dice;

struct ch_dice*		dice_create(void (*show_delegate)(int, int));
void				dice_go(struct ch_dice *dice);
void				dice_show(struct ch_dice *dice);
struct ch_dice*		dice_destroy(struct ch_dice *dice);

#endif
