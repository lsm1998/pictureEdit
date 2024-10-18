#include "cutdialog.h"
#include <QMouseEvent>
#include <QDebug>
#include <QRect>


CutDialog::CutDialog(QWidget *parent, int minAw, int minAh, int maxAw, int maxAh) :
        QWidget(parent)
{
    setGeometry(0, 0, this->aw, this->ah);
    m_mouseDown = false;
    this->minAw = minAw;
    this->minAh = minAh;
    this->maxAw = maxAw;
    this->maxAh = maxAh;
}

CutDialog::~CutDialog()
{
}

void CutDialog::mousePressEvent(QMouseEvent *event)
{
    //鼠标位置
    m_startPoint = event->pos();
    //鼠标左键
    m_mouseDown = event->button() == Qt::LeftButton;
}

void CutDialog::mouseMoveEvent(QMouseEvent *event)
{
    //获取到拖动位置
    QPoint dragPoint = event->pos();

    if (m_mouseDown)
    {
        //pos保存小部件在欺父部件中的位置
        QPoint p = QPoint(pos().x() + dragPoint.x() - m_startPoint.x(), pos().y() + dragPoint.y() - m_startPoint.y());

        QPoint dragEndge = p;
        dragEndge.setX(dragEndge.x() + rect().width());
        dragEndge.setY(dragEndge.y() + rect().height());

        p.setX(p.x() < 0 ? 0 : p.x());
        p.setY(p.y() < 0 ? 0 : p.y());

        p.setX(dragEndge.x() > parentWidget()->width() ? parentWidget()->width() - rect().width() : p.x());
        p.setY(dragEndge.y() > parentWidget()->height() ? parentWidget()->height() - rect().height() : p.y());

        move(p);
    }
}

void CutDialog::mouseReleaseEvent(QMouseEvent *event)
{
    m_mouseDown = false;
}

void CutDialog::scaleDialog(double factor)
{
    this->aw = int(this->aw * factor);
    this->ah = int(this->ah * factor);
    this->aw = this->aw < minAw ? minAw : this->aw;
    this->ah = this->ah < minAh ? minAh : this->ah;
    this->aw = this->aw > maxAw ? maxAw : this->aw;
    this->ah = this->ah > maxAh ? maxAh : this->ah;
    setGeometry(0, 0, this->aw, this->ah);
}