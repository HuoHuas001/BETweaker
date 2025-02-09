#pragma once

#include <Utils/FileHelper.h>
#include <Nlohmann/json.hpp>

namespace Settings {
    extern bool BetterHarvestingCrop;
    extern bool NoFarmDestroy;
    extern bool FastSleeping;
    extern bool DispenserCrops;
    extern bool FastLeafDecay;
    extern bool HUBinfo;
    extern bool EditSign;
    extern bool AutoFish;
    extern bool DoubleDoors;
    extern bool FastSetMinecart;
    extern bool AutoSupplyItem;
    extern bool CuttingTree;
    extern string HUBInfoShow;
    extern std::unordered_set<string> CanDispenserItemList;
    nlohmann::json globaljson();
    void initjson(nlohmann::json json);
    void WriteDefaultConfig(const std::string& fileName);
    void LoadConfigFromJson(const std::string& fileName);
    void reloadJson(const std::string& fileName);
} // namespace Settings