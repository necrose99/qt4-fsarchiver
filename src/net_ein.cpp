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
#include "net_ein.h"
#include "net.h"
#include "clone_net.h"
#include "mainWindow.h"
#include <iostream>

QString widget_net[100]; // Netzwerk
QString comNet;
QString comNet_name;
QString user;
//QString key= "";
QString dummykey;

NetEin::NetEin(QWidget *parent)
{
QString homepath = QDir::homePath(); 
int i = 0;
setupUi(this);
connect( pushButton_net, SIGNAL( clicked() ), this, SLOT(listWidget_show()));
connect( pushButton_go, SIGNAL( clicked() ), this, SLOT(go()));
connect( pushButton_end, SIGNAL( clicked() ), this, SLOT(end()));
connect( chk_password, SIGNAL( clicked() ), this, SLOT(Kennwort()));
// Ini-Datei auslesen
   QFile file(homepath + "/.config/qt4-fsarchiver/qt4-fsarchiver.conf");
   if (file.exists()) {
        QSettings setting("qt4-fsarchiver", "qt4-fsarchiver");
        setting.beginGroup("Basiseinstellungen");
        int auswertung = setting.value("Passwort").toInt();
        if (auswertung ==1){
           	txt_key ->setEchoMode(QLineEdit::Normal);
                chk_password->setChecked(Qt::Checked);
        } 
   	else
		txt_key ->setEchoMode(QLineEdit::Password);
        auswertung = setting.value("save").toInt();
        if (auswertung ==1)
           chk_datesave->setChecked(Qt::Checked);      
        setting.endGroup();
   }
    while (widget_net[i] != ""){
    	listWidget_net->addItem (widget_net[i]);
        i++;
        if (i > 99)
            break;   
        }
}

void NetEin::Kennwort()
{
Qt::CheckState state;
state = chk_password->checkState(); 
	if (state != Qt::Checked) {
		txt_key ->setEchoMode(QLineEdit::Password);
        } 
   	else
		txt_key ->setEchoMode(QLineEdit::Normal);
}

int NetEin:: list_net_ssh(QString flag)
{
QString befehl;
QString homepath = QDir::homePath(); 
QString hostname_;
QStringList adresse_;
QString adresse; 
QString adresse_router;
QString adresse_eigen;
QString adresse_eigen_;
int k = 0;
int i = 0;
        // Routeradresse ermitteln
        befehl = "route -n 1> " +  homepath + "/.config/qt4-fsarchiver/smbtree.txt";
        system (befehl.toAscii().data());
        QFile file(homepath + "/.config/qt4-fsarchiver/smbtree.txt");
        QTextStream ds1(&file);
        if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
     	     	adresse = ds1.readLine();
             	adresse = ds1.readLine();
             	adresse = ds1.readLine();
		do{
    			k=adresse.indexOf("  ");
			if (k > 0)
             	    	   adresse.replace("  ", " ");
	          }
			while  (k >= 0);
	     adresse_ = adresse.split(" ");
             adresse_router = adresse_[1];
	}
        file.close();
        hostname_ = hostname();
        adresse_eigen = IP("localhost");
        i = adresse_eigen.indexOf("name_query");
        if (i > -1)
           adresse_eigen = IP(hostname_);
        adresse_ = adresse_eigen.split(" ");
        adresse_eigen = adresse_[0];
        adresse_eigen_ = adresse_[0];
        k = adresse_eigen.size();
        i = adresse_eigen.indexOf(".",k-2);
        if (i != -1)
            adresse_eigen = adresse_eigen.left(i);
        else {

        i = adresse_eigen.indexOf(".",k-3);
        if (i != -1)
            adresse_eigen = adresse_eigen.left(i); 
        i = adresse_eigen.indexOf(".",k-4);
        if (i != -1)
            adresse_eigen = adresse_eigen.left(i);
       }
        //Zahl zwischen 3. und 4. Punkt ermitteln
        //route -n ermittelt die Routeradresse
        befehl = "nmap -sP " + adresse_eigen + ".0/24 1> " +  homepath + "/.config/qt4-fsarchiver/smbtree.txt";
        system (befehl.toAscii().data()); 
       	QTextStream ds(&file);
        if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
     	     adresse = ds.readLine();
  	     //Ermitteln widget_net Belegung
             i = 0;
             while (widget_net[i] != ""){
	            i = i +1;}
             while (!ds.atEnd()) {
		adresse = ds.readLine();
                if (adresse.indexOf("Nmap scan report") == 0){
                   adresse_ = adresse.split(" ");
                   adresse = adresse_[4];
                  // Prüfung ob adresse im Array widget_net schon vorhanden ist
                  if (adresse != adresse_router  &&  adresse != adresse_eigen_){
			k = Array_pruefen(adresse);
    		if (k == 2) {
         	     		//listWidget_net->addItem (adresse);
                   		widget_net[i]= adresse;
                     		i++;
               		 }
			}}
	}}
	file.close();
   return 0;
}

