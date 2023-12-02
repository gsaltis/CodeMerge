/*****************************************************************************
 * FILE NAME    : SourceTreeWindow.cpp
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
#include "SourceTreeWindow.h"

/*****************************************************************************!
 * Function : SourceTreeWindow
 *****************************************************************************/
SourceTreeWindow::SourceTreeWindow
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
 * Function : ~SourceTreeWindow
 *****************************************************************************/
SourceTreeWindow::~SourceTreeWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
SourceTreeWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
SourceTreeWindow::CreateSubWindows()
{
  header = new MainWindowHeader("Source Files", this);
  sourceTree = new SourceTree();
  sourceTree->setParent(this);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
SourceTreeWindow::InitializeSubWindows()
{
  header = NULL;  
  sourceTree = NULL;
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
SourceTreeWindow::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   sourceTreeW;
  int                                   sourceTreeH;
  int                                   sourceTreeY;
  int                                   sourceTreeX;
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

  sourceTreeX = 0;
  sourceTreeY = MAIN_WINDOW_HEADER_HEIGHT;
  sourceTreeW = width;
  sourceTreeH = height - MAIN_WINDOW_HEADER_HEIGHT;
  sourceTree->move(sourceTreeX, sourceTreeY);
  sourceTree->resize(sourceTreeW, sourceTreeH);
}
