// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QTextEdit>

QT_BEGIN_NAMESPACE
class QUrl;
class QNetworkAccessManager;
class QNetworkReply;
QT_END_NAMESPACE

class TextEdit : public QTextEdit
{
    Q_OBJECT

public:
    TextEdit(QWidget *parent = nullptr);
    void setContents(const QString& data);
    void openFile(const QString &fileName);
    void openUrl(const QUrl &url);

private:
    QVariant loadResource(int type, const QUrl &name) override;
    void replyReady(QNetworkReply *reply);

    QUrl srcUrl;

    QNetworkAccessManager *manager;
};

#endif
