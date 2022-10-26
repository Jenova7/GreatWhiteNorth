#ifndef GWNGUI_H
#define GWNGUI_H

#include <QDebug>
#include <QDesktopServices>
#include <QDir>
#include <QStandardPaths>
#include <QStyle>
#include <QTimer>
#include <QUrl>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class GwnGui; }
QT_END_NAMESPACE

class GwnGui : public QWidget
{
    Q_OBJECT

public:
    GwnGui(QWidget *parent = nullptr);
    ~GwnGui();

private:
    Ui::GwnGui *ui;

    bool mod_isEnabled = false;

    QString m_7d2dFolder = "";
    QString m_modFolder = "";
    QString m_tmpStr = "_TMP";
private Q_SLOTS:
    void activateMod();
};
#endif // GWNGUI_H