int NetEin:: list_net(QString flag)
{
int pos = 0;
int pos1 = 0;
int i = 0;
int j;
int m;
QStringList adresse_;
QString adresse_eigen;
QString adresse2;
QString befehl;
QString homepath = QDir::homePath(); 
QString hostname_;
 	hostname_ = hostname();
      // Eigenen Rechner nicht anzeigen
        adresse_eigen = IP("localhost");
        i = adresse_eigen.indexOf("name_query");
        if (i > -1)
           adresse_eigen = IP(hostname_);
        adresse_ = adresse_eigen.split(" ");
        adresse_eigen = adresse_[0];
 //smbtree: zuverlässige und schnelle Linux-Rechner Suche. Windows-Rechner werden aber nicht erkannt
// -N verhindert die sudo-Abfrage
        befehl = "smbtree -N 1> " +  homepath + "/.config/qt4-fsarchiver/smbtree.txt";
	system (befehl.toAscii().data()); 
        QFile file(homepath + "/.config/qt4-fsarchiver/smbtree.txt");
    	QTextStream ds(&file);
        QString text = ds.readLine();
        if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
     	     text = ds.readLine();
   	     while (!ds.atEnd()) {
             	text = ds.readLine();
               // text = text.toLower(); 
                pos = text.indexOf("IPC$ ");
                if (pos > -1){
                pos1 = text.indexOf(hostname_);
                text = text.left(pos-1);
                text = text.trimmed();
                j = text.size();
		        text = text.right(j-2);
                if (pos1 == -1) {
                     text = text.toLower();
                     text = IP(text); // IP ermitteln
                     adresse_ = text.split(" ");
                     adresse2 = adresse_[0]; 
                  if (adresse2 != adresse_eigen){ // Eigenen Rechner nicht anzeigen
                      widget_net[i]= text;
                      i++;}
                   if (i > 99)
                      break;
                }
             }} 
        } 
	file.close();
