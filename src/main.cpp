#include <Geode/modify/GameManager.hpp>
#include <Geode/modify/GameStatsManager.hpp>
#include <Geode/loader/Mod.hpp>

using namespace geode::prelude;

class $modify(GameManager) {
    bool isColorUnlocked(int key, UnlockType type) {
        auto mod = Mod::get();

        if (mod->getSettingValue<bool>("enabled")) {
            return true;
        }

        return GameManager::isColorUnlocked(key, type);
    }

    bool isIconUnlocked(int key, IconType type) {
        auto mod = Mod::get();

        if (mod->getSettingValue<bool>("enabled")) {
            return true;
        }

        return GameManager::isIconUnlocked(key, type);
    }
};

class $modify(GameStatsManager) {
    bool isItemUnlocked(UnlockType type, int key) {
        auto mod = Mod::get();

        if (mod->getSettingValue<bool>("enabled")) {
            return true;
        }

        return GameStatsManager::isItemUnlocked(type, key);
    }
};
