#ifndef CH_DELEGATE_H
#define CH_DELEGATE_H

struct ch_dice_delegate;

struct ch_dice_delegate *
dice_delegate_create(void (*show)(int, int));

void
dice_delegate_add(struct ch_dice_delegate **delegate, void (*show)(int, int));

void
dice_delegate_remove(struct ch_dice_delegate **delegate, void (*show)(int, int));

void
dice_delegate_go(struct ch_dice_delegate *delegate, int a, int b);

void
dice_delegate_destroy(struct ch_dice_delegate **delegate);

#endif