//Auswertung findsmb-qts Windows-Rechner werden erkannt
        befehl = "findsmb-qt 1> " +  homepath + "/.config/qt4-fsarchiver/findsmb-qt.txt";
	system (befehl.toAscii().data()); 
        QFile file1(homepath + "/.config/qt4-fsarchiver/findsmb-qt.txt");
    	QTextStream ds1(&file1);
        QString adresse = ds1.readLine();
        QString adresse1; 
        int k;
        // Eigenen Rechner nicht anzeigen
	hostname_ = hostname();
        adresse_eigen = IP("localhost");
        i = adresse_eigen.indexOf("name_query");
        if (i > -1)
           adresse_eigen = IP(hostname_);
        adresse_ = adresse_eigen.split(" ");
        adresse_eigen = adresse_[0];
        if (file1.open(QIODevice::ReadWrite | QIODevice::Text)) {
            for (k = 0; k < 5; k++){
               	adresse = ds1.readLine();
             }
   	     while (!ds1.atEnd()) {
             	adresse = ds1.readLine();
                adresse = adresse.toLower();
                k = adresse.size();
                adresse_ = adresse.split(" ");
                j = adresse_[0].size();
				adresse2 =adresse_[0];
				adresse = adresse.right(k-j);
                adresse = adresse.trimmed();
                adresse_ = adresse.split(" ");
                adresse = adresse_[0];
                adresse = IP(adresse);
		// Prüfung ob adresse im Array widget_net schon vorhanden ist
                k = 0;
                if (adresse2 != adresse_eigen) // Eigenen Rechner nicht anzeigen
                	k = Array_pruefen(adresse2);
                if (k == 2) {
         	     listWidget_net->addItem(adresse);
                     widget_net[i]= adresse;
                     i++;
                }
             } 
        }
	file1.close();
        // Dateien entfernen 
  	if (file1.exists()){
     		befehl = "rm ~/.config/qt4-fsarchiver/findsmb-qt.txt";
		system (befehl.toAscii().data());
       } 	
        list_net_ssh(" ");
        //Ermitteln widget_net Belegung
        if (widget_net[0] == "" && flag == "1"){
   		QMessageBox::about(this,tr("Note","Hinweis"),
      		tr("There is currently no available network computer.\n","Es ist derzeit kein Netzwerkrechner.\n"));
        return 1;
   }
   
   return 0;
}

int NetEin::Array_pruefen(QString ip){
int k= 0;
int pos;
int pos1;
QString hostname_;
        hostname_ = hostname();
        pos = widget_net[k].indexOf(ip);
        pos1 = ip.indexOf(hostname_);
        if (pos >= 0)  // Name im Array vorhanden
               return 0;
        if (pos1 >= 0)  // Hostname, Abbruch
               return 0;
        while (widget_net[k] != "") {
            pos = widget_net[k].indexOf(ip);
            pos1 = ip.indexOf(hostname_);
            if (pos >= 0)  // Name im Array vorhanden
               return 0;
            if (pos1 >= 0)  // Hostname, Abbruch
               return 0;
            k++;
            }
        return 2;
}

int NetEin:: setting_save()
{
   extern int dialog_auswertung;   
   QString key;  
   QString befehl;
   QString text;
   QString filename;
   QFile f(filename);
   QString homepath = QDir::homePath(); 
   Qt::CheckState state;
   state = chk_datesave->checkState();
   QSettings setting("qt4-fsarchiver", "qt4-fsarchiver");
   setting.beginGroup(comNet_name);
   user = txt_user->text();
   key = txt_key->text();
dummykey = key;
   //Neue oder geänderte Daten in setting eingeben
    if (state == Qt::Checked && comNet != "")   
       {
       setting.setValue("Name",user);
       // Key verschlüsseln und in setting eingeben
       setting.setValue("key",crypt(key));
      }
   setting.endGroup();
  // Dateien entfernen 
  filename = "~/.config/qt4-fsarchiver/ip.txt";
	if (f.exists()){
     		befehl = "rm " +filename;
		system (befehl.toAscii().data());
       }     
       filename = "~/.config/qt4-fsarchiver/smbtree.txt";
       if (f.exists()){
     		befehl = "rm " + filename;
		system (befehl.toAscii().data());
       } 
   return 0;
} 


QString NetEin::hostname()
{
QString befehl;
QString text;
QString homepath = QDir::homePath();
	befehl = "hostname > " +  homepath + "/.config/qt4-fsarchiver/hostname.txt";
	system (befehl.toAscii().data()); 
        QFile file(homepath + "/.config/qt4-fsarchiver/hostname.txt");
    	QTextStream ds(&file);
        if (file.open(QIODevice::ReadWrite | QIODevice::Text)) 
            text = ds.readLine();
        befehl = "rm " + homepath + "/.config/qt4-fsarchiver/hostname.txt";
        system (befehl.toAscii().data());
        return text;
}
        
