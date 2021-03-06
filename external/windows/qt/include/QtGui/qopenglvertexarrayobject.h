/****************************************************************************
**
** Copyright (C) 2014 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Sean Harmer <sean.harmer@kdab.com>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtGui module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia. For licensing terms and
** conditions see http://qt.digia.com/licensing. For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights. These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QOPENGLVERTEXARRAYOBJECT_H
#define QOPENGLVERTEXARRAYOBJECT_H

#include <QtCore/qglobal.h>

#ifndef QT_NO_OPENGL

#include <QtCore/QObject>
#include <QtGui/qopengl.h>

QT_BEGIN_NAMESPACE

class QOpenGLVertexArrayObjectPrivate;

class Q_GUI_EXPORT QOpenGLVertexArrayObject : public QObject
{
    Q_OBJECT

public:
    explicit QOpenGLVertexArrayObject(QObject* parent = 0);
    ~QOpenGLVertexArrayObject();

    bool create();
    void destroy();
    bool isCreated() const;
    GLuint objectId() const;
    void bind();
    void release();

    class Q_GUI_EXPORT Binder
    {
    public:
        inline Binder(QOpenGLVertexArrayObject *v)
            : vao(v)
        {
            Q_ASSERT(v);
            if (vao->isCreated() || vao->create())
                vao->bind();
        }

        inline ~Binder()
        {
            release();
        }

        inline void release()
        {
            vao->release();
        }

        inline void rebind()
        {
            vao->bind();
        }

    private:
        Q_DISABLE_COPY(Binder)
        QOpenGLVertexArrayObject *vao;
    };

private:
    Q_DISABLE_COPY(QOpenGLVertexArrayObject)
    Q_DECLARE_PRIVATE(QOpenGLVertexArrayObject)
    Q_PRIVATE_SLOT(d_func(), void _q_contextAboutToBeDestroyed())
    QOpenGLVertexArrayObject(QOpenGLVertexArrayObjectPrivate &dd);
};

QT_END_NAMESPACE

#endif

#endif // QOPENGLVERTEXARRAYOBJECT_H
