#include "photoshotdialog.h"
#include <QPainterPath>
#include <QPainter>
#include <QBrush>

PhotoShotDialog::PhotoShotDialog(QWidget *parent) :
        QWidget(parent)
{
    //裁剪头像活动窗口
    //设置透明
    this->setWindowFlags(Qt::FramelessWindowHint);

    //设置矩形区域
    this->setGeometry(0, 0, parentWidget()->width(), parentWidget()->height());

    //头像剪切窗口
    m_cutDialog = new CutDialog(this, 10, 10, parentWidget()->width(), parentWidget()->height());
    m_cutDialog->show();

    m_cutDialog->scaleDialog(1);
}


PhotoShotDialog::~PhotoShotDialog()
{

}

QRect PhotoShotDialog::getCutGeometry()
{
    return m_cutDialog->geometry();
}

void PhotoShotDialog::paintEvent(QPaintEvent *event)
{
    QPainterPath painterPath;
    QPainterPath p;
    p.addRect(x(), y(), this->rect().width(), this->rect().height()); //裁剪头像活动窗口 （蓝色矩形）
    painterPath.addRect(m_cutDialog->geometry()); //头像剪切窗口 (紫色矩形)

    QPainterPath drawPath = p.subtracted(painterPath); //subtracted 获取除了painterPath区域以外的窗口
    QPainter painter(this);
    painter.setOpacity(0.6); //设置Qt控件透明度 0表示全透明,1表示不透明
    painter.fillPath(drawPath, QBrush(Qt::black));
}

void PhotoShotDialog::scaleDialog(double factor)
{
    m_cutDialog->scaleDialog(factor);
}

