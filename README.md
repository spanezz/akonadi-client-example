# Akonadi client example

I have spent hours of utter frustration trying to build a C++ Akonadi client,
and now I'm sharing the result hoping to spare others from all the suffering.

## Background information

### Packages

At least in Debian, Akonadi client libraries are not in `libakonadi-dev` but in
`kdepimlibs5-dev`, even if `kdepimlibs5-dev` does not show in `apt-cache search
akonadi`.

### Dependencies

kdepimlibs is built with Qt4. If your application uses Qt5 you currently need
to port it back to Qt4 if you want to talk to Akonadi.

### Build system

kdepimlibs does not seem to support qmake and does not ship pkg-config `.pc`
files. If you want to use kdepimlibs your build system needs to be *cmake*.

### Application templates

Most of the code / build system snippets found on the internet (eventually
including this one) seem flawed in a way or another, because the build
toolchain of Qt/KDE applications has undergone several redesignins during time,
and the network is littered with examples from different eras.

*The* way to obtain template code to start a Qt/KDE project is to use
[kapptemplate](https://www.kde.org/applications/development/kapptemplate/).

Do not just copy the snippets from here, run kapptemplate instead to see if
there is a version that is more up to date.

kapptemplate currently supports building an "Akonadi Resource" and an "Akonadi
Serializer", but it does not support generating template code for an akonadi
client. I would be grateful if someone reviewed this example and added it as a
template to kapptemplate.

## Further links

 * [Akonadi API documentation](http://api.kde.org/stable/kdepimlibs-apidocs/akonadi/html/index.html)
