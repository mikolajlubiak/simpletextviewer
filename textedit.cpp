// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "textedit.h"

#include <QFile>
#include <QFileInfo>
#include <QUrl>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

TextEdit::TextEdit(QWidget *parent)
    : QTextEdit(parent)
{
    setReadOnly(true);

    manager = new QNetworkAccessManager(parent);
}

void TextEdit::setContents(const QString &data)
{
    // setHtml(data);
    setPlainText(data);
}

void TextEdit::openFile(const QString &fileName)
{
    const QFileInfo fi(fileName);
    srcUrl = QUrl::fromLocalFile(fi.absoluteFilePath());
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly)) {
        const QString data(QString::fromUtf8(file.readAll()));

        if (fi.suffix() == "html") {
            setHtml(data);
            // setPlainText(data);
        }
        else {
            setPlainText(data);
        }
    }
}

void TextEdit::openUrl(const QUrl &url)
{
    auto status = connect(manager, &QNetworkAccessManager::finished,
                          this, &TextEdit::replyReady);

    manager->get(QNetworkRequest(url));
}

void TextEdit::replyReady(QNetworkReply *reply) {
    const QString data(QString::fromUtf8(reply->readAll()));
    setHtml(data);
    // setPlainText(data);
}

QVariant TextEdit::loadResource(int type, const QUrl &name)
{
    if (type == QTextDocument::ImageResource) {
        QFile file(srcUrl.resolved(name).toLocalFile());
        if (file.open(QIODevice::ReadOnly))
            return file.readAll();
    }
    return QTextEdit::loadResource(type, name);
}
