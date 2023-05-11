#include "pose.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if (argc == 2)
    {
        const QString version = APP_VERSION;

        if ((!strncmp(argv[1], "--version", 9)))
        {
            qInfo() << QString("pose ") << version << "\n";
            std::cout << "pose " << version.toStdString() << "\n";
            return 0;
        }
    }

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages)
    {
        const QString baseName = "pose2_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName))
        {
            a.installTranslator(&translator);
            break;
        }
    }
    pose w;
    w.show();
    return a.exec();
}
