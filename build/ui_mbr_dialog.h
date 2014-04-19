/********************************************************************************
** Form generated from reading UI file 'mbr_dialog.ui'
**
** Created: Wed Jan 15 15:43:49 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MBR_DIALOG_H
#define UI_MBR_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTreeView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mbr_dialog
{
public:
    QComboBox *cmb_mbr;
    QPushButton *bt_end;
    QPushButton *bt_save;
    QTreeView *treeView;
    QLabel *label;
    QLabel *label_2;
    QRadioButton *rdbt_sda;
    QRadioButton *rdbt_sdb;
    QRadioButton *rdbt_sdc;
    QRadioButton *rdbt_sdd;

    void setupUi(QWidget *mbr_dialog)
    {
        if (mbr_dialog->objectName().isEmpty())
            mbr_dialog->setObjectName(QString::fromUtf8("mbr_dialog"));
        mbr_dialog->resize(469, 505);
        cmb_mbr = new QComboBox(mbr_dialog);
        cmb_mbr->setObjectName(QString::fromUtf8("cmb_mbr"));
        cmb_mbr->setGeometry(QRect(20, 380, 431, 22));
        bt_end = new QPushButton(mbr_dialog);
        bt_end->setObjectName(QString::fromUtf8("bt_end"));
        bt_end->setGeometry(QRect(20, 460, 201, 28));
        bt_save = new QPushButton(mbr_dialog);
        bt_save->setObjectName(QString::fromUtf8("bt_save"));
        bt_save->setGeometry(QRect(250, 460, 201, 28));
        treeView = new QTreeView(mbr_dialog);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(20, 60, 431, 301));
        treeView->header()->setDefaultSectionSize(400);
        label = new QLabel(mbr_dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 421, 18));
        label_2 = new QLabel(mbr_dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 410, 311, 41));
        rdbt_sda = new QRadioButton(mbr_dialog);
        rdbt_sda->setObjectName(QString::fromUtf8("rdbt_sda"));
        rdbt_sda->setGeometry(QRect(340, 410, 61, 23));
        rdbt_sdb = new QRadioButton(mbr_dialog);
        rdbt_sdb->setObjectName(QString::fromUtf8("rdbt_sdb"));
        rdbt_sdb->setGeometry(QRect(340, 430, 61, 23));
        rdbt_sdc = new QRadioButton(mbr_dialog);
        rdbt_sdc->setObjectName(QString::fromUtf8("rdbt_sdc"));
        rdbt_sdc->setGeometry(QRect(400, 410, 61, 23));
        rdbt_sdd = new QRadioButton(mbr_dialog);
        rdbt_sdd->setObjectName(QString::fromUtf8("rdbt_sdd"));
        rdbt_sdd->setGeometry(QRect(400, 430, 61, 23));

        retranslateUi(mbr_dialog);

        QMetaObject::connectSlotsByName(mbr_dialog);
    } // setupUi

    void retranslateUi(QWidget *mbr_dialog)
    {
	 int w,h, mw, mh, cw, ch;
        QWidget *d = QApplication::desktop();
        w=d->width();                   // returns screen width
        h=d->height();                  // returns screen height
        //qDebug() << "Bildschrimbreite";
        //qDebug() << h;
        //Center position calculation
        mw = mbr_dialog->width();
        mh = mbr_dialog->height();
        cw = (w/2) - (mw/2);
        ch = (h/2) - (mh/2); 
        mbr_dialog->setGeometry(QRect(cw, ch, 469, 505));        
	mbr_dialog->setWindowTitle(QApplication::translate("mbr_dialog", "Save / Restore MBR/GPT", 0, QApplication::UnicodeUTF8));
        cmb_mbr->clear();
        cmb_mbr->insertItems(0, QStringList()
         << QApplication::translate("mbr_dialog", "Only the boot loader area to restore", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("mbr_dialog", "Bootloader area and restore the partition table", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("mbr_dialog", "Restore partition table", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("mbr_dialog", "Secretly area to restore. (Without Boot Loader and without partition table).", 0, QApplication::UnicodeUTF8)
         << QString()
        );
        bt_end->setText(QApplication::translate("mbr_dialog", "Cancel", 0, QApplication::UnicodeUTF8));
        bt_save->setText(QApplication::translate("mbr_dialog", "Save / restore MBR", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("mbr_dialog", "Directory in which the MBR/GPT is written.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("mbr_dialog", "MBR/GPT backup directory:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("mbr_dialog", "MBR of that drive this\n"
"Backup / restore:", 0, QApplication::UnicodeUTF8));
        rdbt_sda->setText(QApplication::translate("mbr_dialog", "sda", 0, QApplication::UnicodeUTF8));
        rdbt_sdb->setText(QApplication::translate("mbr_dialog", "sdb", 0, QApplication::UnicodeUTF8));
        rdbt_sdc->setText(QApplication::translate("mbr_dialog", "sdc", 0, QApplication::UnicodeUTF8));
        rdbt_sdd->setText(QApplication::translate("mbr_dialog", "sdd", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class mbr_dialog: public Ui_mbr_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MBR_DIALOG_H
