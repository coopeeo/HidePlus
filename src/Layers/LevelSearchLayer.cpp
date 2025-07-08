#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>
#include <Geode/binding/LevelSearchLayer.hpp>
#include "../utils.hpp"


void hidesearchbtns(auto replace,auto btnslayer) {
     remove("LevelSearchLayer-levelsearchbutton",replace,btnslayer->getChildByID("search-level-button"));
     remove("LevelSearchLayer-levelsearchuserbutton",replace,btnslayer->getChildByID("search-user-button"));
     remove("LevelSearchLayer-levelclearbutton",replace,btnslayer->getChildByID("clear-search-button"));
}
void hideotherfiltersmenu(auto replace,auto btnslayer) {
    remove("LevelSearchLayer-clearfilters",replace,btnslayer->getChildByID("clear-filters-button"));
    remove("LevelSearchLayer-advancedfilters",replace,btnslayer->getChildByID("advanced-filters-button"));
    remove("LevelSearchLayer-listbutton",replace,btnslayer->getChildByID("lists-button"));
}

void hideQuickSearchMenu(auto replace,auto btnslayer) {
    remove("LevelSearchLayer-mostdownloadedbutton",replace,btnslayer->getChildByID("most-downloaded-button"));
    remove("LevelSearchLayer-mostlikedbutton",replace,btnslayer->getChildByID("most-liked-button"));
    remove("LevelSearchLayer-sentbutton",replace,btnslayer->getChildByID("sent-button"));
    remove("LevelSearchLayer-trendingbutton",replace,btnslayer->getChildByID("trending-button"));
    remove("LevelSearchLayer-recentbutton",replace,btnslayer->getChildByID("recent-button"));
    remove("LevelSearchLayer-magicbutton",replace,btnslayer->getChildByID("magic-button"));
    remove("LevelSearchLayer-awardedbutton",replace,btnslayer->getChildByID("awarded-button"));
    remove("LevelSearchLayer-followedbutton",replace,btnslayer->getChildByID("followed-button"));
    remove("LevelSearchLayer-friendsbutton",replace,btnslayer->getChildByID("friends-button"));
}
void ThisStupidDiffcultymenu(auto replace,auto btnslayer) {
        remove("LevelSearchLayer-nafilterbutton",replace,btnslayer->getChildByID("na-filter-button"));
        remove("LevelSearchLayer-easyfilterbutton",replace,btnslayer->getChildByID("easy-filter-button"));
        remove("LevelSearchLayer-normalfilterbutton",replace,btnslayer->getChildByID("normal-filter-button"));
        remove("LevelSearchLayer-hardfilterbutton",replace,btnslayer->getChildByID("hard-filter-button"));
        remove("LevelSearchLayer-harderfilterbutton",replace,btnslayer->getChildByID("harder-filter-button"));
        remove("LevelSearchLayer-insanefilterbutton",replace,btnslayer->getChildByID("insane-filter-button"));
        remove("LevelSearchLayer-demonfilterbutton",replace,btnslayer->getChildByID("demon-filter-button"));
        remove("LevelSearchLayer-demontypebutton",replace,btnslayer->getChildByID("demon-type-filter-button"));
        remove("LevelSearchLayer-autofilterbutton",replace,btnslayer->getChildByID("auto-filter-button"));
}
void lengthmenu(auto replace,auto btnslayer) {
    remove("LevelSearchLayer-iconclock",replace,btnslayer->getChildByID("clock-icon"));
    remove("LevelSearchLayer-shortfilter",replace,btnslayer->getChildByID("short-filter-button"));
    remove("LevelSearchLayer-tinyfilter",replace,btnslayer->getChildByID("tiny-filter-button"));
    remove("LevelSearchLayer-mediumfilter",replace,btnslayer->getChildByID("medium-filter-button"));
    remove("LevelSearchLayer-longfilter",replace,btnslayer->getChildByID("long-filter-button"));
    remove("LevelSearchLayer-xlfilter",replace,btnslayer->getChildByID("xl-filter-button"));
    remove("LevelSearchLayer-platfilter",replace,btnslayer->getChildByID("plat-filter-button"));
    remove("LevelSearchLayer-starfilter",replace,btnslayer->getChildByID("star-filter-button"));
}
class $modify(LevelSearchLayer) {
	static void onModify(auto& self) {
        self.setHookPriority("LevelSearchLayer::init", -26902);
    }
	
	bool init(int p0) {
		if (!LevelSearchLayer::init(p0)) {
			return false;
		}

		auto mod = Mod::get();

		if (!mod->getSettingValue<bool>("hideplus-enable")) return true;
	
		auto bottomMenuReplacement = CCMenu::create();
		bottomMenuReplacement->setVisible(false);
		bottomMenuReplacement->setID("replacer"_spr);
		this->addChild(bottomMenuReplacement);

		hide("LevelSearchLayer-background",bottomMenuReplacement,this->getChildByID("background"));
        remove("LevelSearchLayer-levelsearchbg",bottomMenuReplacement,this->getChildByID("level-search-bg"));
        remove("LevelSearchLayer-levelsearchbarbg",bottomMenuReplacement,this->getChildByID("level-search-bar-bg"));
        remove("LevelSearchLayer-quicksearchbg",bottomMenuReplacement,this->getChildByID("quick-search-bg"));
        remove("LevelSearchLayer-difficultyfiltersbg",bottomMenuReplacement,this->getChildByID("difficulty-filters-bg"));
        remove("LevelSearchLayer-lengthfiltersbg",bottomMenuReplacement,this->getChildByID("length-filters-bg"));
        remove("LevelSearchLayer-quicksearchtext",bottomMenuReplacement,this->getChildByID("quick-search-title"));
        remove("LevelSearchLayer-filterstitle",bottomMenuReplacement,this->getChildByID("filters-title"));
        remove("LevelSearchLayer-corners",bottomMenuReplacement,this->getChildByID("left-corner"));
        remove("LevelSearchLayer-corners",bottomMenuReplacement,this->getChildByID("right-corner"));
        
        if(auto searchbtns = this->getChildByID("search-button-menu")) {
			hidesearchbtns(bottomMenuReplacement,searchbtns);
		};
        
        if(auto menuQuickSearch = this->getChildByID("quick-search-menu")) {
			hideQuickSearchMenu(bottomMenuReplacement,menuQuickSearch);
		};
        
        if(auto filter = this->getChildByID("other-filter-menu")) {
			hideotherfiltersmenu(bottomMenuReplacement,filter);
		};
        
        if(auto menufilters = this->getChildByID("difficulty-filter-menu")) {
			ThisStupidDiffcultymenu(bottomMenuReplacement,menufilters);
		};
        
        if(auto menutime = this->getChildByID("length-filter-menu")) {
			lengthmenu(bottomMenuReplacement,menutime);
		};
		return true;
	}
};

