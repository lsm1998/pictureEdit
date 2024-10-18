#ifndef PHOTOSHOTDIALOG_H
#define PHOTOSHOTDIALOG_H

#include <QWidget>
#include "cutdialog.h"

//裁剪头像活动窗口
class PhotoShotDialog : public QWidget
{
Q_OBJECT

public:
    explicit PhotoShotDialog(QWidget *parent = nullptr);

    ~PhotoShotDialog() override;

    //获取头像剪切窗口矩形
    QRect getCutGeometry();

    void scaleDialog(double factor);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    CutDialog *m_cutDialog;
};

#endif // PHOTOSHOTDIALOG_H
