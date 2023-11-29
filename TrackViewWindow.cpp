/*****************************************************************************
 * FILE NAME    : TrackViewWindow.cpp
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
#include "TrackViewWindow.h"

/*****************************************************************************!
 * Function : TrackViewWindow
 *****************************************************************************/
TrackViewWindow::TrackViewWindow
(QString InTitleText) : QWidget()
{
  QPalette pal;

  titleText = InTitleText;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~TrackViewWindow
 *****************************************************************************/
TrackViewWindow::~TrackViewWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
TrackViewWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
TrackViewWindow::CreateSubWindows()
{
  header = new MainWindowHeader(titleText, this);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
TrackViewWindow::InitializeSubWindows()
{
  header = NULL;  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
TrackViewWindow::resizeEvent
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
  headerH = MAIN_WINDOW_HEADER_HEIGHT;
  
  header->move(headerX, headerY);
  header->resize(headerW, headerH);
}
