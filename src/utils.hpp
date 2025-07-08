#pragma once
#include <Geode/Geode.hpp>
using namespace geode::prelude;

static void remove(std::string setting, CCMenu* replacementMenu, CCNode* node) {
	auto mod = Mod::get();
	if(!mod->getSettingValue<bool>(setting)) return;
    if(!node) return;
    auto parent = node->getParent();
	node->setVisible(false);
	node->removeFromParent();
	replacementMenu->addChild(node);
    if (auto parentAsLayer = static_cast<CCMenu*>(parent)) parent->updateLayout();
}
static void hide(std::string setting, CCMenu* replacementMenu, CCNode* node) {
	auto mod = Mod::get();
	if(!mod->getSettingValue<bool>(setting)) return;
    if(!node) return;
	node->setVisible(false);
}
