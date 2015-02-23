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
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Example w;

    w.show();

    return a.exec();
}
