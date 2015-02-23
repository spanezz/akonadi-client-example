/*
 * example akonadi client
 *
 * Copyright (C) 2015  Enrico Zini <enrico@enricozini.org>
 *
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the COPYING file for more details.
 */
#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <QMainWindow>
#include <QStringList>
#include "akonadical.h"

namespace Ui {
class Example;
}

class Example : public QMainWindow
{
    Q_OBJECT

protected:
    Akonadical calendar;

public:
    explicit Example(QWidget *parent = 0);
    ~Example();

private:
    Ui::Example *ui;

protected slots:
    void onStart();
    void newCollectionList(QStringList list);
};

#endif // ZAVAI_H
