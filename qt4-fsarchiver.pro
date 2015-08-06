######################################################################
# Automatically generated by qmake (2.01a) Mi. Jan 9 23:07:48 2013
######################################################################

TEMPLATE = app
TARGET = bin/qt4-fsarchiver
DEPENDPATH += . src translations src/ui

DEFINES +=  HAVE_CONFIG_H _REENTRANT _FILE_OFFSET_BITS=64 _LARGEFILE64_SOURCE _GNU_SOURCE 
INCLUDEPATH += . src /usr/include/ext2fs /usr/include/et /usr/include/e2p /usr/include/blkid /usr/include/uuid 
LIBS += -L/usr/lib -lQtGui -lQtCore -lpthread -lrt -llzma -lext2fs -lcom_err -le2p -lblkid -luuid -lz -lbz2 -llzo2 -lgcrypt -lgpg-error
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
RCC_DIR = build
CODECFORTR=utf8
CODECFORSRC=utf8
#CONFIG += debug

# Input
HEADERS += src/archinfo.h \
           src/archreader.h \
           src/archwriter.h \
           src/clone.h \
           src/clone_net.h \
           src/common.h \
           src/comp_bzip2.h \
           src/comp_gzip.h \
           src/comp_lzma.h \
           src/comp_lzo.h \
           src/config.h \
           src/connect_c_cpp.h \
           src/crypto.h \
           src/datafile.h \
           src/devinfo.h \
           src/dichl.h \
           src/dico.h \
           src/dir.h \
           src/error.h \
           src/filedialog.h \
           src/filesys.h \
           src/fs_btrfs.h \
           src/fs_ext2.h \
           src/fs_jfs.h \
           src/fs_ntfs.h \
           src/fs_reiser4.h \
           src/fs_reiserfs.h \
           src/fs_xfs.h \
           src/fsarchiver.h \
           src/gettext.h \
           src/logfile.h \
           src/mainWindow.h \
           src/mbr.h \
           src/net.h \
           src/net_ein.h \
           src/oper_probe.h \
           src/oper_restore.h \
           src/oper_save.h \
           src/options.h \
           src/qt_probe.h \
           src/queue.h \
           src/regmulti.h \
           src/setting.h \
           src/strdico.h \
           src/strlist.h \
           src/syncthread.h \
           src/system.h \
           src/thread.h \
           src/thread_archio.h \
           src/thread_comp.h \
           src/treeview.h \
           src/types.h \
           src/writebuf.h
FORMS += src/ui/clone_dialog.ui \
         src/ui/clone_dialog_net.ui \
         src/ui/dir_dialog.ui \
         src/ui/filedialog.ui \
         src/ui/fsarchiverMain.ui \
         src/ui/mbr_dialog.ui \
         src/ui/net.ui \
         src/ui/net_ein.ui \
         src/ui/setting.ui \
         src/ui/treeview.ui
SOURCES += src/archinfo.c \
           src/archreader.c \
           src/archwriter.c \
           src/clone.cpp \
           src/clone_net.cpp \
           src/common.c \
           src/comp_bzip2.c \
           src/comp_gzip.c \
           src/comp_lzma.c \
           src/comp_lzo.c \
           src/connect_c_cpp.c \
           src/crypto.c \
           src/datafile.c \
           src/devinfo.c \
           src/dichl.c \
           src/dico.c \
           src/dir.cpp \
           src/error.c \
           src/filedialog.cpp \
           src/filesys.c \
           src/fs_btrfs.c \
           src/fs_ext2.c \
           src/fs_jfs.c \
           src/fs_ntfs.c \
           src/fs_reiser4.c \
           src/fs_reiserfs.c \
           src/fs_xfs.c \
           src/fsarchiver.c \
           src/logfile.c \
           src/main.cc \
           src/mainWindow.cpp \
           src/mbr.cpp \
           src/net.cpp \
           src/net_ein.cpp \
           src/oper_probe.c \
           src/oper_restore.c \
           src/oper_save.c \
           src/options.c \
           src/qt_probe.cpp \
           src/queue.c \
           src/regmulti.c \
           src/setting.cpp \
           src/strdico.c \
           src/strlist.c \
           src/syncthread.c \
           src/thread.cpp \
           src/thread_archio.c \
           src/thread_comp.c \
           src/treeview.cpp \
           src/writebuf.c
RESOURCES += src/icon.qrc
# install
 target.path = /usr/sbin
 icon.files = src/images/harddrive.png
 icon.path = /usr/share/app-install/icons
 autostart.files = starter/gnome-qt4-fsarchiver.desktop
 autostart.path = /usr/share/applications
 autostart1.files = starter/kde-qt4-fsarchiver.desktop 
 autostart1.path = /usr/share/applications
 autostart2.files = starter/mate-qt4-fsarchiver.desktop 
 autostart2.path = /usr/share/applications
 doc.files = doc
 doc.path = /usr/share/doc/qt4-fsarchiver
 smbfind.files = src/sbin
 smbfind.path = /usr
 polkit.files = src/share/polkit-1/actions/org.project.pkexec.run-qt4-fsarchiver.policy
 polkit.path = /usr/share/polkit-1/actions

