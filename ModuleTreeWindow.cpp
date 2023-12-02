/*****************************************************************************
 * FILE NAME    : ModuleTreeWindow.cpp
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
#include "ModuleTreeWindow.h"

/*****************************************************************************!
 * Function : ModuleTreeWindow
 *****************************************************************************/
ModuleTreeWindow::ModuleTreeWindow
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
 * Function : ~ModuleTreeWindow
 *****************************************************************************/
ModuleTreeWindow::~ModuleTreeWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ModuleTreeWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
ModuleTreeWindow::CreateSubWindows()
{
  header = new MainWindowHeader("Modules", this);
  moduleTree = new ModuleTree();
  moduleTree->setParent(this);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
ModuleTreeWindow::InitializeSubWindows()
{
  header = NULL;  
  moduleTree = NULL;
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
ModuleTreeWindow::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   moduleTreeW;
  int                                   moduleTreeH;
  int                                   moduleTreeY;
  int                                   moduleTreeX;
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
  headerH = MAIN_WINDOW_HEADER_HEIGHT;;
  header->move(headerX, headerY);
  header->resize(headerW, headerH);

  moduleTreeX = 0;
  moduleTreeY = MAIN_WINDOW_HEADER_HEIGHT;
  moduleTreeW = width;
  moduleTreeH = height - MAIN_WINDOW_HEADER_HEIGHT;
  moduleTree->move(moduleTreeX, moduleTreeY);
  moduleTree->resize(moduleTreeW, moduleTreeH);
}

/*****************************************************************************!
 * Function : AddModuleSet
 *****************************************************************************/
void
ModuleTreeWindow::AddModuleSet
(BuildModuleSet* InModuleSet1, BuildModuleSet* InModuleSet2)
{
  moduleTree->AddModuleSet(InModuleSet1, InModuleSet2);
}
