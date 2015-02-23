/*
 * example akonadi client
 *
 * Copyright (C) 2015  Enrico Zini <enrico@enricozini.org>
 *
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the COPYING file for more details.
 */
#include "example.h"
#include "ui_example.h"
#include <QDebug>

using namespace std;

Example::Example(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Example)
{
    ui->setupUi(this);

    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(onStart()));
    connect(&calendar, SIGNAL(newCollectionList(QStringList)), this, SLOT(newCollectionList(QStringList)));
}

Example::~Example()
{
    delete ui;
}

void Example::onStart()
{
    calendar.fetchItems();
}

void Example::newCollectionList(QStringList list)
{
    for (auto& s: list)
        ui->output->appendPlainText(s + "\n");
}
