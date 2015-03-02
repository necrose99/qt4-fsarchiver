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

#ifndef CLONE_NET_H
#define CLONE_NET_H
#include <QtGui>
#include <string.h>
#include "ui_clone_dialog_net.h"
#include <qthread.h>
#include "thread.h"
using namespace std;

class DialogClone_net : public QWidget, private Ui::clone_dialog_net
{
	Q_OBJECT

public:
	DialogClone_net(QWidget *parent = 0);

protected slots:
   	void closeEvent(QCloseEvent* event);

public slots:
	int do_image();
        int restore_image();
        int file_check();
        void ViewProzent();
	int questionMessage(QString frage);
        void rdbutton_image_save();
        void rdbutton_image_restore();
        void format_Disk();
        void todo();
        void remainingTime(int prozent);
	void elapsedTime();
	void pid_ermitteln();
        void esc_end();
        int  block_size(int row);
        void read_write_hd();
	void keyPressEvent(QKeyEvent *event) ;
        void save_txt(QString txt);
        void Daten_eintragen();
        int search_folder_free(QString rechner_IP);
        int listWidget_folder_free_auslesen();
        QString read_txt();
        
private:
    QDirModel *dirModel;
    QItemSelectionModel *selModel;
    QLabel *questionLabel;
    int mountpoint(QString partition);
    Thread thread1;
    Thread thread2;
    QTimer *timer_clone_net; 
    QTimer *timer_read_write_net; 
    

private slots: 
      
   void startThread1();
   void thread1Ready();
   void startThread2();
   void thread2Ready();
};
#endif








