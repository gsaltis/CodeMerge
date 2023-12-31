/*****************************************************************************
 * FILE NAME    : MainMessageWindow.cpp
 * DATE         : November 29 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainMessageWindow.h"

/*****************************************************************************!
 * Function : MainMessageWindow
 *****************************************************************************/
MainMessageWindow::MainMessageWindow
() : QWidget()
{
  QPalette pal;

  StartingColor = QColor(114, 159, 207);
  EndingColor = QColor(52, 82, 105);
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~MainMessageWindow
 *****************************************************************************/
MainMessageWindow::~MainMessageWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
MainMessageWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
  CreateConnections();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
MainMessageWindow::CreateSubWindows()
{
  header = new MainWindowHeader("Messages", this);
  compileErrorText = new CompileErrorDisplay();
  compileErrorText->setParent(this);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
MainMessageWindow::InitializeSubWindows()
{
  header = NULL;  
  compileErrorText = NULL;
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
MainMessageWindow::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   compileErrorTextW;
  int                                   compileErrorTextH;
  int                                   compileErrorTextY;
  int                                   compileErrorTextX;
  int                                   headerW;
  int                                   headerH;
  int                                   headerY;
  int                                   headerX;
  QSize					size;  
  int					width;
  int					height;

  size = InEvent->size();
  width = size.width();
  height = size.height();

  headerX = 0;
  headerY = 0;
  headerW = width;
  headerH = MAIN_WINDOW_HEADER_HEIGHT;
  header->move(headerX, headerY);
  header->resize(headerW, headerH);

  compileErrorTextX = 0;
  compileErrorTextY = MAIN_WINDOW_HEADER_HEIGHT;
  compileErrorTextW = width;
  compileErrorTextH = height - MAIN_WINDOW_HEADER_HEIGHT;
  compileErrorText->move(compileErrorTextX, compileErrorTextY);
  compileErrorText->resize(compileErrorTextW, compileErrorTextH);
}

/*****************************************************************************!
 * Function : paintEvent
 *****************************************************************************/
void
MainMessageWindow::paintEvent
(QPaintEvent* )
{
  QPainter                              painter(this);
  QSize                                 s;
  QLinearGradient                       grad;

  s = size();

  grad.setStart(QPoint(0, 0));
  grad.setFinalStop(QPoint(0, size().height()));
  grad.setColorAt(0, StartingColor);
  grad.setColorAt(1, EndingColor);
  painter.setPen(QPen(QColor(StartingColor)));
  painter.setBrush(QBrush(grad));
  painter.drawRect(QRect(QPoint(0, 0), s));
}

/*****************************************************************************!
 * Function : SlotErrorMessage
 *****************************************************************************/
void
MainMessageWindow::SlotErrorMessage
(QString InErrorMessage)
{
  emit SignalErrorMessage(InErrorMessage);
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
MainMessageWindow::CreateConnections(void)
{
  connect(this,
          MainMessageWindow::SignalErrorMessage,
          compileErrorText,
          CompileErrorDisplay::SlotErrorMessage);
  connect(this,
          MainMessageWindow::SignalErrorClear,
          compileErrorText,
          CompileErrorDisplay::SlotErrorClear);
}

/*****************************************************************************!
 * Function : SlotErrorClear
 * Purpose  : Send 'Clear Error Display Window' message 
 *****************************************************************************/
void
MainMessageWindow::SlotErrorClear()
{
  emit SignalErrorClear();
}
