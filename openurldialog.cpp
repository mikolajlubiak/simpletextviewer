#include "openurldialog.h"
#include "assistant.h"
#include "textedit.h"


#include <QDialogButtonBox>
#include <QLabel>
#include <QBoxLayout>
#include <QPushButton>
#include <QLineEdit>

openurldialog::openurldialog(TextEdit *editor, Assistant *assistant)
    : QDialog(editor)
    , currentEditor(editor)
    , currentAssistant(assistant)
{
    createButtons();
    createLineEdits();
    createLabels();
    createLayout();
}

void openurldialog::openUrl() {
    currentEditor->openUrl(urlLineEdit->text());
    close();
}

void openurldialog::update()
{
    buttonBox->button(QDialogButtonBox::Open)->setEnabled(urlLineEdit->text().length() > 0);
}


void openurldialog::createButtons() {
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Open
                                     | QDialogButtonBox::Cancel
                                     | QDialogButtonBox::Help);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &openurldialog::openUrl);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

void openurldialog::createLineEdits()
{
    urlLineEdit = new QLineEdit;

    urlLineEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    connect(urlLineEdit, &QLineEdit::textChanged, this, &openurldialog::update);
}


void openurldialog::createLabels() {
    urlLabel = new QLabel(tr("Open URL"));
}

void openurldialog::createLayout()
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(urlLabel);
    mainLayout->addWidget(urlLineEdit);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);
}