QString NetEin:: IP(QString adresse)
{
QString befehl;
int pos;
int pos1;
QString homepath = QDir::homePath();
QFile file(homepath + "/.config/qt4-fsarchiver/ip.txt");
QTextStream ds(&file);
QString text;
	befehl = "nmblookup -R " + adresse + " 1> " +  homepath + "/.config/qt4-fsarchiver/ip.txt";
	system (befehl.toAscii().data()); 
        // IP-Adresse auslesen
        int i = 0;
        // Anzahl Zeilen der Datei /.config/qt4-fsarchiver/ip.txt ermitteln
        // Ausgabe nmblookup manchmal mit einer aber auch mit 2 Zeilen
        if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
     	     do {
                 i = i + 1;
                text = ds.readLine();
	        } while (!ds.atEnd());
              }
             file.close();
        if (i  == 2) // Anzahl 2 Zeilen, nmblookup -T adresse arbeitet korrekt
	  {
          if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
     	     text = ds.readLine();
	     text = ds.readLine();   
              }
             file.close();
          }
          pos = text.indexOf("<");
          text = text.left(pos);
          text = text.toLower();
          return text;
}

void NetEin:: listWidget_show()
{
extern int dialog_auswertung;
int row = 1;
QString key_;
QString key;
QStringList comNet_;
    key = " ";
    row = listWidget_net->currentRow();
    comNet = widget_net[row];
    if (comNet.indexOf(" ") != -1){
    comNet_ = comNet.split(" ");
    comNet = comNet_[0];
    comNet_name = comNet_[1];}
    else
         comNet_name = "";
    // Prüfen ob Daten in setting
   QSettings setting("qt4-fsarchiver", "qt4-fsarchiver");
   setting.beginGroup(comNet_name);
   user = setting.value("Name").toString();
   key_ = setting.value("key").toString();
   setting.endGroup();
   //Netzwerk-Daten in Textfeld eintragen
   //key entschlüsseln 
   key = decrypt(key_);
   dummykey = key;
   txt_user ->setText(user);
   txt_key ->setText(key);
}

QString NetEin::Namen_holen()
{
  return comNet + " " + comNet_name;
}

QString NetEin::key_holen()
{
    return dummykey;
}

QString NetEin::user_holen()
{
  return user;
}

int NetEin:: end()
{ 
   close();
}

int NetEin:: go()
{ 
extern int dialog_auswertung;
QString key;
Qt::CheckState state;
state = chk_datesave->checkState();
QSettings setting("qt4-fsarchiver", "qt4-fsarchiver");
setting.beginGroup(comNet_name);
     user = txt_user->text();
     key = txt_key->text();
     if (comNet == "" && dialog_auswertung == 6)
       {
       QMessageBox::about(this, tr("Note", "Hinweis"),
      tr("You must select the computer on which the backup data to be written\n", "Sie müssen den Rechner auswählen, auf den die Sicherungsdaten geschrieben werden sollen\n"));
      return 1 ;
      }
     if (comNet == "" && dialog_auswertung == 7)
      {
       QMessageBox::about(this, tr("Note", "Hinweis"),
       tr("You must select your computer from which the backup data to be written back\n", "Sie müssen den Rechner auswählen, von dem die Sicherungsdaten zurück geschrieben werden sollen\n"));
      return 1 ;
      }
     if (user == "" )
      {
       QMessageBox::about(this, tr("Note","Hinweis"),
      tr("You must enter the user name. Can not otherwise be accessible to network computers\n", "Sie müssen den Benutzernamen eingeben. Sonst kann nicht auf Netzrechner zugegriffen werden\n"));
      return 1 ;
      }
     if (key == "" ) {
          int ret = questionMessage(tr("Is it true that you have entered a key? (NFS dont need a key)", "Ist das richtig, dass Sie keinen Schlüssel eingegeben haben? (NFS benötigt keinen Schlüssel)"));
              if (ret == 2)
              return 1;
      }
     
     if (state == Qt::Checked )   
      {
       setting.setValue("Name",user);
       setting.setValue("key",crypt(key));
      }
     setting.endGroup();
     int i = setting_save();     
     if (dialog_auswertung == 6 && i == 0)
	save_net();
     if (dialog_auswertung == 7 && i == 0)
	restore_net(); 
     if (dialog_auswertung == 8 && i == 0)
	save_clone();
     return 0;
}

