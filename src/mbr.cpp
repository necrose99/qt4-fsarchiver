/*
 * qt4-fsarchiver: Filesystem Archiver
 * 
* Copyright (C) 2008-2015 Dieter Baum.  All rights reserved.
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
#include "mbr.h"
#include <string.h>

extern int dialog_auswertung;

QString folder_;
QString Ubuntuversion;
int sektor_byte;
int sektor_byte_1;
QString Sektor_byte;
QString Sektor_byte_1;
qint64 size_;
int efiflag;
QString disk_name[20];
QStringList items_disk;

DialogMBR::DialogMBR(QWidget *parent)
{
QStringList filters;
	setupUi(this); // this sets up GUI
        connect( bt_end, SIGNAL( clicked() ), this, SLOT(close()));
        connect( bt_save, SIGNAL( clicked() ), this, SLOT(mbr()));
        connect( bt_dummy, SIGNAL( clicked() ), this, SLOT(disk_art()));
        dirModel = new QDirModel;
   	selModel = new QItemSelectionModel(dirModel);
   	treeView->setModel(dirModel);
   	treeView->setSelectionModel(selModel);
   	QModelIndex cwdIndex = dirModel->index(QDir::rootPath());
   	treeView->setRootIndex(cwdIndex);
   	disk_exist();
        if (dialog_auswertung == 4){
            bt_save->setText (tr("MBR/GPT save", "MBR/GPT sichern"));
            dirModel->setFilter(QDir::AllDirs  | QDir::NoDotAndDotDot);
   	    dirModel->setNameFilters(filters); 
            } 
        if (dialog_auswertung == 5){
            bt_save->setText (tr("MBR/GPT restore", "MBR/GPT zurückschreiben"));  
	    filters << "*_gpt_sd*" << "*_mbr_sd*" ;
   	    dirModel->setFilter(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot);
   	    dirModel->setNameFilters(filters);  
            }
         disk_art();
}

void DialogMBR::disk_exist()
{
//vorhandene disk ermitteln
QString befehl;
QString homepath = QDir::homePath();
int i = 0;
int j = 0;
int pos;
QString filename = homepath + "/.config/qt4-fsarchiver/disk.txt";
QFile file(filename);
QStringList disk;
QString disk_;
        befehl = "fdisk -l 1> " + homepath + "/.config/qt4-fsarchiver/disk.txt";
        i = system (befehl.toAscii().data());
        if( file.open(QIODevice::ReadOnly|QIODevice::Text)) {
            QTextStream ds(&file);
           while (!ds.atEnd()){
           	disk_ = ds.readLine();
                if (disk_.indexOf("/dev/sd") > 4)
                { 
                   disk = disk_.split(" ");
                   disk_name[j] = disk[1];
                   disk_name[j] = disk_name[j].left(disk_name[j].size() -1);
                   disk_name[j] = disk_name[j].right(disk_name[j].size() -5);
                   j++;
                }
           } 
           } 
           file.close();
           befehl = "rm " + filename;
           system (befehl.toAscii().data());
//Anzahl Festplatten ermitteln 
          j = 0;
          while (disk_name[j]!= "")
            {
            j++;
            }
//Combobox füllen
           items_disk.clear();
           for (i=0; i < j; i++) 
              items_disk <<  disk_name[i];
           cmb_disk->addItems (items_disk);      
}

void DialogMBR::disk_art()
{
    int i = cmb_disk->currentIndex();
    QString partition = disk_name[i];
    int efi = is_gpt("/dev/" + partition);
    cmb_mbr->setEnabled(false);
    if (efi == 0 &&  dialog_auswertung == 5)
	     cmb_mbr->setEnabled(true);
}

int DialogMBR::mbr()
{
QString befehl;
int i;
int efi=0;
QString partition;
QString homepath = QDir::homePath();
    //Ubuntu Version einlesen, nur wenn Systempartition
    Ubuntuversion_auslesen();
    i = cmb_disk->currentIndex();
    partition = disk_name[i];
    efi = is_gpt("/dev/" + partition);
    if (efi == 0)
        sektor_auslesen();
    else
       efiflag = 1;
    if (efi == 1 &&  (dialog_auswertung == 5))
	     cmb_mbr->setEnabled(false);
    if (efi == 0 &&  (dialog_auswertung == 5))
	     cmb_mbr->setEnabled(true);
    if (dialog_auswertung == 4)	
       {
	i = folder_einlesen();
        if (i ==0) {
                QFile file(folder_);
             this->setCursor(Qt::WaitCursor);
             if (efiflag == 0)   
                befehl = ("dd if=/dev/" + partition + " of='" + folder_ + "'/" + Ubuntuversion + "_mbr_" + partition + " bs=" + Sektor_byte + " " + "count=1");
             this->setCursor(Qt::ArrowCursor);	     
	     if (efiflag == 1)
                befehl = ("sgdisk -b '" + folder_ + "'/" + Ubuntuversion + "_gpt_" + partition + " /dev/" + partition);
                i = system (befehl.toAscii().data());
             this->setCursor(Qt::ArrowCursor);
   		if (i == 0 && efiflag == 0)
      			QMessageBox::about(this,tr("Note", "Hinweis"), tr("MBR was successfully backed up.\n", "MBR wurde erfolgreich gesichert.\n"));
        	if (i != 0 && efiflag == 0)
      			QMessageBox::about(this, tr("Note", "Hinweis"), tr("MBR has not been backeed.\n", "MBR wurde nicht gesichert.\n"));
                if (i == 0 && efiflag == 1)
      			QMessageBox::about(this,tr("Note", "Hinweis"), tr("GPT was successfully backed up.\n", "GPT wurde erfolgreich gesichert.\n"));
        	if (i != 0 && efiflag == 1)
      			QMessageBox::about(this, tr("Note", "Hinweis"), tr("GPT has not been backeed.\n", "GPT wurde nicht gesichert.\n"));
      		
                }
       }

 if (dialog_auswertung == 5 && efiflag == 1)
	{
	   i = folder_einlesen();
           if (i ==1)
	       return 0; 
	   int auswertung = questionMessage(tr("Caution: If you really want to to write back the GUID partition table?\n", "Vorsicht: Wollen Sie wirklich die GUID Partitionstabelle zurückschreiben?\n")); 
            if  (auswertung == 2) 
                return 1;
         if (i ==0) {
             this->setCursor(Qt::WaitCursor);	
	      if (cmb_mbr->currentIndex() == 0) {
              befehl = ("sgdisk -l '" + folder_ + "' /dev/" + partition);
              i = system (befehl.toAscii().data());
              this->setCursor(Qt::ArrowCursor); 
   	      if (i == 0)
      		QMessageBox::about(this, tr("Note", "Hinweis"), tr("The GUID partition table is successful return.\n", "Die GUID Partitionstabelle wurde erfolgreich wieder hergestellt.\n"));
              else
      		QMessageBox::about(this, tr("Note", "Hinweis"), tr("The GUID partition table was not restored.\n", "Die GUID Partitionstabelle wurde nicht wieder hergestellt.\n"));
              }
 	      }
	}

     if (dialog_auswertung == 5 && cmb_mbr->currentIndex() != 3 && efiflag == 0)	
       {
        i = folder_einlesen();
        if (i ==1)
	   return 0;
 	if (efiflag == 0)
	{
          int auswertung = questionMessage(tr("Caution: If you really want to to write back the MBR completely or partially?\n", "Vorsicht: Wollen Sie wirklich den MBR komplett beziehungsweise teilweise zurückschreiben?\n")); 
            if  (auswertung == 2) 
                return 1; 
           if (i ==0) {
        	this->setCursor(Qt::WaitCursor);
	   if (cmb_mbr->currentIndex() == 0) {
              befehl = ("dd if='"+ folder_ + "' of=/dev/" + partition + " bs=1 count=446");
              i = system (befehl.toAscii().data());
              this->setCursor(Qt::ArrowCursor);  
   	      if (i == 0)
      		QMessageBox::about(this, tr("Note", "Hinweis"), tr("The Boot Loader section is successful return.\n", "Der Bootloaderbereich wurde erfolgreich wieder hergestellt.\n"));
              else
      		QMessageBox::about(this, tr("Note", "Hinweis"), tr("The boot loader area was not restored.\n", "Der Bootloaderbereich wurde nicht wieder hergestellt.\n"));
              }
              if (cmb_mbr->currentIndex() == 2) {
		   //Partitionstabelle extrahieren                   
                   befehl = ("dd if='"+ folder_ + "' of=" + homepath + "/.mbr.txt  bs=1 skip=446 count=66");
                   i = system (befehl.toAscii().data());
                   //Partitionstabelle wiederherstellen 
                   befehl = ("dd if=" + homepath + "/.mbr.txt of=/dev/" + partition + " bs=1 seek=446 count=66");
                   i = i + system (befehl.toAscii().data());  	
                   //Datei löschen
                   befehl = "rm " + homepath + "/.mbr.txt";
                   system (befehl.toAscii().data());
                   this->setCursor(Qt::ArrowCursor);    
   	           if (i == 0)
      			QMessageBox::about(this, tr("Note", "Hinweis"), tr("The partition table is successful return.", "Die Partitionstabelle wurde erfolgreich wieder hergestellt.\n"));
                   else
      			QMessageBox::about(this, tr("Note", "Hinweis"), tr("The partition table was not restored.\n", "Die Partitionstabelle wurde nicht wieder hergestellt.\n"));
               }
               if (cmb_mbr->currentIndex() == 1) {
                 // MBR und Pasrtitionstabelle wieder herstellen
                 befehl = ("dd if='"+ folder_ + "' of=/dev/" + partition + " bs=1 count=512");
                 i = system (befehl.toAscii().data());
               this->setCursor(Qt::ArrowCursor); 
   	       if (i == 0) 
      		   QMessageBox::about(this, tr("Note","Hinweis"), tr("The MBR is successful return.\n", "Der MBR wurde erfolgreich wieder hergestellt.\n"));
                else
      		  QMessageBox::about(this, tr("Note", "Hinweis"), tr("The MBR is not restored.\n", "Der MBR wurde nicht wieder hergestellt.\n"));
               }
                 
          }
       }
    }
    if (dialog_auswertung == 5 && cmb_mbr->currentIndex() == 3)	
       {
        i = folder_einlesen();
        if (i ==1)
	   return 0;
        int auswertung = questionMessage(tr("Caution: If you really want to to write back the secret field?\n", "Vorsicht: Wollen Sie wirklich den verborgenen Bereich zurückschreiben? \n")); 
            if  (auswertung == 2) 
                return 1; 
            //i = folder_einlesen();
            this->setCursor(Qt::WaitCursor);
            if (i ==0) {
		   //verborgenen Bereich extrahieren                   
                   befehl = ("dd if='"+ folder_ + "' of=" + homepath + "/.mbr.txt  bs=1 skip=512 count=" + Sektor_byte_1);
                   i = system (befehl.toAscii().data());
                   //verborgenen Bereich wiederherstellen 	
                   befehl = ("dd if=" + homepath + "/.mbr.txt of=/dev/" + partition + " bs=1 seek=512 count=" + Sektor_byte_1);
                   i = i + system (befehl.toAscii().data());  	
                   //Datei löschen
                   befehl = "rm " + homepath + "/.mbr.txt";
                   i = system (befehl.toAscii().data());
                   this->setCursor(Qt::ArrowCursor);       
      	        if (i == 0) 
      		   QMessageBox::about(this, tr("Note", "Hinweis"), tr("The hidden area is successful return.\n", "Der verborgene Bereich wurde erfolgreich wieder hergestellt.\n"));
                else
      		  QMessageBox::about(this, tr("Note", "Hinweis"), tr("The hidden area was not restored.\n", "Der verborgene Bereich wurde nicht wieder hergestellt.\n"));
        }
    }
    return 0;
}

void DialogMBR::sektor_auslesen() {
QString Dateiname;
QString befehl;
QString text;
QString partition;
QString homepath = QDir::homePath();
int sektor_ = 0;
int efi= 0;
int i = 0;
int j = 0;
QString dummy[10];
QStringList hidden_size;
QString hidden_size_;
        efiflag = 0;
        i = cmb_disk->currentIndex();
        partition = disk_name[i];
        efi = is_gpt("/dev/" + partition);
        if (efi == 1)
	   efiflag = 1; 
        // fdisk -lu , mit diesem Befehl Startsektor von sda1 ermitteln.
        // derzeit für Ubuntu:  Startsektor sda1 = 63*512 = 32256 
	// Sektornummer in Datei abspeichern
        Dateiname = homepath + "/.config/qt4-fsarchiver/sektornummer.txt";
        befehl = "fdisk -lu | grep " + partition + "1 > " + homepath + "/.config/qt4-fsarchiver/sektornummer.txt";
        i = system (befehl.toAscii().data());
        QFile file(Dateiname);
        //Datei auslesen
        if( file.open(QIODevice::ReadOnly|QIODevice::Text)) {
            QTextStream ds(&file);
            hidden_size_ = ds.readLine();
            hidden_size =  hidden_size_.split(" ");
            file.close();
            for (i=0; i < 100; i++){
                if (hidden_size[i] != "") 
                   {
                   dummy[j] = hidden_size[i];
                   j = j + 1; 
                   }
                if (j == 3)
                   break;
            }
            if (dummy[1] == "*")  //Festplatte hat Bootsektor
               sektor_ = dummy[2].toInt();
            else 
               sektor_ = dummy[1].toInt(); //Festplatte hat keinen Bootsektor
            }
       //Datei löschen
       befehl = "rm "  + homepath + "/.config/qt4-fsarchiver/sektornummer.txt";;
       system (befehl.toAscii().data()); 
       if (sektor_ < 2 && efiflag == 0) {
	    QMessageBox::about(this, tr("Note", "Hinweis"), tr("The end of hidden area of the 1st Partition could not be read. Only 512 bytes are saved.", "Das Ende des verborgenen Bereiches der 1. Partition konnte nicht ausgelesen werden. Es werden nur 512 Bytes gesichert.\n"));
            sektor_ = 2;
	}
        sektor_byte = sektor_  * 512;
        Sektor_byte =  QString::number(sektor_byte);
        sektor_byte_1 = (sektor_ -1) * 512 ;
        Sektor_byte_1=  QString::number(sektor_byte_1);  
}

void DialogMBR::Ubuntuversion_auslesen() {
QString Dateiname;
QString partition;
QString befehl;
QStringList Ubuntu_;
string part_art;
int i = 0;
        i = cmb_disk->currentIndex();
        partition = disk_name[i];
        partition = "/dev/"+ partition;
        //Prüfen ob System Partition
        if (mtab_einlesen(partition.toAscii().data()) == "system") {
             	Dateiname = "/etc/issue";     
        	QFile file(Dateiname);
        	//Datei auslesen
        	if( file.open(QIODevice::ReadOnly|QIODevice::Text)) {
            		QTextStream ds(&file);
            		Ubuntuversion = ds.readLine();
            		Ubuntu_ = Ubuntuversion.split(" ");
            		Ubuntuversion = Ubuntu_[1];
            		file.close();
                }
         }
         else
		Ubuntuversion = "";
   
}

int DialogMBR::folder_einlesen() {
   QString partition;
   QString Festplatte;
   int ret = 1; 
   int pos;
   int pos1;
   int pos2;
   int i = 0;
   QModelIndex index = treeView->currentIndex();
   QModelIndexList indexes = selModel->selectedIndexes();
   folder_.append  (dirModel->filePath(index));
   folder_ =  (dirModel->filePath(index));
   if (dialog_auswertung == 5)
	Festplatte = folder_.right(3);
   QFileInfo info(folder_); 
   size_ = info.size(); 
    pos = folder_.indexOf("mbr_sd");
    pos2 = folder_.indexOf("gpt_sd");
   if (folder_ == "" && (dialog_auswertung == 4))
      {
       QMessageBox::about(this, tr("Note", "Hinweis"),
      tr("You must select a directory", "Sie müssen ein Verzeichnis auswählen\n"));
      return 1 ;
      }
   if (info.isFile() && (dialog_auswertung == 4))
      {
      QMessageBox::about(this, tr("Note", "Hinweis"),
      tr("You have selected a file. You must select a directory.\n", "Sie haben eine Datei ausgewählt. Sie müssen ein Verzeichnis auswählen\n"));
      return 1 ;
      }
    if (folder_ == "" && (dialog_auswertung == 5))
      {
       QMessageBox::about(this, tr("Note", "Hinweis"),
      tr("You must choose the MBR/GPT file\n","Sie müssen die MBR/GPT Sicherungsdatei auswählen.\n"));
      return 1 ;
      }
    if (info.isDir() && (dialog_auswertung == 5))
      {
      QMessageBox::about(this, tr("Note", "Hinweis"),
      tr("You have selected a directory. You must select the MBR/GPT backup file\n", "Sie haben ein Verzeichnis ausgewählt. Sie müssen die MBR/GPT Sicherungsdatei auswählen\n"));
      return 1 ;
       }
    if (efiflag == 0 && (pos == -1) && (dialog_auswertung == 5))
      {
       QMessageBox::about(this, tr("Note", "Hinweis"),
      tr("You must choose the MBR file\n","Sie müssen eine MBR Sicherungsdatei auswählen.\n"));
      return 1 ;
      } 
    if (efiflag == 1 && (pos2 == -1) && (dialog_auswertung == 5))
      {
       QMessageBox::about(this, tr("Note", "Hinweis"),
      tr("You must choose the GPT file\n","Sie müssen eine GPT Sicherungsdatei auswählen.\n"));
      return 1 ;
      } 
    i = cmb_disk->currentIndex();
    partition = disk_name[i];
    if (dialog_auswertung == 5 )
       pos1 = folder_.indexOf("_" + partition);
    if (pos1 == -1  && dialog_auswertung == 5){
      //Partitionen stimmen nicht überein
      QString text = tr("You may have the wrong disk is selected. The restore disk is ", "Sie haben eventuell eine falsche Festplatte ausgewählt. Die wiederherzustellende Festplatte ist ") + partition + tr(", the saved hard drive is ", ",  die gesicherte Festplatte ist aber ") +  Festplatte + tr(" Are you sure?", " Wollen Sie fortfahren?");
        ret = questionMessage(text);
        if (ret == 2)
            return 1;
        }
    QString sA = QString::number(size_);
    if (efiflag == 0)
    {
    QString text = tr("You may have a wrong file selected. Restore the hidden field has a size of ", "Sie haben eventuell eine falsche Datei ausgewählt. Der wiederherzustellende verborgene Bereich hat eine Größe von") +  sA + 
    tr(" bytes. The hidden area of the disk ", " Byte. Der verborgene Bereich von der Festplatte ") + partition + tr(" has a size of ", " hat eine Größe von ") + Sektor_byte + tr(" bytes. Are you sure?", " Byte. Wollen Sie fortfahren?");
    if (size_ != sektor_byte && dialog_auswertung == 5 && cmb_mbr->currentIndex() == 3) {
        ret = questionMessage(text);
        if (ret == 2)
            return 1;
        if (ret == 1)
           return 0;
       }
    }
    return 0;
}

int DialogMBR::questionMessage(QString frage)
{
	QMessageBox msg(QMessageBox::Question, tr("Note", "Hinweis"), frage);
	QPushButton* yesButton = msg.addButton(tr("Yes", "Ja"), QMessageBox::YesRole);
	QPushButton* noButton = msg.addButton(tr("No", "Nein"), QMessageBox::NoRole);
	msg.exec();
	if (msg.clickedButton() == yesButton)
    		return 1;
	else if (msg.clickedButton() == noButton)
    		return 2;
}

string DialogMBR::mtab_einlesen(string partition_if_home)
{
   QString text;
   QFile file("/etc/mtab");
   QTextStream ds(&file);
   string text_str;
   int pos;
   if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
     text = ds.readLine();
     text_str = text.toAscii().data();
     pos = text_str.find(partition_if_home); 
     if (pos > -1)  // Partitionsname gefunden
        return "system";
     file.close();
     }
  return  " ";
}

int DialogMBR::is_gpt(QString partition_efi)
{
      QString homepath = QDir::homePath();
      QString text;
      QString befehl = "gdisk -l " + partition_efi +  " 1> " +  homepath + "/.config/qt4-fsarchiver/efi.txt";
      //QString befehl = "sgdisk -p " + partition_efi +  " 1> " +  homepath + "/.config/qt4-fsarchiver/efi.txt";
      system (befehl.toAscii().data());
      QString filename = homepath + "/.config/qt4-fsarchiver/efi.txt";
      QFile file(filename);
      int pos, pos1,i,j;
      int line = 0;
      if( file.open(QIODevice::ReadOnly|QIODevice::Text)) { 
	QTextStream ds(&file);
        while (!ds.atEnd()){
           	text = ds.readLine();
		if (text.indexOf("GPT: present") > -1) 
                   return 1;
               // if( text.isEmpty() )
         	// break;
           }
 } 

   	file.close();
  return 0;
}






