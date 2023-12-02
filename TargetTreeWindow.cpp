/*****************************************************************************
 * FILE NAME    : TargetTreeWindow.cpp
 * DATE         : December 02 2023
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
#include "TargetTreeWindow.h"

/*****************************************************************************!
 * Function : TargetTreeWindow
 *****************************************************************************/
TargetTreeWindow::TargetTreeWindow
() : QWidget()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~TargetTreeWindow
 *****************************************************************************/
TargetTreeWindow::~TargetTreeWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
TargetTreeWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
TargetTreeWindow::CreateSubWindows()
{
  header = new MainWindowHeader("Targets", this);
  targetTree = new TargetTree();
  targetTree->setParent(this);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
TargetTreeWindow::InitializeSubWindows()
{
  header = NULL;  
  targetTree = NULL;
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
TargetTreeWindow::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   targetTreeW;
  int                                   targetTreeH;
  int                                   targetTreeY;
  int                                   targetTreeX;
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

  targetTreeX = 0;
  targetTreeY = MAIN_WINDOW_HEADER_HEIGHT;
  targetTreeW = width;
  targetTreeH = height - MAIN_WINDOW_HEADER_HEIGHT;
  targetTree->move(targetTreeX, targetTreeY);
  targetTree->resize(targetTreeW, targetTreeH);
}
