#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>

using namespace geode::prelude;

const char* ROW_TOP[3] = {"create-button", "saved-button", "scores-button"};
const char* ROW_MID[4] = {"quests-button", "daily-button", "weekly-button", "gauntlets-button"};
const char* ROW_BOT[3] = {"featured-button", "map-packs-button", "search-button"};

void placeRow(CCMenu* menu, const char* ids[4], float y, float gap) {
    int n = 0;
    while (n < 4 && ids[n]) n++;
    float startX = -(gap * (n - 1)) / 2.f;
    for (int i = 0; i < n; i++) {
        auto btn = menu->getChildByID(ids[i]);
        if (!btn) continue;
        btn->setPosition({startX + gap * i, y});
        btn->setScale(1.15f);
    }
}

class $modify(CreatorLayer) {
    bool init() {
        if (!CreatorLayer::init()) return false;

        auto menu = static_cast<CCMenu*>(getChildByID("creator-buttons-menu"));
        if (!menu) return true;
        menu->setLayout(nullptr);

        auto win = CCDirector::get()->getWinSize();
        menu->setPosition({win.width / 2.f, win.height / 2.f});

        placeRow(menu, ROW_TOP, win.height * 0.22f, 145.f);
        placeRow(menu, ROW_MID, 0.f, 110.f);
        placeRow(menu, ROW_BOT, -win.height * 0.22f, 145.f);

        return true;
    }
};
