/*
 * qt4-fsarchiver: Filesystem Archiver
 * 
* Copyright (C) 2008-2014 Dieter Baum.  All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License v2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 */

#include <QtGui> 
#include "setting.h"


extern int dialog_auswertung;
QStringList items_kerne;
QStringList items_zip;
QStringList items_language; 
QStringList items_network;

DialogSetting::DialogSetting(QWidget *parent)
{
        setupUi(this); // this sets up GUI
	connect( cmd_save, SIGNAL( clicked() ), this, SLOT( setting_save())); 
        connect( cmd_cancel, SIGNAL( clicked() ), this, SLOT(close()));
        //items_language << tr("German", "Deutsch") << tr("English", "Englisch") ;
        items_language << tr("German", "Deutsch") << tr("English", "Englisch") << tr("Russia", "Russisch") << tr("Español", "Spanisch");
        cmb_language->addItems (items_language);
         items_kerne << "1" << "2" << "3" << "4" <<  "5" << "6" << "7" << "8" << "9" << "10" << "11" << "12" << "13" << "14" << "15" << "16" ;
        cmb_Kerne->addItems (items_kerne);
   	items_kerne.clear();
        items_zip << tr("lzo") << tr("gzip fast") << tr("gzip standard") << tr("qzip best") <<  tr("bzip2 fast");
   	cmb_zip->addItems (items_zip);
   	items_zip.clear();
   	items_zip << tr("bzip2 good") << tr("lzma fast") << tr("lzma medium") << tr("lzma best");
   	cmb_zip->addItems (items_zip);
   	items_zip.clear();
        items_network << tr("Samba") << tr("SSH") << tr("NFS");
   	cmb_network->addItems (items_network);
   	items_network.clear();
        QSettings setting("qt4-fsarchiver", "qt4-fsarchiver");
        setting.beginGroup("Basiseinstellungen");
        int auswertung = setting.value("Sprache").toInt(); 
        cmb_language -> setCurrentIndex(auswertung-1); 
        auswertung = setting.value("Kompression").toInt();
        cmb_zip -> setCurrentIndex(auswertung); 
        auswertung = setting.value("Kerne").toInt();
        cmb_Kerne -> setCurrentIndex(auswertung-1); 
        auswertung = setting.value("Network").toInt();
        cmb_network -> setCurrentIndex(auswertung-1); 
        auswertung = setting.value("overwrite").toInt();
        //chk_ssh->setChecked(Qt::Checked);
        //chk_sshfs->setChecked(Qt::Checked);
        if (auswertung ==1)
           chk_file->setChecked(Qt::Checked); 
        auswertung = setting.value("tip").toInt();
        if (auswertung ==1)
           chk_tip->setChecked(Qt::Checked);  
        auswertung = setting.value("key").toInt();
        if (auswertung ==1)
           chk_key->setChecked(Qt::Checked); 
        auswertung = setting.value("place").toInt();
        if (auswertung ==1)
           chk_folder->setChecked(Qt::Checked); 
        auswertung = setting.value("split").toInt();
        if (auswertung ==1)
           chk_split->setChecked(Qt::Checked); 
        auswertung = setting.value("Passwort").toInt();
        if (auswertung ==1)
           chk_password->setChecked(Qt::Checked); 
        auswertung = setting.value("save").toInt();
        if (auswertung ==1)
           chk_datesave->setChecked(Qt::Checked);
        auswertung = setting.value("pbr").toInt();
        if (auswertung ==1)
           chk_pbr->setChecked(Qt::Checked);
        auswertung = setting.value("ssh").toInt();
        if (auswertung ==1)
           chk_ssh->setChecked(Qt::Checked);
        auswertung = setting.value("sshfs").toInt();
        if (auswertung ==1)
           chk_sshfs->setChecked(Qt::Checked);
        auswertung = setting.value("showPrg").toInt();
        if (auswertung ==1)
           chk_prg->setChecked(Qt::Checked);
        setting.endGroup();
}        

void DialogSetting:: setting_save()
{
     Qt::CheckState state;
     QSettings setting("qt4-fsarchiver", "qt4-fsarchiver");
     setting.beginGroup("Basiseinstellungen");
     if (cmb_Kerne->currentIndex() > -1)
     	setting.setValue("Kerne",cmb_Kerne->currentText());
     else
        setting.setValue("Kerne","1");
     setting.setValue("Sprache",cmb_language->currentIndex()+1);
     int zip = cmb_zip->currentIndex();
     setting.setValue("Kompression",zip);
     int net = cmb_network->currentIndex()+1;
     setting.setValue("Network",net);
     state = chk_file->checkState();
     if (state == Qt::Checked) 
            setting.setValue("overwrite",1);
     else
            setting.setValue("overwrite",0);
     state = chk_tip->checkState();
     if (state == Qt::Checked) 
            setting.setValue("tip",1);
     else
            setting.setValue("tip",0);
     state = chk_key->checkState();
     if (state == Qt::Checked) 
            setting.setValue("key",1);
     else
            setting.setValue("key",0);
     state = chk_folder->checkState();
     if (state == Qt::Checked) 
            setting.setValue("place",1);
     else
            setting.setValue("place",0);
     state = chk_split->checkState();
     if (state == Qt::Checked) 
            setting.setValue("split",1);
     else
            setting.setValue("split",0);
     state = chk_password->checkState();
     if (state == Qt::Checked) 
            setting.setValue("Passwort",1);
     else
            setting.setValue("Passwort",0);
     state = chk_datesave->checkState();
     if (state == Qt::Checked) 
            setting.setValue("save",1);
     else
            setting.setValue("save",0);
     state = chk_pbr->checkState();
     if (state == Qt::Checked) 
            setting.setValue("pbr",1);
     else
            setting.setValue("pbr",0);
     state = chk_ssh->checkState();
     if (state == Qt::Checked) 
            setting.setValue("ssh",1);
     else
            setting.setValue("ssh",0);
     state = chk_sshfs->checkState();
     if (state == Qt::Checked) 
            setting.setValue("sshfs",1);
     else
            setting.setValue("sshfs",0);
     state = chk_prg->checkState();
     if (state == Qt::Checked) 
            setting.setValue("showPrg",1);
     else
            setting.setValue("showPrg",0);
     setting.endGroup();
     QMessageBox::about(this,tr("Note", "Hinweis"),
         tr("The settings have been saved. Be restarted, the program modified the language setting.","Die Einstellungen wurden gespeichert. Bei geänderter Spracheinstellung muss das Programm neu gestartet werden.\n"));
}







