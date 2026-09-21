#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>

using namespace geode::prelude;

const char* ROW_TOP[3] = {"create-button", "saved-button", "scores-button"};
const char* ROW_MID[4] = {"quests-button", "daily-button", "weekly-button", "gauntlets-button"};
const char* ROW_BOT[3] = {"featured-button", "map-packs-button", "search-button"};

class $modify(CreatorLayer) {
    bool init() {
        if (!CreatorLayer::init()) return false;
        return true;
    }
};
