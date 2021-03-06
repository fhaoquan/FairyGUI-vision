#ifndef __GBUTTON_H
#define __GBUTTON_H

#include "FGUIMacros.h"
#include "GComponent.h"

NS_FGUI_BEGIN

class FGUI_IMPEXP GButton : public GComponent
{
public:
    static const std::string UP;
    static const std::string DOWN;
    static const std::string OVER;
    static const std::string SELECTED_OVER;
    static const std::string DISABLED;
    static const std::string SELECTED_DISABLED;

    CREATE_FUNC(GButton);

    const std::string& getTitle() { return _title; }
    void setTitle(const std::string& value);

    virtual const std::string& getText() const override { return _title; }
    virtual void setText(const std::string& value) override { setTitle(value); }

    virtual const std::string& getIcon() const override { return _icon; }
    virtual void setIcon(const std::string& value) override;

    const std::string& getSelectedTitle() const { return _selectedTitle; }
    void setSelectedTitle(const std::string& value);

    const std::string& getSelectedIcon() const { return _selectedIcon; }
    void setSelectedIcon(const std::string& value);

    const VColorRef& getTitleColor() const;
    void setTitleColor(const VColorRef& value);

    float getTitleFontSize() const;
    void setTitleFontSize(float value);

    bool isSelected() const { return _selected; }
    void setSelected(bool value);

    GController* getRelatedController() const { return _relatedController; }
    void setRelatedController(GController* c);

    bool isChangeStateOnClick() { return _changeStateOnClick; }
    void setChangeStateOnClick(bool value) { _changeStateOnClick = value; }

protected:
    GButton();
    virtual ~GButton();

protected:
    virtual void constructFromXML(TXMLElement* xml) override;
    virtual void setup_AfterAdd(TXMLElement* xml) override;
    virtual void handleControllerChanged(GController* c) override;

    void setState(const std::string& value);
    void setCurrentState();

private:
    void onRollOver(EventContext* context);
    void onRollOut(EventContext* context);
    void onTouchBegin(EventContext* context);
    void onTouchEnd(EventContext* context);
    void onClick(EventContext* context);
    void onRemoveFromStage(EventContext* context);

    ButtonMode _mode;
    GObject* _titleObject;
    GObject* _iconObject;
    GController* _buttonController;
    GController* _relatedController;
    std::string _relatedPageId;
    std::string _title;
    std::string _selectedTitle;
    std::string _icon;
    std::string _selectedIcon;
    std::string _sound;
    float _soundVolumeScale;
    bool _selected;
    bool _over;
    bool _down;
    int _downEffect;
    bool _downScaled;
    float _downEffectValue;
    bool _changeStateOnClick;

private:
    CC_DISALLOW_COPY_AND_ASSIGN(GButton);
};

NS_FGUI_END

#endif
