#pragma once

#include "Game/Play/Player.h"
#include "Game/Play/Item/Item.h"
#include "Video/Object.h"
#include "PlatformTypes.h"
#include <stdbool.h>

extern const uint16_t PalNumTableNormalBlocks[11];
uint16_t BlockPalNum(const Player* player, uint8_t blockNum);
uint16_t BlockTypePalNum(RotationSystem rotationSystem, BlockType blockType);
const ObjectData* WorldBlockObject(const Player* player, Block block, uint8_t borderMask, const ObjectData* source, ObjectData* destination);
extern const uint16_t PalNumTableItemBlocks[NUMITEMTYPES];
extern const Color* PalTableItemFieldBorder[NUMITEMTYPES];

void SetFieldBorderColor(Player* player, ItemType itemType);

typedef enum ShowBlockType {
	SHOWBLOCKTYPE_ACTIVE,
	SHOWBLOCKTYPE_NEXT,
	SHOWBLOCKTYPE_NEXT2,
	SHOWBLOCKTYPE_NEXT3,
	SHOWBLOCKTYPE_HOLD,
	SHOWBLOCKTYPE_TLS
} ShowBlockType;
void ShowBlock(Player* player, ShowBlockType showBlockType, bool show);

void ShowField(Player* player);

void ShowFieldPlus(Player* player);