TRANSLATIONS += translations/qt4-fsarchiver_de.ts \
                translations/qt4-fsarchiver_es.ts \
		translations/qt4-fsarchiver_ru.ts \
                translations/qt4-fsarchiver_nl.ts \
                translations/qt4-fsarchiver_id.ts \
		translations/qt4-fsarchiver_it.ts \
                translations/qt4-fsarchiver_ch.ts \
                translations/qt4-fsarchiver_cs.ts \
		translations/qt4-fsarchiver_jp.ts \
                translations/qt4-fsarchiver_ar.ts \
                translations/qt4-fsarchiver_ca.ts \
		translations/qt4-fsarchiver_da.ts \
                translations/qt4-fsarchiver_el.ts \
                translations/qt4-fsarchiver_et.ts \
                translations/qt4-fsarchiver_fa.ts \
		translations/qt4-fsarchiver_fi.ts \
                translations/qt4-fsarchiver_fr.ts \
                translations/qt4-fsarchiver_he.ts \
                translations/qt4-fsarchiver_hi.ts \
		translations/qt4-fsarchiver_hu.ts \
                translations/qt4-fsarchiver_hy.ts \
                translations/qt4-fsarchiver_ko.ts \
                translations/qt4-fsarchiver_lv.ts \ 
                translations/qt4-fsarchiver_lt.ts \
		translations/qt4-fsarchiver_no.ts \
                translations/qt4-fsarchiver_pl.ts \
                translations/qt4-fsarchiver_pt.ts \
		translations/qt4-fsarchiver_ro.ts \
                translations/qt4-fsarchiver_sl.ts \
		translations/qt4-fsarchiver_sr.ts \
                translations/qt4-fsarchiver_sv.ts \
                translations/qt4-fsarchiver_th.ts \
		translations/qt4-fsarchiver_tr.ts \
                translations/qt4-fsarchiver_vi.ts \
                translations/qt4-fsarchiver_ur.ts \ 
                translations/qt4-fsarchiver_uk.ts
QMAKE_EXTRA_COMPILERS += lrelease
lrelease.input  = TRANSLATIONS
lrelease.output = ${QMAKE_FILE_BASE}.qm
lrelease.commands = $$[QT_INSTALL_BINS]/lrelease ${QMAKE_FILE_IN} -qm translations/${QMAKE_FILE_BASE}.qm
lrelease.CONFIG += no_link target_predeps
translations.files = translations/qt4-fsarchiver_de.qm \
                translations/qt4-fsarchiver_es.qm \
		translations/qt4-fsarchiver_ru.qm \
                translations/qt4-fsarchiver_nl.qm \
                translations/qt4-fsarchiver_id.qm \
		translations/qt4-fsarchiver_it.qm \
                translations/qt4-fsarchiver_ch.qm \
                translations/qt4-fsarchiver_cs.qm \
		translations/qt4-fsarchiver_jp.qm \
                translations/qt4-fsarchiver_ar.qm \
                translations/qt4-fsarchiver_ca.qm \
		translations/qt4-fsarchiver_da.qm \
                translations/qt4-fsarchiver_el.qm \
                translations/qt4-fsarchiver_et.qm \
                translations/qt4-fsarchiver_fa.qm \
		translations/qt4-fsarchiver_fi.qm \
                translations/qt4-fsarchiver_fr.qm \
                translations/qt4-fsarchiver_he.qm \
                translations/qt4-fsarchiver_hi.qm \
		translations/qt4-fsarchiver_hu.qm \
                translations/qt4-fsarchiver_hy.qm \
                translations/qt4-fsarchiver_ko.qm \
                translations/qt4-fsarchiver_lv.qm \ 
                translations/qt4-fsarchiver_lt.qm \
		translations/qt4-fsarchiver_no.qm \
                translations/qt4-fsarchiver_pl.qm \
                translations/qt4-fsarchiver_pt.qm \
		translations/qt4-fsarchiver_ro.qm \
                translations/qt4-fsarchiver_sl.qm \
		translations/qt4-fsarchiver_sr.qm \
                translations/qt4-fsarchiver_sv.qm \
                translations/qt4-fsarchiver_th.qm \
		translations/qt4-fsarchiver_tr.qm \
                translations/qt4-fsarchiver_vi.qm \
                translations/qt4-fsarchiver_ur.qm \ 
                translations/qt4-fsarchiver_uk.qm
translations.path = /usr/share/qt4/translations
 
 INSTALLS = target icon autostart autostart1 autostart2 translations doc smbfind polkit
 #QMAKE_CXXFLAGS_RELEASE = -pipe -Wall -g -O2
 #QMAKE_CFLAGS_RELEASE = -pipe -Wall -g -O2
