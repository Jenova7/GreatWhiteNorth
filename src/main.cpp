#include "gwngui.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "GreatWhiteNorth_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    QFile file;
    file.setFileName(":/qss/gwn");
    file.open(QFile::ReadOnly);
    QString ss = file.readAll();
    a.setStyleSheet(ss);
    file.close();

    GwnGui w;
    w.show();
    return a.exec();
}
