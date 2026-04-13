#include "ImageViewer.h"
#include <QScrollBar>

ImageViewer::ImageViewer(QWidget *parent)
    : QGraphicsView{parent},
    m_isPan(false),
    m_prevPan(0,0),
    scene(nullptr),
    m_fitScale(1.0)
{
    scene = new QGraphicsScene(this);
    this->setScene(scene);

    setDragMode(QGraphicsView::DragMode::NoDrag);
    setInteractive(false);
    setEnabled(false);
}

void ImageViewer::setPixmap(QPixmap pixmap)
{
    m_image = pixmap.copy();
    initShow();
}
void ImageViewer::resetImage()
{
    scene->clear();
    setEnabled(false);
}

QPixmap ImageViewer::getPixmap()
{
    return m_image;
}
void ImageViewer::initShow()
{
    setEnabled(true);
    setMouseTracking(true);
    scene->clear();
    scene->addPixmap(m_image);
    scene->update();
    this->resetTransform();
    this->setSceneRect(m_image.rect());
    this->fitInView(QRect(0, 0, m_image.width(), m_image.height()), Qt::KeepAspectRatio);
    m_fitScale = transform().m11();
}
void ImageViewer::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        togglePan(true, event->pos());
        event->accept();
        return;
    }
    event->ignore();
}

void ImageViewer::mouseMoveEvent(QMouseEvent *event)
{
    if(m_isPan) {
        pan(event->pos());
        event->accept();
        return;
    }
    event->ignore();
}


void ImageViewer::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        togglePan(false);
        event->accept();
        return;
    }
    event->ignore();
}

void ImageViewer::zoom(QPoint factor)
{
    constexpr double zoomInStep = 1.2;
    constexpr double zoomOutStep = 0.8;
    constexpr double maxZoomFactor = 100.0;
    constexpr double epsilon = 1e-6;

    const double currentScale = transform().m11();
    const double minAllowedScale = m_fitScale;
    const double maxAllowedScale = m_fitScale * maxZoomFactor;

    if (factor.y() > 0) {
        if (currentScale >= maxAllowedScale - epsilon) {
            return;
        }

        const double targetScale = currentScale * zoomInStep;
        if (targetScale > maxAllowedScale) {
            const double correction = maxAllowedScale / currentScale;
            scale(correction, correction);
        } else {
            scale(zoomInStep, zoomInStep);
        }
        return;
    }

    if (factor.y() < 0) {
        if (currentScale <= minAllowedScale + epsilon) {
            return;
        }

        const double targetScale = currentScale * zoomOutStep;
        if (targetScale < minAllowedScale) {
            const double correction = minAllowedScale / currentScale;
            scale(correction, correction);
        } else {
            scale(zoomOutStep, zoomOutStep);
        }
    }
}
void ImageViewer::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_O) {
        this->resetTransform();
        this->setSceneRect(m_image.rect());
        this->fitInView(QRect(0, 0, m_image.width(), m_image.height()), Qt::KeepAspectRatio);
        m_fitScale = transform().m11();
    }
}

void ImageViewer::pan(const QPoint &panTo)
{
    auto hBar = horizontalScrollBar();
    auto vBar = verticalScrollBar();
    auto delta = panTo - m_prevPan;
    m_prevPan = panTo;
    hBar->setValue(hBar->value() - delta.x());
    vBar->setValue(vBar->value() - delta.y());
}

void ImageViewer::wheelEvent(QWheelEvent *event)
{
    if(m_image.isNull()) {
        event->ignore();
        return;
    }

    int deltaY = event->angleDelta().y();
    if (deltaY == 0) {
        deltaY = event->pixelDelta().y();
    }
    if (deltaY == 0) {
        event->ignore();
        return;
    }

    int direction = (deltaY > 0) ? 1 : -1;
    if (event->inverted()) {
        direction = -direction;
    }

    zoom(QPoint(0, direction));
    event->accept();
}


void ImageViewer::togglePan(bool pan, const QPoint &startPos)
{
    if(pan){
        if(m_isPan) {
            return;
        }
        m_isPan = true;
        m_prevPan = startPos;
        setCursor(Qt::ClosedHandCursor);
    } else {
        if(!m_isPan) {
            return;
        }
        m_isPan = false;
        m_prevPan = QPoint(0,0);
        setCursor(Qt::ArrowCursor);
    }
}
