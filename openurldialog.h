#ifndef OPENURLDIALOG_H
#define OPENURLDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QDialogButtonBox;
class QLabel;
QT_END_NAMESPACE

class Assistant;
class TextEdit;

class openurldialog : public QDialog
{
    Q_OBJECT
public:
    openurldialog(TextEdit *editor, Assistant *assistant);

private slots:
    void openUrl();
    void update();

private:
    void createButtons();
    void createLineEdits();
    void createLabels();
    void createLayout();

    TextEdit *currentEditor;
    Assistant *currentAssistant;

    QLineEdit *urlLineEdit;

    QLabel *urlLabel;

    QDialogButtonBox *buttonBox;
};

#endif // OPENURLDIALOG_H
