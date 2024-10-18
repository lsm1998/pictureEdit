#ifndef PICTUREEDIT_H
#define PICTUREEDIT_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPixmap>
#include <QFileDialog>
#include "photoshotdialog.h"

namespace Ui
{
    class PictureEdit;
}

//头像裁剪窗口
class PictureEdit : public QMainWindow
{
Q_OBJECT

public:
    explicit PictureEdit(QWidget *parent = nullptr);

    ~PictureEdit() override;

private:
    Ui::PictureEdit *ui;

    PhotoShotDialog *m_psDialog;
    QPixmap m_srcPix;
    QPixmap m_scaledPix;

    QString selectPath;
    QString fileName;

    void loadPicture();
    void savePicture();
};

#endif // PICTUREEDIT_H
