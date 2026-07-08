#pragma once

#include "PlatformTypes.h"
#include "Video/Video.h"
#include <stdint.h>
#include <stdbool.h>

bool MountRoms();

// "Open" functions need their corresponding "Close" function called when you're done with the data they open.
// "Load" functions don't need anything closed, they merely read from programData and write to statically-allocated global data.

const uint8_t* OpenProgramData();
void CloseProgramData(const uint8_t* const programData);

#define TILEROM_SIZE 0x200000
#define NUMTILEROMS 16
#define TILEDATA_SIZE (TILEROM_SIZE * NUMTILEROMS)
#define WORLD_BLOCK_COLOR_COUNT 8u
#define WORLD_BLOCK_BORDER_COUNT 17u
#define WORLD_BLOCK_RAW_BORDER 16u
#define WORLD_BLOCK_TILE_COUNT (WORLD_BLOCK_COLOR_COUNT * WORLD_BLOCK_BORDER_COUNT)
#define WORLD_BLOCK_TILE_BASE (0xC000u + TILEDATA_SIZE / NUMPALCOLORS_8BPP)
#define BONE_BLOCK_BORDER_COUNT WORLD_BLOCK_BORDER_COUNT
#define BONE_BLOCK_TILE_COUNT (2u * BONE_BLOCK_BORDER_COUNT)
#define BONE_BLOCK_CLASSIC_TILE (WORLD_BLOCK_TILE_BASE + WORLD_BLOCK_TILE_COUNT)
#define BONE_BLOCK_WORLD_TILE (BONE_BLOCK_CLASSIC_TILE + BONE_BLOCK_BORDER_COUNT)
#define SHIRASE_LABEL_TILE_COUNT 8u
#define SHIRASE_LABEL_TILE_BASE (BONE_BLOCK_CLASSIC_TILE + BONE_BLOCK_TILE_COUNT)

extern uint8_t* TileData;
extern Color WorldBlockPalette[NUMPALCOLORS_8BPP];
bool OpenTileData();
void CloseTileData();

void LoadReplays(const uint8_t* const programData);

extern ROMDATA Color Pal1[NUMPALCOLORS_4BPP];
extern ROMDATA Color PalSmallText[NUMPALCOLORS_4BPP];
void LoadPals(const uint8_t* const programData);

void LoadBgMaps(const uint8_t* const programData);

void LoadObjects(const uint8_t* const programData);

#define SNDROM_SIZE 0x400000
extern uint8_t* SoundRomData;
bool OpenSoundData(const uint8_t* const programData);
void CloseSoundData();

// Convenience function that opens all data.
bool OpenData();

// Convenience function that closes all data opened by OpenData().
void CloseData();
