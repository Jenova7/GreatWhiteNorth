#include "gwngui.h"
#include "ui_gwngui.h"

GwnGui::GwnGui(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GwnGui)
{
    ui->setupUi(this);
    setWindowTitle("Great White North");
    setWindowIcon(QIcon(":/images/ca_round"));

    ui->icon_label->setPixmap(QPixmap(":/images/ca_flag"));
    ui->server_label->setText(tr("Servers"));
    ui->map_label->setText(tr("Live map"));

    ui->ovw_button->setText(tr("Servers"));
    connect(ui->ovw_button, &QPushButton::clicked, [=](){
        ui->content_stackedWidget->setCurrentIndex(0);
    });

    ui->settings_button->setText(tr("Settings"));
    connect(ui->settings_button, &QPushButton::clicked, [=](){
        ui->content_stackedWidget->setCurrentIndex(1);
    });

    ui->map_DF_S_button->setText(QString());
    ui->map_DF_S_button->setIconSize(QSize(50,50));
    ui->map_DF_S_button->setIcon(QIcon(":/images/map"));
    connect(ui->map_DF_S_button, &QPushButton::pressed, [=](){
        QDesktopServices::openUrl(QString("http://45.78.186.202:8092/"));
    });


    ui->map_UL_button->setText(QString());
    ui->map_UL_button->setIconSize(QSize(50,50));
    ui->map_UL_button->setIcon(QIcon(":/images/map"));
    connect(ui->map_UL_button, &QPushButton::pressed, [=](){
        QDesktopServices::openUrl(QString("http://45.78.186.202:8082/"));
    });

    ui->map_AN_button->setText(QString());
    ui->map_AN_button->setIconSize(QSize(50,50));
    ui->map_AN_button->setIcon(QIcon(":/images/map"));
    connect(ui->map_AN_button, &QPushButton::pressed, [=](){
        QDesktopServices::openUrl(QString("http://45.78.186.202:8042/"));
    });

#ifdef Q_OS_LINUX
    m_7d2dFolder = QStandardPaths::writableLocation(QStandardPaths::HomeLocation) + "/.7DaysToDie";
#else
    m_7d2dFolder = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/7DaysToDie";
#endif

    m_7d2dFolder.remove("/GreatWhiteNorth");
    m_modFolder = m_7d2dFolder + "/Mods";

    mod_isEnabled = QDir(m_modFolder).exists();

    ui->mod_label->setText(tr("Mods folder"));
    ui->data_label->setText(tr("7d2d folder"));

    ui->mod_button->setText(mod_isEnabled ? tr("ON") : tr("OFF"));
    ui->mod_button->setProperty("on", mod_isEnabled);
    style()->polish(ui->mod_button);
    connect(ui->mod_button, &QPushButton::pressed, this, &GwnGui::activateMod);

    ui->open_button->setText(tr("Open"));
    connect(ui->open_button, &QPushButton::pressed, [=](){
        QDesktopServices::openUrl(m_7d2dFolder);
    });

    ui->content_stackedWidget->setCurrentIndex(0);
}

GwnGui::~GwnGui()
{
    delete ui;
}

void GwnGui::activateMod()
{
    ui->mod_button->setEnabled(false);

    if(mod_isEnabled)
        mod_isEnabled = !QDir().rename(m_modFolder, m_modFolder + m_tmpStr);
    else
        if(QDir(m_modFolder + m_tmpStr).exists())
            mod_isEnabled = QDir().rename(m_modFolder + m_tmpStr, m_modFolder);

    ui->mod_button->setText(mod_isEnabled ? tr("ON") : tr("OFF"));
    ui->mod_button->setProperty("on", mod_isEnabled);
    style()->polish(ui->mod_button);

    QTimer::singleShot(1000, [=](){ui->mod_button->setEnabled(true);});
}

