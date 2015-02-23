/*
 * example akonadi client
 *
 * Copyright (C) 2015  Enrico Zini <enrico@enricozini.org>
 *
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the COPYING file for more details.
 */
#include "akonadical.h"
#include <akonadi/collectionfetchjob.h>
#include <akonadi/collectionfetchscope.h>
#include <QStringList>

void Akonadical::fetchItems()
{
    using namespace Akonadi;
    qDebug() << "fetchItems";
    // fetching all collections containing emails recursively, starting at the root collection
    CollectionFetchJob *job = new CollectionFetchJob(Collection::root(), CollectionFetchJob::Recursive, this);
    job->fetchScope().setContentMimeTypes(QStringList() << "message/rfc822");
    connect(job, SIGNAL(result(KJob*)), this, SLOT(collectionsFetchResult(KJob*)));
}

void Akonadical::collectionsFetchResult(KJob *job)
{
    using namespace Akonadi;
    qDebug() << "collectionFetchResult";
    if (job->error())
    {
      qDebug() << "Error occurred:" << job->error();
      return;
    }

    CollectionFetchJob *fetchJob = qobject_cast<CollectionFetchJob*>(job);
    const Collection::List collections = fetchJob->collections();
    QStringList result;
    for (auto& coll: collections)
        result << coll.name();
    emit newCollectionList(result);
}

Akonadical::Akonadical()
{
}
