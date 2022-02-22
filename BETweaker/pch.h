﻿// pch.h: 这是预编译标头文件。
// 下方列出的文件仅编译一次，提高了将来生成的生成性能。
// 这还将影响 IntelliSense 性能，包括代码完成和许多代码浏览功能。
// 但是，如果此处列出的文件中的任何一个在生成之间有更新，它们全部都将被重新编译。
// 请勿在此处添加要频繁更新的文件，这将使得性能优势无效。

#ifndef PCH_H
#define PCH_H

#define JsonFile "plugins/BETweaker/config.json"
#define VERSION LL::Version{1,0,1}
#define BDSP 486
// 添加要在此处预编译的标头
#include <iostream>
#include <Global.h>
#include "setting.h"
#include <MC/Player.hpp>
#include <MC/BlockInstance.hpp>
#include <MC/Block.hpp>
#include <MC/CropBlock.hpp>
#include <MC/BlockLegacy.hpp>
#include <MC/ItemStack.hpp>
#include <EventAPI.h>
#include <LoggerAPI.h>
#include <MC/ItemInstance.hpp>
#include <mc/CompoundTag.hpp>
#include <MC/Level.hpp>
#include <MC/Randomize.hpp>
#include <MC/Random.hpp>
#include <MC/EnchantUtils.hpp>
#include <MC/BlockSource.hpp>
#include "Helper.h"
#endif //PCH_H