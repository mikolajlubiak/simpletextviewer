HEADERS       = mainwindow.h \
                findfiledialog.h \
                assistant.h \
                textedit.h \
		openurldialog.h
SOURCES       = main.cpp \
                mainwindow.cpp \
                findfiledialog.cpp \
                assistant.cpp \
                textedit.cpp \
		openurldialog.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

QT += widgets
QT += network

target.path = simpletextviewer
docs.files += $$PWD/documentation
docs.path = $$target.path

INSTALLS += target docs

