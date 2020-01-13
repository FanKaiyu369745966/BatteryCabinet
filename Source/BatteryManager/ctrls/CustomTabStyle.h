#ifndef CUSTOMTABSTYLE_H
#define CUSTOMTABSTYLE_H

#include <QPainter>
#include <QProxyStyle>
#include <QStyleOptionTab>
#include <QRect>
#include <QSize>
#include <QDebug>
class CustomTabStyle : public QProxyStyle
{
public:
    QSize sizeFromContents(ContentsType type, const QStyleOption *option, const QSize &size, const QWidget *widget) const
    {
        QSize s = QProxyStyle::sizeFromContents(type, option, size, widget);
        if (type == QStyle::CT_TabBarTab)
        {
            s.transpose();
            s.rwidth() = 200;
            s.rheight() = 100;
        }
        return s;
    }

    void drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const
    {
        if (element == CE_TabBarTabLabel)
        {
            if (const QStyleOptionTab *tab = qstyleoption_cast<const QStyleOptionTab *>(option))
            {
                QRect allRect = tab->rect;

                if (tab->state & QStyle::State_Selected)
                {
                    painter->save();
                    painter->setPen(QColor("#D13C4F"));
                    painter->setBrush(QColor("#D13C4F"));
                    painter->drawRect(allRect.adjusted(0, 0, 0, 0));
                    painter->restore();
                }

                // 文字
                QTextOption option;
                option.setAlignment(Qt::AlignCenter);
                if (tab->state & QStyle::State_Selected)
                {
                    painter->setPen(QColor("#FFFFFF"));
                }
                else
                {
                    painter->setPen(QColor("#CCCCCC"));
                }
                painter->drawText(allRect, tab->text, option);

                // 图标
                if(tab->text==QString::fromLocal8Bit("电池日志"))
                {
                    painter->drawImage(allRect.x()+13, allRect.y()+36, QImage("./res/icon/tab_log.png"));
                }
                else if(tab->text==QString::fromLocal8Bit("电池柜  "))
                {
                    painter->drawImage(allRect.x()+15, allRect.y()+36, QImage("./res/icon/tab_cabinet.png"));
                }
                else if(tab->text==QString::fromLocal8Bit("电池盒  "))
                {
                    painter->drawImage(allRect.x()+15, allRect.y()+36, QImage("./res/icon/tab_box.png"));
                }

                return;
            }
        }

        if (element == CE_TabBarTab)
        {
            QProxyStyle::drawControl(element, option, painter, widget);
        }
    }
};
#endif // CUSTOMTABSTYLE_H