void NetEin::save_net () {
extern int dialog_auswertung;
	this->setCursor(Qt::WaitCursor);
    	dialog_auswertung = 6;
     	DialogNet *dialog2 = new DialogNet;
     	dialog2->show();
        this->setCursor(Qt::ArrowCursor);
        close();
}
void NetEin::restore_net () {
extern int dialog_auswertung;
        this->setCursor(Qt::WaitCursor);
      	dialog_auswertung = 7;
      	DialogNet *dialog2 = new DialogNet;
        dialog2->show();
        this->setCursor(Qt::ArrowCursor);
        close();
}

void NetEin::save_clone () {
extern int dialog_auswertung;
        close();
      	dialog_auswertung = 8;
      	DialogClone_net *dialog2 = new DialogClone_net;
        dialog2->show();
}

QString NetEin::crypt(QString key){
FILE *lesen, *schreiben;
char dateiname_eingabe[100], dateiname_ausgabe[100];
char *homepath_;
char *suffix;
char zeichen;
int schluessel=5;
int j;
int i;
QString text;
QString homepath = QDir::homePath();
QFile file(homepath + "/.config/qt4-fsarchiver/crypt.txt");
QFile file1(homepath + "/.config/qt4-fsarchiver/crypt1.txt");
QTextStream ds(&file1);
j = key.size();
QTextStream stream(&file);
       if (file.open(QIODevice::ReadWrite| QIODevice::Text)) {
	  file.resize(1);
	  stream << key << "\n";
          file.close(); 
       }
homepath_ =  homepath.toAscii().data();
suffix = "/.config/qt4-fsarchiver/crypt.txt";
strcpy (dateiname_eingabe, homepath_);
strcat (dateiname_eingabe, suffix);
lesen=fopen(dateiname_eingabe,"r");
suffix = "/.config/qt4-fsarchiver/crypt1.txt";
strcpy (dateiname_ausgabe, homepath_);
strcat (dateiname_ausgabe, suffix);
schreiben=fopen(dateiname_ausgabe,"w");
for (i=0; i < j + 1; i++)
	{
		zeichen=fgetc(lesen);
		//Zahlen
		if((zeichen>47)&&(zeichen<58)&&((zeichen+schluessel)<58)&&((zeichen+schluessel)>47))
			fputc(zeichen+schluessel, schreiben);

		else if((zeichen>47)&&(zeichen<58)&&((zeichen+schluessel)>57))
			fputc(zeichen+schluessel+47-57, schreiben);

		else if((zeichen>47)&&(zeichen<58)&&((zeichen+schluessel)<48))
			fputc(zeichen+schluessel-47+57, schreiben);
		//Grossbuchstaben
		else if((zeichen>64)&&(zeichen<91)&&((zeichen+schluessel)<91)&&((zeichen+schluessel)>64))
			fputc(zeichen+schluessel, schreiben);

		else if((zeichen>64)&&(zeichen<91)&&((zeichen+schluessel)>90))
			fputc(zeichen+schluessel+64-90, schreiben);

		else if((zeichen>64)&&(zeichen<91)&&((zeichen+schluessel)<65))
         		fputc(zeichen+schluessel-64+90, schreiben);
		//Kleinbuchstaben
		else if((zeichen>96)&&(zeichen<123)&&((zeichen+schluessel)<123)&&((zeichen+schluessel)>96))
			fputc(zeichen+schluessel, schreiben);

		else if((zeichen>96)&&(zeichen<123)&&((zeichen+schluessel)>122))
			fputc(zeichen+schluessel+96-122, schreiben);

		else if((zeichen>96)&&(zeichen<123)&&((zeichen+schluessel)<97))
			fputc(zeichen+schluessel-96+122, schreiben);

		//sonstige Zeichen
		else
			fputc(zeichen, schreiben);
	}
	fclose(lesen);
	fclose(schreiben);
	file.remove();
        if (file1.open(QIODevice::ReadWrite | QIODevice::Text)) {
     	     text = ds.readLine();
             file1.close();
        }
        return text;
}


