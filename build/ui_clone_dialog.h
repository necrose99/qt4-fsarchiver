/********************************************************************************
** Form generated from reading UI file 'clone_dialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLONE_DIALOG_H
#define UI_CLONE_DIALOG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTreeView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clone_dialog
{
public:
    QTreeView *treeView_clone;
    QLabel *lbl_hd;
    QListWidget *listWidget_exist;
    QListWidget *listWidget_clone;
    QLabel *label_3;
    QCommandLinkButton *commandLinkButton;
    QCommandLinkButton *commandLinkButton_2;
    QFrame *frame_2;
    QLabel *label_8;
    QLineEdit *SekundeElapsed;
    QLabel *label_7;
    QLineEdit *MinuteElapsed;
    QLabel *label_5;
    QLabel *label_10;
    QLineEdit *SekundeRemaining;
    QLabel *label_9;
    QLineEdit *MinuteRemaining;
    QLabel *label_6;
    QProgressBar *progressBar;
    QPushButton *pushButton_break;
    QLineEdit *savedBytes;
    QLabel *lbl_save;
    QLabel *lbl_hd_size;
    QLabel *label_11;
    QLineEdit *HourElapsed;
    QLabel *label_12;
    QLineEdit *HourRemaining;
    QLabel *label;
    QLineEdit *bytes_sec;
    QLabel *label_2;
    QPushButton *pushButton_folder;
    QLabel *label_folder;
    QFrame *frame;
    QRadioButton *rdbt_image_restore;
    QRadioButton *rdbt_clone;
    QGroupBox *groupBox;
    QRadioButton *rdbt_image_save;
    QRadioButton *rdbt_partition_save;
    QRadioButton *rdbt_partition_restore;
    QCheckBox *chk_zip;
    QPushButton *pushButton_partition;
    QPushButton *bt_save;
    QPushButton *bt_end;
    QCommandLinkButton *commandLinkButton_3;
    QCommandLinkButton *commandLinkButton_4;
    QCommandLinkButton *commandLinkButton_5;
    QListWidget *listWidget;

    void setupUi(QWidget *clone_dialog)
    {
        if (clone_dialog->objectName().isEmpty())
            clone_dialog->setObjectName(QString::fromUtf8("clone_dialog"));
        clone_dialog->resize(752, 607);
        treeView_clone = new QTreeView(clone_dialog);
        treeView_clone->setObjectName(QString::fromUtf8("treeView_clone"));
        treeView_clone->setGeometry(QRect(410, 170, 321, 231));
        treeView_clone->header()->setDefaultSectionSize(400);
        lbl_hd = new QLabel(clone_dialog);
        lbl_hd->setObjectName(QString::fromUtf8("lbl_hd"));
        lbl_hd->setGeometry(QRect(20, 150, 351, 18));
        listWidget_exist = new QListWidget(clone_dialog);
        listWidget_exist->setObjectName(QString::fromUtf8("listWidget_exist"));
        listWidget_exist->setGeometry(QRect(20, 170, 168, 231));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        font.setBold(true);
        font.setWeight(75);
        listWidget_exist->setFont(font);
        listWidget_clone = new QListWidget(clone_dialog);
        listWidget_clone->setObjectName(QString::fromUtf8("listWidget_clone"));
        listWidget_clone->setGeometry(QRect(220, 170, 168, 231));
        listWidget_clone->setFont(font);
        label_3 = new QLabel(clone_dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 150, 171, 18));
        commandLinkButton = new QCommandLinkButton(clone_dialog);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(190, 210, 31, 41));
        commandLinkButton_2 = new QCommandLinkButton(clone_dialog);
        commandLinkButton_2->setObjectName(QString::fromUtf8("commandLinkButton_2"));
        commandLinkButton_2->setGeometry(QRect(190, 170, 31, 41));
        frame_2 = new QFrame(clone_dialog);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(20, 420, 491, 161));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(410, 10, 71, 34));
        SekundeElapsed = new QLineEdit(frame_2);
        SekundeElapsed->setObjectName(QString::fromUtf8("SekundeElapsed"));
        SekundeElapsed->setGeometry(QRect(370, 10, 30, 27));
        SekundeElapsed->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(295, 10, 61, 30));
        MinuteElapsed = new QLineEdit(frame_2);
        MinuteElapsed->setObjectName(QString::fromUtf8("MinuteElapsed"));
        MinuteElapsed->setGeometry(QRect(260, 10, 30, 27));
        MinuteElapsed->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 10, 135, 34));
        label_10 = new QLabel(frame_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(410, 35, 71, 34));
        SekundeRemaining = new QLineEdit(frame_2);
        SekundeRemaining->setObjectName(QString::fromUtf8("SekundeRemaining"));
        SekundeRemaining->setGeometry(QRect(370, 40, 30, 27));
        SekundeRemaining->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(295, 37, 61, 30));
        MinuteRemaining = new QLineEdit(frame_2);
        MinuteRemaining->setObjectName(QString::fromUtf8("MinuteRemaining"));
        MinuteRemaining->setGeometry(QRect(260, 40, 30, 27));
        MinuteRemaining->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 40, 135, 31));
        label_6->setWordWrap(true);
        progressBar = new QProgressBar(frame_2);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(10, 125, 411, 25));
        progressBar->setMaximum(100);
        progressBar->setValue(0);
        pushButton_break = new QPushButton(frame_2);
        pushButton_break->setObjectName(QString::fromUtf8("pushButton_break"));
        pushButton_break->setGeometry(QRect(430, 120, 24, 21));
        pushButton_break->setMinimumSize(QSize(24, 21));
        pushButton_break->setMaximumSize(QSize(24, 21));
        pushButton_break->setSizeIncrement(QSize(24, 21));
        pushButton_break->setBaseSize(QSize(21, 21));
        pushButton_break->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/src/images/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_break->setIcon(icon);
        pushButton_break->setAutoDefault(false);
        pushButton_break->setDefault(false);
        pushButton_break->setFlat(false);
        savedBytes = new QLineEdit(frame_2);
        savedBytes->setObjectName(QString::fromUtf8("savedBytes"));
        savedBytes->setGeometry(QRect(385, 85, 61, 27));
        savedBytes->setAlignment(Qt::AlignCenter);
        lbl_save = new QLabel(frame_2);
        lbl_save->setObjectName(QString::fromUtf8("lbl_save"));
        lbl_save->setGeometry(QRect(270, 80, 111, 41));
        lbl_save->setWordWrap(true);
        lbl_hd_size = new QLabel(frame_2);
        lbl_hd_size->setObjectName(QString::fromUtf8("lbl_hd_size"));
        lbl_hd_size->setGeometry(QRect(450, 90, 31, 17));
        label_11 = new QLabel(frame_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(183, 15, 75, 20));
        HourElapsed = new QLineEdit(frame_2);
        HourElapsed->setObjectName(QString::fromUtf8("HourElapsed"));
        HourElapsed->setGeometry(QRect(150, 10, 30, 27));
        HourElapsed->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(frame_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(183, 45, 75, 20));
        HourRemaining = new QLineEdit(frame_2);
        HourRemaining->setObjectName(QString::fromUtf8("HourRemaining"));
        HourRemaining->setGeometry(QRect(150, 40, 30, 27));
        HourRemaining->setAlignment(Qt::AlignCenter);
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 80, 131, 41));
        label->setWordWrap(true);
        bytes_sec = new QLineEdit(frame_2);
        bytes_sec->setObjectName(QString::fromUtf8("bytes_sec"));
        bytes_sec->setGeometry(QRect(150, 85, 51, 27));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(205, 90, 51, 17));
        pushButton_folder = new QPushButton(clone_dialog);
        pushButton_folder->setObjectName(QString::fromUtf8("pushButton_folder"));
        pushButton_folder->setGeometry(QRect(550, 540, 16, 21));
        label_folder = new QLabel(clone_dialog);
        label_folder->setObjectName(QString::fromUtf8("label_folder"));
        label_folder->setGeometry(QRect(410, 150, 171, 18));
        label_folder->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        frame = new QFrame(clone_dialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 10, 711, 131));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        rdbt_image_restore = new QRadioButton(frame);
        rdbt_image_restore->setObjectName(QString::fromUtf8("rdbt_image_restore"));
        rdbt_image_restore->setGeometry(QRect(410, 30, 301, 25));
        rdbt_clone = new QRadioButton(frame);
        rdbt_clone->setObjectName(QString::fromUtf8("rdbt_clone"));
        rdbt_clone->setGeometry(QRect(410, 90, 161, 25));
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 0, 221, 31));
        groupBox->setSizeIncrement(QSize(10, 10));
        groupBox->setFlat(true);
        groupBox->setCheckable(false);
        rdbt_image_save = new QRadioButton(frame);
        rdbt_image_save->setObjectName(QString::fromUtf8("rdbt_image_save"));
        rdbt_image_save->setGeometry(QRect(20, 30, 251, 25));
        rdbt_partition_save = new QRadioButton(frame);
        rdbt_partition_save->setObjectName(QString::fromUtf8("rdbt_partition_save"));
        rdbt_partition_save->setGeometry(QRect(20, 60, 301, 25));
        rdbt_partition_restore = new QRadioButton(frame);
        rdbt_partition_restore->setObjectName(QString::fromUtf8("rdbt_partition_restore"));
        rdbt_partition_restore->setGeometry(QRect(410, 60, 301, 25));
        chk_zip = new QCheckBox(frame);
        chk_zip->setObjectName(QString::fromUtf8("chk_zip"));
        chk_zip->setGeometry(QRect(20, 90, 391, 25));
        pushButton_partition = new QPushButton(clone_dialog);
        pushButton_partition->setObjectName(QString::fromUtf8("pushButton_partition"));
        pushButton_partition->setGeometry(QRect(520, 430, 31, 27));
        bt_save = new QPushButton(clone_dialog);
        bt_save->setObjectName(QString::fromUtf8("bt_save"));
        bt_save->setGeometry(QRect(520, 420, 211, 71));
        bt_end = new QPushButton(clone_dialog);
        bt_end->setObjectName(QString::fromUtf8("bt_end"));
        bt_end->setGeometry(QRect(520, 510, 211, 71));
        commandLinkButton_3 = new QCommandLinkButton(clone_dialog);
        commandLinkButton_3->setObjectName(QString::fromUtf8("commandLinkButton_3"));
        commandLinkButton_3->setGeometry(QRect(190, 250, 31, 41));
        commandLinkButton_4 = new QCommandLinkButton(clone_dialog);
        commandLinkButton_4->setObjectName(QString::fromUtf8("commandLinkButton_4"));
        commandLinkButton_4->setGeometry(QRect(190, 290, 31, 41));
        commandLinkButton_5 = new QCommandLinkButton(clone_dialog);
        commandLinkButton_5->setObjectName(QString::fromUtf8("commandLinkButton_5"));
        commandLinkButton_5->setGeometry(QRect(190, 330, 31, 41));
        listWidget = new QListWidget(clone_dialog);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 170, 371, 231));
        pushButton_folder->raise();
        treeView_clone->raise();
        lbl_hd->raise();
        listWidget_exist->raise();
        listWidget_clone->raise();
        label_3->raise();
        commandLinkButton->raise();
        commandLinkButton_2->raise();
        frame_2->raise();
        label_folder->raise();
        frame->raise();
        pushButton_partition->raise();
        bt_save->raise();
        bt_end->raise();
        commandLinkButton_3->raise();
        commandLinkButton_4->raise();
        commandLinkButton_5->raise();
        listWidget->raise();

        retranslateUi(clone_dialog);
        QObject::connect(treeView_clone, SIGNAL(clicked(QModelIndex)), pushButton_folder, SLOT(click()));
        QObject::connect(listWidget, SIGNAL(clicked(QModelIndex)), pushButton_partition, SLOT(click()));

        QMetaObject::connectSlotsByName(clone_dialog);
    } // setupUi

    void retranslateUi(QWidget *clone_dialog)
    {
        clone_dialog->setWindowTitle(QApplication::translate("clone_dialog", "Clone hard drive", 0, QApplication::UnicodeUTF8));
        lbl_hd->setText(QApplication::translate("clone_dialog", "Exist harddrive:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("clone_dialog", "New harddrive:", 0, QApplication::UnicodeUTF8));
        commandLinkButton->setText(QApplication::translate("clone_dialog", "CommandLinkButton", 0, QApplication::UnicodeUTF8));
        commandLinkButton_2->setText(QApplication::translate("clone_dialog", "CommandLinkButton", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("clone_dialog", "seconds", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("clone_dialog", "minutes", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("clone_dialog", "elapsed time:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("clone_dialog", "seconds", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("clone_dialog", "minutes", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("clone_dialog", "remaining time:", 0, QApplication::UnicodeUTF8));
        pushButton_break->setText(QString());
        pushButton_break->setShortcut(QString());
        lbl_save->setText(QApplication::translate("clone_dialog", "already saved:", 0, QApplication::UnicodeUTF8));
        lbl_hd_size->setText(QApplication::translate("clone_dialog", "MB", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("clone_dialog", "hours", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("clone_dialog", "hours", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("clone_dialog", "Transmission speed:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("clone_dialog", "MB/sec", 0, QApplication::UnicodeUTF8));
        pushButton_folder->setText(QApplication::translate("clone_dialog", "f", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_folder->setToolTip(QApplication::translate("clone_dialog", "Directory in which the image is written", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_folder->setText(QApplication::translate("clone_dialog", "Backup directory:", 0, QApplication::UnicodeUTF8));
        rdbt_image_restore->setText(QApplication::translate("clone_dialog", "Image of a hard disk write back", 0, QApplication::UnicodeUTF8));
        rdbt_clone->setText(QApplication::translate("clone_dialog", "Clone hard disk", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("clone_dialog", "Proposed action:", 0, QApplication::UnicodeUTF8));
        rdbt_image_save->setText(QApplication::translate("clone_dialog", "Image of a hard disk to create", 0, QApplication::UnicodeUTF8));
        rdbt_partition_save->setText(QApplication::translate("clone_dialog", "Image of a partition to create", 0, QApplication::UnicodeUTF8));
        rdbt_partition_restore->setText(QApplication::translate("clone_dialog", "Image of a partition write back", 0, QApplication::UnicodeUTF8));
        chk_zip->setText(QApplication::translate("clone_dialog", "Use gzip", 0, QApplication::UnicodeUTF8));
        pushButton_partition->setText(QApplication::translate("clone_dialog", "p", 0, QApplication::UnicodeUTF8));
        bt_save->setText(QApplication::translate("clone_dialog", "Save/Restore", 0, QApplication::UnicodeUTF8));
        bt_end->setText(QApplication::translate("clone_dialog", "Exit", 0, QApplication::UnicodeUTF8));
        commandLinkButton_3->setText(QApplication::translate("clone_dialog", "CommandLinkButton", 0, QApplication::UnicodeUTF8));
        commandLinkButton_4->setText(QApplication::translate("clone_dialog", "CommandLinkButton", 0, QApplication::UnicodeUTF8));
        commandLinkButton_5->setText(QApplication::translate("clone_dialog", "CommandLinkButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class clone_dialog: public Ui_clone_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLONE_DIALOG_H
