#pragma once

#include "GeneralCreator.h"
#include "../../corelib/enumerations.h"

namespace Utils
{
    struct ProxySettings;
}

namespace Ui
{
    class LineEditEx;
    class GeneralDialog;

    class ConnectionSettingsWidget : public QWidget
    {
        Q_OBJECT
        
    public Q_SLOTS:


    public: 
        ConnectionSettingsWidget(QWidget* _parent);
        void show();
    private:
        LineEditEx*                     passwordEdit_;
        LineEditEx*                     usernameEdit_;
        LineEditEx*                     addressEdit_;
        LineEditEx*                     portEdit_;
        QCheckBox*                      showPasswordCheckbox_;
        GeneralCreator::DropperInfo     dropper_;
        QWidget*                        mainWidget_;
        GeneralDialog*                  generalDialog_;
        std::vector<core::proxy_types>  activeProxyTypes_;
        int                             selectedProxyIndex_;
        std::vector<QString>            typesNames_;
        QSpacerItem*                    horizontalSpacer_;

        void saveProxy() const;
        void fill();
        int proxyTypeToIndex(core::proxy_types type) const;
        void fillProxyTypesAndNames();
        void setVisibleAuth(bool _use_auth);
        void setVisibleParams(int _ix, bool _use_auth);
        void updateVisibleParams(int _ix);
    };
}