QString NetEin::decrypt(QString key_){
FILE *lesen, *schreiben;
char dateiname_eingabe[100], dateiname_ausgabe[100];
char *homepath_;
char *suffix;
char zeichen;
int schluessel= -5;
int j;
int i;
QString homepath = QDir::homePath();
QFile file(homepath + "/.config/qt4-fsarchiver/crypt1.txt");
QFile file1(homepath + "/.config/qt4-fsarchiver/crypt2.txt");
QTextStream ds(&file1);
QTextStream ds1(&file);
QString text;
// key_ in Datei crypt1.txt eintragen
if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
     	     ds1 << key_;
             file.close();
        }
j = file.size();
if (j == 0) // Datei noch nicht vorhanden
    return "";
homepath_ =  homepath.toAscii().data();
suffix = "/.config/qt4-fsarchiver/crypt1.txt";
strcpy (dateiname_eingabe, homepath_);
strcat (dateiname_eingabe, suffix);
lesen=fopen(dateiname_eingabe,"r");
suffix = "/.config/qt4-fsarchiver/crypt2.txt";
strcpy (dateiname_ausgabe, homepath_);
strcat (dateiname_ausgabe, suffix);
schreiben=fopen(dateiname_ausgabe,"w");

for (i=0; i < j; i++)
	{
		zeichen=fgetc(lesen);
		//Zahlen
		if((zeichen>47)&&(zeichen<58)&&((zeichen+schluessel)<58)&&((zeichen+schluessel)>47))
			fputc(zeichen+schluessel, schreiben);

		else if((zeichen>47)&&(zeichen<58)&&((zeichen+schluessel)>57))
			fputc(zeichen+schluessel+47-57, schreiben);

		else if((zeichen>47)&&(zeichen<58)&&((zeichen+schluessel)<48))
			fputc(zeichen+schluessel-47+57, schreiben);
		//Grossbuchstaben
		else if((zeichen>64)&&(zeichen<91)&&((zeichen+schluessel)<91)&&((zeichen+schluessel)>64))
			fputc(zeichen+schluessel, schreiben);

		else if((zeichen>64)&&(zeichen<91)&&((zeichen+schluessel)>90))
			fputc(zeichen+schluessel+64-90, schreiben);

		else if((zeichen>64)&&(zeichen<91)&&((zeichen+schluessel)<65))
         		fputc(zeichen+schluessel-64+90, schreiben);
		//Kleinbuchstaben
		else if((zeichen>96)&&(zeichen<123)&&((zeichen+schluessel)<123)&&((zeichen+schluessel)>96))
			fputc(zeichen+schluessel, schreiben);

		else if((zeichen>96)&&(zeichen<123)&&((zeichen+schluessel)>122))
			fputc(zeichen+schluessel+96-122, schreiben);

		else if((zeichen>96)&&(zeichen<123)&&((zeichen+schluessel)<97))
			fputc(zeichen+schluessel-96+122, schreiben);

		//sonstige Zeichen
		else
			fputc(zeichen, schreiben);
	}
	fclose(lesen);
	fclose(schreiben);
        if (file1.open(QIODevice::ReadWrite | QIODevice::Text)) {
     	     text = ds.readLine();
             file1.close();
        }
	file1.remove();
        return text;
}

int NetEin::questionMessage(QString frage)
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










