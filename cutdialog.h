#ifndef CUTDIALOG_H
#define CUTDIALOG_H

#include <QWidget>
#include <QPoint>

//头像剪切窗口
class CutDialog : public QWidget
{
Q_OBJECT

public:
    explicit CutDialog(QWidget *parent, int minAw, int minAh, int maxAw, int maxAh);

    ~CutDialog() override;

    // 放缩
    void scaleDialog(double factor);

protected:
    void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    //QPoint m_pt;
    QPoint m_startPoint;
    bool m_mouseDown;
    int aw{150};
    int ah{150};
    int maxAw{500};
    int maxAh{500};
    int minAw{10};
    int minAh{10};
};

#endif // CUTDIALOG_H
