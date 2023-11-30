/*****************************************************************************
 * FILE NAME    : ModuleSectionWindow.cpp
 * DATE         : November 29 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <trace_winnetqt.h>
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ModuleSectionWindow.h"

/*****************************************************************************!
 * Function : ModuleSectionWindow
 *****************************************************************************/
ModuleSectionWindow::ModuleSectionWindow
(QString InTitleText) : QWidget()
{

  StartingColor = QColor(240, 240, 240);
  EndingColor = QColor(192, 192, 192);
  
  HeaderStartingColor = QColor(127, 146, 155);
  HeaderEndingColor = QColor(202, 229, 250);
  titleText = InTitleText;
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~ModuleSectionWindow
 *****************************************************************************/
ModuleSectionWindow::~ModuleSectionWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ModuleSectionWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
ModuleSectionWindow::CreateSubWindows()
{
  header = new MainWindowHeader(titleText, this);
  header->SetColors(HeaderStartingColor, HeaderEndingColor);
  header->SetFontSize(8);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
ModuleSectionWindow::InitializeSubWindows()
{
  header = NULL;  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
ModuleSectionWindow::resizeEvent
(QResizeEvent* InEvent)
{
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
  (void)height;
  (void)width;

  headerX = 0;
  headerY = 0;
  headerW = width;
  headerH = MAIN_WINDOW_HEADER_SHORT_HEIGHT;
  header->move(headerX, headerY);
  header->resize(headerW, headerH);
}

/*****************************************************************************!
 * Function : paintEvent
 *****************************************************************************/
void
ModuleSectionWindow::paintEvent
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
  painter.setBrush(QBrush(grad));
  painter.setPen(QPen(QColor(StartingColor)));
  painter.drawRect(QRect(QPoint(0, 0), s));  
}

