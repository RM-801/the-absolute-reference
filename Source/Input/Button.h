#pragma once

#include "Input/InputTypes.h"
#include <stdint.h>

extern uint16_t SystemButtonsDown[NUMPLAYERS];
extern uint16_t PlatformExtraButtonsDown[NUMPLAYERS];
// TODO: DIP switches? Check MAME source.
extern uint8_t UNK_6064756[2];
extern uint16_t ButtonsDown[NUMPLAYERS];
extern uint16_t GameButtonsDown[NUMPLAYERS];
extern uint16_t GameButtonsOld[NUMPLAYERS];
extern uint16_t GameButtonsNew[NUMPLAYERS];
