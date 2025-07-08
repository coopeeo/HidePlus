#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include "../utils.hpp"
#include "Geode/binding/GJGameLevel.hpp"

using namespace geode::prelude;

class $modify(LevelInfoLayer) {
	static void onModify(auto& self) {
        self.setHookPriority("LevelInfoLayer::init", -26902);
    }
	
	bool init(GJGameLevel* level, bool challenge) {
		if (!LevelInfoLayer::init(level, challenge)) {
			return false;
		}

		auto mod = Mod::get();

		if (!mod->getSettingValue<bool>("hideplus-enable")) return true;

		auto bottomMenuReplacement = CCMenu::create();
		bottomMenuReplacement->setVisible(false);
		bottomMenuReplacement->setID("replacer"_spr);
		this->addChild(bottomMenuReplacement);

		hide("LevelInfoLayer-iconkit",bottomMenuReplacement,this->getChildByID("garage-menu"));

		return true;
	}
};
