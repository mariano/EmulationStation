#ifndef _GUICOMPONENT_H_
#define _GUICOMPONENT_H_

#include "InputConfig.h"
#include "Vector2.h"

class Window;

class GuiComponent
{
public:
	GuiComponent(Window* window);
	virtual ~GuiComponent();

	//Return true if the input is consumed, false if it should continue to be passed to other children.
	virtual bool input(InputConfig* config, Input input);
	virtual void update(int deltaTime);
	virtual void render();
	virtual void init();
	virtual void deinit();

	Vector2i getGlobalOffset();
	Vector2i getOffset();
	void setOffset(Vector2i offset);
	void setOffset(int x, int y);

	void setParent(GuiComponent* parent);
	GuiComponent* getParent();

	void addChild(GuiComponent* cmp);
	void removeChild(GuiComponent* cmp);
	void clearChildren();
	unsigned int getChildCount();
	GuiComponent* getChild(unsigned int i);

protected:
	Window* mWindow;
	GuiComponent* mParent;
	Vector2i mOffset;
	std::vector<GuiComponent*> mChildren;
};

#endif
