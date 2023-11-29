/*****************************************************************************
 * FILE NAME    : ModuleWindow.cpp
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
#include "ModuleWindow.h"

/*****************************************************************************!
 * Function : ModuleWindow
 *****************************************************************************/
ModuleWindow::ModuleWindow
() : QWidget()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(240, 240, 240)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~ModuleWindow
 *****************************************************************************/
ModuleWindow::~ModuleWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ModuleWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
ModuleWindow::CreateSubWindows()
{
  header = new MainWindowHeader("Modules", this);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
ModuleWindow::InitializeSubWindows()
{
  header = NULL;  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
ModuleWindow::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   headerW;
  int                                   headerY;
  int                                   headerX;
  int                                   headerH;
  QSize					size;  
  int					width;
  int					height;

  (void)height;
  
  size = InEvent->size();
  width = size.width();
  height = size.height();

  headerX = 0;
  headerY = 0;
  headerW = width;
  headerH = MAIN_WINDOW_HEADER_HEIGHT;

  header->move(headerX, headerY);
  header->resize(headerW, headerH);
}
