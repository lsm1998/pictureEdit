#include "pictureedit.h"
#include "ui_pictureedit.h"

PictureEdit::PictureEdit(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::PictureEdit)
{
    ui->setupUi(this);
    //裁剪头像活动窗口
    m_psDialog = new PhotoShotDialog(ui->label);
    connect(ui->selectButton, &QPushButton::clicked, this, [&](bool checked)
    {
        loadPicture();
    });
    connect(ui->pushButton, &QPushButton::clicked, this, [&](bool checked)
    {
        savePicture();
    });
    connect(ui->amplifyButton, &QPushButton::clicked, this, [&](bool checked)
    {
        m_psDialog->scaleDialog(1.2);
    });
    connect(ui->reduceButton, &QPushButton::clicked, this, [&](bool checked)
    {
        m_psDialog->scaleDialog(0.8);
    });
    m_psDialog->show();
}

PictureEdit::~PictureEdit()
{
    delete ui;
}

void PictureEdit::loadPicture()
{
    // 选择图片
    this->fileName = QFileDialog::getOpenFileName(this, "open", "", "Image Files(*.jpg *.png *.bmp)");
    m_srcPix.load(fileName);
    this->selectPath = QFileInfo(fileName).absolutePath();
    m_scaledPix = m_srcPix.scaled(ui->label->width(), ui->label->height());
    ui->label->setPixmap(m_scaledPix);
}

void PictureEdit::savePicture()
{
    //截图
    QPixmap pix = m_scaledPix.copy(m_psDialog->getCutGeometry());
    // 获取文件名称
    auto filename = QFileInfo(this->fileName).fileName();
    auto ext = QFileInfo(this->fileName).suffix();
    pix.save(this->selectPath + "/cut_" + filename, ext.toStdString().c_str());
    // 提示保存成功
    QMessageBox::information(this, "提示", "保存成功");
    // 重置选择框位置
    this->m_psDialog->scaleDialog(1);
}
