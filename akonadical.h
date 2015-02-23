/*
 * example akonadi client
 *
 * Copyright (C) 2015  Enrico Zini <enrico@enricozini.org>
 *
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the COPYING file for more details.
 */
#ifndef AKONADICAL_H
#define AKONADICAL_H

#include <kjob.h>
#include <QStringList>

class Akonadical : public QObject
{
    Q_OBJECT

public:
    Akonadical();
    void fetchItems();

signals:
    void newCollectionList(QStringList);

protected slots:
    void collectionsFetchResult(KJob* job);
};

#endif // AKONADI_H
