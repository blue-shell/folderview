/* General options (for both fm and web modes) konqueror options
 *
 * Copyright (c) Sven Radej 1998
 * Copyright (c) David Faure 1998
 * Copyright (c) Nick Shaforostoff 2007
 *
 */

#ifndef GENERALOPTS_H
#define GENERALOPTS_H

#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>

#include <kcmodule.h>
#include <ksharedconfig.h>

class KUrlRequester;
class Ui_advancedTabOptions;

class KKonqGeneralOptions : public KCModule
{
    Q_OBJECT

public:
    KKonqGeneralOptions( QWidget *parent, const QVariantList& );
    ~KKonqGeneralOptions();
    virtual void load();
    virtual void save();
    virtual void defaults();

private Q_SLOTS:
    void slotChanged();

private:
    KSharedConfig::Ptr m_pConfig;

    KUrlRequester *homeURL;
    Ui_advancedTabOptions* tabOptions;
};

#endif // GENERALOPTS_H
