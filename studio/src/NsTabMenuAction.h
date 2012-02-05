// -----------------------------------------------------------------------------
//
// NsTabMenuAction.h
//
// Naiad Studio tab menu action, header file.
//
// Copyright (c) 2011 Exotic Matter AB. All rights reserved.
//
// This file is part of Open Naiad Studio.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// * Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
//
// * Neither the name of Exotic Matter AB nor its contributors may be used to
// endorse or promote products derived from this software without specific
// prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
// COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
// ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// -----------------------------------------------------------------------------

#ifndef NS_TAB_MENU_ACTION_H
#define NS_TAB_MENU_ACTION_H

#include <QAction>

// -----------------------------------------------------------------------------

class NsTabMenuAction : public QAction
{
    Q_OBJECT

public:

    //! CTOR.
    explicit
    NsTabMenuAction(const QString &opType, QObject *parent = 0)
        : QAction(opType, parent)
        , _opType(opType)
    { connect(this, SIGNAL(triggered()), SLOT(_onTriggered())); }

    //! DTOR.
    virtual
    ~NsTabMenuAction()
    {}

public:

    const QString&
    opType() const
    { return _opType; }

signals:
    
    void
    triggered(const QString &opType);

private slots:

    void
    _onTriggered()
    { emit triggered(_opType); }

private:    // Member variables.

    QString _opType;
};  

#endif  // NS_TAB_MENU_ACTION_H
