#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>
#include <algorithm>

using namespace geode::prelude;

const char* ROW_TOP[3] = {"create-button", "saved-button", "scores-button"};
const char* ROW_MID[4] = {"quests-button", "daily-button", "weekly-button", "gauntlets-button"};
const char* ROW_BOT[4] = {"featured-button", "lists-button", "map-packs-button", "search-button"};

constexpr float SCALE = 1.1f;

CCMenu* buildRow(CCMenu* src, const char* const* ids, int n, float gap, const char* id) {
    auto row = CCMenu::create();
    row->setID(id);
    for (int i = 0; i < n; i++) {
        auto btn = src->getChildByID(ids[i]);
        if (!btn) continue;
        btn->retain();
        btn->removeFromParent();
        btn->setScale(SCALE);
        row->addChild(btn);
        btn->release();
    }
    row->setLayout(RowLayout::create()->setGap(gap));
    row->updateLayout();
    return row;
}

class $modify(CreatorLayer) {
    bool init() {
        if (!CreatorLayer::init()) return false;

        if (Mod::get()->getSettingValue<std::string>("menu-version") != "2.1") return true;

        auto menu = static_cast<CCMenu*>(getChildByID("creator-buttons-menu"));
        if (!menu) return true;

        auto win = CCDirector::get()->getWinSize();

        auto top = buildRow(menu, ROW_TOP, 3, 8.f, "legacymenu-top"_spr);
        auto mid = buildRow(menu, ROW_MID, 4, 8.f, "legacymenu-mid"_spr);
        auto bot = buildRow(menu, ROW_BOT, 4, 8.f, "legacymenu-bot"_spr);

        float rowGap = std::max({top->getContentSize().height, mid->getContentSize().height, bot->getContentSize().height}) * 1.05f;

        top->setPosition({win.width / 2.f, win.height / 2.f + rowGap});
        mid->setPosition({win.width / 2.f, win.height / 2.f});
        bot->setPosition({win.width / 2.f, win.height / 2.f - rowGap});

        addChild(top);
        addChild(mid);
        addChild(bot);

        menu->setVisible(false);

        return true;
    }
};
