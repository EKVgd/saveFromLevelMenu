#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>

using namespace geode::prelude;

class $modify(MyInfoLayer, LevelInfoLayer) {

	void onMyButton(CCObject* target) {
		auto scene = reinterpret_cast<CCNode*>(CCScene::get());
		auto accLayer = AccountLayer::create();
		accLayer->setZOrder(1);
		accLayer->setVisible(true);
		accLayer->enterLayer();
		scene->addChild(accLayer);
	}

	bool init(GJGameLevel* p0, bool p1) {
		if (!LevelInfoLayer::init(p0, p1))
			return false;

		auto buttonSprite = CCSprite::createWithSpriteFrameName("GJ_profileButton_001.png");
		auto button = CCMenuItemSpriteExtra::create(
			buttonSprite, nullptr, this,
			menu_selector(MyInfoLayer::onMyButton)
		);
		button->setZOrder(2);
		button->setPosition(0, 0);
		auto menu = CCMenu::create();
		menu->addChild(button);
		menu->setPosition(-71, -81);
		menu->setScale(0.5);
		auto sidebar = this->getChildByID("other-menu");
		if (sidebar) 
		{
			sidebar->addChild(menu);
		}
		return true;
	} 
};