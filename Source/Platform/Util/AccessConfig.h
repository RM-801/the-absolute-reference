#pragma once

#include "Input/InputTypes.h"
#include "SDL.h"
#include <stdbool.h>

bool OpenConfig();
void SaveConfig();
void CloseConfig();

typedef struct KeySetting {
	SDL_Keymod mod;
	SDL_Keycode code;
} KeySetting;

extern KeySetting InputConfigKeyboard[NUMINPUTS][8];

extern KeySetting InputApplicationKeyboardQuit;

extern SDL_Joystick* Joysticks[NUMPLAYERS];
extern int InputConfigJoystickButtons[NUMPLAYERS][NUMINPUTS][8];
extern int InputConfigJoystickAxes[NUMPLAYERS][NUMINPUTS][8][2];
extern int InputConfigJoystickHats[NUMPLAYERS][NUMINPUTS][8][2];

typedef enum DisplayMode {
	DISPLAY_WINDOW,
	DISPLAY_FULLSCREENEXCLUSIVE,
	DISPLAY_FULLSCREENDESKTOP
} DisplayMode;
extern DisplayMode DisplayModeSetting;

extern int DisplayDimensions[2];

extern int Vsync;

extern int VsyncUpdateRate;

extern bool AudioMuted;

typedef enum MixingSetting {
	MIXING_MONO,
	MIXING_STEREO
} MixingSetting;
extern MixingSetting AudioMixing;

typedef enum SpeakersSetting {
	SPEAKERS_LEFT  = 1 << 0,
	SPEAKERS_RIGHT = 1 << 1,
	SPEAKERS_BOTH  = SPEAKERS_LEFT | SPEAKERS_RIGHT
} SpeakersSetting;
extern SpeakersSetting AudioSpeakers;

extern uint8_t DiagonalUpperwardMask;
extern uint8_t DiagonalDownwardMask;

// List of control methods, some codes are automatically generated
// based on the contents of this macro.
//
// method(rotationSystem, variant, stepReset)
//  -  "rotationSystem" is related to the color, initial direction, and
//     drop method of tetrominos.
//  -  "stepReset" is related to how tetrominos reset lock delay, step
//     reset or move, rotation reset.
//
// Config options are also automatically generated.
// The program will call function RotationBlockedCheckKick_$(rotation)_$(variant)
// (e.g. RotationBlockedCheckKick_ARS_TA)
// to check if a rotation is possible, it still needs to write this function manually.
#define FOREACH_CONTROL_METHOD(method) \
	method(ARS, TA, 1) method(SRS, TI, 0)

#define DEFAULT_CONTROL_METHOD CTRL_METHOD_ARS_TA

#define FUNC(rs, var, unused)							\
	CTRL_METHOD_##rs##_##var,

typedef enum ControlMethods {
	FOREACH_CONTROL_METHOD(FUNC)
} ControlMethods;

#undef FUNC
extern ControlMethods ControlMethod;

// TODO: Support more randomizers.
#define FOREACH_RANDOMIZER(randomizer) \
	randomizer(4H6R)

#define DEFAULT_RANDOMIZER RANDOMIZER_4H6R

#define FUNC(name) \
	RANDOMIZER_##name,

typedef enum Randomizers {
	FOREACH_RANDOMIZER(FUNC)
} Randomizers;

#undef FUNC
extern Randomizers Randomizer;
